#include "Customer.h"

Customer::Customer(string newName, string newAddress, int newPhone)
{
	customerName = newName;
	customerAddress = newAddress;
	phoneNumber = newPhone;
}

void Customer::setName(string newName)
{
	customerName = newName;
}

void Customer::setAddress(string newAddress)
{
	customerAddress = newAddress;
}

void Customer::setPhone(int newPhone)
{
	phoneNumber = newPhone;
}

void Customer::rentMovie(Movie newMovie)
{
	rentedMovies.insert(newMovie);
}

void Customer::returnMovie(Movie oldMovie)
{
	string movieName = oldMovie.getTitle();
	rentedMovies.erase(movieName);
}

string Customer::getName(void) const
{
	return customerName;
}

string Customer::getAddress(void)
{
	return customerAddress;
}

int Customer::getPhone(void)
{
	return phoneNumber;
}

MovieCollection * Customer::getRentedMovies(void)
{
	return &rentedMovies;
}

bool Customer::operator<(const Customer& other) {
    return getName() < other.getName();
}

bool Customer::operator>(const Customer& other) {
    return getName() > other.getName();
}

bool Customer::operator==(const Customer& other) {
    return getName() == other.getName();
}

bool Customer::operator!=(const Customer& other) {
    return !(*this == other);
}

Customer::~Customer(void)
{
}
