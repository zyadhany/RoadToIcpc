// To get all possibilities
// fron n elements we have 2^n subset.

// recursive call to get all elements
void search(int k) {
    if (k == n) {
        // process subset
        } else {
            search(k+1);
            subset.push_back(k);
            search(k+1);
            subset.pop_back();
    }
}

// itrative with bit number
for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
        if (b&(1<<i)) subset.push_back(i);
    }
}
