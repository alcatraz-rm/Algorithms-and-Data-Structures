#include <iostream>
#include <vector>
#include <algorithm>
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
    heap.erase(heap.begin());
    return make_heap(heap);
}

int main()
{
    int i, j, index, len;
    cin >> len;

    vector<int> numbers(len);
    vector<int> sorted(len);

    for (i = 0; i < len; i++)
    {
        numbers[i] = rand() % 1000;
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    numbers = make_heap(numbers);

    for (i = 0; i < len; i++)
    {
        sorted[len - i - 1] = numbers[0];
        numbers = remove_top_item(numbers);
    }

    for (j = 0; j < sorted.size(); j++)
    {
        cout << sorted[j] << " ";
    }
    cout<<endl;

    return 0;
}
