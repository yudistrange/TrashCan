/**
 * This program will implement Quicksort algorithm where in the pivot will be the last element of the array
 *
 * SELF NOTE:
 * After each iteration of quicksort the pivot is inserted at its right position and also the other elements
 * are sorted in a way that the left side of the pivot are smaller and right side of pivot are bigger than it.
 */

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void Swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return;
}

int Partition(int array[], int start, int end)
{
    int pivot = array[end-1];
    int j=start-1, i;
    
    for(i=start; i<end; i++) {
        if(array[i] < pivot) {
            j++;
            Swap(array, i, j);
        }
    }
    Swap(array, j+1, end-1);
    return j+1;
}

void QuickSort(int array[], int start, int end)
{
    if(start>=end)
        return;

    int q = Partition(array, start, end);
    QuickSort(array, start, q-1);
    QuickSort(array, q+1, end);
}

void trialQS(int array[], int start, int end)
{
    if(start>=end)
        return;

    int pivot = array[end-1];
    int j = start;
    for(int i=start; i<end; i++) {
        if(array[i] < pivot) {
            Swap(array, i, j);
            j++;
        }
    }
    Swap(array, j, end-1);
    trialQS(array, start, j);
    trialQS(array, j+1, end);
}

int main()
{
    int n, * arr;
    cin>>n;
    arr = new int[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
//    QuickSort(arr, 0, n);
    trialQS(arr, 0, n);
    cout<<"\n\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
    return 0;
}
