//PA 1
//Name: Arantxa Sierra
//Description: This program reads 24 hours of patient data from a file record and processes the 
// data by filtering it and separating it into relevant fields in a struct. The data is used to calculate
// the patient's total calorie burn, distance walked in miles, floors walked, steps taken, their average heartrate
// maximum steps in 1 minute and their worst sleep period. This data is then organized and written into
// a results file along with the filtered data.


#include "fitbit.h"

int main() 
{
	const char targetPatient[50];
	char tokenBuff[50] = "";
	double totalCalories = 0;
	double distanceWalked = 0;
	int floorsWalked = 0;
	int maxSteps;
	int stepsTaken = 0;
	int totalHeart = 0;
	double averageHeart = 0;
	int validHeart = 0;
	int foundDuplicate = 0;
	char startMin[10] = "";
	char endMin[10] = "";
	char uncheckedID[50];
	char uncheckedMin[50];
	char cleansedData[1450][100];

	FILE* inputStream = fopen("testing.csv", "r"); 
	if (inputStream == NULL)
	{
		printf("File could not be opened");
	}

	else {
		FILE* outputStream = fopen("results.csv", "w");
		fprintf(outputStream, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");

		char line[100] = "";

		FitbitData records[1440] = { {"-1", '-1', -1, -1, -1, -1, -1, -1} };
		int numRecords = 0;


			fgets(line, 100, inputStream); //get first line
			strcpy(tokenBuff, strtok(line, ","));
			strcpy(targetPatient, strtok(NULL, ",")); //separate overall target patient id

			fgets(line, 100, inputStream); //eat label line

			//loop for each patient starts here
			while (fgets(line, 100, inputStream) != NULL)
			{
				//cleansing the line 
				dataCleanser(line);

				strcpy(cleansedData[numRecords], line); //copying line to array that will be printed

				strcpy(uncheckedID, strtok(line, ",")); //curr patient num
				//strcpy(records[numRecords].patient, strtok(line, ",")); //curr patient num
				if (strcmp(uncheckedID, targetPatient) != 0) //checks if id matches, if not skips rest and doesn't incrememnt record num (overwrites)
				{
					continue;
				}

				strcpy(uncheckedMin, strtok(NULL, ",")); //string minute
				//strcpy(records[numRecords].minute, strtok(NULL, ",")); //string minute

				
				if (numRecords > 1)
				{
					for (int i = numRecords - 1; i > 0; i--) //goes through all previous records and checks if the minute is the same (id was was already checked)
					{
						if (strcmp(uncheckedMin, records[i].minute) == 0) //if the minute is the same, the line is a dupe so flag and break loop
						{
							foundDuplicate = 1;
							break;
						}
					}
					if (foundDuplicate) //if flag is true, skips rest and doesn't increment record num (overwrites)
					{
						foundDuplicate = 0;
						continue;
					}
				}
			
				strcpy(records[numRecords].patient, uncheckedID);
				strcpy(records[numRecords].minute, uncheckedMin);
				records[numRecords].calories = atof(strtok(NULL, ",")); //calories
				if (records[numRecords].calories != -1) {
					totalCalories += records[numRecords].calories;
				}

				records[numRecords].distance = atof(strtok(NULL, ",")); //distance
				if (records[numRecords].distance != -1) {
					distanceWalked += records[numRecords].distance;
				}

				records[numRecords].floors = atoi(strtok(NULL, ",")); //floors
				if (records[numRecords].floors != -1) {
					floorsWalked += records[numRecords].floors;
				}

				records[numRecords].heartRate = atoi(strtok(NULL, ",")); //heart
				if (records[numRecords].heartRate != -1) {
					totalHeart += records[numRecords].heartRate;
					validHeart++;
				}

				records[numRecords].steps = atoi(strtok(NULL, ",")); //steps
				if (records[numRecords].steps != -1) {
					stepsTaken += records[numRecords].steps;
				}

				records[numRecords].sleepLevel = atoi(strtok(NULL, ",")); //sleep

				numRecords++; //increment	
			}

		averageHeart = (double)totalHeart / validHeart;
		maxSteps = findMaxSteps(records, numRecords);
		findLongestRange(records, startMin, endMin, numRecords);

		fprintf(outputStream, "%.2lf  %.2lf  %d  %d  %.2lf  %d  %s-%s\n\n", totalCalories, distanceWalked, floorsWalked, stepsTaken, averageHeart, maxSteps, startMin, endMin);

		for (int i = 0; i < numRecords; i++)
		{
			fprintf(outputStream, "%s", cleansedData[i]);
		}
		

		fclose(inputStream);
		fclose(outputStream);
	}
	return 0;
}