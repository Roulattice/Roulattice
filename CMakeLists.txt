cmake_minimum_required (VERSION 3.9)

project(roulattice
  DESCRIPTION "TODO"
  LANGUAGES C
)

find_package(GDAL)
find_package(OpenMP)
find_package(MPI)

add_executable(roulattice
  src/bricks.c
  src/checks.c
  src/entropy.c
  src/getArgs.c
  src/intra_potential.c
  src/license.c
  src/main.c
  src/observables.c
  src/output.c
  src/pair_correlation_function.c
  src/random_knuth.c
  src/read_dcd.c
  src/SASA.c
  src/statistics.c
  src/tetra_bsaw1.c
  src/tetra_bsaw2.c
  src/tetra_bsaw3.c
  src/tetra_fbsaw1.c
  src/tetra_fbsaw2.c
  src/tetra_fbsaw3.c
  src/tetra_fsaw1.c
  src/tetra_fsaw2.c
  src/tetra_fsaw3.c
  src/tetra_fww.c
  src/tetra_rw.c
  src/tetra_saw1.c
  src/tetra_saw2.c
  src/tetra_saw3.c
  src/time.c
)
target_compile_options(roulattice PRIVATE -Wall) # -fsanitize=address)
target_compile_features(roulattice PRIVATE c_std_99)
target_include_directories(roulattice PUBLIC include)
target_link_libraries(roulattice PRIVATE m)
# target_link_options(roulattice PRIVATE -fsanitize=address)
