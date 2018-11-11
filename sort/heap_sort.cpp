#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

vector<int> make_heap(vector<int> arr)
{
    int i, index, parent, size = arr.size();

    for (i = 0; i < size; i++)
    {
        index = i;

        while (index != 0)
        {
            parent = (index - 1) / 2;

            if (0 <= parent <= size && arr[index] <= arr[parent])
            {
                break;
            }
            else
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
        }
    }

    return arr;
}

vector<int> remove_top_item(vector<int> heap)
{
    heap[0] = *(heap.end() - 1);
    heap.pop_back();

    int index, child_1, child_2, size = heap.size(), swap_child, j;
    index = 0;

    while (true)
    {
        if (index >= size)
        {
            break;
        }

        child_1 = index * 2 + 1;
        child_2 = child_1 + 1;

        if (child_1 >= size)
        {
            child_1 = index;
        }

        if (child_2 >= size)
        {
            child_2 = index;
        }

        if (heap[index] >= heap[child_1] && heap[index] >= heap[child_2])
        {
            break;
        }

        if (heap[child_1] > heap[child_2])
        {
            swap_child = child_1;
        }
        else
        {
            swap_child = child_2;
        }

        swap(heap[index], heap[swap_child]);
        index = swap_child;
    }

    return heap;
}

vector<int> sort(vector<int> numbers)
{
    int i, j, size = numbers.size();
    vector<int> sorted(size);

    numbers = make_heap(numbers);

    for (i = 0; i < size; i++)
    {
        sorted[size - i - 1] = numbers[0];

        numbers = remove_top_item(numbers);
    }

    return sorted;
}

int main()
{
    srand(time(0));
    int i, j, index, len;
    cin >> len;

    vector<int> numbers(len);

    for (i = 0; i < len; i++)
    {
        numbers[i] = rand() % 1000;
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    numbers = sort(numbers);

    for (j = 0; j < numbers.size(); j++)
    {
        cout << numbers[j] << " ";
    }
    cout<<endl;

    return 0;
}
