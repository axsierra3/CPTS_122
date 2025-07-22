#include "fitbit.h"

void dataCleanser(char* line)
{
	int consecComCt = 0;

	int lineLength = strlen(line);

	for (int i = 0; i < lineLength; i++)
	{
		if (line[i] == ',')
		{
			consecComCt++; //if this hits two there is a missing val
		}
		else 
		{
			consecComCt = 0;
		}

		//[encountered a consec comma
		if (consecComCt == 2) 
		{
			//here move everything in the array over by 2 to replace 
			for (int j = lineLength; j >= i; j--)
			{
				line[j + 2] = line[j];
			}
			lineLength += 2;

			line[i] = '-';
			line[i + 1] = '1';
			}
		}
	}

int findMaxSteps(FitbitData arr[], int numRecords)
{
	int maxSteps = arr[0].steps;

	for(int i = 1; i < numRecords; i++) 
	{
		if (arr[i].steps > maxSteps)
		{
			maxSteps = arr[i].steps;
		}

	}
	return maxSteps;
}

void findLongestRange(FitbitData arr[], char* startTime, char* endTime, int numRecords)
{
	int maxRange = 0;
	strcpy(startTime, arr[0].minute);
	strcpy(endTime, arr[0].minute);
	int currSum = 0;
	int consecPoorSleep = 0;
	char hour[10] = "";

	for (int i = 1; i < numRecords; i++)
	{
			strcpy(hour, arr[i].minute);
			strtok(hour,":");

		if (atoi(hour) < 8 || atoi(hour) >= 21) //from 0-8am, or 9pm+
		{ 
			if (arr[i].sleepLevel > 1) //if awake
			{
				currSum += arr[i].sleepLevel; //add that sleep num to sum
				consecPoorSleep++; //how many in a row
			}
			else
			{
				if (currSum > maxRange && consecPoorSleep > 1) 
				{
					maxRange = currSum;
					strcpy(startTime, arr[i - consecPoorSleep].minute); 
					strcpy(endTime, arr[i - 1].minute);
				}
				currSum = 0;
				consecPoorSleep = 0;
			}
		}
	}
}






