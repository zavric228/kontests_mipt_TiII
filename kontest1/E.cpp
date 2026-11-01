#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void BinarySearch(const std::vector<long long>& a,
                  const std::vector<long long>& c, long long x) {
  int left = 0;
  int right = static_cast<int>(c.size()) - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (c[mid] == x) {
      std::cout << mid + 1 << "\n";
      return;
    }
    if (c[mid] < x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  if (right < 0) {
    std::cout << 1 << "\n";
  } else if (left >= static_cast<int>(c.size())) {
    std::cout << static_cast<int>(c.size()) << "\n";
  } else {
    long long val_left = a[left] + std::max(x, c[left]);
    long long val_right = a[right] + std::max(x, c[right]);
    if (val_left < val_right) {
      std::cout << left + 1 << "\n";
    } else {
      std::cout << right + 1 << "\n";
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  std::vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = b[i] - a[i];
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    long long x;
    std::cin >> x;
    BinarySearch(a, c, x);
  }
  return 0;
}