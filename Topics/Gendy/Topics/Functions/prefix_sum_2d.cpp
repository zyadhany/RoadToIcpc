// to add 1 to a square from i,j to i+k, j+k
// if k == 2
arr[i][j] += 1;                 // 100-1
arr[i][j + k] -= 1;             // 0000
arr[i + k][j] -= 1;             // -1001
arr[i + k][j + k] += 1;         // 0000

// to get the prefix array
// sum left
for (int i = 0; i < n; ++i)
{
    for (int j = 1; j < m; ++j)
    {
        v2[i][j] += v2[i][j - 1];
    }
}
// sum up
for (int i = 1; i < n; ++i)
{
    for (int j = 0; j < m; ++j)
    {
        v2[i][j] += v2[i - 1][j];
    }
}
// after
/*
    1100
    1100
    0000
    0000
*/