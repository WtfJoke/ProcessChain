#include <iostream>
#include "Duration.h"
#include "Process.h"
#include "ProcessChain.h"

using namespace std;

int main() 
{
	// declare simple variables
	Duration emptyDuration = Duration();
	cout << "empty duration: " << emptyDuration << endl;

	Duration tenhours = Duration(10, 00, 00);
	cout << "10 hours " << tenhours << endl;

	Duration threeMinutesInSecondsOnly = Duration(0, 0, 180);
	cout << "3minutesInSecondsOnly " << threeMinutesInSecondsOnly << endl;

	Duration threeMinutesAndTenHours = threeMinutesInSecondsOnly + tenhours;
	cout << "threeMinutesAndTenHours " << threeMinutesAndTenHours << endl;

	Duration threeMinutesAndTenHours2 = Duration::Add(threeMinutesInSecondsOnly, tenhours);
	cout << "static add threeMinutesAndTenHours " << threeMinutesAndTenHours2 << endl;

	Duration fourHoursAnd40Seconds = Duration(4, 0, 40);
	cout << "fourHoursAnd40Seconds " << fourHoursAnd40Seconds << endl;

	Process firstProcess = Process(10, "Normalisieren");
	cout << "first process: " << firstProcess << endl;

	Process second = Process(12, "2. Prozess");
	second.TimeSpan(threeMinutesAndTenHours);
	cout << "second process: " << second << endl;

	Process third = Process(33, "3. Prozess");
	third.TimeSpan(fourHoursAnd40Seconds);

	Duration secondProcessDuration = second.TimeSpan();
	cout << "second process duration: " << secondProcessDuration << endl;


	ProcessChain chain = ProcessChain("A Chain");
	chain.Insert(second);
	chain.Insert(firstProcess);
	chain.Insert(third);
	cout << chain << endl;

	// Deep copy
	ProcessChain deepCopyProcessChain = chain;
	cout << "Deep Copy Chain" << endl;
	cout << deepCopyProcessChain << endl;

	// try to readd same process
	cout << "Try to readd firstProcess" << endl;
	if (deepCopyProcessChain.Insert(firstProcess)) 
	{
		cout << endl << "something is wrong" << endl;
	}
	else 
	{
		cout << endl <<  "couldnt readd firstProcess" << endl;
	}

	system("pause");

	return 0;
}