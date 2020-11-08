#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"

int main()
{
    srand(time(NULL));
    //testing insert_front
    printf("****************************Testing insert_front!\n");
    struct song *list1 = NULL;

    list1 = insert_front(list1, "1989", "Taylor Swift");
    list1 = insert_front(list1, "Hey Jude", "The Beatles");
    list1 = insert_front(list1, "Burning Love", "Elvis Presley");
    list1 = insert_front(list1, "The Monster", "Eminem");
    list1 = insert_front(list1, "Love Story", "Taylor Swift");
    list1 = insert_front(list1, "La Isla Bonita", "Madonna");
    list1 = insert_front(list1, "Tiny Dancer", "Elton John");
    list1 = insert_front(list1, "Hung Up", "Madonna");
    list1 = insert_front(list1, "Another Brick in the Wall", "Pink Floyd");
    list1 = insert_front(list1, "Vogue", "Madonna");
    list1 = insert_front(list1, "You Belong With Me", "Taylor Swift");
    list1 = insert_front(list1, "Work", "Rihanna");
    list1 = insert_front(list1, "Lose Yourself", "Eminem");
    list1 = insert_front(list1, "Stay", "Zedd");
    list1 = insert_front(list1, "Circle of Life", "Elton John");
    list1 = insert_front(list1, "4 Minutes", "Madonna");
    list1 = insert_front(list1, "Clarity", "Zedd");

    //printing the unordered list
    printf("The unordered list:\n");
    print_list(list1);

    //testing the removing
    printf("\n****************************Removing a few songs\n");
    printf("Removing Pink Floyd's \"Another Brick in the Wall\" and Madonna's \"Vogue\"...");
    remove_song(list1, "Vogue");
    remove_song(list1, "Another Brick in the Wall");

    printf("\nWe are left with this:\n");
    print_list(list1);

    //freeing
    printf("\n****************************Freeing the list\n");
    list1 = free_list(list1);
    printf("Printing the list now:\n");
    print_list(list1);
    printf("There's nothing!\n");

    //testing insert_order

    printf("\n****************************Testing insert_order!\n");
    list1 = insert_order(list1, "1989", "Taylor Swift");
    list1 = insert_order(list1, "Hey Jude", "The Beatles");
    list1 = insert_order(list1, "Burning Love", "Elvis Presley");
    list1 = insert_order(list1, "The Monster", "Eminem");
    list1 = insert_order(list1, "Love Story", "Taylor Swift");
    list1 = insert_order(list1, "La Isla Bonita", "Madonna");
    list1 = insert_order(list1, "Tiny Dancer", "Elton John");
    list1 = insert_order(list1, "Hung Up", "Madonna");
    list1 = insert_order(list1, "Another Brick in the Wall", "Pink Floyd");
    list1 = insert_order(list1, "Vogue", "Madonna");
    //list1 = insert_front(list1, "You Belong With Me", "Taylor Swift");
    list1 = insert_order(list1, "Work", "Rihanna");
    list1 = insert_order(list1, "Lose Yourself", "Eminem");
    list1 = insert_order(list1, "Stay", "Zedd");
    list1 = insert_order(list1, "Circle of Life", "Elton John");
    list1 = insert_order(list1, "4 Minutes", "Madonna");
    list1 = insert_order(list1, "Clarity", "Zedd");

    //printing the new, ordered list
    printf("The ordered list:\n");
    print_list(list1);
    printf("\n");

    //testing the searches
    printf("****************************Testing the searches\n");
    printf("song_search(list1, \"The Monster\", Eminem): ");
    print_song(song_search(list1, "The Monster", "Eminem"));
    printf("song_search(list1, \"Clarity\", Zedd): ");
    print_song(song_search(list1, "Clarity", "Zedd"));
    printf("artist_search(list1, \"Taylor Swift\"): ");
    print_song(artist_search(list1, "Taylor Swift"));
    printf("artist_search(list1, \"Madonna\"): ");
    print_song(artist_search(list1, "Madonna"));

    printf("random_song(list1): ");
    print_song(random_song(list1));
    printf("random_song(list1): ");
    print_song(random_song(list1));

    return 0;
}
