all: main.o song_list.o song_library.o
	gcc -o test main.o song_list.o song_library.o

main.o: main.c song_list.h song_library.h
	gcc -c main.c

song_list.o: song_list.c song_list.h
	gcc -c song_list.c

song_library.o: song_library.c song_library.h song_list.h

run:
	./test

clear:
	rm *.o
	rm test
