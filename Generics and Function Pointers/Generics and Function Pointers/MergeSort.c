#include "MergeSort.h"
void merge(void* arr[] ,size_t size , int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    char left[n1];
    char right[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
{
    if ((*compar)(&base, &base+((nitems-1) * size))==-1)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = 0 + (nitems - 1) / 2;

        // Sort first and second halves 
        mergeSort(base,m,size,*(compar));
        mergeSort(&base + ((m + 1) * size),nitems,size,*(compar));

        merge(base,size,0,m,nitems);
    }
