// count inversion can be done using ordered multiset
// insert and count how many elements are greater than current element


// count inversion can be done using merge sort
int countInversions(vector<int> &v,int l,int r){
    if(l >= r) return 0;
    int mid = (l+r)/2;
    int res = countInversions(v,l,mid) + countInversions(v,mid+1,r);
    vi x(r-l+1);
    int i = l , j = mid+1 , k = 0;
    while(i <= mid && j <= r){
        if(v[i] <= v[j]){
            res+=(j-mid-1);
            x[k++] = v[i++];
        }
        else x[k++] = v[j++];
    }
    while(i <= mid){
        res+=(j-mid-1);
        x[k++] = v[i++];
    }
    while(j <= r){
        x[k++] = v[j++];
    }
    for(int i = l ; i <= r ; i++) v[i] = x[i-l];
    return res;
}
