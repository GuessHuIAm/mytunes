#ifndef SONG_LIST_H
#define SONG_LIST_H

struct song{
        char name[100];
        char artist[100];
	struct song *next;
};

void print_song(struct song *s);
struct song * new_song(char *n, char *a, struct song *next);
void new_song(struct song *s, char *n, char *a, struct song *next);
void print_list(struct song *s);
struct song * insert_front(struct song *s, char *n, char *a);
struct song * free_list(struct song *s);
struct song * remove_song(struct song *front, char *n);

#endif
