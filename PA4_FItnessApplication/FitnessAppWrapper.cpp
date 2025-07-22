#include "FitnessAppWrapper.hpp"


void FitnessAppWrapper::runApp(void)
{
	cout << "--Welcome To Your Fitness App!--" << endl;
	int choice = 0;
	int eChoice = 0;
	
	DietPlan weeklyDiet[7];
	ExercisePlan weeklyWorkout[7];

	ifstream inputDietStream;
	ifstream inputWorkoutStream;
	std::ofstream outputDietStream;
	std::ofstream outputWorkoutStream;
	inputDietStream.open("dietPlans.txt", std::ios::in); //input/output stream in mode read in
	inputWorkoutStream.open("ePlan.txt", std::ios::in);
	outputDietStream.open("resultDiet.txt", std::ios::out); //input/output stream in mode read in
	outputWorkoutStream.open("resultExercise.txt", std::ios::out);

	do 
	{
		displayMenu();
		cout << endl << "Enter your choice: ";
		cin >> choice;

		switch (choice) 
		{
		case 1: //load weekly diet
		{
			if (inputDietStream.is_open())
			{
				loadWeeklyPlan(inputDietStream, weeklyDiet);

			}
			break;
		}
		case 2: //load weekly exercise
		{
			if (inputWorkoutStream.is_open())
			{
				loadWeeklyPlan(inputWorkoutStream, weeklyWorkout);
			}
			break;
		}
		case 3: //store weekly diet in file
		{
			if (outputDietStream.is_open())
			{
				storeWeeklyPlan(outputDietStream, weeklyDiet);
			}
			break;
		}
		case 4:
		{
			if (outputWorkoutStream.is_open())
			{
				storeWeeklyPlan(outputWorkoutStream, weeklyWorkout);
			}
			break;
		}
		case 5: //printing
		{
			displayWeeklyPlan(weeklyDiet);
			break;
		}
		case 6: 
		{
			displayWeeklyPlan(weeklyWorkout);
			break;
		}
		case 7:
		{
			cout << endl << "Which diet day would you like to edit (1-7)?: ";
			cin >> eChoice;

			weeklyDiet[eChoice].editGoal();
			break;
		}
		case 8:
		{
			cout << endl << "Which exercise day would you like to edit (1-7)?: ";
			cin >> eChoice;

			weeklyWorkout[eChoice].editGoal();
			break;
		}
		case 9:
		{
			storeWeeklyPlan(outputDietStream, weeklyDiet);
			storeWeeklyPlan(outputWorkoutStream, weeklyWorkout);
			inputDietStream.close();
			inputWorkoutStream.close();
			outputDietStream.close();
			inputWorkoutStream.close();
			break;
		}
		}

	} while (choice != 9);
}

void FitnessAppWrapper::displayMenu()
{
	cout << "1. Load weekly diet plan from file" << endl << "2. Load weekly exercise plan from file" << endl << "3. Store weekly diet plan to file" << endl << "4. Store weekly exercise plan to file" << endl << "5. Display weekly diet plan to screen" << endl << "6. Display weekly exercise plan to screen" << endl << "7. Edit daily diet plan" << endl << "8. Edit daily exercise plan" << endl << "9. Exit" << endl;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, DietPlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, ExercisePlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[7])
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, DietPlan& plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeDailyPlan(std::ofstream& fileStream, ExercisePlan& plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}






