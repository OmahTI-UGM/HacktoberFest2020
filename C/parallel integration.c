#include "mpi.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

// Compile with mpicc, run with mpirun. 
// If you don't have it already go install mpich from apt

// Uses numeric rectangular integration

double f(double x){
	// Insert function here
	// todo : expression parser to take functions from CLI input
	
	// Computes normal distribution with mean = 0 and variance = 1
	return (pow(M_E, -1*(x * x)/2.0)/(sqrt(2 * M_PI)));
}

int main(int argc, char **argv){
	int rank, size, iter;
	double upper, lower, i, x, l, r, res, result;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(argc < 4){
		printf("Usage : enter lower bound, upper bound, number of integral iterations\n");
		return 0;
	}

	lower = atof(argv[1]);
	upper = atof(argv[2]);
	iter = atoi(argv[3]);
	
	if(upper < lower){
		printf("Error : Lower bound higher than upper bound\n");
		return 0;
	}
	
	double delta = (double)(upper - lower)/(double)iter, len = iter/size;
			   
	if(rank == size-1){
		l = lower + rank * len * delta;
		r = upper;
		res = 0;
		for(i = l; i <= r; i += delta)
			res += delta * f(i);
		printf("Process %d : from %.2f to %.2f get %.2f\n", rank, l, r, res);
	}
	else{
		l = lower + rank * len * delta;
		r = l + len * delta;
		res = 0;
		for(i = l; i < r; i += delta)
			res += delta * f(i);
		printf("Process %d : from %.2f to %.2f get %.2f\n", rank, l, r, res);
	}
	
	MPI_Reduce(&res, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0) printf("The integral is %.2f\n", result);
	MPI_Finalize();
}

