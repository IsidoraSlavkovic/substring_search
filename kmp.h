#ifndef KMP_H
#define KMP_H

#include <string>

#include "substr_search.h"

using std::string;

class Kmp : public SubstrSearch {
 public:
  Kmp(const string &pattern, const string &text)
      : SubstrSearch(pattern, text) {}
  int Search();
};

#endif  // KMP_H