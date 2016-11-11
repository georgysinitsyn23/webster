//*******************************************************************************************************
// 
//			File:			ArrList2.h
//							
//			Student:		Georgy Sinitsyn 
// 
//			Assignment:		Assignment #5: ArrList2
//
//			Course name:	Data Structures I
//
//			Course number:	COSC 3050 - 01
//
//			Due:			September 30, 2016
//		
//
//			This program stores a dynamically allocated array and modifies it
//          
//			Other files required:
//				1. driver.cpp
//
//*******************************************************************************************************

#ifndef ARRLIST2_H
#define ARRLIST2_H

#include <iostream>
using namespace std;

template <typename Type>
class ArrList2
{
	private:
		  Type * list;
          int capacity,
              numValues;

          bool _resize();

	public:
		ArrList2(int = 5);
		~ArrList2();
		bool retrieveFront(Type &) const;
		bool retrieveBack(Type &) const;
		bool removeFront(Type &);
		bool removeBack(Type &);
		bool remove(Type &);
		bool removeAtIndex(Type &, int);
		bool updateAtIndex(const Type &, int);
		bool updateFront(const Type &);
		bool updateBack(const Type &);
		bool update(const Type &, const Type &);
		bool getSmallest(Type &) const;
		bool reverse();
		bool getSecondLargest(Type &) const;
		void display() const;
		bool insertBefore(const Type &, const Type &);
		bool insertAfter(const Type &, const Type &);
		bool insertBack(const Type &);
		bool insertFront(const Type &);
		bool insertAtIndex(const Type &, const int);
		bool retrieveAtIndex(const int, Type &) const;
		int getCapacity();
		int getNumValues();
		void trimToSize();
		void clearList();
		bool isEmpty() const;
		int find(const Type &) const;
};


#endif

//*******************************************************************************************************
//	Constructor
//*******************************************************************************************************

template <typename Type>
ArrList2 <Type> :: ArrList2(int c)
{
	capacity = c;
	numValues = 0;
	list = new Type[capacity];
}

//*******************************************************************************************************
//	Destructor
//*******************************************************************************************************

template <typename Type>
ArrList2 <Type> :: ~ArrList2()
{
	capacity = 0;
	numValues = 0;
	delete [] list;
}

//*******************************************************************************************************
//	retrieveFront function
//		retrieves value from the front of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: retrieveFront(Type &dataOut) const
{
	bool success = false;

	success = retrieveAtIndex(0, dataOut);
	
	return success;
}

//*******************************************************************************************************
//	retrieveBack function
//		retrieves value from the back of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: retrieveBack(Type &dataOut) const
{
	bool success = false;

	success = retrieveAtIndex(numValues - 1, dataOut);
	
	return success;
}

//*******************************************************************************************************
//	removeFront function
//		removes value from the front 
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: removeFront(Type &dataOut)
{
	bool success = false;

	success = retrieveFront(dataOut);
	
	if(success)
	{
		for(int i = 0; i < numValues - 1; i++)
			list[i] = list[i+1];
		numValues--;
	}
	return success;
}

//*******************************************************************************************************
//	removeBack function
//		removes value from the back of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: removeBack(Type &dataOut)
{
	bool success = false;

	success = retrieveBack(dataOut);

	if(success)
	{
		numValues--;
	}

	return 0;
}

//*******************************************************************************************************
//	removeAtIndex function
//		removes value at an index
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: removeAtIndex(Type &dataOut, int index)
{
	bool success = false;

	if((index >= 0)&&(index < numValues))
    {
		dataOut = list[index];
        for(int i = index; i < numValues; i++)
             list[i] = list[i+1];
        numValues--;
        success = true;
	}
	return success;

}


//*******************************************************************************************************
//	remove function
//		matches a value to a given one and removes it
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: remove(Type &dataOut)
{
	bool success = false;
	int index;
	index = find(dataOut);

	success = removeAtIndex(dataOut, index);

	return 0;
}

//*******************************************************************************************************
//	updateAtIndex function
//		updates a value at an index
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: updateAtIndex(const Type &dataIn, int index)
{
	bool success = false;

	if((index >= 0)&&(index < numValues))
    {
		list[index] = dataIn;
		success = true;
	}

	return success;
}

//*******************************************************************************************************
//	updateFront function
//		updates a value at the front of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: updateFront(const Type &dataIn)
{
	bool success = false;

	success = updateAtIndex(dataIn, 0);

	return success;
}

//*******************************************************************************************************
//	updateBack function
//		updates a value at the back of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: updateBack(const Type &dataIn)
{
	bool success = false;

	success = updateAtIndex(dataIn, numValues - 1);

	return success;
}

//*******************************************************************************************************
//	update function
//		finds a value and updates it
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: update(const Type &dataIn, const Type &element)
{
	int index;
	bool success = false;
	index = find(element);

	success = updateAtIndex(dataIn, index);

	return success;
}

//*******************************************************************************************************
//	getSmallest function
//		finds the smallest value in the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: getSmallest(Type &smallest) const
{
	bool success = false;

	if(numValues > 0)
	{
		success = true;
		smallest = list[0]
		for(int i = 1; i < numValues; i++)
		{
			if(smallest > list[i])
				smallest = list[i];
		}
	}
	return success;
}

