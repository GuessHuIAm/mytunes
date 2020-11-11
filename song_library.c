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
    return lib;
}

struct library *add_node(struct library *lib, char *name1, char *artist1)
{
    char s = artist1[0];
    int i;

    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 27; i++)
    {
        if (s == alphabet[i])
        {
            struct song *section = (lib->categories[i]);
            lib->categories[i] = insert_order(section, name1, artist1);
            return lib;
        }
    }

    insert_order(lib->categories[26], name1, artist1);
    return lib;
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

void entries_byletter(struct library *lib, char y)
{
    int letter = y - 'A';
    struct song *section = lib->categories[letter];
    print_list(section);
}
//Print out all the entries under a certain letter.

void print_library(struct library *lib)
{
    int i;
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    for (i = 0; i < 27; i++)
    {
        if (i == 26)
        {
            printf("Other Symbols: ");
        }
        else
        {
            printf("%c: ", alphabet[i]);
        }
        struct song *section = lib->categories[i];
        print_list(section);
        printf("\n");
    }
}
