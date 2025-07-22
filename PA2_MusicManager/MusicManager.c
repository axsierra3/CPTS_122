#include "MusicManager.h"

void initList(Node** pList)
{
	*pList = NULL; //sets list/pHead to empty
}

Node* createNode(Record newData) //helper
{
	Node* newNode = malloc(sizeof(Node)); //allocate space on heap 

	if (newNode != NULL) //is space allocated on the heap? (checking actual ptr)
	{
		//yes, lets initialize with Record data
		newNode->pNext = NULL;
		newNode->pPrev = NULL;
		newNode->data = newData; //struct assignment 

		return newNode;
	}

}

int insert(Node** pList, Record newData)
{
	Node* newNode = createNode(newData); //make the node
	int success = 0;

	if (newNode != NULL) //space allocated
	{
		if (newData.timesPlayed < 0 || newData.rating < 0 || newData.rating > 5 || newData.length.minutes < 0 || newData.length.seconds < 0)
		{ //invalid data
			return success;
		}
		//else
		success = 1;

		if (*pList == NULL) //is the list empty? (checking head ptr of list)
		{
			*pList = newNode; //then the head of the list is now this new node
		}
		else
		{ //not its not empty
			newNode->pNext = *pList; //inserting at front
			(*pList)->pPrev = newNode; //pHead's prev is now new node
			*pList = newNode; //head = new node
		}
	}
	return success;

	return 0;
}

void cleanLine(char* line)
{
	char lastName[25] = "";
	char first[25] = "";
	char fullName[50] = "";

	if (line[0] == '"')
	{
		int i = 0, j = 1;

		for (; line[j] != ','; i++, j++)
		{
			lastName[i] = line[j];  //get everyhing after " up to ,comma
		}
		lastName[i + 1] = '\0'; //add null
		j = j + 2; //skip comma and that leading space

		for (i = 0; line[j] != '"'; i++, j++)
		{
			first[i] = line[j];
		}
		first[i] = ' '; //add the space back but after first name

		strcpy(fullName, strcat(first, lastName)); //combine

		//now shifting everything in line array to the left by 3 to acct for missing " " and the comma
		int lineLength = strlen(line);

		for (i = 0; i < lineLength - 3; i++)
		{
			line[i] = line[i + 3];
		}
		line[lineLength - 3] = '\0';


		for (i = 0; i < strlen(fullName); i++)
		{
			line[i] = fullName[i];
		}
	}
}

Node** load(FILE* musicFile, Node** playList)
{
	if (musicFile == NULL)
	{
		printf("File could not be opened");
	}

	else {
		initList(&playList); //initalize emptylist
		char line[100] = "";
		Record recordBuff;

		while (fgets(line, 100, musicFile) != NULL) //getting data
		{
			cleanLine(line);
			strcpy(recordBuff.artist, strtok(line, ","));
			strcpy(recordBuff.album, strtok(NULL, ","));
			strcpy(recordBuff.song, strtok(NULL, ","));
			strcpy(recordBuff.genre, strtok(NULL, ","));
			recordBuff.length.minutes = atoi(strtok(NULL, ":"));
			recordBuff.length.seconds = atoi(strtok(NULL, ","));
			recordBuff.timesPlayed = atoi(strtok(NULL, ","));
			recordBuff.rating = atoi(strtok(NULL, ","));

			insert(&playList, recordBuff);
		}
		if (playList != NULL)
		{
			printf("\nPlaylist has been loaded and created!\n");
			Sleep(2000);
		}
	}
	return playList;
}



void store(Node* pCpy, FILE* musicFile)
{
	if (pCpy == NULL) //base case
	{
		printf(" ");
	}
	else {
		fprintf(musicFile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pCpy->data.artist, pCpy->data.album, pCpy->data.song, pCpy->data.genre, pCpy->data.length.minutes, pCpy->data.length.seconds, pCpy->data.timesPlayed, pCpy->data.rating);
		store(pCpy->pNext, musicFile);
	}
}

