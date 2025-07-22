#include "List.hpp"
#include "AttendanceTracker.hpp"


void AttendanceTracker::runProgram()
{
	ifstream inputFile("classfile.csv");
	ofstream repv1("reportv1.csv");
	ofstream repv2("reportv2.csv");
	fstream masterFile("master.csv", std::ios::in | std::ios::out);

	bool exit = false;
	int option = 0, repChoice = 0, num = 0;

	cout << "---Welcome to the attendace tracker!--" << endl;

	while (!exit)
	{
		cout << endl << "--MAIN MENU--" << endl;
		cout << "1. Import course list" << endl << "2. Load master list" << endl << "3. Store master list" << endl << "4. Mark absences" << endl << "5. Generate report" << endl << "6. Exit" << endl << endl;
		cout << "Please enter your option: ";
		cin >> option;

		switch (option) 
		{
		case 1:
			importCourseList(inputFile);
			break;

		case 2:
			loadMasterList(masterFile);
			break;

		case 3:
			storeMasterList(masterFile);
			break;
		case 4:
			markAbsences(masterList.getHeadPtr());
			break;

		case 5: 
			cout << endl << "Would you like to generate report 1 (all students) or report 2 (students with certain absences)?: ";
			cin >> repChoice;

			if (repChoice == 1) {
				generateReport1(repv1);
			}
			if (repChoice == 2) {
				cout << endl << "What is the number of absences you would like to include on the report?: ";
				cin >> num;
				generateReport2(repv2, num);
			}
			break;

		case 6:
			exit = true;
			break;
		}
	}

	inputFile.close();
	repv1.close();
	repv2.close();
}

//reads in the classfile csv (no absences just student info)
void AttendanceTracker::importCourseList(ifstream& inputFile)
{
	string buffer;
	string name, email, major, level, units;
	int recordNumber = 0, ID = 0;
	int len = 0; //length of str to parse

	if (this->masterList.getHeadPtr() != nullptr)
	{
		masterList.deleteList(masterList.getHeadPtr());
	}
	
	getline(inputFile, buffer); //header line
	while (getline(inputFile, buffer))
	{
		len = buffer.find(","); //find returns the index of the first occurence (so can use as length)
		recordNumber = stoi( buffer.substr(0, len) ); // substr goes from start (inclusive) then takes a string of that length
		buffer = buffer.substr(len + 1, buffer.length()); //start delim is included so add 1

		len = buffer.find(",");
		ID = stoi( buffer.substr(0, len) );
		buffer = buffer.substr(len + 2, buffer.length()); //+2 to go to the index after the quote

		len = buffer.find("\"");
		name = buffer.substr(0, len);
		buffer = buffer.substr(len + 2, buffer.length()); //start after the comma

		len = buffer.find(",");
		email = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		units = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		major = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		level = buffer.substr(0, len);

		Data newData(recordNumber, ID, name, email, units, major, level); // put data here
		masterList.insertAtFront(newData);
	
	}

}

void AttendanceTracker::markAbsences(Node<Data>* headPtr)
{
	int absent = 0;
	int year = 0, month = 0, day = 0;
	string date;


	time_t t = time(0); // get time now
	struct tm* now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1; 
	day = now->tm_mday;

	date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

	if (headPtr == nullptr)
	{
		return;
	}
		
		cout << endl << "Was " << headPtr->getData().getName() << " present (0) or absent(1) today?: ";
		cin >> absent; 

		if (absent)
		{
			headPtr->getData().setNumAbsences(headPtr->getData().getNumAbsences() + 1); //increase num absences
			headPtr->getData().getAbsencesStack().push(date);    //push the date to the top
		}
		markAbsences(headPtr->getNextPtr());
}

void AttendanceTracker::generateReport1(ofstream& reportv1)
{
	Node<Data>* currStudent = masterList.getHeadPtr();

	reportv1 << "Report Version 1 (All Students)" << endl << endl;
	while (currStudent != nullptr)
	{
		Data studentData = currStudent->getData();

		reportv1 << "Student: " << studentData.getName() << " Number of absences: " << studentData.getNumAbsences(); 

		if (studentData.getNumAbsences() >= 1)
		{
			reportv1 << " Most Recent Absence: " << studentData.getAbsencesStack().top() << endl;
		}
		else 
		{
			reportv1 << " Most Recent Absence: N/A" << endl;
		}
	
		currStudent = currStudent->getNextPtr();
	}
}

void AttendanceTracker::generateReport2(ofstream& reportv2, int num)
{
	Node<Data>* currStudent = masterList.getHeadPtr();

	reportv2 << "Report Version 2 (Students with " << num << " or more absences)" << endl << endl;
	while (currStudent != nullptr)
	{
		Data studentData = currStudent->getData();

		if (studentData.getNumAbsences() >= num)
		{
			reportv2 << "Student: " << studentData.getName() << " Number of absences: " << studentData.getNumAbsences() << endl;
		}
	
		currStudent = currStudent->getNextPtr();
	}
}

void AttendanceTracker::loadMasterList(fstream& masterFile)
{
	string buffer;
	string name, email, major, level, units, date;
	int recordNumber = 0, ID = 0, numAbsences = 0;
	int len = 0; //length of str to parse

	getline(masterFile, buffer); //header line
	while (getline(masterFile, buffer))
	{
		len = buffer.find(","); //find returns the index of the first occurence (so can use as length)
		recordNumber = stoi(buffer.substr(0, len)); // substr goes from start (inclusive) then takes a string of that length
		buffer = buffer.substr(len + 1, buffer.length()); //start delim is included so add 1

		len = buffer.find(",");
		ID = stoi(buffer.substr(0, len));
		buffer = buffer.substr(len + 1, buffer.length()); 

		len = buffer.find(",");
		len += buffer.find(",");
		name = buffer.substr(0, len);
		buffer = buffer.substr(len + 1, buffer.length()); 

		len = buffer.find(",");
		email = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		units = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		major = buffer.substr(0, len);

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		level = buffer.substr(0, len);

		Data newData(recordNumber, ID, name, email, units, major, level); 

		buffer = buffer.substr(len + 1, buffer.length());
		len = buffer.find(",");
		numAbsences = stoi (buffer.substr(0, len) );
		newData.setNumAbsences(numAbsences);

		while (numAbsences > 0)
		{
			buffer = buffer.substr(len + 1, buffer.length());
			len = buffer.find(",");
			date = buffer.substr(0, len);
			newData.getAbsencesStack().push(date);

			numAbsences--;
		}

		masterList.insertAtFront(newData);

	}
}

void AttendanceTracker::storeMasterList(fstream& masterFile)
{
	Node<Data>* currStudent = masterList.getHeadPtr();

	masterFile << ",ID,Name,Email,Units,Program,Level,Number Absences,Absent Dates" << endl;
	while (currStudent != nullptr)
	{
		Data studentData = currStudent->getData();

		masterFile << studentData.getRecordNumber() << "," << studentData.getID() << "," << studentData.getName() << "," << studentData.getEmail() << "," << studentData.getUnits() << ","
			<< studentData.getMajor() << "," << studentData.getNumAbsences();

		if (studentData.getNumAbsences() > 0)
		{
			int i = studentData.getNumAbsences();
			stack<string> absenceDates = studentData.getAbsencesStackCopy();

			for (; i > 0; i--)
			{
				masterFile << "," << absenceDates.top();
				absenceDates.pop();
			}
		}
		
		masterFile << endl;

		currStudent = currStudent->getNextPtr();
	}

}



