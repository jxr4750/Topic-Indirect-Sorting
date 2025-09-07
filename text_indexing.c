/*
 * Topic: Indirect sorting with insertion sort, and binary search in text. Made by Joseph Ramsay.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void insertionSort(char *arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        char *temp = arr[i];
        int j = i - 1;

        while(j >= 0 && strcmp(arr[j], temp) > 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

/* Determines if a listed word is in the paragraph
by comparing tokens.
If yes, returns amount of words
If no, returns 0
*/
int binarySearch(char *arr[], int N, char *v) //determines if v is an element of arr, N is the size
{
    int left, right;
    left = 0; right = N-1;
    while(left <= right)
    {
        int m = left + (right - left) /2;
        if (strcmp(v, arr[m]) == 0) return m;
        if (strcmp(v, arr[m]) < 0) right = m-1;
        else left = m+1;
    }

    return -1;
}


int main(int argc, char** argv) {

    char *fname_par = NULL;
    char *fname_words = NULL;
    char paragraphFile[50];
    char wordFile[50];

    int mode = 0; // 0 - normal, 1 - verbose

    //Open paragraph file
    printf("\nPlease enter your paragraph file: ");
    scanf("%s", paragraphFile); //dont forget to rename when finished
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

    //Open Word list file
    printf("\nPlease enter your Word List file: ");
    scanf("%s", wordFile); //dont forget to rename when finished
    FILE *fptr2;
    fptr2 = fopen(wordFile, "r");

    if(fptr2 == NULL)
    {
        printf("Invalid file, please try again"); //Program exits if file pointer returns NULL
        exit(0);
    }
    else
    {
        printf("Loading word file...\n");
    }




    //read the entire paragraph as one big string.
    char string[50];
    fgets(string, 50, fptr);

    printf("\nParagraph File Contains:\n%s", string);

    char string2[50];
    for(int i = 0; i < 50; i++)
    {
        string2[i] = fgetc(fptr2);
    }

    printf("\nWord File Contains:\n%s", string2);

    //make an array of pointers to the beginning of each word in the paragraph

    printf("\nParagraph tokenized:\n");
    char *tokens[10];
    int i = 0;

    char *token = strtok(string, "., \n\t");

    while (token != NULL && i < 10)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, "., \n\t");
    }

    for(int j = 0; j < i; j++)
    {
        printf("Index %d: %s\n", j, tokens[j]);
    }

    for(int j = 0; j < i; j++) //formats the words to lower case
    {
        for(int k = 0; tokens[j][k]; k++)
        {
            tokens[j][k] = tolower((unsigned char)tokens[j][k]);
        }

    }

    //use insertion sort to reorder the pointers to give access to the words in increasing lexicographical order

    insertionSort(tokens, i);

    //print the paragraph words before and after sorting.
    printf("\nNew word list:\n");



    for(int j = 0; j < i; j++)
    {
        printf("Index %d: %s\n", j, tokens[j]);
    }

    //open the word list file, and use binary search for each word in the indirectly sorted list of paragraph words.
    int result;
    char *tokens2[10];
    int w = 0;

    char *token2 = strtok(string2, "., \n\t");

    while (token2 != NULL && w < 10)
    {
        tokens2[w] = token2;
        w++;
        token2 = strtok(NULL, "., \n\t");
    }

    for(int j = 0; j < w; j++) //formats the words to lower case
    {
        for(int k = 0; tokens2[j][k]; k++)
        {
            tokens2[j][k] = tolower((unsigned char)tokens2[j][k]);
        }

    }

    for(int j = 0; j < w; j++)
    {
        printf("wfile Index %d: %s\n", j, tokens2[j]);
    }



    printf("Searching for: %s", string2);
    result = binarySearch(tokens, i, string2);
    printf("\nThe result is: %d", result);


    /*
    Starter code below
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
    */
    fclose(fptr);
    fclose(fptr2);
    return 0;
}
