#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H
struct library{
	struct song * categories[27];
	int size;
};

struct library * new_library();
struct library * add_node(struct library *lib, char *name1, char *artist1);
struct song * librarysong_search(struct library *lib, char *name1, char *artist1);
struct song * artistsong_search(struct library *lib, char *artist1);
void entries_by_letter(struct library *lib, char y);
void entries_by_artist(struct library *lib, char* artist);
void print_library(struct library * lib);
void shuffle(struct library *lib, int number);
struct library * library_delete(struct library *lib, char* name, char* artist);
struct library * free_library(struct library * lib);

#endif
