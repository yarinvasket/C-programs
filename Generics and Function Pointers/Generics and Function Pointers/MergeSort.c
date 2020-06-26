#include "MergeSort.h"
void mergeSort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
{
    if ((*compar)(l, r)==-1)
    {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - size) / 2;

        // Sort first and second halves 
        mergeSort(base,nitems,size, l, m);
        mergeSort(base+((m+1)*size),nitems,size, m + 1, r);

        mergeSort(base,nitems,size, l, m, r);
    }
