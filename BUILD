load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary", "cc_test")

cc_library(
    name = "ngb-library",
    hdrs = glob(["include/*.h"]),
    copts = ["-Iinclude"],
    srcs = glob(["src/*.cpp"]),
)

cc_test(
  name = "ngb-tests",
  size = "small",
  srcs = ["tests/food.cc"],
  copts = [
    "-Iinclude",
  ],
  data = [
    "//:ngb.config"
  ],
  deps = [
    "@com_google_googletest//:gtest_main",
    "//:ngb-library"
  ]
)

exports_files(["ngb.config"])