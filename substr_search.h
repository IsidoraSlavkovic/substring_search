#ifndef SUBSTR_SEARCH_H
#define SUBSTR_SEARCH_H

#include <string>

using std::string;

class SubstrSearch {
 public:
  SubstrSearch(const string &pattern, const string &text)
      : pattern_(pattern), text_(text) {}
  virtual ~SubstrSearch() {}

  string GetPattern() const { return pattern_; }
  string GetText() const { return text_; }
  virtual int Search() = 0;

 protected:
  string pattern_;
  string text_;
};

#endif  // SUBSTR_SEARCH_H
