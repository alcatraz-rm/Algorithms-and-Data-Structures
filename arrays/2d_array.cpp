#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

vector<vector<int> > array_init(int size_y, int size_x)
{
  int i, j;
  vector<vector<int> > array(size_y);
  vector<int> tmp(size_x);

  for (i = 0; i < size_y; i++)
    array[i] = tmp;

  cout<<"SUCCESS"<<endl;
  cout<<array.size()<<" "<<array[0].size()<<endl;

  for (i = 0; i < size_y; i++)
    for (j = 0; j < size_x; j++)
      array[i][j] = rand() % 100 + 1;

  return array;
}

void print_array(vector<vector<int> > array)
{
  int i, j, size_y = array.size(), size_x = array[0].size();

  for (i = 0; i < size_y; i++)
  {
    for (j = 0; j < size_x; j++)
      cout<<array[i][j]<<" ";
    cout<<endl;
  }
}

pair <int, int> get_indexes(vector<vector<int> > array, int target)
{
  int i, j;
  for (i = 0; i < array.size(); i++)
    for (j = 0; j < array[i].size(); j++)
      if (array[i][j] == target)
          return make_pair(i, j);

  return make_pair(-1, -1);
}

int get_max(vector<vector<int> > array)
{
  int m = array[0][0], i, j;

  for (i = 0; i < array.size(); i++)
    for (j = 0; j < array[i].size(); j++)
      if (array[i][j] > m)
        m = array[i][j];

  return m;
}

int get_min(vector<vector<int> > array)
{
  int m = array[0][0], i, j;

  for (i = 0; i < array.size(); i++)
    for (j = 0; j < array[i].size(); j++)
      if (array[i][j] < m)
        m = array[i][j];

  return m;
}

double get_average(vector<vector<int> > array)
{
  double result = 0;
  int i, j;

  for (i = 0; i < array.size(); i++)
    for (j = 0; j < array[i].size(); j++)
      result += array[i][j];

  return result / (array.size() * array[0].size());
}

int main()
{
  srand(time(0));
  int i, j, size_y = 10, size_x = 10;
  vector<vector<int> > array = array_init(size_y, size_x);
  print_array(array);

  cout<<get_max(array)<<endl;
  cout<<get_min(array)<<endl;
  cout<<get_average(array)<<endl;

  return 0;
}
