run:string_client.o string_s.o
	gcc string_client.o string_s.o -o run
string_client.o:string_client.c session2_strmatch.h
	gcc -c string_client.c
string_s.o:string_s.c session2_strmatch.h
	gcc -c string_s.c
