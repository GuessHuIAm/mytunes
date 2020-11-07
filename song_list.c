#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"

//print song
void print_song(struct song *s)
{
	printf("'%s' by %s\n", s->name, s->artist);
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
	struct song *first = s;
	struct song *next;

	while (s != NULL)
	{
		next = s->next;
		printf("Free %s\n", s->name);
		free(s);
		s = next;
	}
	return first;
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

struct song *insert(struct song *old, char *name1, char *artist1)
{
	struct song *nn = malloc(sizeof(struct song));
	struct song *p = old;
	strcpy(nn->name, name1);
	strcpy(nn->artist, artist1);
	nn->next = NULL;

	if (old == NULL)
	{
		return nn;
	}

	while (p != NULL)
	{

		if (strcmp(p->artist, artist1) == 0)
		{

			if (p->next == NULL && strcmp(p->name, name1) < 0)
			{
				printf("b\n");
				p->next = nn;
				p = old;
				return p;
			}

			if (strcmp(p->name, name1) > 0)
			{
				printf("c\n");
				nn->next = p->next;
				p->next = nn;
				strcpy(nn->name, p->name);
				strcpy(p->name, name1);
				p = old;
				return p;
			}
			if (strcmp(p->name, name1) < 0 && strcmp(p->next->artist, artist1) == 0 && strcmp(p->next->name, name1) < 0)
			{
				p = p->next;
			}
			if (strcmp(p->name, name1) < 0)
			{
				printf("d\n");
				nn->next = p->next;
				p->next = nn;
				p = old;
				return p;
			}
		}
		if (strcmp(p->artist, artist1) > 0)
		{
			nn->next = p;
			p = nn;
			return p;
		}

		if (p->next == NULL && strcmp(p->artist, artist1) < 0)
		{
			p->next = nn;
			p = old;
			return p;
		}
		if (strcmp(p->artist, artist1) < 0 && strcmp(p->next->artist, artist1) > 0 && p->next != NULL)
		{
			nn->next = p->next;
			p->next = nn;
			p = old;
			return p;
		}
		p = p->next;
	}
}
//assumes its sorted by artist at this point

//insert nodes in order alphabetical by Artist then by Song, returns beginning of the list

struct song *search(struct song *x, char *name1, char *artist1)
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
//find and return a pointer to a node based on artist and song name

struct song *first_search(struct song *x, char *artist1)
{
	struct song *returnval = NULL;
	while (x != NULL)
	{
		if (strcmp(x->artist, artist1) == 0)
		{
			return x;
		}
	}
}
//find and return a pointer to the first song of an artist based on artist name

struct song *random_element(struct song *x)
{
	int len = 0;
	srand(time(NULL));
	struct song *j = x;
	while (x != NULL)
	{
		len += 1;
		x = x->next;
	}
	//gets length of list by going through all nodes

	x = j;

	int random_i = (rand() % 10);
	while (random_i > len || random_i == 0)
	{
		random_i = (rand() % 10);
	}
	//rng
	random_i -= 1;

	int k;
	for (k = 0; k < random_i; k++)
	{
		x = x->next;
	}
	//goes to random node

	return x;
}

//Return a pointer to random element in the list.