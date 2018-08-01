run:session11_horspools_client.o session11_horspools.o
	gcc session11_horspools_client.o session11_horspools.o -o run
session11_horspools_client.o:session11_horspools_client.c session11_horspools.h
	gcc session11_horspools_client.c -c
session11_horspools.o:session11_horspools.c session11_horspools.h
	gcc session11_horspools.c -c
