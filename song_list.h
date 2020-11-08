#ifndef SONG_LIST_H
#define SONG_LIST_H

struct song
{
        char name[100];
        char artist[100];
        struct song *next;
};

void print_song(struct song *s);
struct song *new_song(char *n, char *a, struct song *next);
void print_list(struct song *s);
struct song *insert_front(struct song *s, char *n, char *a);
struct song *insert_order(struct song *old, char *name1, char *artist1);
struct song *remove_song(struct song *front, char *n);
struct song *song_search(struct song *x, char *artist1, char *name1);
struct song *artist_search(struct song *x, char *artist1);
struct song *random_song(struct song *x);
struct song *free_list(struct song *s);

#endif
