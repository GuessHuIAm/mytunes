#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"
#include "song_library.h"

int main()
{
    srand(time(NULL));
    printf("====================================\nLINKED LIST TESTS\n====================================\n");
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
    list1 = insert_order(list1, "You Belong With Me", "Taylor Swift");
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

    printf("\n====================================\nMUSIC LIBRARY TESTS\n====================================\n");
    printf("Testing add_node and print_library...\n");

    struct library *lib = new_library();
    char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    lib = add_node(lib, "1989", "Taylor Swift");
    lib = add_node(lib, "Hey Jude", "The Beatles");
    lib = add_node(lib, "Burning Love", "Elvis Presley");
    lib = add_node(lib, "The Monster", "Eminem");
    lib = add_node(lib, "Love Story", "Taylor Swift");
    lib = add_node(lib, "La Isla Bonita", "Madonna");
    lib = add_node(lib, "Tiny Dancer", "Elton John");
    lib = add_node(lib, "Hung Up", "Madonna");
    lib = add_node(lib, "Another Brick in the Wall", "Pink Floyd");
    lib = add_node(lib, "Vogue", "Madonna");
    lib = add_node(lib, "You Belong With Me", "Taylor Swift");
    lib = add_node(lib, "Work", "Rihanna");
    lib = add_node(lib, "Lose Yourself", "Eminem");
    lib = add_node(lib, "Stay", "Zedd");
    lib = add_node(lib, "Circle of Life", "Elton John");
    lib = add_node(lib, "4 Minutes", "Madonna");
    lib = add_node(lib, "Clarity", "Zedd");
    lib = add_node(lib, "Blinding Lights", "The Weeknd");
    lib = add_node(lib, "Rockstar", "DaBaby");
    lib = add_node(lib, "Level of Concern", "Twenty One Pilots");
    lib = add_node(lib, "Together", "Sia");
    lib = add_node(lib, "Toosie Slide", "Drake");
    lib = add_node(lib, "Hate The Other Side", "Juice WRLD");
    lib = add_node(lib, "Wishing Well", "Juice WRLD");
    lib = add_node(lib, "3am", "Halsey");
    lib = add_node(lib, "The Box", "Roddy Rich");
    lib = add_node(lib, "bloody valentine", "Machine Gun Kelly");
    lib = add_node(lib, "positions", "Ariana Grande");
    lib = add_node(lib, "Dynamite", "BTS");

    print_library(lib);

    printf("\n");
    printf("****************************Testing the searches for the library!\n");
    printf("librarysong_search(lib, \"Vogue\", Madonna): ");
    print_song(librarysong_search(lib, "Vogue", "Madonna"));
    printf("librarysong_search(lib, \"Work\", Rihanna): ");
    print_song(librarysong_search(lib, "Work", "Rihanna"));
    printf("librarysong_search(lib, \"Hate The Other Side\", Juice WRLD): ");
    print_song(librarysong_search(lib, "Hate The Other Side", "Juice WRLD"));

    printf("artistsong_search(lib, \"Zedd\"): ");
    print_song(artistsong_search(lib, "Zedd"));
    printf("artistsong_search(lib, \"Elton John\"): ");
    print_song(artistsong_search(lib, "Elton John"));
    printf("artistsong_search(lib, \"Juice WRLD\"): ");
    print_song(artistsong_search(lib, "Juice WRLD"));

    printf("\n");
    printf("All songs associated with artists that start with the letter E:\n");
    entries_by_letter(lib, 'E');

    printf("\n");
    printf("All songs associated with artists that start with the letter D:\n");
    entries_by_letter(lib, 'D');

    printf("\nPrint out all of Taylor Swift's song:\n");
    entries_by_artist(lib, "Taylor Swift");
    printf("\nPrint out all of Eminem's song:\n");
    entries_by_artist(lib, "Eminem");
    printf("\nPrint out all of Juice WRLD's song:\n");
    entries_by_artist(lib, "Juice WRLD");

    printf("\nPrint out a series of 10 random songs:\n");
    shuffle(lib, 10);

    printf("\n***************************The removing part of the library functions!\n");
    printf("\nDeleting a few of Madonna's and Rihanna's songs:\n");
    printf("library_delete(lib, \"Hung Up\", \"Madonna\")\n");
    lib = library_delete(lib, "Hung Up", "Madonna");
    printf("library_delete(lib, \"Work\", \"Rihanna\")\n");
    lib = library_delete(lib, "Work", "Rihanna");
    printf("library_delete(lib, \"Dynamite\", \"BTS\")\n");
    lib = library_delete(lib, "Dynamite", "BTS");
    printf("Here's what's left:\n");
    print_library(lib);

    printf("\nClearing and freeing the library...\n");
    lib = free_library(lib);
    printf("Here's what's left when we print_library(lib)...\n");
    print_library(lib);

    return 0;
}
