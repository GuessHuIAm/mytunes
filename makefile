all: main.o song_list.o
	gcc -o test main.o song_list.o

main.o: main.c song_list.h
	gcc -c main.c

song_list.o: song_list.c song_list.h
	gcc -c song_list.c

run:
	./test

clear:
	rm *.o
	rm test
