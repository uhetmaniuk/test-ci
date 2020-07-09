
#include <iostream>

#ifdef HAVE_MPI
#include <mpi.h>
#endif

int main(int argc, char **argv) {

#ifdef HAVE_MPI
  MPI_Init(&argc, &argv);
#endif

  int myRank = 0, numRank = 1;
 
#ifdef HAVE_MPI
  MPI_Comm_size(MPI_COMM_WORLD, &numRank);
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
#endif

std::cout << " Code running on " << numRank << " procs ... I am " << myRank << "\n";
  
#ifdef HAVE_MPI
  std::cout << " Call to MPI_Finalize()\n";
  MPI_Finalize();
#endif

return 0;

}
