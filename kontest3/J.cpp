#include <iostream>
#include <string>
#include <vector>

struct Couple {
  long long l1;
  int l2;
};

std::vector<Couple> heap;
std::vector<Couple> ids;

void Swap(int i, int j) {
  std::swap(heap[i], heap[j]);
  ids[heap[i].l2].l2 = i;
  ids[heap[j].l2].l2 = j;
}

bool LessPos(int i, int j) {
  return heap[i].l1 < heap[j].l1 ||
         (heap[i].l1 == heap[j].l1 && heap[i].l2 < heap[j].l2);
}

void SiftUp(int i) {
  while (i > 0 && LessPos(i, (i - 1) / 2)) {
    Swap(i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

void SiftDown(int i) {
  int n = (int)heap.size();
  while (true) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int best = i;
    if (l < n && LessPos(l, best)) {
      best = l;
    }
    if (r < n && LessPos(r, best)) {
      best = r;
    }
    if (best == i) {
      break;
    }
    Swap(i, best);
    i = best;
  }
}

void Insert(long long val, int id) {
  Couple it;
  it.l1 = val;
  it.l2 = id;
  heap.push_back(it);
  int ind = (int)heap.size() - 1;
  ids[id].l2 = ind;
  SiftUp(ind);
}

void ExtractMin() {
  int last = (int)heap.size() - 1;
  Swap(0, last);
  ids[heap[last].l2].l2 = -1;
  heap.pop_back();
  if (!heap.empty()) {
    SiftDown(0);
  }
}

void DecreaseKey(int id, long long d) {
  int i = ids[id].l2;
  heap[i].l1 -= d;
  SiftUp(i);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int q;
  std::cin >> q;

  ids.resize(q + 1);
  heap.reserve(q + 1);

  for (int i = 1; i <= q; i++) {
    std::string op;
    std::cin >> op;

    if (op == "insert") {
      long long x;
      std::cin >> x;
      Insert(x, i);
    } else if (op == "getMin") {
      std::cout << heap[0].l1 << '\n';
    } else if (op == "extractMin") {
      ExtractMin();
    } else if (op == "decreaseKey") {
      int id;
      long long d;
      std::cin >> id >> d;
      DecreaseKey(id, d);
    }
  }

  return 0;
}