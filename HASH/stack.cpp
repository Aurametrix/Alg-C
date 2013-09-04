#include <iostream>

using namespace std;

#define MAX 10        // MAXIMUM STACK CONTENT

class stack

{
  private:
    int arr[MAX];   // Contains all the Data
    int top;        //Contains location of Topmost Data pushed onto Stack
  public:
     stack()         //Constructor
     {
        top=-1;      //Sets the Top Location to -1 indicating an empty stack
     }
     void push(int a)  // Push ie. Add Value Function
     {
        top++;        // increment to by 1
        if(top<MAX)
         {
            arr[top]=a;  //If Stack is Vacant store Value in Array
         }
         else
         {
            cout<<"STACK FULL!!"<<endl;
            top--;
         }
     }
    int pop()                  // Delete Item. Returns the deleted item
    {
        if(top==-1)
        {
            cout<<"STACK IS EMPTY!!!"<<endl;
            return NULL;
        }
        else
        {
            int data=arr[top];     //Set Topmost Value in data
            arr[top]=NULL;       //Set Original Location to NULL
            top--;               // Decrement top by 1
            return data;         // Return deleted item
        }
     }
};

int main()
{
 stack a;
 a.push(3);
 cout<<"3 is Pushed\n";
 a.push(10);
 cout<<"10 is Pushed\n";
 a.push(1);
 cout<<"1 is Pushed\n\n";
 cout<<a.pop()<<" is Popped\n";
 cout<<a.pop()<<" is Popped\n";
 cout<<a.pop()<<" is Popped\n";
 return 0;
}