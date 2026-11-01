#include <iostream>
#include <vector>

std::vector<int> MergeSort(std::vector<int>& arr, int n) {
  if (n <= 2) {
    return arr;
  }
  int right_n = (n / 4) * 2;
  int left_n = n - right_n;
  std::vector<int> right_arr(right_n);
  std::vector<int> left_arr(left_n);
  for (int i = 0; i < right_n; i++) {
    right_arr[i] = arr[i];
  }
  for (int i = 0; i < left_n; i++) {
    left_arr[i] = arr[i + right_n];
  }
  right_arr = MergeSort(right_arr, right_n);
  left_arr = MergeSort(left_arr, left_n);
  int right_i = 0;
  int left_i = 0;
  int i = 0;
  while (right_i < right_n && left_i < left_n && right_arr[right_i] != 0 &&
         left_arr[left_i] != 0) {
    if (right_arr[right_i + 1] < left_arr[left_i]) {
      arr[i] = right_arr[right_i];
      arr[i + 1] = right_arr[right_i + 1];
      i += 2;
      right_i += 2;
      continue;
    }
    if (right_arr[right_i] > left_arr[left_i + 1]) {
      arr[i] = left_arr[left_i];
      arr[i + 1] = left_arr[left_i + 1];
      i += 2;
      left_i += 2;
      continue;
    }
    if (right_arr[right_i] <= left_arr[left_i]) {
      arr[i] = right_arr[right_i];
      if (right_arr[right_i + 1] <= left_arr[left_i + 1]) {
        left_arr[left_i] = right_arr[right_i];
        right_i += 2;
      } else {
        left_i += 2;
      }
    } else {
      if (right_arr[right_i + 1] <= left_arr[left_i + 1]) {
        right_i += 2;
      } else {
        right_arr[right_i] = left_arr[left_i];
        left_i += 2;
      }
    }
  }
  while (right_i < right_n && right_arr[right_i] != 0) {
    arr[i] = right_arr[right_i];
    i++;
    right_i++;
  }
  while (left_i < left_n && left_arr[left_i] != 0) {
    arr[i] = left_arr[left_i];
    i++;
    left_i++;
  }
  if (n > i) {
    arr[i] = 0;
  }
  return arr;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n * 2);
  int inp;
  for (int i = 0; i < n * 2; i++) {
    std::cin >> inp;
    arr[i] = inp;
  }
  std::vector<int> sorted_array = MergeSort(arr, n * 2);
  int new_n = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i * 2] != 0) {
      new_n++;
    } else {
      break;
    }
  }
  std::cout << new_n;
  int i = 0;
  while (i < n * 2 && arr[i] != 0) {
    if ((i / 2) * 2 == i) {
      std::cout << '\n';
    } else {
      std::cout << ' ';
    }
    std::cout << arr[i];
    i++;
  }
}