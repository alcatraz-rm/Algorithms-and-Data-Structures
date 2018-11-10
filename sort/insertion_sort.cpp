#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, index, len = 100000;
    vector<int> numbers(len);

    for (i = 0; i < len; i++)
    {
        numbers[i] = rand() % 1000;
        // cout << numbers[i] << " ";
    }
    // cout<<endl;

    for (i = 0; i < len; i++)
    {
        index = i;

        while (index - 1 >= 0 and numbers[index] < numbers[index - 1])
        {
            swap(numbers[index], numbers[index - 1]);
            index--;
        }
    }

    for (i = 0; i < len; i++)
    {
        cout << numbers[i] << " ";
    }
    cout<<endl;

    return 0;
}