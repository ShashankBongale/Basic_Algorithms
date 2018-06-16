//Header file for session4_tsp.c

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int get_next_permutation(int *permutation, int n);
int tsp(int** graph, int n);
