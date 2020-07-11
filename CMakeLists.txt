#
# CMakeLists.txt file
#

cmake_minimum_required(VERSION 3.12)
project(uhfem VERSION 0.1.0 LANGUAGES CXX)

enable_testing()

option(USE_PURE_MPI "Whether to use Pure MPI (no Trilinos)" OFF)

#LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
message(STATUS "${CMAKE_MODULE_PATH}")

#find_package(Exodus REQUIRED)

if(KOKKOS_ROOT_DIR)
  message("-- Compiling with Kokkos")
  add_subdirectory(${KOKKOS_ROOT_DIR} ./kokkos)
  include_directories(${Kokkos_INCLUDE_DIRS_RET})
  set(NIMBLE_KOKKOS_LIBS kokkos)
  target_compile_definitions(nimble PUBLIC -DNIMBLE_HAVE_KOKKOS)
  set(NIMBLE_HAVE_KOKKOS TRUE)
else()
  find_package(Kokkos REQUIRED)
  set(NIMBLE_KOKKOS_LIBS ${Kokkos_LIBRARIES} ${Kokkos_TPL_LIBRARIES})
  message(STATUS "Compiling with Kokkos:")
  message("       Kokkos_DIR: ${Kokkos_DIR}")
  message("       Kokkos_LIBRARIES: ${Kokkos_LIBRARIES}")
  message("       Kokkos_TPL_LIBRARIES: ${Kokkos_TPL_LIBRARIES}")
  message("       Kokkos_CXX_FLAGS: ${Kokkos_CXX_FLAGS}")
endif()


# Optional dependency for pure MPI build (no Trilinos)
if (USE_PURE_MPI)
  set(HAVE_MPI TRUE)
  message(STATUS "Compiling with MPI")
  find_package(MPI REQUIRED)
  include_directories(SYSTEM ${MPI_INCLUDE_PATH})
  ADD_EXECUTABLE(uhfem uh_code.cpp)
  target_compile_definitions(uhfem PUBLIC HAVE_MPI)
  target_link_libraries(uhfem PUBLIC MPI::MPI_CXX)
else()
  ADD_EXECUTABLE(uhfem uh_code.cpp)
endif()


