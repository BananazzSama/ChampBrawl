ChampBrawl : brawl.o main.o utility.o
	gcc -o ChampBrawl brawl.o main.o utility.o

brawl.o : brawl.c
	gcc -o brawl.o -c brawl.c

main.o : main.c
	gcc -o main.o -c main.c

utility.o : utility.c
	gcc -o utility.o -c utility.c