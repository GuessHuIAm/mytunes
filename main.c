#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_list.h"

int main()
{
    //testing old functions
    /*
    struct song *list1 = NULL;
    list1 = insert_front(list1, "Happy", "Pharrel Williams");
    list1 = insert_front(list1, "Blinding Lights", "The Weeknd");
    print_list(list1);
    list1 = free_list(list1);
    print_list(list1);
    */

    struct song *list1 = NULL;
    list1 = insert_front(list1, "Happy", "Pharrel Williams");
    list1 = insert_front(list1, "Happy2", "Pharrel Williams");
    printf("Testing new functions\n");
    printf("%p\n", search(list1, "Happy", "Pharrel Williams"));
    printf("%p\n", first_search(list1, "Pharrel Williams"));
    print_song(first_search(list1, "Pharrel Williams"));
    printf("%p\n", random_element(list1));

    return 0;
}