void display(Node* pCpy) //pass in copy bc its not really changing the list
{
	//base case 
	if (pCpy == NULL) //pts to null
	{
		printf("-->\n"); //either end of list or list is empty
	}
	else //recursive step
	{
		printf("--> Artist: %s, Album: %s, Song: %s, Genre: %s, Duration: %d minutes: %d seconds, Times Played: %d, Rating: %d/5\n",
			pCpy->data.artist, pCpy->data.album, pCpy->data.song, pCpy->data.genre, pCpy->data.length.minutes, pCpy->data.length.seconds, pCpy->data.timesPlayed, pCpy->data.rating);
		display(pCpy->pNext);
	}
}

void edit(Node** pList, char* nameToFind)
{
	int artistFound = 0;
	if (*pList != NULL) //not empty
	{
		Node* pCur = *pList;

		while (pCur != NULL) //continue to advance until pCur is null
		{
			int answer = -1;
			int choice = -1;
			char newVal[50] = "";

			if (strcmp(pCur->data.artist, nameToFind) == 0)
			{
				artistFound = 1;
				printf("Would you like to modify %s by %s? (1/0): ", pCur->data.song, pCur->data.artist);
				scanf("%d", &answer);

				if (answer == 1)
				{
					printf("\nWhich value would you like to edit?\n1. Artist 2. Album 3. Song 4. Genre 5. Minute 6. Seconds 7. Times Played 8. Rating\n");
					scanf("%d", &choice);
					printf("\nEnter the new value: ");
					getchar(); //eat the newline
					fgets(newVal, 50, stdin);
					newVal[strlen(newVal) - 1] = '\0'; //getting rid of extra ln from input

					switch (choice)
					{

					case 1:
					{
						strcpy(pCur->data.artist, newVal);
						break;
					}
					case 2:
					{
						strcpy(pCur->data.album, newVal);
						break;
					}
					case 3:
					{
						strcpy(pCur->data.song, newVal);
						break;
					}
					case 4:
					{
						strcpy(pCur->data.genre, newVal);
						break;
					}
					case 5:
					{
						pCur->data.length.minutes = atoi(newVal);
						break;
					}
					case 6:
					{
						pCur->data.length.seconds = atoi(newVal);
						break;
					}
					case 7:
					{
						pCur->data.timesPlayed = atoi(newVal);
						break;
					}
					case 8:
					{
						pCur->data.rating = atoi(newVal);
						break;
					}
					default:
						printf("Something went wrong!\n");
						break;
					}
				}
			}
			pCur = pCur->pNext; //moving it along until end of list
		}
	}
	if (artistFound == 0) {
		printf("\nArtist not found\n");
	}
}

void rate(Node** pList, char* songToEdit, int rating)
{
	if (*pList != NULL) //not empty
	{
		Node* pCur = *pList; //start of list

		while (pCur != NULL) //continue to advance until pCur is null
		{
			if (strcmp(pCur->data.song, songToEdit) == 0)
			{
				pCur->data.rating = rating;
				return;
			}
			pCur = pCur->pNext;

		}
	}
	printf("\nSong not found\n");
}

void play(Node* pList, char* songToEdit)
{
	int songFound = 0;
	if (pList != NULL) //not empty
	{
		Node* pCur = pList; //start of list

		while (pCur != NULL) //continue to advance until pCur is null
		{
			if (strcmp(pCur->data.song, songToEdit) == 0 || songFound == 1)
			{
				songFound = 1;
				printf("\n\n--NOW PLAYING--: %s by %s --  %s, %s -- %d:%d, played %d times, Rating: %d/5",
					pCur->data.song, pCur->data.artist, pCur->data.album, pCur->data.genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.timesPlayed, pCur->data.rating);

				Sleep(2000);
				system("cls");

			}
			pCur = pCur->pNext;
		}
	}
	if (songFound == 0) {
		printf("\nSong not found\n");
	}

}

