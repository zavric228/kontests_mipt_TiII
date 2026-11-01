#include <deque>
#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::deque<int> left;
  std::deque<int> right;
  for (int i = 0; i < n; i++) {
    char b;
    std::cin >> b;
    if (b == '-') {
      std::cout << left.front() << '\n';
      left.pop_front();
    } else {
      int x;
      std::cin >> x;
      if (b == '+') {
        right.push_back(x);
      } else {
        right.push_front(x);
      }
    }
    if (left.size() < right.size()) {
      left.push_back(right.front());
      right.pop_front();
    }
  }
}