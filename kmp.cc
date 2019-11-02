#include "kmp.h"

#include <vector>

int Kmp::Search() {
  int m = pattern_.length();
  int r = 256;
  std::vector<std::vector<int>> dfa(r, std::vector<int>(m));
  dfa[pattern_[0]][0] = 1;

  for (int x = 0, j = 1; j < m; j++) {
    for (int c = 0; c < r; c++) {
      dfa[c][j] = dfa[c][x];
    }
    dfa[pattern_[j]][j] = j + 1;
    x = dfa[pattern_[j]][x];
  }

  int n = text_.length();
  int i = 0, j = 0;
  for (; i < n && j < m; i++) {
    j = dfa[text_[i]][j];
  }

  return j == m ? i - m : n;
}