#include "boyer_moore.h"

#include <vector>

#include "substr_search.h"

int BoyerMoore::Search() {
  int n = text_.length();
  int m = pattern_.length();
  int r = 256;
  std::vector<int> right(r, -1);

  for (int j = 0; j < m; j++) {
    right[pattern_[j]] = j;
  }

  int skip = 0;
  for (int i = 0; i <= n - m; i += skip) {
    skip = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (pattern_[j] != text_[i + j]) {
        skip = j - right[text_[i + j]];
        if (skip < 1) {
          skip = 1;
        }
        break;
      }
      if (skip == 0) {
        return i;
      }
    }
  }

  return n;
}