void generatePlayOrder(Node* pList, int arr[100])
{
	int numSongs = 0;
	int assigned;
	int randNum;
	Node* pCur = pList;

	while (pCur != NULL) //just counting songs in list
	{
		pCur = pCur->pNext;
		numSongs++;
	}

	for (int i = 1; i <= numSongs; i++)
	{
		assigned = 0;
		while (assigned == 0)
		{
			randNum = rand() % numSongs + 1;

			if (arr[randNum] == 0)
			{
				arr[randNum] = i;
				assigned = 1;
			}
		}
	}
}

void shuffle(Node* pList, int playOrder[])
{
	Node* pCur = pList;
	Node* songPosition[100];
	int numSongs = 0;

	while (pCur != NULL) //just counting songs in list
	{
		numSongs++;
		songPosition[numSongs] = pCur;
		pCur = pCur->pNext;
	}

	for (int i = 1; i <= numSongs; i++)
	{
		pCur = songPosition[playOrder[i]];
		printf("\n\n--NOW PLAYING--: %s by %s --  %s, %s -- %d:%d, played %d times, Rating: %d/5",
			pCur->data.song, pCur->data.artist, pCur->data.album, pCur->data.genre, pCur->data.length.minutes, pCur->data.length.seconds, pCur->data.timesPlayed, pCur->data.rating);

		Sleep(2000);
		system("cls");
	}

}

void sort(Node** pList, int option)
{
	Node* pCur;
	Node* pSorted = NULL; //tracks where has been sorted
	int swapOccured; //if no swaps happen after a full pass, we can just exit bc the list is sorted
	Node* lastSwapped = NULL; // Track last swapped element

	if (*pList != NULL) //not empty
	{
		switch (option)
		{
		case 1: //artist
		{
			do
			{
				pCur = *pList; //start at head everytime
				swapOccured = 0;
				Node* lastSwapped = NULL;

				while (pCur->pNext != NULL && pCur->pNext != pSorted) //go thru everything before last bit thats sorted
				{
					if (strcmp(pCur->pNext->data.artist, pCur->data.artist) < 0) //
					{
						Node* pNext = pCur->pNext; //the one just compared
						if (pCur->pPrev == NULL) //head
						{
							*pList = pNext; //just make the head pt to next
						}
						else
						{
							pCur->pPrev->pNext = pNext; //point the node before's next, to pNext
						}
						if (pNext->pNext != NULL) //theres a node after pNext (not the end)
						{
							pNext->pNext->pPrev = pCur;
						}

						pCur->pNext = pNext->pNext; //main swaps between the ptrs of the nodes being compaired
						pNext->pPrev = pCur->pPrev;
						pNext->pNext = pCur;
						pCur->pPrev = pNext;


						swapOccured = 1;
						lastSwapped = pCur;
					}
					pCur = pCur->pNext; //just keep moving
				}
				pSorted = lastSwapped; //whats been sorted
			} while (swapOccured); //go again if there was a swap
			break;
		}
		case 2: //album title
		{
			do
			{
				pCur = *pList; //start at head everytime
				swapOccured = 0;
				Node* lastSwapped = NULL;

				while (pCur->pNext != NULL && pCur->pNext != pSorted) //go thru everything before last bit thats sorted
				{
					if (strcmp(pCur->data.album, pCur->pNext->data.album) > 0) //
					{
						Node* pNext = pCur->pNext; //the one just compared
						if (pCur->pPrev == NULL) //head
						{
							*pList = pNext; //just make the head pt to next
						}
						else
						{
							pCur->pPrev->pNext = pNext; //point the node before's next, to pNext
						}
						if (pNext->pNext != NULL) //theres a node after pNext (not the end)
						{
							pNext->pNext->pPrev = pCur;
						}

						pCur->pNext = pNext->pNext; //main swaps between the ptrs of the nodes being compaired
						pNext->pPrev = pCur->pPrev;
						pNext->pNext = pCur;
						pCur->pPrev = pNext;


						swapOccured = 1;
						lastSwapped = pCur;
					}
					pCur = pCur->pNext; //just keep moving
				}
				pSorted = lastSwapped; //whats been sorted
			} while (swapOccured); //go again if there was a swap
			break;
		}
		case 3: //rating
		{
			do
			{
				pCur = *pList; //start at head everytime
				swapOccured = 0;

				while (pCur->pNext != pSorted && pCur->pNext != NULL) //go thru everything before last bit thats sorted
				{
					if (pCur->data.rating > pCur->pNext->data.rating) //bigger rating in front
					{
						Node* pNext = pCur->pNext; //the one just compared
						if (pCur->pPrev == NULL) //head
						{
							*pList = pNext; //just make the head pt to next
						}
						else
						{
							pCur->pPrev->pNext = pNext; //point the node before's next, to pNext
						}
						if (pNext->pNext != NULL) //theres a node after pNext (not the end)
						{
							pNext->pNext->pPrev = pCur;
						}

						pCur->pNext = pNext->pNext; //main swaps between the ptrs of the nodes being compaired
						pNext->pPrev = pCur->pPrev;
						pNext->pNext = pCur;
						pCur->pPrev = pNext;


						swapOccured = 1;
					}
					pCur = pCur->pNext; //just keep moving
				}
				pSorted = pCur; //whats been sorted
			} while (swapOccured); //go again if there was a swap

			break;
		}
		case 4: //times played
		{
			do
			{
				pCur = *pList; //start at head everytime
				swapOccured = 0;

				while (pCur->pNext != pSorted && pCur->pNext != NULL) //go thru everything before last bit thats sorted
				{
					if (pCur->data.timesPlayed > pCur->pNext->data.timesPlayed) //bigger rating in front
					{
						Node* pNext = pCur->pNext; //the one just compared
						if (pCur->pPrev == NULL) //head
						{
							*pList = pNext; //just make the head pt to next
						}
						else
						{
							pCur->pPrev->pNext = pNext; //point the node before's next, to pNext
						}
						if (pNext->pNext != NULL) //theres a node after pNext (not the end)
						{
							pNext->pNext->pPrev = pCur;
						}

						pCur->pNext = pNext->pNext; //main swaps between the ptrs of the nodes being compaired
						pNext->pPrev = pCur->pPrev;
						pNext->pNext = pCur;
						pCur->pPrev = pNext;


						swapOccured = 1;
					}
					pCur = pCur->pNext; //just keep moving
				}
				pSorted = pCur; //whats been sorted
			} while (swapOccured); //go again if there was a swap

			break;
		}
		}
	}
}



