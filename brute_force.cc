#include "brute_force.h"

int BruteForce::Search() {
  int n = text_.length();
  int m = pattern_.length();
  for (int i = 0; i <= n - m; i++) {
    int j = 0;
    for (; j < m; j++) {
      if (text_[j + i] != pattern_[j]) {
        break;
      }
    }
    if (j == m) {
      return i;
    }
  }
  return -1;
}
