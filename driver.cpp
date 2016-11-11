//*******************************************************************************************************
// 
//			File:			driver.cpp
//							
//			Student:		Georgy Sinitsyn 
// 
//			Assignment:		Assignment #4: ArrList2
//
//			Course name:	Data Structures I
//
//			Course number:	COSC 3050 - 01
//
//			Due:			September 23, 2016
//		
//
//			This program stores a dynamically allocated array and modifies it
//          
//			Other files required:
//				1. ArrList2.h
//
//*******************************************************************************************************

#include "ArrList2.h"
#include <iostream>

using namespace std;

int main()
{
	ArrList2 <int> intList(6);
	int temp;

	//*******************************************************************************************************

	cout << "=======Inserting 1, 2, 3, 4, 5, 6, to the list==========" << endl;
	cout << "Using insert back:" << endl;
	intList.insertBack(1);
	intList.insertBack(2);
	intList.insertBack(3);
	intList.insertBack(4);
	intList.insertBack(5);
	intList.insertBack(6);
	intList.display();
	cout << endl;

	//*******************************************************************************************************

	cout << "=======Retrieves==========" << endl;
	intList.retrieveFront(temp);
	cout << "The Front Value: " << temp << endl;
	intList.retrieveBack(temp);
	cout << "The Back Value: " << temp << endl;
	intList.getSecondLargest(temp);
	cout << "The Second Largest: " << temp << endl << endl;
	
	//*******************************************************************************************************

	cout << "=======Reverse==========" << endl;
	intList.reverse();
	intList.display();

	//*******************************************************************************************************

	cout << "=======Removes==========" << endl;
	intList.removeFront(temp);
	cout << "Removing Front: " << temp << endl;
	intList.display();
	intList.removeBack(temp);
	cout << "Removing Back: " << temp << endl;
	intList.display();
	temp = 3;
	intList.remove(temp);
	cout << "Removing value 3: " << temp << endl;
	intList.display();
	cout << endl;

	//*******************************************************************************************************

	cout << "=======Updates==========" << endl;
	cout << "Updates First Values as 100: " << endl;
	intList.updateFront(100);
	intList.display();
	cout << "Updates Last Values as 50: " << endl;
	intList.updateBack(50);
	intList.display();
	cout << "Update Location 2 as 15: " << endl;
	intList.updateAtIndex(15, 2);
	intList.display();
	

	return 0;
}

/*
=======Inserting 1, 2, 3, 4, 5, 6, to the list==========
Using insert back:
1 2 3 4 5 6

=======Retrieves==========
The Front Value: 1
The Back Value: 6
The Second Largest: 5

=======Reverse==========
6 5 4 3 2 1
=======Removes==========
Removing Front: 6
5 4 3 2 1
Removing Back: 1
5 4 3 2
Removing value 3: 3
5 4 2

=======Updates==========
Updates First Values as 100:
100 4 2
Updates Last Values as 50:
100 4 50
Update Location 2 as 15:
100 4 15
Press any key to continue . . .
*/