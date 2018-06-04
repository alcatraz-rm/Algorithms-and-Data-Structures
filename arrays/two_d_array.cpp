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

int main()
{
  int i, j, size_y = 10, size_x = 10;
  vector<vector<int> > array = array_init(size_y, size_x);
  print_array(array);

  return 0;
}
