cc_binary(
  name = "main",
  srcs = ["main.cc"],
  deps = [
    ":substr_search",
    ":brute_force",
    ":boyer_moore",
    ":rabin_karp",
    ":kmp",
    ":z"
  ],
)

cc_library(
  name = "substr_search",
  hdrs = ["substr_search.h"],
)

cc_library(
  name = "brute_force",
  hdrs = [
    "brute_force.h",
    "substr_search.h"
  ],
  srcs = ["brute_force.cc"],
)

cc_library(
  name = "kmp",
  hdrs = [
    "kmp.h",
    "substr_search.h"  
  ],
  srcs = ["kmp.cc"],
)

cc_library(
  name = "rabin_karp",
  hdrs = [
    "rabin_karp.h",
    "substr_search.h"  
  ],
  srcs = ["rabin_karp.cc"],
)

cc_library(
  name = "boyer_moore",
  hdrs = [
    "boyer_moore.h",
    "substr_search.h"
  ],
  srcs = ["boyer_moore.cc"],
)

cc_library(
  name = "z",
  hdrs = [
    "z.h",
    "substr_search.h"
  ],
  srcs = ["z.cc"],
)