int delete(Node** pList, char* songToFind)
{
	int success = 0;

	if (*pList != NULL) //not empty
	{
		Node* pCur = *pList; //start of list

		while (pCur != NULL) //continue to advance until pCur is null
		{
			if (strcmp(pCur->data.song, songToFind) == 0)
			{
				Node* temp;
				success = 1;

				//only song in list (emptying the list)
				if (pCur->pNext == NULL && pCur->pPrev == NULL)
				{
					*pList = NULL;
					free(pCur);
					return success;
				}

				//deletion was found at front
				if (pCur == *pList) //its still the head
				{
					temp = *pList; //temp now pts at pList (will be deleted)
					*pList = temp->pNext;   //head is now next
					(*pList)->pPrev = NULL;  //prev = null
					free(temp); //free
					return success;
				}

				//end
				if (pCur->pNext == NULL)
				{
					temp = pCur;
					pCur = pCur->pPrev; //last item in list is now what prev was
					pCur->pNext = NULL;
					free(temp);
					return success;
				}

				//found in middle
				temp = pCur;
				pCur = pCur->pNext; //moving
				temp->pPrev->pNext = pCur; //fixing prev node's next
				pCur->pPrev = temp->pPrev; //fixing prev ptr

				free(temp);
				return success;
			}
			pCur = pCur->pNext; //if it wasnt found keep moving
		}
	}
	return success;
}

void exit(Node* pList, FILE* musicFile)
{
	store(pList, musicFile);
	fclose(musicFile);
}
