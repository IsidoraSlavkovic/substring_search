#include <iostream>
#include <string>

#include "boyer_moore.h"
#include "brute_force.h"
#include "kmp.h"
#include "rabin_karp.h"
#include "substr_search.h"
#include "z.h"

using namespace std;

int main() {
  string p, t;

  cout << "Text: ";
  cin >> t;
  cout << "Pattern: ";
  cin >> p;

  BruteForce s1(p, t);
  cout << "Brute Force: " << s1.Search() << endl;

  Kmp s2(p, t);
  cout << "KMP: " << s2.Search() << endl;

  BoyerMoore s3(p, t);
  cout << "Boyer Moore: " << s3.Search() << endl;

  RabinKarp s4(p, t);
  cout << "Rabin Karp: " << s4.Search() << endl;

  Z s5(p, t);
  cout << "Z algorithm: " << s5.Search() << endl;

  return 0;
}
