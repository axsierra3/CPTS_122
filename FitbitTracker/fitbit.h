// guard code
#ifndef FITBIT_H
#define FITBIT_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

//takes a string line of data as an argument, and checks if there are any consecutive commas in the data
//if there are, every value in the array is shifted to the right to make room for a dummy variable that will
//be ignored in data calculations, the dummy variable is inserted and the rest of the line is checked
void dataCleanser(char* line);


//takes an array of fitbit data records, and the total number of records. 
//iterates through the array to find the maximum amount of steps in one minute
// taken by the user and comparies it to the previous maxes
int findMaxSteps(FitbitData arr[], int numRecords);

//takes an array of fitbit data records, a string for the start time, a string for the end time, and the 
// number of total records.
// the function iterates through the array, checks if it is sleeping hours, then checks if 
// there is a consecutive streak of poor sleep, if there is then it adds the sleep values
//and compares it to the previous longest streak to determine the longest overall streak
// function returns the start and ending minute for the streak through output parameters
void findLongestRange(FitbitData arr[], char* startTime, char* endTime, int numRecords);


#endif // guard code end

#pragma once
