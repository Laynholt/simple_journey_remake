all: bioms.o landscape.o cloud.o tree.o

bioms.o: bioms.c bioms.h
	cc -c biom.c

landscape.o: landscape.c landscape.h
	cc -c landscape.c

cloud.o: cloud.c cloud.h
	cc -c cloud.c

tree.o: tree.c tree.h
	cc -c tree.c

clear:
	rm bioms.o landscape.o cloud.o tree.o
