template <typename T>
vector<T> get_window_maxs_1d(const vector<T>& a, int k) {
  const int n = a.size();
  vector<T> b(n - k + 1);
  deque<int> mono;
  for (int i = 0; i < n; ++i) {
    while (!mono.empty() && a[mono.back()] <= a[i]) {
      mono.pop_back();
    }
    mono.push_back(i);
    if (mono.front() <= i - k) {
      mono.pop_front();
    }
    if (i + 1 >= k) {
      b[i + 1 - k] = a[mono.front()];
    }
  }
  return b;
}

template <typename T>
vector<vector<T>> get_window_maxs_2d(const vector<vector<T>>& a, int k, int l) {
  const int n = a.size(), m = a[0].size();
  vector<vector<T>> b(m - l + 1, vector<T>(n));
  for (int i = 0; i < n; ++i) {
    const auto tmp = get_window_maxs_1d(a[i], l);
    for (int j = 0; j < m - l + 1; ++j) {
      b[j][i] = tmp[j];
    }
  }
  vector<vector<T>> c(n - k + 1, vector<T>(m - l + 1));
  for (int j = 0; j < m - l + 1; ++j) {
    const auto tmp = get_window_maxs_1d(b[j], k);
    for (int i = 0; i < n - k + 1; ++i) {
      c[i][j] = tmp[i];
    }
  }
  return c;
}
