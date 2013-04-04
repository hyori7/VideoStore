#pragma once
#include <iostream>
#include "Movie.h"
const int CAPACITY=100;
using namespace std;

class MovieCollection
{
private:
	int mySize; //current size of list 
	Movie myArray[CAPACITY]; //array to store the list

public:
	/* Pre:  true
	 * Post: construct an empty list
     */
	MovieCollection();

	/* Pre: true
     * Post: return true if the list is empty;
     *		 otherwise, return false.
     */
    bool empty() const;

	/* Pre: true
     * Post: return the size of the collection
     */
	int getMySize() const;

	/* Pre: true
     * Post: Object item is added to the list at the specified
     *       position pos, mySize increases by one
     */
	void insert(Movie item); 

    /* Pre: true 
     * Post: the item at the specified position is removed 
     * 	  from the list, mySize decreases by one
     */
	void erase(string movieTitle); 

	/* Pre: stream is an ostream object 
     * Post: list’s contents have been output to stream
     */
	void display(ostream& stream) const;

	/* an overload for the << operator
	 * Pre: stream is an ostream object, and aCollection is a Movie Collection
     * Post: list’s contents have been output to stream
     */
	friend ostream& operator<<(ostream& stream, const MovieCollection& aCollection);

	/* Pre: index is in range 
     * Post: returns the movie (reference) specified by the index
     */
	Movie * operator[](int i);


	/* Pre: true 
     * Post: list contents have been sorted alphabetically by title
     */
	void sort();

	/* Pre: list is sorted
     * Post: returns the index of the movie with matching title
     */
	int search(string searchTitle);

	/* Pre: true
     * Post: output a list of the top ten rented movies
     */
	void topTen();

	~MovieCollection();
};
