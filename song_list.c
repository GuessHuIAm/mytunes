#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
        char name[100];
        char artist[100];
	struct song *next;
};

//print song
void print_song(struct song *s){
	printf("'%s'\tby%s\n", s->name, s->artist);
}

//new song
struct song * new_song(char *n, char *a, struct song *next_song){
	struct song *ns;

	ns = malloc(sizeof(struct song));
	strncpy(ns->name, n, sizeof(ns->name) - 1);
	strncpy(ns->artist, a, sizeof(ns->artist) - 1);
	ns->next = next_song;

	return ns;
}

//change the song
void change_song(struct song *s, char *n, char *a, struct song *next_song){
	strncpy(s->name, n, sizeof(s->name) - 1);
	strncpy(s->artist, a, sizeof(s->artist) - 1);
	s->next = next_song;
}

//print a song list
void print_list(struct song *s){
	while(s != NULL){
		print_song(s);
		s = s->next;
	}
}

//insert a song to the front
struct song * insert_front(struct song *list, char *n, char *a){
	struct song *ns = new_song(n, a, list);
	return ns;
}

//free a song list
struct song * free_list(struct song *s){
	struct song *first = s;
	struct song *next;

	while(s != NULL){
		next = s->next;
		printf("Free %s\n", s->name);
		free(s);
		s = next;
	}
	return first;
}

//remove a song from a list
struct song * remove_song(struct song *front, char *name){
	struct song* first = front;
	struct song* previous = NULL;

	while (front != NULL){
		if (!strcmp(front->name, name)){
			if (previous != NULL){
				previous->next = front->next;
				free(front);
				break;
			}
			return front->next;
		}
		previous = front;
		front = front->next;
	}
	return first;
}
