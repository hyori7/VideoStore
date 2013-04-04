#pragma once
#include <string>
#include "Customer.h"
using namespace std;

class CustomerCollectionNode
{
private:
	Customer customerItem;	// data
	CustomerCollectionNode * lChild; // left child pointer
	CustomerCollectionNode * rChild; // right child pointer
public:
	//pre: true
	//post: a node for CustomerCollection is created, the data of the node is
	//      initialised with item, and the left and right child pointers are null
	CustomerCollectionNode(Customer item);

	//pre: true
	//post: the data in the node is replaced by the data in the formal parameter
	void setCustomerItem(const Customer& item);

	//pre: true
	//post: the left child pointer is replaced by node
	void setLChild(CustomerCollectionNode* node);

	//pre: true
	//post: the right child pointer is replaced by p
	void setRChild(CustomerCollectionNode* node);

	//pre: true
	//post: return the data stored in the node
	Customer getCustomerItem() const;

	//pre: true
	//post: return the left child pointer
	CustomerCollectionNode* getLChild() const;

	//pre: true
	//post: return the right child pointer
	CustomerCollectionNode* getRChild() const;

	//pre: true
	//post: destroy the node and reclaim the memory used by the node
	virtual ~CustomerCollectionNode();
};
