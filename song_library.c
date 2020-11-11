#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_library.h"
#include "song_list.h"

struct library *new_library()
{
    struct library *lib = malloc(sizeof(struct library));
    int i;
    for (i = 0; i < 27; i++)
    {
        (lib->categories)[i] = NULL;
    }
    lib->size = 0;
    return lib;
}

struct library *add_node(struct library *lib, char *name1, char *artist1)
{
    char s = artist1[0];
    int i;

    int num = artist1[0] - 'A';

    if (num < 26 && num > 0){
    	lib->categories[num] = insert_order(lib->categories[num], name1, artist1);
	lib->size++;
    	return lib;
    }
    else{
    	lib->categories[num] = insert_order(lib->categories[26], name1, artist1);
    	lib->size++;
	return lib;
    }
}

// Add song nodes and return a pointer to the array.

struct song *librarysong_search(struct library *lib, char *name1, char *artist1)
{
    char s = artist1[0];
    int letter = s - 'A';
    struct song *section = lib->categories[letter];
    struct song *returnval = song_search(section, name1, artist1);
    return returnval;
}

//Search for a song given song and artist name (return a pointer).

struct song *artistsong_search(struct library *lib, char *artist1)
{
    char s = artist1[0];
    int letter = s - 'A';
    struct song *section = lib->categories[letter];
    struct song *returnval = artist_search(section, artist1);
    return returnval;
}

//Search for an artist. Returns a pointer to a separate linked list with all entires of said artist.

void entries_by_letter(struct library *lib, char y)
{
    int letter = y - 'A';
    struct song *section = lib->categories[letter];
    print_list(section);
}
//Print out all the entries under a certain letter.

void print_library(struct library *lib)
{
    if (lib == NULL){
	printf("Library is NULL\n");
	return;
    }

    int i;
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < 27; i++)
    {
        if (i == 26)
        {
            printf("Other Symbols: ");
        }
        else
        {
            printf("-----%c-----\n", alphabet[i]);
        }
        struct song *section = lib->categories[i];
        print_list(section);
        printf("\n");
    }
    printf("Number of songs in library: %d\n", lib->size);
}

void entries_by_artist(struct library *lib, char* artist){
	char c = artist[0];
	int letter = c - 'A';
    	struct song *section = lib->categories[letter];
	section = artist_search(section, artist);
	while (strcmp(section->artist, artist) == 0){
		print_song(section);
		if (section->next == NULL){
			return;
		}
		section = section-> next;
	}
}

void shuffle(struct library *lib, int number){
	srand(time(NULL));
	printf("Number of songs in total: %d\nNumber of songs in this shuffle: %d\n", lib->size, number);

	if (lib->size == 0){
		printf("No songs.\n");
	}

	// void* refers to the pointer memory
	struct song ** library_array = (struct song **) malloc(lib->size * sizeof(struct song *));

	int i;
	int k = 0;

	for (i = 0; i < 27; i++){
		if(lib->categories[i] != NULL){
			library_array[k] = lib->categories[i];
			k++;
		}
	}

	for (i = 0; i < number; i++){
		print_song(library_array[rand() % (k - 1)]);
	}

	free(library_array);
}

struct library * library_delete(struct library *lib, char* name, char* artist){
	lib->size--;
	struct song * section = lib->categories[artist[0]-'A'];
	section = remove_song(section, name);
	return lib;
}

struct library * free_library(struct library * lib){
	int i;
	for (i = 0; i < 27; i++){
		lib->categories[i] = free_list(lib->categories[i]);
	}
	free(lib);
	return NULL;
}
