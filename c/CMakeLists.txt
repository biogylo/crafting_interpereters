cmake_minimum_required(VERSION 3.10)

project(
  ci
  C
)
add_compile_options(-std=c17)

add_executable(main 
    src/dll.c
    src/main.c
)
include_directories(src/)

# Add libraries
# add_library(cunit cunit.c cunit.h)

# Link libraries
#   target_link_libraries(cunit)