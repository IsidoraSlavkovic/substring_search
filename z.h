#ifndef Z_H
#define Z_H

#include <string>
#include <vector>

#include "substr_search.h"

using std::string;
using std::vector;

class Z : public SubstrSearch {
 public:
  Z(const string &pattern, const string &text) : SubstrSearch(pattern, text) {}
  int Search();

 private:
  static vector<int> get_zarr(const string &str);
};

#endif  // Z_H