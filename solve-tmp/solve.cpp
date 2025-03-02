/*
#include <stdio.h>
#define ll long long
ll arr[100001], brr[100001], ind[100001];
void mergeSort(ll *arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) >> 1;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        ll aux[high - low + 1 ], auxind[high - low + 1], inv = 0;
        int j = 0, p1 = low, p2 = mid + 1, end1 = mid, end2 = high;

        while(p1 <= end1 || p2 <= end2)
        {
            if(p1 <= end1 && p2 <= end2)
            {
                if(arr[p1] + inv >= arr[p2])
                {
                    ++inv;
                    aux[j] = arr[p2];
                    auxind[j] = ind[p2++];
                }
                else
                {
                    aux[j] = arr[p1]+inv;
                    auxind[j] = ind[p1++];
                }
            }
            else if(p1 <= end1)
            {
                aux[j] = arr[p1] + inv;
                auxind[j] = ind[p1++];
            }
            else
            {
                aux[j] = arr[p2];
                auxind[j] = ind[p2++];
            }
            ++j;

        }
        memcpy(arr + low, aux, j * sizeof(ll));
        memcpy(ind + low, auxind, j * sizeof(ll));
    }
}
int main()
{
    int n;
    scanf("%i",&n);

    for(register int i=0;i<n;i++)
    {
        scanf("%lli", &arr[i]);

        // storing index of each element
        ind[i] = i;        
    }   

    mergeSort(arr,0,n-1);

    // rearranging elements after sorting in array brr
    for(register int i = 0; i < n; ++i)
        brr[ind[i]] = arr[i];

    for(register int i = 0; i < n; ++i)
        printf("%lli ",brr[i]);
    return 0;
}
*/

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vi vector<ll>

using namespace std;

const int N = 1e5 + 5;

int arr[N], brr[N], ind[N];

void merge_sort(int lw, int hi) {
    if (lw >= hi) return;

    int mid = (lw + hi) >> 1;
    merge_sort(lw, mid);
    merge_sort(mid + 1, hi);
    
    vi aux(hi - lw + 1), auxind(hi - lw + 1);
    int inv = 0, j = 0, p1 = lw, p2 = mid + 1, end1 = mid, end2 = hi;

    while (p1 <= end1 || p2 <= end2) {
        if (p1 <= end1 && p2 <= end2) {
            if (arr[p1] + inv >= arr[p2]) {
                ++inv;
                aux[j] = arr[p2];
                auxind[j] = ind[p2++];
            } else {
                aux[j] = arr[p1] + inv;
                auxind[j] = ind[p1++];
            }
        } else if (p1 <= end1) {
            aux[j] = arr[p1] + inv;
            auxind[j] = ind[p1++];
        } else {
            aux[j] = arr[p2];
            auxind[j] = ind[p2++];
        }
        ++j;
    }
    // memcpy(arr + lw, aux, j * sizeof(int));
    // memcpy(ind + lw, auxind, j * sizeof(int));
    for (int i = 0; i < j; i++) {
        arr[lw + i] = aux[i];
        ind[lw + i] = auxind[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ind[i] = i;
    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        brr[ind[i]] = arr[i];

    for (int i = 0; i < n; i++)
        cout << brr[i] << ' ';
}
