#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <string>

#include "substr_search.h"

using std::string;

class RabinKarp : public SubstrSearch {
 public:
  RabinKarp(const string &pattern, const string &text)
      : SubstrSearch(pattern, text) {}
  int Search();
};

#endif  // RABIN_KARP_H