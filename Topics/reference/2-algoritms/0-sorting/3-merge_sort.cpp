// O(nLog(n))
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    inplace_merge(array + begin, array + mid + 1, array + end + 1);
}
