tmp:dcs_s.o dcs_c.o
	gcc dcs_s.c dcs_c.c -o tmp
dcs_c.o:dcs_c.c session10_dcs.h
	gcc dcs_c.c -c
dcs_s.o:dcs_s.c session10_dcs.h
	gcc dcs_s.c -c
