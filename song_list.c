#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"

//print song
void print_song(struct song *s)
{
	printf("%s -- \"%s\"\n", s->artist, s->name);
}

//new song
struct song *new_song(char *n, char *a, struct song *next_song)
{
	struct song *ns;

	ns = malloc(sizeof(struct song));
	strncpy(ns->name, n, sizeof(ns->name) - 1);
	strncpy(ns->artist, a, sizeof(ns->artist) - 1);
	ns->next = next_song;

	return ns;
}

//change the song
void change_song(struct song *s, char *n, char *a, struct song *next_song)
{
	strncpy(s->name, n, sizeof(s->name) - 1);
	strncpy(s->artist, a, sizeof(s->artist) - 1);
	s->next = next_song;
}

//print a song list
void print_list(struct song *s)
{
	while (s != NULL)
	{
		print_song(s);
		s = s->next;
	}
}

//insert a song to the front
struct song *insert_front(struct song *list, char *n, char *a)
{
	struct song *ns = new_song(n, a, list);
	return ns;
}

//free a song list
struct song *free_list(struct song *s)
{
	struct song *temp;
	struct song *first = s;
	printf("Freeing... ");
	while (s != NULL)
	{
		temp = s;
		temp->next = NULL;
		free(temp);
		s = s->next;
	}
	printf("Done!\n");
	return NULL;
}

//remove a song from a list
struct song *remove_song(struct song *front, char *name)
{
	struct song *first = front;
	struct song *previous = NULL;

	while (front != NULL)
	{
		if (!strcmp(front->name, name))
		{
			if (previous != NULL)
			{
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

//insert a song in order, returns the beginning of the list
struct song *insert_order(struct song *current, char *new_name, char *new_artist)
{
	struct song *nsong = new_song(new_name, new_artist, NULL);
	struct song *copy = current;

	// if this node is empty
	if (current == NULL) return nsong;

	// if the new node is before this node (either by artist or by song)
	if ( (strcmp(new_artist, current->artist) < 0) ||
	     ((!strcmp(new_artist, current->artist)) && (strcmp(new_name, current -> name) < 0)) ){
        	nsong->next = current;
        	return nsong;
    	}

	// a loopy kinda thing where we find where this node belongs
    	struct song *last_song = current;
   	current = current->next;

	while (current != NULL){
		// if the new song's artist comes before the current song's artist
        	if (strcmp(new_artist, current->artist) < 0){
            		nsong->next = current; // new song points to the current song
            		last_song->next = nsong; // and the last song points to where the new song
            		return(copy);
        	}
		// same thing happens if the current song and the new song have the same artist, but the new song still precede
        	if ((!strcmp(new_artist, current->artist)) && (strcmp(new_name, current->name) < 0)){
                	nsong->next = current;
                	last_song->next = nsong;
                	return(copy);
            	}
        	last_song = current; // swapping for another round of comparisons in this while loop
        	current = current->next;
    	}

	// if we get to the end and is still yet to find a place, that means this new song belongs at the end
	last_song->next = nsong; // last_song pointed to a NULL in the last iteration of the while loop
	return copy;
}

//return a pointer based on artist and song name
struct song *song_search(struct song *x, char *name1, char *artist1)
{
	while (x != NULL)
	{
		if (strcmp(x->artist, artist1) == 0 && strcmp(x->name, name1) == 0)
		{
			return x;
		}
		else
		{
			x = x->next; /* code */
		}
	}
	return NULL;
}

//return the first pointer to a node based on artist
struct song *artist_search(struct song *x, char *artist1)
{
	struct song *returnval = NULL;
	while (x != NULL)
	{
		if (strcmp(x->artist, artist1) == 0)
		{
			return x;
		}
		else
		{
			x = x->next;
		}
	}
	return NULL;
}

//return the pointer to a random song in the list
struct song *random_song(struct song *x)
{
	int len = 0;
	struct song *j = x;
	while (x != NULL)
	{
		len += 1;
		x = x->next;
	}
	//gets length of list by going through all nodes

	x = j;

	int random_i = rand() % len;

	int k;
	for (k = 0; k < random_i; k++)
	{
		x = x->next;
	}
	//goes to random node

	return x;
}
