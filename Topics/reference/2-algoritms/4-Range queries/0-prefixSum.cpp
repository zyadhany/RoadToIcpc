// prefix summ 1-d array,
// summ(a, b) = pref[b] - pref[a- 1]
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}


/**
 * 2-D Array
 * summ({a-b},{c,d})=pref[a][b]+pref[c-1][d-1]-pref[a][d-1]-pref[b-1][b]
 */
void prefixSum(int arr[3][3], int n) { 
    //vertical prefixsum 
    for (int j = 0; j < n; j++) { 
        for (int i = 1; i < n; i++) { 
            arr[i][j] += arr[i-1][j]; 
        } 
    } 
    //horizontal prefixsum 
    for (int i = 0; i < n; i++) { 
        for (int j = 1; j < n; j++) { 
            arr[i][j] += arr[i][j-1]; 
        } 
    } 
} 