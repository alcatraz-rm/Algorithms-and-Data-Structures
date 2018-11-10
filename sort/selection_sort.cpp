#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i, j, index, len;
    cin >> len;

    vector<int> numbers(len);

    for (i = 0; i < len; i++)
    {
        numbers[i] = rand() % 1000;
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            if (numbers[j] < numbers[i])
            {
                swap(numbers[i], numbers[j]);
            }
        }
    }

    for (i = 0; i < len; i++)
    {
        cout << numbers[i] << " ";
    }
    cout<<endl;

    return 0;
}
