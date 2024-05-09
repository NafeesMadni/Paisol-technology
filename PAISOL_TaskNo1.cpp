#include <iostream>
#include <climits>
using namespace std;

int partition(int *arr, int s, int e)
{
     int pivot = arr[e];
     int i = s;
     for (int j = s; j <= e; j++)
     {
          if (arr[j] <= pivot)
          {
               swap(arr[i], arr[j]);
               i++;
          }
     }

     return --i;
}

int quickSelect(int *arr, int s, int e, int k)
{
     int pivotIndex = partition(arr, s, e);

     if (pivotIndex + 1 == k)
          return arr[pivotIndex];
     if (pivotIndex + 1 > k)
          return quickSelect(arr, s, pivotIndex - 1, k);
     else
          return quickSelect(arr, pivotIndex + 1, e, k);
}

int main()
{
     int arr[] = {6, 3, 1, 6, 0, 4, 8};
     int size = 7;
     cout << quickSelect(arr, 0, size - 1, 3) << endl;
}
