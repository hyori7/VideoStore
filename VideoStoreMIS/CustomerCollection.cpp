#include "CustomerCollection.h"

CustomerCollection::CustomerCollection()
{
	root = 0;
}

bool CustomerCollection::isEmpty() const
{
	return (root == 0);
}

void CustomerCollection::insert(const Customer item)
{
	if(root == 0)
		root = new CustomerCollectionNode(item);
	else
		insert(item, root);	
}

void CustomerCollection::insert(Customer item, CustomerCollectionNode * ptr)
{
	if (item < ptr->getCustomerItem())
	{
		if (ptr->getLChild() == 0)
			ptr->setLChild(new CustomerCollectionNode(item));
		else 
			insert(item, ptr->getLChild());
	}
	else 
	{
		if (ptr->getRChild() == 0)			
			ptr->setRChild(new CustomerCollectionNode(item));
		else 
			insert(item, ptr->getRChild());
	}
}

void CustomerCollection::Delete(Customer item)
{
	// search for item and its parent
	CustomerCollectionNode * ptr = root; // search reference
	CustomerCollectionNode * parent = 0; // parent of ptr
	while((ptr!=0)&&(item != ptr->getCustomerItem()))
	{
		parent = ptr;
		if(item < ptr->getCustomerItem()) // move to the left child of ptr
			ptr = ptr->getLChild();
		else
			ptr = ptr->getRChild();
	}
	if(ptr != 0) // if the search was successful
	{
		// case 3: item has two children
		if((ptr->getLChild() != 0)&&(ptr->getRChild() != 0))
		{
			// find the right-most node in left subtree of ptr
			if(ptr->getLChild()->getRChild() == 0) // a special case
			{
				CustomerCollectionNode * temp = ptr->getLChild();
				ptr->setCustomerItem((ptr->getLChild())->getCustomerItem());
				ptr->setLChild(ptr->getLChild()->getLChild());
				delete temp;
			}
			else 
			{
				CustomerCollectionNode * p = ptr->getLChild()->getRChild();
				CustomerCollectionNode * pp = ptr->getLChild(); // parent of p
				while(p->getRChild() != 0)
				{
					pp = p;
					p = p->getRChild();
				}
				// copy the item at p to ptr
				Customer temp = p->getCustomerItem();
				ptr->setCustomerItem (temp);
				CustomerCollectionNode * temp_pointer = p->getLChild();
				pp->setRChild (temp_pointer);
				delete p;
			}
		}
		else // cases 1 & 2: item has no or only one child
		{
			CustomerCollectionNode * c;
			if(ptr->getLChild() != 0) c = ptr->getLChild();
			else
				c = ptr->getRChild();
			// remove node ptr
			if(ptr == root) //need to change root
				root = c;
			else
				if(ptr == parent->getLChild()) parent->setLChild (c);
				else
					parent->setRChild (c);
			delete ptr;
		}
	}
}

bool CustomerCollection::exists(string customerName) const
{
	return exists(customerName, root);
}

bool CustomerCollection::exists(string customerName, CustomerCollectionNode * r) const
{
	if(r != 0)
	{
		Customer tempCustomer = r->getCustomerItem();
		string tempName = tempCustomer.getName();
		if(customerName == tempName)
			return true;
		else
			if(customerName < tempName)
			return exists(customerName, r->getLChild());
		else
			return exists(customerName, r->getRChild());
	}
	else
		return false;
}

void CustomerCollection::showCustomerPhone(string customerName)
{
	showCustomerPhone(customerName, root);
}

void CustomerCollection::showCustomerPhone(string customerName,
											   CustomerCollectionNode * r)
{
	Customer tempCustomer = r->getCustomerItem();
	string tempName = tempCustomer.getName();
	int tempPhone = tempCustomer.getPhone();
	if(customerName == tempName) {
		cout << tempPhone << endl << endl;
	} else if(customerName < tempName) {
		showCustomerPhone(customerName, r->getLChild());
	} else {
		showCustomerPhone(customerName, r->getRChild());
	}
}

MovieCollection CustomerCollection::getCustomerRented(string customerName)
{
	return getCustomerRented(customerName, root);
}

MovieCollection CustomerCollection::getCustomerRented(string customerName,
											   CustomerCollectionNode * r)
{
	Customer tempCustomer = r->getCustomerItem();
	string tempName = tempCustomer.getName();
	if(customerName == tempName) {
		MovieCollection * tempMovies = tempCustomer.getRentedMovies();
		return *tempMovies;
	} else if(customerName < tempName) {
		getCustomerRented(customerName, r->getLChild());
	} else {
		getCustomerRented(customerName, r->getRChild());
	}
}

void CustomerCollection::listCustomerWithMovie(string movieName)
{
	cout << "Customers who rented " << movieName << ":" <<endl;
	listCustomerWithMovie(movieName, root);
	cout << endl;
}

void CustomerCollection::listCustomerWithMovie(string movieName,
											   CustomerCollectionNode * r)
{
	if(r != 0)
	{
		listCustomerWithMovie(movieName, r->getLChild());

		Customer tempCustomer = r->getCustomerItem();
		MovieCollection * tempMovies = tempCustomer.getRentedMovies();
		if(tempMovies->search(movieName) != -1) {
			cout << tempCustomer.getName() << endl;
		}

		listCustomerWithMovie(movieName, r->getRChild());
	}
}

void CustomerCollection::leaseMovie(string customerName, Movie movieItem)
{
	leaseMovie(customerName, movieItem, root);
}

void CustomerCollection::leaseMovie(string customerName, Movie movieItem,
									CustomerCollectionNode * r)
{
	Customer tempCustomer = r->getCustomerItem();
	string tempName = tempCustomer.getName();
	if(customerName == tempName) {
		tempCustomer.getRentedMovies()->insert(movieItem);
		r->setCustomerItem(tempCustomer);
	} else if(customerName < tempName) {
		leaseMovie(customerName, movieItem, r->getLChild());
	} else {
		leaseMovie(customerName, movieItem, r->getRChild());
	}
}

void CustomerCollection::returnMovie(string customerName, Movie movieItem)
{
	leaseMovie(customerName, movieItem, root);
}

void CustomerCollection::returnMovie(string customerName, Movie movieItem,
									CustomerCollectionNode * r)
{
	Customer tempCustomer = r->getCustomerItem();
	string tempName = tempCustomer.getName();
	if(customerName == tempName) {
		tempCustomer.getRentedMovies()->erase(movieItem.getTitle());
		r->setCustomerItem(tempCustomer);
	} else if(customerName < tempName) {
		returnMovie(customerName, movieItem, r->getLChild());
	} else {
		returnMovie(customerName, movieItem, r->getRChild());
	}
}

void CustomerCollection::destructor(const CustomerCollectionNode * r)
{
	if(r!=0)
	{
		destructor( r->getLChild());
		destructor( r->getRChild());
		delete r;
	}
}

CustomerCollection::~CustomerCollection()
{
	destructor(root);
}
