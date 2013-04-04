// VideoStoreMIS.cpp : Defines the entry point for the console application.
#include "Movie.h"
#include "Customer.h"
#include "MovieCollection.h"
#include "CustomerCollection.h"
#include <iostream>
#include <limits> // for declaration of 'numeric_limits'
#include <ios> // for declaration of 'streamsize'
#include <string>
using namespace std;


int main()
{
	MovieCollection storeMovies;
	CustomerCollection storeCustomers;
    string next;

	int menuChoice = 0;
	while (menuChoice != 12)
	{
		menuChoice = 0;
		cout << "PLEASE SELECT AN OPTION FROM THE MENU:" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1. Browse store movies" << endl;
		cout << "2. Display movie information" << endl;
		cout << "3. Add movie " << endl;
		cout << "4. Remove movie" << endl;
		cout << "5. Add customer" << endl;
		cout << "6. Display customer's phone number" << endl;
		cout << "7. Display customer's rented movies" << endl;
		cout << "8. Lease movie" << endl;
		cout << "9. Return movie" << endl;
		cout << "10. List customers renting a specific movie" << endl;
		cout << "11. Top 10 movies" << endl;
		cout << "12. Exit" << endl << endl;
		cout << "Choice #: ";
		cin >> menuChoice;
		cout << endl;

		while (menuChoice < 1 || menuChoice > 12) {
			//clears the iostream buffer if an error occurs (invalid inputs)
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//prompt for a retry
			cout << "Please supply an integer between 1 and 12: "; 
			cin >> menuChoice;
			cout << endl;
		}

        
		if (menuChoice == 1) //Browse store movies
		{
            do{
			cout << storeMovies;
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next!= "y");
		}

		if (menuChoice == 2) //Display movie information
		{
            
			string movieTitle;
			int movieIndex;

			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter the movie title: ";
			getline(cin, movieTitle);
			cout << endl;
			movieIndex = storeMovies.search(movieTitle);
			if (movieIndex == -1) {
				cout << "The movie does not exist in the store's collection";
				cout << endl << endl;
			} else {
				cout << *storeMovies[movieIndex];
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");

		}

		if (menuChoice == 3) //Add movie
		{
			int number = 0;
			string title;
			string starring;
			string director;
			string duration;
			string genre;
			string classification;
			string releaseDate;

			cout << "enter the number of movies you want to enter the system: ";
			cin >> number;
			while (number < 1 || number > 10) {
				//clears the iostream buffer if an error occurs (invalid inputs)
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//prompt for a retry
				cout << "Please supply an integer between 1 and 10: "; 
				cin >> number;
				cout << endl;
			}
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (storeMovies.getMySize() + number > CAPACITY)
			{
				cout << "No enough space left for the specified number of";
				cout << " movies" << endl << endl;
			}
			else
			{
				for (int i=0; i < number; i++) {
					cout << "Movie " << i << " details" << endl;
					cout << "---------------" << endl;
					cout << "enter the title: ";
					getline(cin, title);

					//checking if movie already exists
					int movIndex = storeMovies.search(title);
					if (movIndex == -1) {
						//movie doesn't exists, create new movie object
						cout << "enter the starring: ";
						getline(cin, starring);
						cout << "enter the director: ";
						getline(cin, director);
						cout << "enter the duration: ";
						getline(cin, duration);
						cout << "enter the genre: ";
						getline(cin, genre);
						cout << "enter the classification: ";
						getline(cin, classification);
						cout << "enter the release date: ";
						getline(cin, releaseDate);
						Movie tempMovie (title,starring,director,duration,genre,
							classification,releaseDate);
						storeMovies.insert(tempMovie);
						cout << "Movie added" << endl << endl;
					} else {
						//movie already exists, ask if new copies are desired
						string answer;
						cout << "Movie already exists, add new copies? (y/n)";
						getline(cin, answer);
						while (answer != "y" && answer != "n") {
							cout << "Please provide 'y' or 'n' as answer: ";
							getline(cin, answer);
						}
						if (answer == "y") {
							int numCopies = 0;
							cout << "Enter the number of copies: ";
							cin >> numCopies;
							while (numCopies < 1 || numCopies > 100) {
								//clears the iostream buffer if an error occurs (invalid inputs)
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								//prompt for a retry
								cout << "Please supply an integer between 1 and 100: "; 
								cin >> numCopies;
								cout << endl;
							}
							storeMovies[movIndex]->incNumInStore(numCopies);
							cout << "Copies added" << endl << endl;
						} else {
							cout << "Movie not added" << endl << endl;
						}
					}
				}
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}// end of menuChoice 3

		if (menuChoice == 4) //Remove movie
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string movieTitle;
			cout << "Enter the movie title: ";
			getline(cin, movieTitle);
			cout << endl;
			
			//checking if movie exists
			int eraseIndex;
			eraseIndex = storeMovies.search(movieTitle);
			if (eraseIndex == -1) {
				cout << "The movie does not exist in the store's collection, ";
				cout << "action terminated.";
				cout << endl << endl;
			} else {
				//checking if all copies are in store
				int numLeased;
				numLeased = storeMovies[eraseIndex]->getNumLeased();
				if (numLeased != 0) {
					cout << "Not all copies of the movie are in store, ";
					cout << "action terminated.";
					cout << endl << endl;
				} else {
					storeMovies.erase(movieTitle);
					cout << "Movie removed" << endl << endl;
				}
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 5) //Add Customer
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string name;
			string address;
			int phone;

			cout << "Enter customer name: ";
			getline(cin, name);
			if (storeCustomers.exists(name)) {
				cout << "Customer already exists" << endl << endl;
			} else {
				cout << "Enter address: ";
				getline(cin, address);
				cout << "Enter phone number: ";
				cin >> phone;
				cout << endl;

				Customer newCustomer (name,address,phone);
				storeCustomers.insert(newCustomer);
				cout << "Customer added" << endl << endl;
                cout<<"Name: "<<newCustomer.getName()<<endl;
                cout<<"Address: "<<newCustomer.getAddress()<<endl;
                cout<<"Phone: "<<newCustomer.getPhone()<<endl<<endl;
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 6) //Display customer's phone number
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string cName;
			cout << "Enter the customer name: ";
			getline(cin, cName);
			if (storeCustomers.exists(cName)) {
				storeCustomers.showCustomerPhone(cName);
			} else {
				cout << cName << " is not registered" << endl << endl;
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 7) //Display customer's rented movies
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string cName;
			cout << "Enter the customer name: ";
			getline(cin, cName);
			if (storeCustomers.exists(cName)) {
				MovieCollection customerMovies;
				customerMovies = storeCustomers.getCustomerRented(cName);
				cout << customerMovies;
			} else {
				cout << cName << " is not registered" << endl << endl;
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 8) //Lease movie
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string cName;
			cout << "Enter the customer name: ";
			getline(cin, cName);
			if (!storeCustomers.exists(cName)) {
				//customer doesn't exist
				cout << cName << " is not registered, action terminated.";
				cout << endl << endl;
			} else {
				string movieTitle;
				cout << "Enter the movie title: ";
				getline(cin, movieTitle);
				int movieIndex = storeMovies.search(movieTitle);
				if (movieIndex == -1) {
					//movie not found
					cout << "Movie does not exist, action terminated.";
					cout << endl << endl;
				} else {
					if (storeMovies[movieIndex]->getNumInStore() < 1) {
						//no copies in store
						cout << "No copies in store, action terminated.";
						cout << endl << endl;
					} else {
						storeCustomers.leaseMovie(cName, *storeMovies[movieIndex]);
						cout << "Movie leased" << endl << endl;
						//updating statistics
						storeMovies[movieIndex]->decNumInStore();
						storeMovies[movieIndex]->incNumLeased();
						storeMovies[movieIndex]->incNumTimesRented();
                        //display leased movies
                        MovieCollection customerMovies;
				        customerMovies = storeCustomers.getCustomerRented(cName);
				        cout << customerMovies; 
					}
				}
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 9) //Return movie
		{
			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			string cName;
			cout << "Enter the customer name: ";
			getline(cin, cName);
			if (!storeCustomers.exists(cName)) {
				//customer doesn't exist
				cout << cName << " is not registered, action terminated.";
				cout << endl << endl;
			} else {
				string movieTitle;
				cout << "Enter the movie title: ";
				getline(cin, movieTitle);
				int movieIndex = storeMovies.search(movieTitle);
				if (movieIndex == -1) {
					//movie not found in store database
					cout << "Movie does not exist, action terminated.";
					cout << endl << endl;
				} else {
					MovieCollection customerMovies;
					customerMovies = storeCustomers.getCustomerRented(cName);
					int eraseIndex = customerMovies.search(movieTitle);
					if (eraseIndex == -1) {
						//customer isn't renting the movie
						cout << "Customer did not rent this movie, ";
						cout << "action terminated." << endl << endl;
					} else {
						storeCustomers.returnMovie(cName, *storeMovies[movieIndex]);
						cout << "Movie return" << endl << endl;
					}
				}
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 10) //List customers renting a specific movie
		{
			string movieTitle;
			int movieIndex;

			//clears the iostream buffer for getline() to work properly
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter the movie title: ";
			getline(cin, movieTitle);
			cout << endl;
			movieIndex = storeMovies.search(movieTitle);
			if (movieIndex == -1) {
				cout << "The movie does not exist in the store's collection";
				cout << endl << endl;
			} else {
				storeCustomers.listCustomerWithMovie(movieTitle);
                //cout<<storeCustomers.listCustomerWithMovie(); 
			}
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

		if (menuChoice == 11) //Top 10 movies
		{
			storeMovies.topTen();
            do{
            cout<<"Enter 'y' to continue: ";
            cin>>next;
            }while(next != "y");
		}

	
	}//exit loop when menuChoice is 12 (exit)
	
	cout << "--------Provide an input to end programm--------" << endl;
	string exit;
	cin >> exit;

	return 0;
}

