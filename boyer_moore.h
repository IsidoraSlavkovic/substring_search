#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <string>

#include "substr_search.h"

using std::string;

class BoyerMoore : public SubstrSearch {
 public:
  BoyerMoore(const string &pattern, const string &text)
      : SubstrSearch(pattern, text) {}
  int Search();
};

#endif  // BOYER_MOORE_H