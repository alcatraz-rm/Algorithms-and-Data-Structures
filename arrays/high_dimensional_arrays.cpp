#include <iostream>
#include <ctime>
using namespace std;

int*** array_init(int size)
{
  int*** arr = new int**[size];
  int i, j, k;

  for (i = 0; i < size; i++)
  {
    arr[i] = new int*[size];

    for (j = 0; j < size; j++)
    {
      arr[i][j] = new int[size];

      for (k = 0; k < size; k++)
      {
        arr[i][j][k] = (rand() % 100) + 1;
      }
    }
  }

  return arr;
}

void print_array(int*** arr, int size)
{
  int i, j, k;

  for (i = 0; i < size; i++)
  {
    cout << endl << "i = " << i << endl << endl;

    for (j = 0; j < size; j++)
    {
      cout << "j = " << j << endl;

      for (k = 0; k < size; k++)
      {
        cout << arr[i][j][k] << " ";
      }

      cout << endl;
    }
  }
}

int main()
{
  int size = 10;

  int*** arr = array_init(size);
  print_array(arr, size);

  return 0;
}
