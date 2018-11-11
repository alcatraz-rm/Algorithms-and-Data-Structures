#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
int calls_counter = 0;

void qsort(int start, int end, vector<int>(&numbers))
{
    calls_counter++;
    int divider = numbers[(end + start) / 2], l = start, r = end;

    while (l <= r)
    {
        while (numbers[l] < divider) l++;
        while (numbers[r] > divider) r--;

        if (l <= r) 
        {
            swap(numbers[l++], numbers[r--]);
        }
    }

    if (start < r) qsort(start, r, numbers);

    if (l < end) qsort(l, end, numbers);
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
    // cout << endl << endl;
    clock_t start = clock();

    qsort(0, numbers.size() - 1, numbers);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    cout << endl << "Sorted." << endl;
    cout << "Calls: " << calls_counter << endl;
    cout << "Time: " << seconds << endl;

    return 0;
}
