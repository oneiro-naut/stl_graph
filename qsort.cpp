#include <bits/stdc++.h>
using namespace std;


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void print_arr(vector<int>& A)
{
    for(auto i : A)
        cout << i << " ";
    cout << "\n";
}

//finds position of pivot and partitions the array around it
int partition(vector<int>& A, int low, int high)
{
    //here I have taken highest index to be the pivot element
    //we can take randomly generated pivot for best results
    //or we can take the mid element as the pivot
    //int p = (high + low)/ 2;
    //int pivot = A[p];
    int p = high; // the pivot index
    int pivot = A[p];
    int i = low;
    for(int j = low; j <= high; j++)
        if(A[j] < pivot){
            swap(&A[i], &A[j]);
            i++;
        }
    
    int temp = A[i];
    A[i] = pivot;
    A[p] = temp;
    
    //print_arr(A);
    
    return i;
}


//recursive implementation of quicksort
void qksort(vector<int>& A, int low, int high)
{
    int p;
    if(low < high)
    {
        p = partition(A, low, high);
        // divide n conquer
        qksort(A, low, p - 1);
        qksort(A, p + 1, high);
    }
}


void quicksort(vector<int>& A)
{
    qksort(A, 0, A.size() - 1);
}

int main(int argc, char** argv)
{
    vector<int> test_array{5, 11, 7, 8, 1, 3, -1, 10, 0};
    cout << "Input :\n";
    print_arr(test_array);
    cout << "Sorted Array(quicksort):\n";
    quicksort(test_array);
    print_arr(test_array);

    return 0;
}