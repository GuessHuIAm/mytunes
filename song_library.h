#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H
struct library{
	struct song * categories[27];
};

struct library * new_library();
struct library * add_node(struct library *lib, char *name1, char *artist1);
struct song *librarysong_search(struct library *lib, char *name1, char *artist1);
struct song *artistsong_search(struct library *lib, char *artist1);
void entries_byletter(struct library *lib, char y);
void print_library(struct library * lib);

#endif
