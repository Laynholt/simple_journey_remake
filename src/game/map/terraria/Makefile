all: bioms.o terraria.o

bioms.o:
	+$(MAKE) -C bioms

terraria.o: terraria.c terraria.h
	cc -c terraria.c

clear:
	rm terraria.o
