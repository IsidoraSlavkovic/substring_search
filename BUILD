cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":substr_search_factory"],
)

cc_library(
    name = "substr_search",
    hdrs = ["substr_search.h"],
)

cc_library(
    name = "brute_force",
    srcs = ["brute_force.cc"],
    hdrs = [
        "brute_force.h",
    ],
    deps = [":substr_search"],
)

cc_library(
    name = "kmp",
    srcs = ["kmp.cc"],
    hdrs = [
        "kmp.h",
    ],
    deps = [":substr_search"],
)

cc_library(
    name = "rabin_karp",
    srcs = ["rabin_karp.cc"],
    hdrs = [
        "rabin_karp.h",
    ],
    deps = [":substr_search"],
)

cc_library(
    name = "boyer_moore",
    srcs = ["boyer_moore.cc"],
    hdrs = [
        "boyer_moore.h",
    ],
    deps = [":substr_search"],
)

cc_library(
    name = "z",
    srcs = ["z.cc"],
    hdrs = [
        "z.h",
    ],
    deps = [":substr_search"],
)

cc_library(
    name = "substr_search_factory",
    hdrs = ["substr_search_factory.h"],
    srcs = ["substr_search_factory.cc"],
    deps = [
        ":boyer_moore",
        ":brute_force",
        ":kmp",
        ":rabin_karp",
        ":substr_search",
        ":z",
    ],
)
