/*
 * Topic: Indirect sorting with insertion sort, and binary search in text. Made by Joseph Ramsay.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    char *fname_par = NULL;
    char *fname_words = NULL;
    char paragraphFile[50];

    int mode = 0; // 0 - normal, 1 - verbose

    //Open paragraph file
    printf("\nPlease enter your paragraph file: ");
    scanf("%s", paragraphFile);
    FILE *fptr;
    fptr = fopen(paragraphFile, "r");

    if(fptr == NULL)
    {
        printf("Invalid file, please try again"); //Program exits if file pointer returns NULL
        exit(0);
    }
    else
    {
        printf("Loading paragraph file...\n");
    }
    //read the entire paragraph as one big string.


    //make an array of pointers to the beginning of each word in the paragraph


    //use insertion sort to reorder the pointers to give access to the words in increasing lexicographical order


    //print the paragraph words before and after sorting.


    //open the word list file, and use binary search for each word in the indirectly sorted list of paragraph words.



    //Starter code below
    if (argc < 4 ) {
        printf("Not enough arguments. Need mode and 2 filenames, e.g.:   0 small.txt words1.txt\n");
        return 0;
    }
    else {
        fname_par = argv[2];
        fname_words = argv[3];
        mode = atoi(argv[1]);
    }

    printf("mode: %d  |  paragraph: %s  |  words: %s\n", mode, fname_par, fname_words);  // KEEP THIS LINE

    return 0;
}
