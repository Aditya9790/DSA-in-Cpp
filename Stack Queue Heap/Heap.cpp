/*
Complete binary tree a tree in which all nodes are filled from left.

In a max heap each left child will be located at 2*i th index.
And right child will be located at 2*i + 1 th index
And parent will be ocated at i/2 th index.

1. To insert a element in a heap initially insert element at last
2. Now compare ehether the element if greater than parent(i.e. compare ith ans i/2 th index) if greater swap them

3. Continue this process until we reach at 0th index.

In a Complete binary tree leaf nodes lie from n/2 th index to n th index.
*/
#include <iostream>
#include <algorithm>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1; // just some random value
        size = 0;
    }

    // void heapify(int arr[], int index)
    // {
    //     int parent = index/2;
    //     if(index<0) return;
    //     if(arr[index] > arr[parent])
    //         swap(arr[parent], arr[index]);
    //     heapify(arr, parent);

    // }

    // time complexity is O(logn)
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val; // insert val at end

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index]) // if element to be inserted is greater than parent swap them
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
        // heapify(arr, index);
    }

    /*
    Deletion a node i.e  a root node:
    1. Swap the roor node and the last node
    2. Delete the last node
    3. Now place the newly place root node to it's correct position
    4. Swap the root with max of it's children. To maintain heap property.
    5. repeat this until heap property satisfied.
    */

    // Time complexity O(logn)
    void deleteNode()
    {
        if (size == 0)
        {
            cout << "Nothing to delete";
            return;
        }
        arr[1] = arr[size - 1]; // put last node at root node and delete this newly placed last node
        size--;                 // decrease the size

        // place the new root to it's correct position
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;      // left child
            int right = 2 * i + 1; // righr child

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                return;
        }
    }

    /*
        In a Complete binary tree leaf nodes lies from n/2 th index to n th index.
        So all the nodes from (n/2) to n th inde are always in their correct position so we process only 1 to n/2 th index.

        Heapify places the element on which it is called to a correct position in it's correct position
    */

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // if element at i is smaller than it's left child update largest to left
    // else update to right
    if (left <= n && arr[largest] < arr[left])
        largest = left;

    if (right <= n && arr[largest] < arr[right])
        largest = right;

    // check if largest updated or not
    // if it is updated then i will not be equal to largest
    if (i != largest)
    {
        swap(arr[largest], arr[i]);
        // now call the function recursively
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]); // swap ist and last element and decrease the size
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(52);
    h.print();
    cout << endl;
    h.deleteNode();
    h.print();

    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = 9;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "array after heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    // cout<<"\n Sorted array:"<<endl;
    // heapsort(arr, 5);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}