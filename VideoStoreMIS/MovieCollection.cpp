#include "MovieCollection.h"
#include "Movie.h"
#include <iostream>

MovieCollection::MovieCollection()
{
	mySize = 0;
}

bool MovieCollection::empty() const
{
	return mySize == 0;
}

int MovieCollection::getMySize() const
{
	return mySize;
}

void MovieCollection::display(ostream& stream) const
{
	stream << "---------------------Movies---------------------" << endl;
	for (int i = 0; i < mySize; i++)
	{
		Movie tempMovie = myArray[i];
		stream << tempMovie.getTitle() << " : ";
		stream << tempMovie.getNumInStore() << " copies in store" << endl;
	}
	stream << endl;
}

ostream& operator<<(ostream& stream, const MovieCollection& aCollection)
{
	aCollection.display(stream);
	return stream;
}

Movie * MovieCollection::operator[](int i)
{
	return &myArray[i];
}

void MovieCollection::insert(Movie item)
{
	//checking to see if array is full
	if (mySize == CAPACITY)
	{
		cout << "No space for list element -- terminating "
				"execution" << endl << endl;
		return;
	}

	//adds the new item to end of list and then sort the list
	myArray[mySize] = item;
	mySize++;
	sort();
}

void MovieCollection::erase(string movieTitle)
{
	int eraseIndex;
	eraseIndex = search(movieTitle);

	//shift array elements left and decrease list size
	for (int i = eraseIndex; i < mySize; i++)
	{
		myArray[i] = myArray[i+1];
	}
	mySize--;
}

void MovieCollection::sort()
{
	for (int i=1; i < mySize; i++)
	{
		Movie tempMovie = myArray[i];
		int j = i-1;
		while (j >= 0 && tempMovie < myArray[j])
		{
			myArray[j+1] = myArray[j];
			j = j-1;
		}
		myArray[j+1] = tempMovie;
	}
}

//the search method accepts a string parameter and returns the index value
//of the movie inside the list
int MovieCollection::search(string searchTitle)
{
	int first = 0; int last = mySize-1;
	while (first <= last)
	{
		int middle = (first+last)/2;
		Movie tempMovie = myArray[middle];
		if (tempMovie.getTitle() == searchTitle) {
			return middle;
		} else if (searchTitle < tempMovie.getTitle()) {
			last = middle-1;
		} else {
			first = middle+1;
		}
	}
	return -1;
}

void MovieCollection::topTen()
{
	//creating a copy of the array
	Movie tempArray[CAPACITY];
	for (int i=0; i < mySize; i++)
	{
		tempArray[i] = myArray[i];
	}
	//sort the copied array by the number of times rented in descending order
	for (int i=1; i < mySize; i++)
	{
		Movie tempMovie = tempArray[i];
		int j = i-1;
		while (j >= 0 && tempMovie.getNumTimesRented() >
			tempArray[j].getNumTimesRented())
		{
			tempArray[j+1] = tempArray[j];
			j = j-1;
		}
		tempArray[j+1] = tempMovie;
	}

	//output the first 10 movies of the array (if available)
	int iterations = 10;
	if (mySize < 10) {
		iterations = mySize;
	}
	cout << "--------------------Top Ten---------------------" << endl;
	for (int i=0; i < iterations; i++)
	{
		cout << "Movie: " << tempArray[i].getTitle() << "       ";
		cout << "Times Rented: " << tempArray[i].getNumTimesRented() << endl;
	}
	cout << "------------------------------------------------" << endl << endl;
}

MovieCollection::~MovieCollection()
{
}
