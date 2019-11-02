#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <string>

#include "substr_search.h"

using std::string;

class BruteForce : public SubstrSearch {
 public:
  BruteForce(const string &pattern, const string &text)
      : SubstrSearch(pattern, text) {}
  int Search();
};

#endif  // BRUTEFORCE_H
