#include "substr_search_factory.h"

#include <memory>

#include "boyer_moore.h"
#include "brute_force.h"
#include "kmp.h"
#include "rabin_karp.h"
#include "substr_search.h"
#include "z.h"

std::unique_ptr<SubstrSearch> SubstrSearchFactory::Create(
    const std::string& type, const std::string& pattern,
    const std::string& text) {
  if (type == "brute_force") {
    return std::make_unique<BruteForce>(pattern, text);
  } else if (type == "boyer_moore") {
    return std::make_unique<BoyerMoore>(pattern, text);
  } else if (type == "rabin_karp") {
    return std::make_unique<RabinKarp>(pattern, text);
  } else if (type == "kmp") {
    return std::make_unique<Kmp>(pattern, text);
  } else if (type == "z") {
    return std::make_unique<Z>(pattern, text);
  } else {
    return nullptr;
  }
}
