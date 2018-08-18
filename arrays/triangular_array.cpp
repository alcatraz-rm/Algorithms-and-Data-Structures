#include <iostream>
#include <ctime>
using namespace std;

int** array_init(int size)
{
  int** arr = new int*[size];
  int i, j;

  for (i = 0; i < size; i++)
  {
    arr[i] = new int[i + 1];

    for (j = 0; j < i + 1; j++)
    {
      arr[i][j] = (rand() % 100) + 1;
    }
  }

  return arr;
}

void print_array(int** arr, int size)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < i + 1; j++)
    {
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }
}

void delete_array(int** arr, int size)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    delete arr[i];
  }

  delete arr;
}

int main()
{
  int size = 10;
  int** arr = array_init(size);
  print_array(arr, size);
  delete_array(arr, size);

  return 0;
}
