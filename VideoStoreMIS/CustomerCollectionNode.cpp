#include "CustomerCollectionNode.h"

CustomerCollectionNode::CustomerCollectionNode(Customer newItem)
{
	customerItem = newItem;
	lChild = 0;
	rChild = 0;
}

void CustomerCollectionNode::setCustomerItem(const Customer& item)
{
	customerItem = item;
}

void CustomerCollectionNode::setLChild(CustomerCollectionNode* node)
{
	lChild = node;
}

void CustomerCollectionNode::setRChild(CustomerCollectionNode* node)
{
	rChild = node;
}

Customer CustomerCollectionNode::getCustomerItem() const
{
	Customer anItem = customerItem; // copy constructor
	return anItem;
}

CustomerCollectionNode* CustomerCollectionNode::getLChild() const
{
	CustomerCollectionNode * node = lChild;
	return node;
}

CustomerCollectionNode* CustomerCollectionNode::getRChild() const
{
	CustomerCollectionNode * node = rChild;
	return node;
}

CustomerCollectionNode::~CustomerCollectionNode()
{
}
