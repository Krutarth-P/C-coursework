/*
This is a program written to maintain a personal music library, using a linked list to hold the songs in the library in alphabetical order. 
It also allows to insert, delete, search, and print songs in the list.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.
const int MAX_LENGTH = 1024;
typedef struct node {
    char* artist;
    char* songName;
    char* genre;
    struct node* next;
} Node;

typedef struct linkedList {
    Node* head;
} LinkedList;

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char* prompt, char* s, int maxStrLength)
{
    int i = 0;
    char c;

    printf("%s --> ", prompt);
    while(i < maxStrLength && (c = getchar()) != '\n')
        s[i++] = c;
    s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char* songName)
{
    printf("\nA song with the name '%s' is already in the music library.\n"
           "No new song entered.\n",
        songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char* songName)
{
    printf("\nThe song name '%s' was found in the music library.\n", songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char* songName)
{
    printf("\nThe song name '%s' was not found in the music library.\n", songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char* songName)
{
    printf("\nDeleting a song with name '%s' from the music library.\n", songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void)
{
    printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void)
{
    printf("\nMy Personal Music Library: \n");
}

// Declarations of linked list functions
//
// DECLARE YOUR LINKED-LIST FUNCTIONS HERE
bool checkDuplicate(char* song, LinkedList* list)
{
    Node* n = list->head;

    while(n != NULL) {
        if(strcmp(song, n->songName) == 0)
            return true;

        n = n->next;
    }
    return false;
}
Node* createNode(char* song, char* artistName, char* genreName)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) { // checking mem.
        newNode->songName = (char*)malloc(MAX_LENGTH * sizeof(char));
        strcpy(newNode->songName, song);

        newNode->artist = (char*)malloc(MAX_LENGTH * sizeof(char));
        strcpy(newNode->artist, artistName);

        newNode->genre = (char*)malloc(MAX_LENGTH * sizeof(char));
        strcpy(newNode->genre, genreName);

        newNode->next = NULL;
    }
    return newNode;
}

void insertAtFront(char* song, char* artistName, char* genreName, LinkedList* list)
{
    if(list->head == NULL) {
        list->head = createNode(song, artistName, genreName);
        return;
    }

    Node* temp = createNode(song, artistName, genreName);

    temp->next = list->head;
    list->head = temp;
}

void insertSorted(char* song, char* artistName, char* genreName, LinkedList* list)
{
    if(list->head == NULL) {
        insertAtFront(song, artistName, genreName, list);
        return;
    }

    if(strcmp(song, list->head->songName) < 0) {
        insertAtFront(song, artistName, genreName, list);
        return;
    }

    Node* n = list->head;
    while(n->next != NULL && (strcmp(song, n->next->songName) > 0)){
        n = n->next;
    }

    Node* newNode = createNode(song, artistName, genreName);

    newNode->next = n->next;
    n->next = newNode;
}

bool deleteMatch(char* song, LinkedList* list)
{
    if(list->head == NULL) {
        return false;
    }

    if(strcmp(song, list->head->songName) == 0) {
        Node* temp = list->head->next;
        free(list->head->songName);
        free(list->head->artist);
        free(list->head->genre);

        free(list->head);

        list->head = temp;

        return true;
    }
    Node* n = list->head;
    while(n->next != NULL && (strcmp(song, n->next->songName) != 0))
        n = n->next;

    if(n->next != NULL) {
        Node* temp = n->next;
        n->next = temp->next;
        free(temp->songName);
        free(temp->artist);
        free(temp->genre);
        free(temp);

        return true;
    }
    return false;
}

bool search(char* song, LinkedList* list)
{
    Node* n = list->head;
    while(n != NULL) {
        if((strcmp(song, n->songName) == 0)) {
            songNameFound(song);
            printf("%s\n", n->songName);
            printf("%s\n", n->artist);
            printf("%s\n", n->genre);
            return true;
        }
        n = n->next;
    }
    return false;
}

void print(LinkedList* list)
{
    Node* n = list->head;
    if(n != NULL)
        printMusicLibraryTitle();
    else
        printMusicLibraryEmpty();

    while(n != NULL) {
        printf("\n%s\n", n->songName);
        printf("%s\n", n->artist);
        printf("%s\n", n->genre);
        n = n->next;
    }
}
void deleteList(LinkedList* list)
{
    while(list->head != NULL) {
        Node* newHead = list->head->next;
        songNameDeleted(list->head->songName);
        free(list->head->songName);
        free(list->head->artist);
        free(list->head->genre);
        free(list->head);
        list->head = newHead;
    }

    list->head = NULL;
    print(list);

    free(list);
}

// Declarations of support functions
// See below the main function for descriptions of what these functions do

/*void inputStringFromUser(char* prompt, char* s, int arraySize);
void songNameDuplicate(char* songName);
void songNameFound(char* songName);
void songNameNotFound(char* songName);
void songNameDeleted(char* songName);
void artistFound(char* artist);
void artistNotFound(char* artist);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);
*/
int main(void)
{
    // Declare the head of the linked list.
    //   ADD YOUR STATEMENT(S) HERE
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    ;
    list->head = NULL;
    // Announce the start of the program
    printf("Personal Music Library.\n\n");
    printf("%s",
        "Commands are I (insert), D (delete), S (search by song name),\n"
        "P (print), Q (quit).\n");

    char response;
    char input[MAX_LENGTH + 1];
    do {
        char song[MAX_LENGTH + 1], artistName[MAX_LENGTH + 1], genreName[MAX_LENGTH + 1];
        inputStringFromUser("\nCommand", input, MAX_LENGTH);

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if(response == 'I') {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE

            // USE THE FOLLOWING STRINGS WHEN PROMPTING FOR DATA:
            char* promptName = "Song name";
            inputStringFromUser(promptName, song, MAX_LENGTH);

            char* promptArtist = "Artist";
            inputStringFromUser(promptArtist, artistName, MAX_LENGTH);

            char* promptGenre = "Genre";
            inputStringFromUser(promptGenre, genreName, MAX_LENGTH);
            if(checkDuplicate(song, list))
                songNameDuplicate(song);
            else
                insertSorted(song, artistName, genreName, list);

        } else if(response == 'D') {
            // Delete a song from the list.

            char* prompt = "\nEnter the name of the song to be deleted";
            inputStringFromUser(prompt, song, MAX_LENGTH);
            //   ADD STATEMENT(S) HERE
            if(deleteMatch(song, list))
                songNameDeleted(song);
            else
                songNameNotFound(song);

        } else if(response == 'S') {
            // Search for a song by its name.

            char* prompt = "\nEnter the name of the song to search for";
            inputStringFromUser(prompt, song, MAX_LENGTH);
            //   ADD STATEMENT(S) HERE
            if(search(song, list) == false)
                songNameNotFound(song);
        } else if(response == 'P') {
            // Print the music library.

            print(list);

            //   ADD STATEMENT(S) HERE

        } else if(response == 'Q') {
            ; // do nothing, we'll catch this below
        } else {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while(response != 'Q');

    // Delete the entire linked list.
    //   ADD STATEMENT(S) HERE
    deleteList(list);
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE

    return 0;
}

// Support Function Definitions

// Add your functions below this line.

//   ADD STATEMENT(S) HERE
