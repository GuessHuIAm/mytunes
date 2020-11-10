#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_library.h"
#include "song_list.h"

struct song *add_node(struct song *library, char *name1, char *artist1)
{
    char s = artist1[0];
    int letter;
    if (s - 'A' >= 0 && s - 'Z' <= 0)
    {
        letter = s - 'A';
    }
    else
    {
        letter = 26;
    }

}
// Add song nodes and return a pointer to the array.

/*
struct song *librarysong_search(struct song *library[], char *name1, char *artist1)
{
    char s = artist1[0];
    int letter = s - 'A';
    struct song *returnval = song_search(library[letter], artist1, name1);
    return returnval;
}

//Search for a song given song and artist name (return a pointer).

struct song *libraryartist_search(struct song *library[], char *artist1)
{
    char s = artist1[0];
    int letter = s - 'A';
    struct song *returnval = artist_search(library[letter], artist1);
    return returnval;
}

//Search for an artist. Returns a pointer to a separate linked list with all entires of said artist.

void entries_byletter(struct song *library[], char y)
{
    int letter = y - 'A';
    struct song *x = library[letter];
    print_list(x);
}
//Print out all the entries under a certain letter.
*/

void print_library(struct song *library)
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
        print_list((library[i]));
        printf("\n");
    }
}