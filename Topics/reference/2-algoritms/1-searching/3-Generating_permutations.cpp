// To get all permution of given set

// recursive method
void search() {
    if (permutation.size() == n) {
        // process permutation
    } else {
    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

// itrarive method
vector<int> permutation;
for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}
do {
    // process permutation
} while (next_permutation(permutation.begin(),permutation.end()));
