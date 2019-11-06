#include "z.h"

using std::string;
using std::vector;

vector<int> Z::get_zarr(const string& str) {
  int n = str.length();
  vector<int> z(n);

  int l = 0;
  int r = 0;
  for (int i = 1; i < n; ++i) {
    if (i > r) {
      l = r = i;
      while (r < n && str[r - l] == str[r]) r++;
      z[i] = r - l;
      r--;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1) {
        z[i] = z[k];
      } else {
        l = i;
        while (r < n && str[r - l] == str[r]) r++;
        z[i] = r - l;
        r--;
      }
    }
  }
  return z;
}

int Z::Search() {
  if (pattern_.length() == 0) {
    return 0;
  }
  string concat = pattern_ + "$" + text_;
  int l = concat.length();

  auto z = get_zarr(concat);
  for (int i = 0; i < l; i++) {
    if (z[i] == pattern_.length()) {
      return i - pattern_.length() - 1;
    }
  }
  return -1;
}
