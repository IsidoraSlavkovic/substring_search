#include "rabin_karp.h"

int RabinKarp::Search() {
  int n = text_.length();
  int m = pattern_.length();
  long pat_hash = 0;
  long txt_hash = 0;
  long q = 997;
  int r = 256;
  long rm = 1;

  for (int i = 0; i < m; i++) {
    pat_hash = (r * pat_hash + pattern_[i]) % q;
    txt_hash = (r * txt_hash + text_[i]) % q;
  }

  for (int i = 1; i <= m - 1; i++) {
    rm = (r * rm) % q;
  }

  for (int i = 0; i <= n - m; i++) {
    if (pat_hash == txt_hash) {
      int j = 0;
      for (; j < m; j++) {
        if (text_[i + j] != pattern_[j]) break;
      }
      if (j == m) {
        return i;
      }
    }
    if (i < n - m) {
      txt_hash = (r * (txt_hash - text_[i] * rm) + text_[i + m]) % q;
      if (txt_hash < 0) {
        txt_hash = txt_hash + q;
      }
    }
  }
  return n;
}