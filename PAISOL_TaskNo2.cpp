#include <iostream>
using namespace std;

void search(int *nums2, int n, int s, int e, int &unSortedElement, bool &isFound)
{
    if (s >= e)
    {
        if (unSortedElement > nums2[s] && !isFound)
        {
            swap(unSortedElement, nums2[s]);
            isFound = true;
        }
        if (isFound)
        {
            for (int i = s; i < n - 1; i++)
            {
                if (nums2[i] > nums2[i + 1])
                    swap(nums2[i], nums2[i + 1]);
            }
        }
        return;
    }
    int mid = s + (e - s) / 2;
    search(nums2, n, s, mid, unSortedElement, isFound);
    search(nums2, n, mid + 1, e, unSortedElement, isFound);
}

void merge(int *nums1, int m, int *nums2, int n)
{
    if (n == 0)
        return;

    int i;
    bool isFound;

    for (i = 0; i < m; i++)
    {
        isFound = false;
        search(nums2, n, 0, n - 1, nums1[i], isFound);
    }
    for (int j = 0; j < n; j++)
        nums1[i++] = nums2[j];
}

int main() {
    int nums1[] = {1, 5, 6, 0, 0, 0};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {1, 2, 7};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    merge(nums1, m - n, nums2, n);

    for (int i = 0; i < m; i++)
        cout << nums1[i] << " ";
}
