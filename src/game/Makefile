all: simple.out

map.o:
	+$(MAKE) -C map

control.o:
	+$(MAKE) -C control

camera.o:
	+$(MAKE) -C camera

game.o: game.c game.h config.h types.h
	cc -c game.c

main.o:
	cc -c main.c

simple.out: main.o game.o camera/camera.o control/kbhit.o map/map.o map/terraria/terraria.o map/terraria/bioms/bioms.o map/terraria/bioms/tree.o map/terraria/bioms/cloud.o map/terraria/bioms/landscape.o -o simple.out
