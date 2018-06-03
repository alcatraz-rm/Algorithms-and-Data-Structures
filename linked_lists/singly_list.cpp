#include <iostream>
#include <ctime>
using namespace std;

struct element
{
  int data;
  element* next;
};

class list
{
private:
  element* top_limiter = new element;

public:
  list(int number_of_items)
  {
    create_list(number_of_items);
  }

  void create_list(int number_of_items)
  {
    element* head = new element; //initializing head of list
    head->data = rand() % 100 + 1;
    head->next = NULL;
    top_limiter->next = head;

    element* tmp_element = head;

    for(int i = 0; i < number_of_items - 1; i++)
    {
        tmp_element->next = new element;
        tmp_element = tmp_element->next;
        tmp_element->data = rand() % 100 + 1;
        tmp_element->next = NULL;
    }
  }

  int size()
  {
    int list_size = 0;
    element* tmp_element = top_limiter;

    while (tmp_element->next != NULL)
    {
      tmp_element = tmp_element->next;
      list_size++;
    }

    return list_size;
  }

  void print()
  {
    element* tmp_element = top_limiter->next;
    while (tmp_element != NULL)
    {
      cout<<tmp_element->data<<endl;
      tmp_element = tmp_element->next;
    }
    cout<<endl;
  }

  int get_index_by_data(int target) //this method returns element by data
  {
    element* tmp_element = top_limiter->next;
    int index = 0;

    while (tmp_element)
    {
      if (tmp_element->data == target)
        return index;
      else
      {
        tmp_element = tmp_element->next;
        index++;
      }

      if (!tmp_element)
        return -1;
    }
  }

  int* get_data_by_index(int index)
  {
    if (index < 0 || index >= size())
      return NULL;

    element* tmp_element = top_limiter->next;

    while (index)
    {
      tmp_element = tmp_element->next;
      index--;
    }

    return &tmp_element->data;
  }

  void add(int data)
  {
    element* new_element = new element;
    new_element->data = data;
    new_element->next = top_limiter->next;
    top_limiter->next = new_element;
  }

  void add_sorted(int data)
  {
    element* tmp_element = top_limiter;
    element* new_element = new element;
    new_element->data = data;

    while (tmp_element->next && tmp_element->next->data < data)
      tmp_element = tmp_element->next;

    new_element->next = tmp_element->next;
    tmp_element->next = new_element;
  }

  void delete_element_by_index(int index)
  {
    if (index < 0 || index >= size())
      return;

    element* prev = top_limiter;
    element* tmp_element;

    while (index >= 1)
    {
      prev = prev->next;
      index--;
    }

    tmp_element = prev->next;
    prev->next = prev->next->next;
    delete tmp_element;
  }

  void delete_element_by_data(int target)
  {
    delete_element_by_index(get_index_by_data(target));
  }

  void clear()
  {
    element* tmp = top_limiter->next;
    element* prev;

    while(tmp)
    {
      prev = tmp;
      tmp = tmp->next;
      delete prev;
    }

    top_limiter->next = NULL;
  }

  void delete_all()
  {
    clear();
    delete top_limiter;
  }

  void input()
  {
    cout<<"Enter all items in the list separated by enter/space: "<<endl;
    element* tmp = top_limiter->next;

    while(tmp)
    {
      cin>>tmp->data;
      tmp = tmp->next;
    }
  }

  void change_data_by_index(int index, int new_val)
  {
    if (index < 0 || index >= size())
      return;

    element* tmp_element = top_limiter->next;

    while (index)
    {
      tmp_element = tmp_element->next;
      index--;
    }

    tmp_element->data = new_val;
  }

  list copy()
  {
    int list_size = size();
    list new_list(list_size);
    for (int i = 0; i < list_size; i++)
      new_list.change_data_by_index(i, *get_data_by_index(i));

    return new_list;
  }

  void insertion_sort()
  {
    int list_size = size();
    if (list_size == 0)
      return;

    int i;
    int* values = new int [list_size];
    element* tmp_element = top_limiter->next;

    for (i = 0; i < list_size; i++)
    {
      values[i] = tmp_element->data;
      tmp_element = tmp_element->next;
    }

    clear();

    for (i = 0; i < list_size; i++)
      add_sorted(values[i]);

  }

};

int main()
{
  srand(time(0));
  list my_list(10000);
//  my_list.input();
  my_list.print();

  my_list.insertion_sort();
  my_list.print();

  my_list.delete_all();
  return 0;
}
