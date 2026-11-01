#include <iostream>
#include <vector>

struct Couple {
  int l1;
  int l2;
};

std::vector<Couple> min_heap;
std::vector<Couple> max_heap;

void SwapMin(int i, int j) {
  std::swap(min_heap[i], min_heap[j]);
  max_heap[min_heap[i].l2].l2 = i;
  max_heap[min_heap[j].l2].l2 = j;
}

void SwapMax(int i, int j) {
  std::swap(max_heap[i], max_heap[j]);
  min_heap[max_heap[i].l2].l2 = i;
  min_heap[max_heap[j].l2].l2 = j;
}

void SiftUpMin(int i) {
  while (i > 0 && min_heap[i].l1 < min_heap[(i - 1) / 2].l1) {
    SwapMin(i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

void SiftDownMin(int i) {
  int n = min_heap.size();
  while (true) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int best = i;
    if (l < n && min_heap[l].l1 < min_heap[best].l1) {
      best = l;
    }
    if (r < n && min_heap[r].l1 < min_heap[best].l1) {
      best = r;
    }
    if (best == i) {
      break;
    }
    SwapMin(i, best);
    i = best;
  }
}

void SiftUpMax(int i) {
  while (i > 0 && max_heap[i].l1 > max_heap[(i - 1) / 2].l1) {
    SwapMax(i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

void SiftDownMax(int i) {
  int n = max_heap.size();
  while (true) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int best = i;
    if (l < n && max_heap[l].l1 > max_heap[best].l1) {
      best = l;
    }
    if (r < n && max_heap[r].l1 > max_heap[best].l1) {
      best = r;
    }
    if (best == i) {
      break;
    }
    SwapMax(i, best);
    i = best;
  }
}

void Insert(int x) {
  int mi = min_heap.size();
  int ma = max_heap.size();
  Couple c1;
  c1.l1 = x;
  c1.l2 = ma;
  Couple c2;
  c2.l1 = x;
  c2.l2 = mi;
  min_heap.push_back(c1);
  max_heap.push_back(c2);
  SiftUpMin(mi);
  SiftUpMax(ma);
}

int ExtractMin() {
  int val = min_heap[0].l1;
  int ma_idx = min_heap[0].l2;
  int last_ma = max_heap.size() - 1;
  if (ma_idx != last_ma) {
    max_heap[ma_idx] = max_heap[last_ma];
    min_heap[max_heap[ma_idx].l2].l2 = ma_idx;
  }
  max_heap.pop_back();
  if (ma_idx < (int)max_heap.size()) {
    SiftDownMax(ma_idx);
    SiftUpMax(ma_idx);
  }
  int last_mi = min_heap.size() - 1;
  if (last_mi != 0) {
    min_heap[0] = min_heap[last_mi];
    max_heap[min_heap[0].l2].l2 = 0;
  }
  min_heap.pop_back();
  if ((int)min_heap.size() > 0) {
    SiftDownMin(0);
  }
  return val;
}

int ExtractMax() {
  int val = max_heap[0].l1;
  int mi_idx = max_heap[0].l2;
  int last_mi = min_heap.size() - 1;
  if (mi_idx != last_mi) {
    min_heap[mi_idx] = min_heap[last_mi];
    max_heap[min_heap[mi_idx].l2].l2 = mi_idx;
  }
  min_heap.pop_back();
  if (mi_idx < (int)min_heap.size()) {
    SiftDownMin(mi_idx);
    SiftUpMin(mi_idx);
  }
  int last_ma = max_heap.size() - 1;
  if (last_ma != 0) {
    max_heap[0] = max_heap[last_ma];
    min_heap[max_heap[0].l2].l2 = 0;
  }
  max_heap.pop_back();
  if ((int)max_heap.size() > 0) {
    SiftDownMax(0);
  }
  return val;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int q;
  std::cin >> q;

  for (int i = 0; i < q; i++) {
    int op;
    std::cin >> op;

    if (op == 0) {
      int x;
      std::cin >> x;
      Insert(x);
      std::cout << "ok\n";
    } else if (op == 1) {
      if (min_heap.empty()) {
        std::cout << "error\n";
      } else {
        std::cout << ExtractMin() << '\n';
      }
    } else if (op == 2) {
      if (min_heap.empty()) {
        std::cout << "error\n";
      } else {
        std::cout << min_heap[0].l1 << '\n';
      }
    } else if (op == 3) {
      if (max_heap.empty()) {
        std::cout << "error\n";
      } else {
        std::cout << ExtractMax() << '\n';
      }
    } else if (op == 4) {
      if (max_heap.empty()) {
        std::cout << "error\n";
      } else {
        std::cout << max_heap[0].l1 << '\n';
      }
    } else if (op == 5) {
      std::cout << min_heap.size() << '\n';
    } else if (op == 6) {
      min_heap.clear();
      max_heap.clear();
      std::cout << "ok\n";
    }
  }
}