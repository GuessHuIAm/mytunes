#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

struct song * add_node(struct song *library, char *name1, char *artist1);
struct song *librarysong_search(struct song *library[], char *name1, char *artist1);
struct song *artistsong_search(struct song *library[], char *artist1);
void entries_byletter(struct song *library[], char y);
void print_library(struct song *library[]);

#endif
