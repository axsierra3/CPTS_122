// guard code
#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <Windows.h>

//structs

//struct used to contain the specific values of the duration of a song, used in record structs
typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

//struct represents an individual song and its data
typedef struct record
{
	char artist[25];
	char album[25];
	char song[25];
	char genre[25];
	Duration length;
	int timesPlayed;
	int rating;
}Record;

//doubly linked node containing record (song) data
typedef struct node
{
	Record data;
	struct node* pNext;
	struct node* pPrev;
}Node;


//functions

//helper function used in load, takes a new list as a parameter and sets it to empty
void initList(Node** pList);

//helper function for insertFront, which creates a node and initializes its pointers and 
// initializes it with the record data passed in
Node* createNode(Record newData);

//function used in load, take a linked list and data, creates a node, and inserts it first in the list
//by replacing the original pHead (handles cases for empty and nonempty list)
int insert(Node** pList, Record newData);

//function used in load to take care of the the artist names that come in '"Last, First"' format
//takes away the quotation marks and puts it into 'First Last' format for readabilty and to allow
//load to parse it
void cleanLine(char* line);

//takes a file, reads each line and puts it into a record struct, this record struct is then inserted into the
//linked list, it does so until all lines have been read. the linked list is returned
Node** load(FILE* musicFile, Node** playList);

//takes the linked list of records (that by now has likely been updated by the user) and overwrites
//the original file with the current playlist
void store(Node* pList, FILE* musicFile);

//prints all the songs in the playlist to the screen (formatted)
void display(Node* pList);

//takes an artist name as a parameter, then asks the user once each of that artist's songs has been
// found if they would like to edit that song, and finally what field they would like to change
// the struct and list is then updated (switch statement)
//if no song is found a message is printed
void edit(Node** pList, char* nameToFind);

//takes a song name and rating, and searches the linked list for a mathcing song
// that song's rating is then replaced by the new value 
void rate(Node** pList, char* songToEdit, int rating);

//searches the linked list for a song, then displays that song's information and 
//the information of all the subsequent songs in the list for a short amount of time
void play(Node* pList, char* songToEdit);

//searches the linked list for a specific song, rearranges the pointers accordingly
//and frees the memory for that song record in order to delete it
int delete(Node** pList, char* songToFind);

//helper function used inside shuffle to generate a random order to play the 
//songs in the playlist using an array to keep track of when each song should be played
//and what numbers have been previously generated
void generatePlayOrder(Node* pList, int arr[]);

//takes an array with a specific play order and prints the songs in the playlist
//onto the screen in that order by traversing the list
void shuffle(Node* pList, int playOrder[]);

//function takes the linked list and an option for the type of sorting that needs to be
//performed (by artist, rating etc) and rearranges the pointers in order to rearrange the
//list through a bubble sort
void sort(Node** pList, int option);

//overwrites the original file with the current linked list of records, then in main,
//the file is closed and the program exits
void exit(Node* pList, FILE* musicFile);


#endif // guard code end

#pragma once
