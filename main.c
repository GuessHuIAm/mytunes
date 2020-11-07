#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"

int main()
{
    //testing old linkedlist functions
    /*
    struct song *list1 = NULL;
    list1 = insert_front(list1, "Happy", "Pharrel Williams");
    list1 = insert_front(list1, "Blinding Lights", "The Weeknd");
    print_list(list1);
    list1 = free_list(list1);
    print_list(list1);
    */

    //testing new linkedlist functions
    /*
    struct song *list1 = NULL;
    list1 = insert_front(list1, "Happy", "Pharrel Williams");
    list1 = insert_front(list1, "Happy2", "Pharrel Williams");
    list1 = insert_front(list1, "Happy3", "Pharrel Williams");
    list1 = insert_front(list1, "Happy4", "Pharrel Williams");
    printf("Testing new functions\n");
    printf("%p\n", search(list1, "Happy", "Pharrel Williams"));
    printf("%p\n", first_search(list1, "Pharrel Williams"));
    print_song(first_search(list1, "Pharrel Williams"));
    printf("%p\n", random_element(list1));
    print_song(random_element(list1));\
    */

    //testing insert (linkedlist)
    struct song *list1 = NULL;
    list1 = insert(list1, "Song3", "Taylor");
    list1 = insert(list1, "Song1", "Beatles");
    list1 = insert(list1, "Song2", "Elvis");
    list1 = insert(list1, "03", "Eminem");
    list1 = insert(list1, "Song1", "Taylor");
    list1 = insert(list1, "Song0", "Madonna");
    list1 = insert(list1, "Random3", "Elton");
    list1 = insert(list1, "Song2", "Madonna");
    list1 = insert(list1, "Testrun", "Pink Floyd");
    list1 = insert(list1, "Song3", "Madonna");
    list1 = insert(list1, "Song2", "Taylor");
    list1 = insert(list1, "Moretesting", "Rihanna");
    list1 = insert(list1, "01", "Eminem");
    list1 = insert(list1, "Another", "Zedd");
    list1 = insert(list1, "Random6", "Elton");
    list1 = insert(list1, "Song1", "Madonna");
    list1 = insert(list1, "Another1", "Zedd");

    //0,2,3,1
    print_list(list1);

    return 0;
}
