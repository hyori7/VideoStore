#pragma once
#include <string>
using namespace std;

class Movie
{
private:
	string title;
	string starring;
	string director;
	string duration;
	string genre;
	string classification;
	string releaseDate;
	int numInStore;
	int numLeased;
	int numTimesRented;
public:
	/* Pre:  true
	 * Post: construct a movie with no details
     */
	Movie(){};

	/* Pre:  true
	 * Post: construct an movie with details
     */
	Movie(string newTitle, string newStarring, string newDirector,
		string newDuration, string newGenre, string newClassification,
		string newReleaseDate);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setTitle(string newTitle);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setStarring(string newStarring);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setDirector(string newDirector);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setDuration(string newDuration);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setGenre(string newGenre);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setClassification(string newClassification);

	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setReleaseDate(string newReleaseDate);

	/* Pre:  true
	 * Post: attribute is updated
     */
	void incNumInStore(int num);

	/* Pre:  true
	 * Post: attribute is updated
     */
	void incNumLeased();

	/* Pre:  true
	 * Post: attribute is updated
     */
	void incNumTimesRented();

	/* Pre:  true
	 * Post: attribute is updated
     */
	void decNumInStore();

	/* Pre:  true
	 * Post: attribute is updated
     */
	void decNumLeased();

	/* Pre:  true
	 * Post: attribute is updated
     */
	void decNumTimesRented();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getTitle() const;

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getStarring();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getDirector();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getDuration();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getGenre();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getClassification();

	/* Pre:  true
	 * Post: attribute is returned
     */
	string getReleaseDate();

	/* Pre:  true
	 * Post: attribute is returned
     */
	int getNumInStore();

	/* Pre:  true
	 * Post: attribute is returned
     */
	int getNumLeased();

	/* Pre:  true
	 * Post: attribute is returned
     */
	int getNumTimesRented();

	/* Pre:  stream is an ostream object
	 * Post: movie's information have been output to stream
     */
	void display(ostream& stream) const;
	
	/* an overload for the << operator
	 * Pre: stream is an ostream object, and aMovie is a Movie object
     * Post: movie's information have been output to stream
     */
	friend ostream& operator<<(ostream& stream, const Movie& aMovie);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the title of the other movie is greater alphabetically
     */
	bool operator<(const Movie& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the title of the other movie is smaller alphabetically
     */
	bool operator>(const Movie& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the titles of both movies are equal alphabetically
     */
	bool operator==(const Movie& other);

	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the titles of both movies are not equal alphabetically
     */
	bool operator!=(const Movie& other);

	~Movie();
};
