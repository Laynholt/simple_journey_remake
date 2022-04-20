all: terraria.o map.o

terraria.o:
	+$(MAKE) -C terraria

map.o: map.c map.h
	cc -c map.c
