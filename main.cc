#include <iostream>
#include <string>

#include "absl/strings/substitute.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
#include "gflags/gflags.h"
#include "substr_search.h"
#include "substr_search_factory.h"

DEFINE_string(algo, "brute_force",
              "The algorithm to use. See SubstrSearchFactory::Create for "
              "details.");
DEFINE_string(pattern, "", "The pattern we're looking for in the text.");
DEFINE_string(text, "", "The text we're searching.");

using std::cin;
using std::cout;

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if (FLAGS_pattern.empty()) {
    cout << "Pattern: ";
    cin >> FLAGS_pattern;
  }

  if (FLAGS_text.empty()) {
    cout << "Text: ";
    cin >> FLAGS_text;
  }

  auto search =
      SubstrSearchFactory::Create(FLAGS_algo, FLAGS_pattern, FLAGS_text);
  cout << absl::Substitute("Text = <$0>\n", FLAGS_text);
  cout << absl::Substitute("Pattern = <$0>\n", FLAGS_pattern);
  auto start = absl::Now();
  int res = search->Search();
  auto end = absl::Now();
  cout << absl::Substitute("$0 : $1\nFinished in $2\n", FLAGS_algo, res,
                           absl::FormatDuration(end - start));
  return 0;
}
