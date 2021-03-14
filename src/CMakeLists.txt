add_executable(
  test
  test.cc
)

add_executable(
  vector_benchmark
  vector_benchmark.cc
)
target_link_libraries(
  vector_benchmark
  benchmark::benchmark
)
