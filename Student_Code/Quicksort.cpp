/*
 * Quicksort.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: msivraj
 */

#include "Quicksort.h"
#include <sstream>
#include <iostream>
#include <string>

namespace std {

Quicksort::Quicksort() {
	globalCapacity = 0;
	theArray = NULL;
	globalIndex = 0;
	// TODO Auto-generated constructor stub
}

Quicksort::~Quicksort() {
	// TODO Auto-generated destructor stub
	if (theArray != NULL) {
		delete[] theArray;  // When done, free memory pointed to by a.
		theArray = NULL;
	}


}

void Quicksort::swap(int &val1, int &val2) {
	int temp = val1;
	val1 = val2;
	val2 = temp;
}


void Quicksort::setCapacity(int capacityIn) {
	globalCapacity = capacityIn;
}

void Quicksort::setVector(vector<int> vectIn)
{
	string nums=getArray();

	theVector=vectIn;
}
void Quicksort::sortAll()
{

	int temp;
	for (int i = 0; i < globalIndex; i++) {
		for (int j = globalIndex - 1; j > i; j--) {
			if (theArray[j] < theArray[j - 1]) {
				temp = theArray[j - 1];
				theArray[j - 1] = theArray[j];
				theArray[j] = temp;
			}
		}
	}

}


int Quicksort::medianOfThree(int left, int right)
{
	string sortedData;
	//bool whatToPrint = false;
	int middle = (left + right) / 2;
	if (getSize() == 0 || left >= right || left < 0 || right >= getSize()) {
		return -1;
	}

	if (theArray[left] > theArray[middle]) {
		int leftVal = theArray[left];
		theArray[left] = theArray[middle];
		theArray[middle] = leftVal;
	} else if (theArray[middle] > theArray[right]) {
		int middleVal = theArray[middle];
		theArray[middle] = theArray[right];
		theArray[right] = middleVal;
	}
	return middle;
}



int Quicksort::partition(int left, int right, int pivotIndex)
{


	if (globalIndex == 0 || left >= right || left < 0 || right >= globalIndex
			|| pivotIndex < left
			|| pivotIndex > right) {
		return -1;
	}

	int countUp = left;
	int countDown = right;
	int newPivotIndex = pivotIndex;

	while (countUp <= countDown)
	{
		/*for (int i = 0; i < right; i++) {
			cout << theArray[i] << "[" << i << "],";
		}
		cout << "left" << left << " " << "right" << right << " " << "pivotIndex"
				<< pivotIndex;
		cout
				<< "\n----------------------" << countUp << "," << countDown
		 << "-------------------------------------------------------------------------------------------------------------------\n";*/

		if (countUp == countDown) {
			break;
		}
		while (theArray[countUp] < theArray[newPivotIndex]) {
			countUp++;
		}
		while (theArray[countDown] > theArray[newPivotIndex]) {
			countDown--;
		}
		int countUpVal = theArray[countUp];
		theArray[countUp] = theArray[countDown];
		theArray[countDown] = countUpVal;
		if (countUp == newPivotIndex) {
			newPivotIndex = countDown;
		} else if (countDown == newPivotIndex) {
			newPivotIndex = countUp;
		}

	}

	return newPivotIndex;
}
int Quicksort::getSize()
{
	return globalIndex;
}
string Quicksort::getArray()
{

	/*stringstream ss;
		for (int i=0;i<theVector.size();i++)
		{
		int val = theVector[i];
		if (theVector.size() == 0) {
			//ss << val;
		}
		else {
			ss << val << ",";
		}
		}
	string theArray = ss.str();
	if (theArray.size() >= 2) {
		theArray.erase(theArray.size() - 1);
	 }*/

	stringstream ss;
	for (int i = 0; i < globalIndex; i++) {
		int val = theArray[i];
		if (getSize() == 0) {
			ss << val;
		} else {
			ss << val << ",";
		}
	}
	string strArray = ss.str();
	if (strArray.size() >= 2) {
		strArray.erase(strArray.size() - 1);
	}


//cout << "the array" << theArray;

	return strArray;
}
void Quicksort::addToArray(int value)
{
	/*if (theVector.size() == 0 && value == 5) {
		;
	}
	else {
		theVector.push_back(value);
	 }*/
	if (theArray != NULL && globalIndex < globalCapacity) {
		theArray[globalIndex] = value;
		globalIndex++;

	}

	
	//cout << "the size" << theVector.size();
}
bool Quicksort::createArray(int capacity)
{
	if (capacity <= 0) {
		return false;
	}
	clear();
	setCapacity(capacity);
	//theArray[capacity];

	theArray = new int[capacity];
	return true;
}
void Quicksort::clear()
{
	if (theArray != NULL) {
		delete[] theArray;  // When done, free memory pointed to by a.
		theArray = NULL;
		setCapacity(0);
		globalIndex = 0;
	}
	//theVector.clear();

}


} /* namespace std */
