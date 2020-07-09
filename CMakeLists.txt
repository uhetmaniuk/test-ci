#
# CMakeLists.txt file
#

cmake_minimum_required(VERSION 3.12)
project(uhfem VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

option(USE_PURE_MPI "Whether to use Pure MPI (no Trilinos)" OFF)

# Optional dependency for pure MPI build (no Trilinos)
if (USE_PURE_MPI)
  set(HAVE_MPI TRUE)
  message(STATUS "Compiling with MPI")
  find_package(MPI REQUIRED)
  target_link_libraries(nimble PUBLIC MPI::MPI_CXX)
  target_compile_definitions(nimble PUBLIC NIMBLE_HAVE_MPI)
endif()

# Define executable and source files
ADD_EXECUTABLE(uhfem uh_code.cpp)
TARGET_LINK_LIBRARIES(uhfem nimble)
