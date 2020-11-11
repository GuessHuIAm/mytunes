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
struct song *insert_order(struct song *old, char *name1, char *artist1)
{
	struct song *nn = new_song(name1, artist1, NULL);
	struct song *p = old;

	if (old == NULL)
	{
		return nn;
	}

	while (p != NULL)
	{
		if (strcmp(p->artist, artist1) == 0) //checks if the current node's artist is equal to the artist of the item we're inserting, then it goes through all the test cases
		{
			if (p->next == NULL && strcmp(p->name, name1) < 0) //if you've reached the end of the linkedlist (p->next == NULL) and the item that we're inserting goes after the current node (p), then insert it after the current node.
			{
				p->next = nn;
				p = old;
				return p;
			}
			if (p->next == NULL && strcmp(p->name, name1) > 0) //if you've reached the end of the linkedlist (p->next == NULL) and the item that we're inserting goes before the current node (p), then insert it before the current node. we do this by swapping the values of the current node and what we're inserting.
			{
				p->next = nn;
				strcpy(nn->artist, p->artist);
				strcpy(nn->name, p->name);
				strcpy(p->artist, artist1);
				strcpy(p->name, name1);
				p = old;
				return p;
			}
			if (strcmp(p->next->artist, artist1) != 0 && strcmp(p->name, name1) > 0) //if the next node after the current node does not have the same artist then we just check to see if the item we're inserting goes before the current node. if it does, do the swap.
			{
				nn->next = p->next;
				p->next = nn;
				strcpy(nn->artist, p->artist);
				strcpy(nn->name, p->name);
				strcpy(p->artist, artist1);
				strcpy(p->name, name1);
				p = old;
				return p;
			}
			if (strcmp(p->next->artist, artist1) != 0 && strcmp(p->name, name1) < 0) //if the next node after the current node does not have the same artist then we just check to see if the item we're inserting goes after the current node. if it does, insert it after the current node.
			{
				nn->next = p->next;
				p->next = nn;
				p = old;
				return p;
			}
			if (strcmp(p->name, name1) < 0 && strcmp(p->next->name, name1) > 0 && p->next != NULL) //at this point we know that the next node after the current node must have the same artist as what we're inserting so we check if we can insert our item in between the current node and the next node. if we can, insert it.
			{
				nn->next = p->next;
				p->next = nn;
				p = old;
				return p;
			}
			if (strcmp(p->name, name1) > 0) //if we can't insert it in between the current and next node, then we see if our item goes before the current node and if it does, we do a swap.
			{
				nn->next = p->next;
				p->next = nn;
				strcpy(nn->artist, p->artist);
				strcpy(nn->name, p->name);
				strcpy(p->artist, artist1);
				strcpy(p->name, name1);
				p = old;
				return p;
			}
			//if all this fails then we know that our item goes after the current node so we just move to the next node to make sure it goes in the right place.
			p = p->next;
		}
		if (strcmp(p->artist, artist1) > 0) //if our item goes alphabetically before the current node, we swap
		{
			nn->next = p->next;
			p->next = nn;
			strcpy(nn->artist, p->artist);
			strcpy(nn->name, p->name);
			strcpy(p->artist, artist1);
			strcpy(p->name, name1);
			p = old;
			return p;
		}
		if (p->next == NULL && strcmp(p->artist, artist1) < 0) //if we're at the end of the list, we insert it after.
		{
			p->next = nn;
			p = old;
			return p;
		}
		if (strcmp(p->artist, artist1) < 0 && strcmp(p->next->artist, artist1) > 0 && p->next != NULL) // if we can insert our item between the current node and the next node, we insert it
		{
			nn->next = p->next;
			p->next = nn;
			p = old;
			return p;
		}

		p = p->next;
	}
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
