#include <memory>
#include <string>

#include "substr_search.h"

class SubstrSearchFactory {
 public:
  SubstrSearchFactory() = delete;
  // Suported types:
  //  - brute_force
  //  - boyer_moore
  //  - rabin_karp
  //  - kmp
  //  - z
  static std::unique_ptr<SubstrSearch> Create(const std::string& type,
                                              const std::string& pattern,
                                              const std::string& text);
};