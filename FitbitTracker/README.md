#Fitbit Tracker

OVERVIEW
Data Collection:
This program reads 24 hours of patient data (1440+ records) from a CSV file. Health metrics such as heart rate and steps per minute are parsed 
and stored into fields within a struct. Data cleansing is performed to handle missing or erroneous entries.

Calculations:
Using the cleaned data, the program calculates:

Total calories burned

Total distance walked (miles)

Total floors climbed

Total steps taken

Average heart rate

Maximum steps in one minute (with timestamp)

Longest consecutive period of poor sleep

Output:
All results are organized and written to an output file (results.csv) along with the filtered dataset, and are displayed to the console.
