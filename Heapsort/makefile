run:heap_c.o heap_s.o
	gcc heap_c.o heap_s.o -o run
heap_c.o:heap_c.c session9_heapsort.h
	gcc heap_c.c -c
heap_s.o:heap_s.c session9_heapsort.h
	gcc heap_s.c -c
