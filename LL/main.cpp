/*************************
* linked list is a data structure consisting of a group of nodes which together represent a sequence.
* Linear singly-linked list consists of a number of data elements in which 
* each data element has a next pointer or next reference (the link) to the element that follows. 
* The last element in the list has an empty or null link.
*
*
In C or C++, an element’s next pointer and the data the element holds are usually bound together as a single unit:
*******************************************************/

/*
typedef struct IntElement { 
    struct IntElement *next; 
    int data;
} IntElement;

*/

/*********************      
* Placing the next pointer at the beginning of the structure or class makes it easy to 
* write generic list- handling routines that work no matter what data the element holds.
*
* Because the links in a singly-linked list consist only of next pointers (or references), 
* the list can be traversed only in the forward direction, so a complete traversal of the list 
* must begin with the first element. In other words, you need a pointer or reference 
* to the first element of a list in order to locate all the elements in the list. 
* Consequently, the term linked list is often used as shorthand for the first element of a linked list.
* If a function takes a linked list as an argument, it takes a pointer/reference 
* to the first element of a linked list as an argument.
* The first element of a singly-linked list is referred to as the head of the list; 
* the last element is referred to as the tail element.
********/


/**
 * A sample code of Creating C++ linked lists,
 * Including definitions the list node class and linked list class,
 * and how to create a blank linked list and a one-node linked list.
 *
 * Outline: understand the definition and structure of the linked
 * list and build a linked list based on it.
 */

#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

/*
 A linked list is a list constructed using pointers. It is not fixed in
 size and could grow and shrink while the program is running.
 
 A typical defination of list nodes contains at least two parts, both the
 content or date of each element and the pointer to the next element,
 which is shown in the figure below.
 
 +---------+
 |  Data   | -----> holds the data of this element in the list.
 +---------+
 | pointer | -----> is a pointer to the next element in the list.
 +---------+
 
 ***Attention***:
 The pointer holds the address of the next element, not the address of the
 data in the next element, even though they are the same in value sometimes.
 And It should be set to NULL while acting as the last node of the list.
 
 
 Implementation of the single linked list:
 +---------+    --->+---------+    --->+---------+
 |  Data   |    |   |  Data   |    |   |  Data   |
 +---------+    |   +---------+    |   +---------+
 | pointer |-----   | pointer |-----   | pointer |
 +---------+        +---------+        +---------+
 */


/* definition of the list node class */
class Node
{
    friend class LinkedList;
private:
    int _value; /* data, can be any data type, but use integer for easiness */
    Node *_pNext; /* pointer to the next node */
    
public:
    /* Constructors with No Arguments */
    Node(void)
    : _pNext(NULL)
    { }
    
	/* Constructors with a given value */
    Node(int val)
    : _value(val), _pNext(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next)
    : _value(val), _pNext(next)
    {}
    
    /* Getters */
    int getValue(void)
    { return _value; }
    
    Node* getNext(void)
    { return _pNext; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *_pHead;
    /* pointer of tail node */
    Node *_pTail;
    
public:
    /* Constructors with No Arguments */
    LinkedList(void);
    /* Constructors with a given value of a list node */
    LinkedList(int val);
	/* Destructor */
    ~LinkedList(void);
    
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
};

LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    _pHead = _pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

LinkedList::~LinkedList()
{
    /*
     * Leaving it empty temporarily.
     * Will add more here to explain "How to delete a linkedlist".
     */

}

void LinkedList::traverse_and_print()
{
    Node *p = _pHead;
    
    /* The list is empty? */
    if (_pHead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    
    cout << "LinkedList: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value */
        cout << p->_value;
        /* The pointer moves along to the next one */
        p = p->_pNext;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    /* Create an empty list */
    LinkedList list1;
    cout << "Created an empty list named list1." << endl;
    /* output the result */
    cout << "list1:" << endl;
    list1.traverse_and_print();
    
    /* Create a list with only one node */
    LinkedList list2(10);
    cout << "Created a list named list2 with only one node." << endl;
    /* output the result */
    cout << "list2:" << endl;
    list2.traverse_and_print();
    
    return 0;
}



