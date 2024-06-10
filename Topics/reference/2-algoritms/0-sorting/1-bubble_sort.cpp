// O(n^2)
for (int i = 0; i < n; i++)
    for (int j = 0; j < n-1; j++)
        if (array[j] > array[j+1])
            swap(array[j],array[j+1]);
