# Algorithms
This Repository contains all the codes for implementation of basic algorithms.For each algorithms there is a client,implentation,
input and output files.For each individual input the output must be checked with the given output files with 'diff' command.
# Commands

1)to generate the object file of the source file: 
 gcc -c source_file.c                              

2)to link clinet file with the object file created in the previous step: 
 gcc client_file.c source_file.o -o a.out 

3)to run executable file with the given input and storing the generated output: 
 ./a.out<input_file>output                       

4)comparing the generated output in the previous step with the giben output:
 diff -wB output given_output                      
                                                 
