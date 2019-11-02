#include <iostream>
#include <string>

#include "substr_search.h"
#include "substr_search_factory.h"

using namespace std;

int main() {
  string p, t;

  cout << "Text: ";
  cin >> t;
  cout << "Pattern: ";
  cin >> p;

  {
    auto search = SubstrSearchFactory::Create("brute_force", p, t);
    cout << "Brute Force: " << search->Search() << endl;
  }

  {
    auto search = SubstrSearchFactory::Create("kmp", p, t);
    cout << "KMP: " << search->Search() << endl;
  }

  {
    auto search = SubstrSearchFactory::Create("boyer_moore", p, t);
    cout << "Boyer Moore: " << search->Search() << endl;
  }

  {
    auto search = SubstrSearchFactory::Create("rabin_karp", p, t);
    cout << "Rabin Karp: " << search->Search() << endl;
  }

  {
    auto search = SubstrSearchFactory::Create("z", p, t);
    cout << "Z: " << search->Search() << endl;
  }

  return 0;
}
