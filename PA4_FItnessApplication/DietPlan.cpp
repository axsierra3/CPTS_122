#include "DietPlan.hpp"

DietPlan::DietPlan(int goalCalories, string planName, string intendedDate)
{
		mGoalCalories = goalCalories;
		mPlanName = planName;
		mIntendedDate = intendedDate;
}

DietPlan::DietPlan(DietPlan& d)
{
	mGoalCalories = d.mGoalCalories;
	mPlanName = d.mPlanName;
	mIntendedDate = d.mIntendedDate;
}

DietPlan& DietPlan::operator=(DietPlan& rhs) //passes by reference and returns by reference (not copy)
{
	if (this != &rhs) //if this object doesnt already equal the one being assigned on right
	{
		mGoalCalories = rhs.mGoalCalories;
		mPlanName = rhs.mPlanName;
		mIntendedDate = rhs.mIntendedDate;
	}
	return *this; //return this updated object
}

DietPlan::~DietPlan()
{
	//clean up (only edit if you dynamically allocate memory
	/* cout << "Inside DietPlan destructor: " << *this << endl; */
}

//setters & getters
int DietPlan::getGoalCalories()
{
	return mGoalCalories;
}

string DietPlan::getPlanName()
{
	return mPlanName;
}

string DietPlan::getIntendedDate()
{
	return mIntendedDate;
}

void DietPlan::setGoalCalories(int newGoalCal)
{
	mGoalCalories = newGoalCal;
}

void DietPlan::setPlanName(string newPlanName)
{
	mPlanName = newPlanName;
}

void DietPlan::setIntendedDate(string newDate)
{
	mIntendedDate = newDate;
}

void DietPlan::editGoal()
{
	int newGoal = 0;

	cout << "Enter a value for this diet plan's new goal calories: " << endl;
	cin >> newGoal;

	setGoalCalories(newGoal);

	cout << *this; //remembering to pass by ref
}

std::ostream& operator<<(std::ostream& lhs, DietPlan& rhs) //printing
{
	//'<<' inserts the data into the stream, directing it to the output device
	lhs << "Plan Name: " << rhs.getPlanName() << " Goal Calories: " << rhs.getGoalCalories() << " Date: " << rhs.getIntendedDate() << endl;

	return lhs; //in this case, lhs represents cout (an outputstream object), we're sending in the string data here, which is then printed (cout << plan1)
}

std::ostream& operator<<(std::ofstream& lhs, DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << " Goal Calories: " << rhs.getGoalCalories() << " Date: " << rhs.getIntendedDate() << endl;

	return lhs; 
}



ifstream& operator>>(ifstream& lhs, DietPlan& rhs)
{
	// '>>' extraction operator extracts data from the input stream on the left and stores it in the right 
	//cin can be linked to the keyboard or to the file here
	string planName = "default", date = "00/00/0000", strCals = "";
	int calories = 0;

	lhs >> planName;
	rhs.setPlanName(planName);

	lhs >> calories;
	rhs.setGoalCalories(calories);

	lhs >> date;
	rhs.setIntendedDate(date);

	return lhs;
}





