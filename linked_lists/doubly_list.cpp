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
  }

  // int get_index_by_data(int target) //this method returns element by data
  // {
  //
  // }
  //
  // int* get_data_by_index(int index)
  // {
  //
  // }
  //
  // void add(int data)
  // {
  //
  // }
  //
  // void delete_element_by_index(int index)
  // {
  //   if (index < 0 || index >= size())
  //     return;
  //
  // }
  //
  // void delete_element_by_data(int target)
  // {
  //
  // }
  //
  // void clear()
  // {
  //
  // }
  //
  // void delete_all()
  // {
  //
  // }
  //
  // void input()
  // {
  //
  // }
  //
  // void change_data_by_index(int index, int new_val)
  // {
  //   if (index < 0 || index >= size())
  //     return;
  // }

};

int main()
{
  srand(time(0));
  list my_list(5);
  my_list.print();

  return 0;
}
