load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

cc_library(
    name = "ngb-library",
    hdrs = glob(["include/*.h"]),
    srcs = glob(["src/*.cpp"]),
)

cc_test(
  name = "ngb-tests",
  size = "small",
  srcs = ["tests/food.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//:ngb-library"
    ]
)