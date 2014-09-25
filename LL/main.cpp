/*************************
* linked list is a data structure consisting of a group of nodes which together represent a sequence.
* Linear singly-linked list consists of a number of data elements in which 
* each data element has a next pointer or next reference (the link) to the element that follows. 
* The last element in the list has an empty or null link.
*
*
In C or C++, an element’s next pointer and the data the element holds are usually bound together as a single unit:
*******************************************************/
 
typedef struct IntElement { 
    struct IntElement *next; 
    int data;
} IntElement;



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