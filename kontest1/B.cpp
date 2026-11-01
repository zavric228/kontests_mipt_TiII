#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

const int cPrecision = 7;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::vector<double> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<double> pref(n + 1);
  pref[0] = 0.0;
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + std::log(a[i]);
  }

  int q;
  std::cin >> q;
  std::cout << std::fixed << std::setprecision(cPrecision);

  for (int i = 0; i < q; ++i) {
    int l;
    int r;
    std::cin >> l >> r;
    int length = r - l + 1;
    double log_sum = pref[r + 1] - pref[l];
    double result = std::exp(log_sum / length);
    std::cout << result << "\n";
  }

  return 0;
}