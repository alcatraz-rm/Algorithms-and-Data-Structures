#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> merge_sort(int begin, int end, vector<int>(&numbers))
{
  if (begin == end)
  {
    return numbers;
  }
}

int main()
{
  vector<int> numbers;
  srand(time(0));
  int i, j, index, len;
  cin >> len;

  numbers.resize(len);

  for (i = 0; i < len; i++)
  {
      numbers[i] = rand() % 1000;
      // cout << numbers[i] << " ";
  }

  return 0;
}
