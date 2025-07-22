//PA 3
//Name: Arantxa Sierra
//Description: This program interacts with users through a main menu interface with 7 options. Users can generate a 
// playlist from a file with song information. These songs are stored as records in a doubly linked list that represents
// the playlist. The playlist can be modified through main menu commands such as edit and rate. Display and  and play print
// songs to the screen, and users can update the original file through store and exit commands.
// These commands either traverse the linked list or directly modify values in the structs it contains.
// The program will continue to prompt the user for input/commands until they chose to exit.
//Program now includes functions for sorting the list by different categories such as artist, shuffling the songs to play in 
// a different order, and for inserting a user's custom songs.

#include "MusicManager.h"

int main() {

	Node* pHead = NULL;
	FILE* musicFile;
	int exited = 0;
	srand(time(0));

	//main menu loop
	while (exited == 0)
	{
		int choice = 0;
		int pick = 0;
		int rating = 0;
		char songName[25] = "";
		char artistName[25] = "";


		Sleep(2000);
		printf("\n------MAIN MENU------\n");
		printf("Welcome to your music manager, please select an option from the list below~\n\n");
		printf("1. Load Songs\n2. Store Songs\n3. Display Songs \n4. Insert a Song \n5. Delete\n6. Edit \n7. Sort \n8. Rate \n9. Play \n10. Shuffle \n11. Exit Player\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			musicFile = fopen("musicPlaylist.csv", "r");
			pHead = load(musicFile, &pHead);
			break;
		}
		case 2:
		{
			musicFile = fopen("musicPlaylist.csv", "w");
			store(pHead, musicFile);
			break;
		}
		case 3:
		{
			display(pHead);
			break;
		}
		case 4: //insert
		{
			int inserted = 0;
			char buff[50];
			Record newSong;
			printf("\nPlease enter the following data for the new song---\n\n");
			getchar();
			printf("Artist: ");
			fgets(newSong.artist, 50, stdin);
			newSong.artist[strcspn(newSong.artist, "\n")] = '\0';

			printf("\nAlbum title: ");
			fgets(newSong.album, 50, stdin);
			newSong.album[strcspn(newSong.album, "\n")] = '\0';

			printf("\nSong title: ");
			fgets(newSong.song, 50, stdin);
			newSong.song[strcspn(newSong.song, "\n")] = '\0';

			printf("\nGenre: ");
			fgets(newSong.genre, 50, stdin);
			newSong.genre[strcspn(newSong.genre, "\n")] = '\0';

			printf("\nMinutes: ");
			scanf("%d", &newSong.length.minutes);
			printf("\nSeconds: ");
			scanf("%d", &newSong.length.seconds);
			printf("\nTimes Played: ");
			scanf("%d", &newSong.timesPlayed);
			printf("\nRating: ");
			scanf("%d", &newSong.rating);


			inserted = insert(&pHead, newSong);
			if (inserted)
			{
				printf("\n\n%s inserted successfully!\n", newSong.song);
			}
			else {
				printf("\n\nError adding song, try again!\n");
			}
			break;
		}
		case 5: //Delete
		{
			int deleted = 0;

			printf("\nWhat song would you like to delete?: ");
			getchar();
			fgets(&songName, 50, stdin);
			songName[strcspn(songName, "\n")] = '\0';

			deleted = delete(&pHead, songName);

			if (deleted)
			{
				printf("\n\n%s deleted!\n", songName);
			}
			else {
				printf("\n\nError deleting song, try again!\n");
			}
			break;
		}
		case 6:
		{
			printf("\nWhat artist's song would you like to edit?: ");
			getchar(); //eat the newline
			fgets(&artistName, 50, stdin);
			artistName[strcspn(artistName, "\n")] = '\0'; //go to the index where the newline is and replace it w null

			edit(&pHead, artistName);
			break;
		}
		case 7: //sort
		{
			printf("\nWould you like to sort based on Artist (1) , Album title (2), Rating (3), or times played? (4): ");
			scanf("%d", &pick);
			sort(&pHead, pick);

			break;
		}
		case 8:
		{
			printf("\nWhat song would you like to rate?: ");
			getchar(); //eat the newline
			fgets(&songName, 50, stdin);
			songName[strcspn(songName, "\n")] = '\0'; //go to the index where the newline is and replace it w null

			printf("\n\nWhat is your new rating for %s?: ", songName);
			scanf("%d", &rating);
			rate(&pHead, songName, rating);
			break;
		}
		case 9:
		{
			printf("\nWhat song would you like to play?: ");
			getchar(); //eat the newline
			fgets(&songName, 50, stdin);
			songName[strcspn(songName, "\n")] = '\0'; //go to the index where the newline is and replace it w null

			play(pHead, songName);
			break;

		}
		case 10: //shuffle
		{
			int playOrder[100] = { 0 };

			generatePlayOrder(pHead, playOrder);

			shuffle(pHead, playOrder);

			break;
		}
		case 11:
		{
			//exit
			musicFile = fopen("musicPlaylist.csv", "w");
			exit(pHead, musicFile);
			exited = 1;

			break;
		}
		default:
		{
			printf("\nMain menu error!\n");
			break;
		}
		}
	}
	return 0;
}