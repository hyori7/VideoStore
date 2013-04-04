#pragma once
#include <string>
#include "CustomerCollectionNode.h"
#include "MovieCollection.h"
#include "Customer.h"
using namespace std;

class CustomerCollection
{
private:
	CustomerCollectionNode * root; //the root of the BST
public:
	// pre: true
	// post: create an object of CustomerCollection
	CustomerCollection();

	// pre: true
	// post: return true if the collection is empty; otherwise, return false
	bool isEmpty() const;

	// pre: true
	// post: item is added to the collection
	void insert(const Customer item);

	// recursion component of the Insert method
	// pre: true
	// post: item is added to the collection
	void insert(Customer item, CustomerCollectionNode * ptr);

	// pre: true
	// post: an occurrence of the item is removed from the collection if found    
	void Delete(const Customer item);
	
	// checks to see if a customer exists in the list that has
	// the specified name
	// pre: true
	// post: return true if item is in the collection;
	//	     otherwise, return false.
	bool exists(string customerName) const;

	// recursive component of the exists method
	// pre: true
	// post: return true if item is in the collection;
	//	     otherwise, return false.
	bool exists(string customerName, CustomerCollectionNode * r) const;

	// displays the phone number of the customer with the specified name
	// pre: true
	// post: displays the phone number
	void showCustomerPhone(string customerName);

	// recursive component of showCustomerPhone
	// pre: true
	// post: displays the phone number
	void showCustomerPhone(string customerName, CustomerCollectionNode * r);

	// returns the rented movies of the customer with the specified name
	// pre: true
	// post: returns the rented movies
	MovieCollection getCustomerRented(string customerName);

	// recursive component of getCustomerRented
	// pre: true
	// post: returns the rented movies
	MovieCollection getCustomerRented(string customerName, CustomerCollectionNode * r);

	// output a list of customer that is currently
	// renting the specified movie
	// pre: true
	// post: outputs the list
	void listCustomerWithMovie(string movieName);

	// recursive component of the listCustomerWithMovie method
	// pre: true
	// post: outputs the list
	void listCustomerWithMovie(string movieName, CustomerCollectionNode * r);

	// adds a movie to the specified customer's collection
	// pre: true
	// post: movie is added
	void leaseMovie(string customerName, Movie movieItem);

	// recursive component to the leaseMovie method
	// pre: true
	// post: movie is added
	void leaseMovie(string customerName, Movie movieItem, CustomerCollectionNode * r);

	// return a movie from the specified customer's collection
	// pre: true
	// post: movie is returned
	void returnMovie(string customerName, Movie movieName);

	// recursive component to the returnMovie method
	// pre: true
	// post: movie is returned
	void returnMovie(string customerName, Movie movieItem, CustomerCollectionNode * r);

	// pre: true
	// post: all the nodes in the collection are removed and the collection 
	//	  becomes empty
	void clear();

	// a method that aids the destructor to delete all nodes
	// pre: true
	// post: all the nodes in the collection are removed and the memory 
	//		 used by the the nodes are released
	void destructor(const CustomerCollectionNode * r);

	// pre: true
	// post: destroy the object and reclaim the memory used by the object
	virtual ~CustomerCollection();
};
