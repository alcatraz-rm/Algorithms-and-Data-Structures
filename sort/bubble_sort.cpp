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
        for (j = 0; j < len - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap(numbers[j], numbers[j + 1]);
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
