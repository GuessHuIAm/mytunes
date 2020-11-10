#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_library.h"
#include "song_list.h"

void print_library(struct song *library){
	int i;
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    	for (i = 0; i < 27; i++){
        	if (i == 26){
			printf("Other Symbols: ");
		}
        	else{
			printf("%c: ", alphabet[i]);
        	}
        	print_list(library[i]);
        	printf("\n");
	}
}
