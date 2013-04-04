#pragma once
#include <string>
#include "MovieCollection.h"
#include "Movie.h"
using namespace std;

class Customer
{
private:
	string customerName;
	string customerAddress;
	int phoneNumber;
	MovieCollection rentedMovies;
public:
	/* Pre:  true
	 * Post: construct a customer with no details
     */
	Customer(){};

	/* Pre:  true
	 * Post: construct a customer object with details
     */
	Customer(string newName, string newAddress, int newPhone);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setName(string newName);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setAddress(string newAddress);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setPhone(int newPhone);

	/* Pre:  parameter is of valid type
	 * Post: movie added to customer's collection, which is reflected through
	 *		 an update of the movie's numInStore and numLeased attribute of the
	 *		 store's collection
     */
	void rentMovie(Movie newMovie);

	/* Pre:  parameter is of valid type
	 * Post: movie removed from customer's collection, which is reflected through
	 *		 an update of the movie's numInStore and numLeased attribute of the
	 *		 store's collection
     */
	void returnMovie(Movie oldMovie);

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getName(void) const;

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getAddress(void);

	/* Pre:  true
	 * Post: attribute is returned
     */
	int getPhone(void);

	/* Pre:  true
	 * Post: movie collection (reference) is returned
     */
	MovieCollection * getRentedMovies(void) ;

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the name of the other customer is greater alphabetically
     */
	bool operator<(const Customer& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the name of the other customer is smaller alphabetically
     */
	bool operator>(const Customer& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the names of both customers are equal alphabetically
     */
	bool operator==(const Customer& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the names of both customers are not equal alphabetically
     */
	bool operator!=(const Customer& other);

	~Customer(void);
};
