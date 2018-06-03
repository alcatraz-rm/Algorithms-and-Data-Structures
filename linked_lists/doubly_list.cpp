#include <iostream>
#include <ctime>
using namespace std;

struct element
{
  int data;
  element* next;
  element* prev;
};

class list
{
private:
  element* top_limiter = new element;
  element* lower_limiter = new element;

public:
  list(int number_of_items)
  {
    create_list(number_of_items);
  }

  void create_list(int number_of_items)
  {
    element* head = new element;
    head->data = rand() % 100 + 1;
    head->next = lower_limiter;
    head->prev = top_limiter;
    top_limiter->next = head;
    element* tmp_element = head;

    for(int i = 0; i < number_of_items - 1; i++)
    {
      tmp_element->next = new element;
      tmp_element->next->prev = tmp_element;
      tmp_element = tmp_element->next;
      tmp_element->data = rand() % 100 + 1;
      tmp_element->next = lower_limiter;
      lower_limiter->prev = tmp_element;
    }

    lower_limiter->next = NULL;
    top_limiter->prev = NULL;
  }

  int size()
  {
    element* tmp_element = top_limiter;
    int list_size = 0;

    while (tmp_element->next != lower_limiter)
    {
      tmp_element = tmp_element->next;
      list_size++;
    }

    return list_size;
  }

  void print()
  {
    element* tmp_element = top_limiter->next;

    while (tmp_element != lower_limiter)
    {
      cout<<tmp_element->data<<endl;
      tmp_element = tmp_element->next;
    }

    cout<<endl;
  }

  int get_index_by_data(int target) //this method returns element by data
  {
    int index = 0;
    element* tmp_element = top_limiter->next;

    while (tmp_element != lower_limiter)
    {
      if (tmp_element->data == target)
        return index;

      tmp_element = tmp_element->next;
      index++;
    }

    return -1;
  }

  int* get_data_by_index(int index)
  {
    if (index < 0 || index >= size())
      return NULL;

    element* tmp_element = top_limiter->next;

    while(index > 0)
    {
      tmp_element = tmp_element->next;
      index--;
    }

    return &tmp_element->data;
  }

  void add(int data)
  {
    element* old_head = top_limiter->next;

    element* new_element = new element;
    new_element->data = data;
    new_element->next = old_head;
    new_element->prev = top_limiter;

    old_head->prev = new_element;
    top_limiter->next = new_element;

  }

  void delete_element_by_index(int index)
  {
    if (index < 0 || index >= size())
      return;

    element* tmp_element = top_limiter->next;
    element* next;
    element* prev;

    while(index > 0)
    {
      tmp_element = tmp_element->next;
      index--;
    }

    prev = tmp_element->prev;
    next = tmp_element->next;

    prev->next = next;
    next->prev = prev;
    delete tmp_element;
  }

  void delete_element_by_data(int target)
  {
    delete_element_by_index(get_index_by_data(target));
  }

  void clear()
  {
    element* tmp_element = top_limiter->next;
    element* next = tmp_element->next;

    while (tmp_element != lower_limiter)
    {
      delete tmp_element;
      tmp_element = next;
      next = next->next;
    }

    top_limiter->next = lower_limiter;
    lower_limiter->prev = top_limiter;
  }

  void delete_all()
  {
    clear();
    delete top_limiter;
    delete lower_limiter;
  }

  void input()
  {
    element* tmp_element = top_limiter->next;
    cout<<"Enter all items in the list separated by enter/space: "<<endl;

    while (tmp_element != lower_limiter)
    {
      cin>>tmp_element->data;
      tmp_element = tmp_element->next;
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

};

int main()
{
  srand(time(0));
  list my_list(10);
  my_list.input();
  my_list.print();
  
  my_list.delete_all();
  return 0;
}
