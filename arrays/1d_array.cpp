#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

vector<int> array_init(int size)
{
  int i;
  vector<int> array(size);

  for (i = 0; i < size; i++)
    array[i] = rand() % 100 + 1;

  return array;
}

void print_array(vector<int> array)
{
  int i;
  for (i = 0; i < array.size(); i++)
    cout<<array[i]<<" ";
  cout<<endl;
}

int get_index(vector<int> array, int target)
{
  int i;
  for (i = 0; i < array.size(); i++)
    if (array[i] == target)
      return i;

  return -1;
}

int get_max(vector<int> array)
{
  int i, m = array[0];

  for (i = 1; i < array.size(); i++)
    if (array[i] > m)
      m = array[i];

  return m;
}

int get_min(vector<int> array)
{
  int i, m = array[0];

  for (i = 1; i < array.size(); i++)
    if (array[i] < m)
      m = array[i];

  return m;
}

double get_average(vector<int> array)
{
  int i;
  double result;

  for(i = 0; i < array.size(); i++)
    result += array[i];

  return result/array.size();
}

int main()
{
  srand(time(0));
  int size = 10;
  vector<int> array = array_init(size);
  print_array(array);

  // array.erase(array.begin() + index); - удаление элемента
  // array.push_back(value); - вставка элемента

  return 0;
}
