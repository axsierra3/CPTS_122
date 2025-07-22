#include "ExercisePlan.hpp"

ExercisePlan::ExercisePlan(int goalSteps, string planName, string intendedDate)
{
	mGoalSteps = goalSteps;
	mPlanName = planName;
	mIntendedDate = intendedDate;
}

ExercisePlan::ExercisePlan(ExercisePlan& d)
{
	mGoalSteps = d.mGoalSteps;
	mPlanName = d.mPlanName;
	mIntendedDate = d.mIntendedDate;
}

ExercisePlan& ExercisePlan::operator=(ExercisePlan& rhs) //passes by reference and returns by reference (not copy)
{
	if (this != &rhs) //if this object doesnt already equal the one being assigned on right
	{
		mGoalSteps = rhs.mGoalSteps;
		mPlanName = rhs.mPlanName;
		mIntendedDate = rhs.mIntendedDate;
	}
	return *this; //return this updated object
}

ExercisePlan::~ExercisePlan()
{
	//clean up (only edit if you dynamically allocate memory
	/* cout << "Inside ExercisePlan destructor: " << *this << endl; */
}

//setters & getters
int ExercisePlan::getGoalSteps()
{
	return mGoalSteps;
}

string ExercisePlan::getPlanName()
{
	return mPlanName;
}

string ExercisePlan::getIntendedDate()
{
	return mIntendedDate;
}

void ExercisePlan::setGoalSteps(int newGoalCal)
{
	mGoalSteps = newGoalCal;
}

void ExercisePlan::setPlanName(string newPlanName)
{
	mPlanName = newPlanName;
}

void ExercisePlan::setIntendedDate(string newDate)
{
	mIntendedDate = newDate;
}

void ExercisePlan::editGoal()
{
	int newGoal = 0;

	cout << "Enter a value for this diet plan's new goal steps: " << endl;
	cin >> newGoal;

	setGoalSteps(newGoal);

	cout << *this; //remembering to pass by ref
}

std::ostream& operator<<(std::ostream& lhs, ExercisePlan& rhs) //printing
{
	//'<<' inserts the data into the stream, directing it to the output device
	lhs << "Plan Name: " << rhs.getPlanName() << " Goal Steps: " << rhs.getGoalSteps() << " Date: " << rhs.getIntendedDate() << endl;

	return lhs; //in this case, lhs represents cout (an outputstream object), we're sending in the string data here, which is then printed (cout << plan1)
}

std::ostream& operator<<(std::ofstream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << " Goal Steps: " << rhs.getGoalSteps() << " Date: " << rhs.getIntendedDate() << endl;

	return lhs;
}


ifstream& operator>>(ifstream& lhs, ExercisePlan& rhs)
{
	// '>>' extraction operator extracts data from the input stream on the left and stores it in the right 
	//cin can be linked to the keyboard or to the file here
	string planName = "default", date = "00/00/0000", strCals = "";
	int steps = 0;

	lhs >> planName;
	rhs.setPlanName(planName);

	lhs >> steps;
	rhs.setGoalSteps(steps);

	lhs >> date;
	rhs.setIntendedDate(date);

	return lhs;
}
