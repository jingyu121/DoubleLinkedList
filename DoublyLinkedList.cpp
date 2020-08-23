// programming assignment 3

#include "DoublyLinkedList.h"
#include <stdexcept>


// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  // Copy from dll
  Node* temp = other.dll;
	while (temp != nullptr) {
		this->insertLast(temp->newobj);
		temp = temp->next;
		temp->previous = temp;
	}
trailer= temp;
  // Complete this function
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
	clear();
	// Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  // Copy from dll
  Node* temp = other.dll;
	while (temp != nullptr) {
		this->insertLast(temp->newobj);
		temp = temp->next;
		temp->previous = temp;
	}
trailer= temp;
  // Complete this function
}

// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
  // Complete this function
}

// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  // Complete this function
}

// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
return count;
  // Complete this function
}

// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  
  return count;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
	Node* newNode;

	newNode = dll.header;

	while (newNode != nullptr)
	{
		out << newNode->newobj<<" ";
		newNode = newNode->next;
	}
  // Complete this function
  return out;
}