//*******************************************************************************************************
//	reverse function
//		reverses the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: reverse()
{
	bool success = false;
	Type temp;

	if(numValues > 0)
	{
		success = true;
		for(int i = 0; i < numValues / 2; i++)
		{
			temp = list[i];
			list[i] = list[numValues - 1 - i];
			list[numValues - 1 - i] = temp;
		}
	}

	return success;
}

//*******************************************************************************************************
//	getSecondLargest function
//		finds the second largest value in the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: getSecondLargest(Type &sLarge) const
{
	Type large;
	int index;
    bool success = false;
    if(numValues > 1)
    {
         success = true;
		 large = 0;
         sLarge = 0;
         for(int i = 0; i < numValues; i++)
         {
            if(list[i] > large)
			{
				large = list[i];
				index = i;
			}
				
		 } 
         
         for(int i = 0; i < numValues; i++)
         {
              if((list[i] > sLarge) && (i != index))
                   sLarge = list[i];
         }
	}
    return success;
}


//*******************************************************************************************************
//	display function
//		display array on the screen
//*******************************************************************************************************

template <typename Type>
void ArrList2 <Type> :: display() const
{
	for(int i = 0; i < numValues; i++)
		cout << list[i] << " ";
	cout << endl;
}

//*******************************************************************************************************
//	insertBefore function
//		inserts a value before a certain element of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: insertBefore(const Type &dataIn, const Type &element)
{
	bool success = true;
	int index;

	if(numValues == capacity)
		success = _resize();

	if(success)
	{
		index = find(element);
		if(index != -1)
		{
			numValues++;
			for(int i = numValues; i >= index; i--)
				list[i] = list[i-1];
			list[index] = dataIn;
		}
		
	}
	return success;
}

//*******************************************************************************************************
//	insertAfter function
//		inserts a value after a certain element of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: insertAfter(const Type &dataIn, const Type &element)
{
	bool success = true;
	int index;

	if(numValues == capacity)
		success = _resize();

	if(success)
	{
		index = find(element);

		if(index != -1)
		{
			for(int i = numValues + 1; i > index; i--)
				list[i] = list[i-1];
			list[index+1] = dataIn;
			numValues++;
		}
	}
	
	return success;
}

//*******************************************************************************************************
// insertBack function
//		insert a value at the end of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: insertBack(const Type &dataIn)
{
     bool success = true;

     if(numValues == capacity)
          success = _resize();

	 if(success)
	 {
		list[numValues] = dataIn;

		numValues++;
	 }

     return success;
}

//*******************************************************************************************************
//	insertFront function
//		inserts a value at the beginning of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: insertFront(const Type &dataIn)
{
     bool success = true;

     if(numValues == capacity)
          success = _resize();

	 if(success)
	 {
		 for(int i = numValues; i > 0; i--)
			 list[i] = list[i-1];

		 list[0] = dataIn;

		numValues++;
	 }

     return success;
}

//*******************************************************************************************************
// insertAtIndex function
//		insert a value at a certain index in the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: insertAtIndex(const Type &dataIn, const int index)
{
     bool success = true;

     if(numValues == capacity)
          success = _resize();

     if(success)
     {
          for(int i = numValues; i > index; i--)
               list[i] = list[i-1];
          list[index] = dataIn;
          numValues++;
	 }
	 return success;
}

//*******************************************************************************************************
// retrieveAtIndex
//		retrieve a value from the array at a certain index
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: retrieveAtIndex(const int index, Type &dataOut) const
{
	bool success = false;

	if(index < numValues)
	{
		dataOut = list[index];
		success = true;
	}

	return success;
}

//*******************************************************************************************************
//	getCapacity Accessor
//*******************************************************************************************************

template <typename Type>
int ArrList2 <Type> :: getCapacity()
{
	return capacity;
}

//*******************************************************************************************************
//	getNumValue Accessor
//*******************************************************************************************************

template <typename Type>
int ArrList2 <Type> :: getNumValues()
{
	return numValues;
}

//*******************************************************************************************************
// trimToSize function
//		equals the capacity to the numValue
//*******************************************************************************************************

template <typename Type>
void ArrList2 <Type> :: trimToSize()
{
	capacity = numValues;
}

//*******************************************************************************************************
// clearList function
//		sets the capacity to zero
//*******************************************************************************************************

template <typename Type>
void ArrList2 <Type> :: clearList()
{
	numValues = 0;
}

//*******************************************************************************************************
//	isEmpty function
//		checks if the array is empty
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> :: isEmpty() const
{
	return (numValues == 0);
}

//*******************************************************************************************************
//	find function
//		finds an element in the array
//*******************************************************************************************************

template <typename Type>
int ArrList2 <Type> :: find(const Type &element) const
{
	int index;
	bool found = false;
	for(int i = 0; i < numValues && !found; i++)
	{
		if(element == list[i])
		{
			index = i;
			found = true;
		}
	}

	if(!found)
		index = -1;

	return index;
}

//*******************************************************************************************************
//	_resize function
//		private function that increases the size of the array
//*******************************************************************************************************

template <typename Type>
bool ArrList2 <Type> ::  _resize()
{
     bool success = false;
     Type * tmpList = list;

     capacity = capacity + capacity / 2;
	 
     list = new (nothrow) Type[capacity];
	 
     if(list)
     {
		for(int i = 0; i < numValues; i++)
               list[i] = tmpList[i];
		//delete [] tmpList;
        success  = true;
     }
	 else
		 cerr << capacity << endl;

     return success;
}


