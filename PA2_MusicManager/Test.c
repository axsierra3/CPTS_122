#include "Test.h"

void testInsert(void)
{
	Record testRec = { "Perry, Katy", "Witness", "Chained To The Rhythm", "pop", {4, 36}, -1, 6 };
	Node* pList = NULL;

	//Testing with -1 played and and 6 rating
	//Should not be added to the list in this case
	//Expected result: 0

	int success = insert(&pList, testRec);

	if (success == 0 && pList == NULL)
	{
		printf("Insert is working for invalid data");
	}
	else {
		printf("Insert is not working for invalid data");
	}
}

void testDelete(void)
{
	int success = 0;
	Node* pList = NULL;
	Record testRec = { "Perry, Katy", "Witness", "Chained To The Rhythm", "pop", {4, 36}, 3, 5 };
	insert(&pList, testRec); //only song in list

	if (pList != NULL)
	{
		success = delete(&pList, "Chained To The Rhythm");
	}
	if (pList == NULL && success)
	{
		printf("Delete working for only song in list\n");
	}
	else
	{
		printf("Delete not working for only song in list\n");
	}
}


void testShuffle(void) 
{
	int playOrder[4] = { 3, 1, 2 };
	Node* pList = NULL;

	//test case: shuffling 3 songs in a list 
	Record testRec = { "Perry, Katy", "Witness", "Chained To The Rhythm", "pop", {4, 36}, 3, 5 };
	insert(&pList, testRec); 
	Record testRec2 = { "Conan Gray", "Super", "People Watching", "pop", {2, 56}, 2, 3 };
	insert(&pList, testRec2);
	Record testRec3 = { "Shack Wes", "X", "Mo Bamba", "rap", {3, 20}, 20, 4 };
	insert(&pList, testRec3);

	shuffle(pList, playOrder);
}
