#include "Movie.h"

Movie::Movie(string newTitle, string newStarring, string newDirector,
		string newDuration, string newGenre, string newClassification,
		string newReleaseDate)
{
	title = newTitle;
	starring = newStarring;
	director = newDirector;
	duration = newDuration;
	genre = newGenre;
	classification = newClassification;
	releaseDate = newReleaseDate;
	numInStore = 1;
	numLeased = 0;
	numTimesRented = 0;
}

void Movie::setTitle(string newTitle)
{
	title = newTitle;
}

void Movie::setStarring(string newStarring)
{
	starring = newStarring;
}

void Movie::setDirector(string newDirector)
{
	director = newDirector;
}

void Movie::setDuration(string newDuration)
{
	duration = newDuration;
}

void Movie::setGenre(string newGenre)
{
	genre = newGenre;
}

void Movie::setClassification(string newClassification)
{
	classification = newClassification;
}

void Movie::setReleaseDate(string newReleaseDate)
{
	releaseDate = newReleaseDate;
}

void Movie::incNumInStore(int num)
{
	numInStore = numInStore + num;
}

void Movie::incNumLeased()
{
	numLeased++;
}

void Movie::incNumTimesRented()
{
	numTimesRented++;
}

void Movie::decNumInStore()
{
	numInStore--;
}

void Movie::decNumLeased()
{
	numLeased--;
}

void Movie::decNumTimesRented()
{
	numTimesRented--;
}

string Movie::getTitle() const
{
	return title;
}

string Movie::getStarring()
{
	return starring;
}

string Movie::getDirector()
{
	return director;
}

string Movie::getDuration()
{
	return duration;
}

string Movie::getGenre()
{
	return genre;
}

string Movie::getClassification()
{
	return classification;
}

string Movie::getReleaseDate()
{
	return releaseDate;
}

int Movie::getNumInStore()
{
	return numInStore;
}

int Movie::getNumLeased()
{
	return numLeased;
}

int Movie::getNumTimesRented()
{
	return numTimesRented;
}

void Movie::display(ostream& stream) const
{
	stream << "------------------------------------------------" << endl;
	stream << "Title: " << title << endl;
	stream << "Starring: " << starring << endl;
	stream << "Director: " << director << endl;
	stream << "Duration: " << duration << endl;
	stream << "Genre: " << genre << endl;
	stream << "Classification: " << classification << endl;
	stream << "Release Date: " << releaseDate << endl;
	stream << "Num In Store: " << numInStore << endl;
	stream << "Num Leased: " << numLeased << endl;
	stream << "------------------------------------------------" << endl;
	stream << endl;
}

ostream &operator<<(ostream& stream, const Movie& aMovie)
{
	aMovie.display(stream);
	return stream;
}

bool Movie::operator<(const Movie& other) {
    return getTitle() < other.getTitle();
}

bool Movie::operator>(const Movie& other) {
    return getTitle() > other.getTitle();
}

bool Movie::operator==(const Movie& other) {
    return getTitle() == other.getTitle();
}

bool Movie::operator!=(const Movie& other) {
    return !(*this == other);
}

Movie::~Movie()
{
}
