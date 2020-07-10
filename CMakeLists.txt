#
# CMakeLists.txt file
#

cmake_minimum_required(VERSION 3.12)
project(uhfem VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

option(USE_PURE_MPI "Whether to use Pure MPI (no Trilinos)" OFF)

find_package(Kokkos REQUIRED)

# Optional dependency for pure MPI build (no Trilinos)
if (USE_PURE_MPI)
  set(HAVE_MPI TRUE)
  message(STATUS "Compiling with MPI")
  find_package(MPI REQUIRED)
  ADD_EXECUTABLE(uhfem uh_code.cpp)
  target_compile_definitions(uhfem PUBLIC HAVE_MPI)
  target_link_libraries(uhfem PUBLIC MPI::MPI_CXX)
else()
  ADD_EXECUTABLE(uhfem uh_code.cpp)
endif()


