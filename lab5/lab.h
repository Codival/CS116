/*
 *Purpose:
 * contains Shared classes and fucntions for non-SQL commands
 * 
 * NOTE- template functions are in the .h files
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
*/

#pragma once

#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <limits>
#include <sstream>
using namespace std;

void printMeFirst(string, string);
void menu(int &);
void priceComparison(string &,string &,string &);
void scoreComparison(string &,string &,string &);
void vintageComparison(string &,string &, string &);

template< typename T > class List; // forward declaration
class Wine;

template< typename NODETYPE  >
class ListNode 
{

public:
   friend class List< NODETYPE >; // make List a friend
   ListNode( const NODETYPE & ); // constructor
   NODETYPE getData() const; // return the data in the node

/*
 *Purpose:sets the next pointer to the next pointer
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param nPtr- ListNode pointer
 * @return - none
*/
   void setNextPtr( ListNode *nPtr ) 
   { 
      nextPtr = nPtr; 
   }
   
/*
 *Purpose: retrieve the next pointer in the linked list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param - none
 * @return - the next pointer
*/
   ListNode *getNextPtr() const 
   { 
      return nextPtr; 
   }

private:
   NODETYPE data;
   int key;
   ListNode *nextPtr; 
}; 


/*
 *Purpose:Constructs a Linked list Node
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param info- the data we wish to store in the linked list node
 * @return - none
*/
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
{
   data = info;
   nextPtr = 0;
}

/*
 *Purpose:returns a copy of the data in the node
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param -none
 * @return - the data inside a node in the linked list
*/

template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
}


template< typename NODETYPE  >
class List 
{
public:
   List(); 
   List( const List< NODETYPE > & ); 
   ~List(); 

   void insertAtFront( const NODETYPE &, int );
   void insertAtBack( const NODETYPE &, int );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;
   void printPtrFunc(   );
   NODETYPE * getInfo(int myKey);

/*
 *Purpose:get the first pointer in a linked list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param - non
 * @return - the first pointer
*/

   ListNode< NODETYPE >  *getFirstPtr() const 
   { 
      return firstPtr; 
   } 
   
 protected:
   ListNode< NODETYPE > *firstPtr;
   ListNode< NODETYPE > *lastPtr;

   ListNode< NODETYPE > *getNewNode( const NODETYPE &, int );
};

/*
 *Purpose:Create an empty Linked List
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param nPtr- ListNode pointer
 * @return - none
*/
template< typename NODETYPE >
List< NODETYPE >::List() 
{ 
   firstPtr = lastPtr = 0; 
}

/*
 *Purpose:copies a currently existing linked list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param copy - The list we want to copy
 * @return - none
*/
template< typename NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
   firstPtr = lastPtr = 0; // initialize pointers

   ListNode< NODETYPE > *currentPtr = copy.firstPtr;

   // insert into the list
   while ( currentPtr != 0 ) 
   {
      insertAtBack( currentPtr->data );
      currentPtr = currentPtr->nextPtr;
   } // end while
}

/*
 *Purpose:Destroys the List created by the constructors
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param - none
 * @return - none
*/
template< typename NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) 
   {

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )
      {
         tempPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }
   }

}

/*
 *Purpose:Inserts a node at the front of the list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param value - the data we want to add to the linked list
 * @param key - unique key to distinguish data
 * @return - none
*/
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value,
  int key)
{
   ListNode<NODETYPE> *newPtr = getNewNode( value, key );

   if ( isEmpty() ) 
      firstPtr = lastPtr = newPtr;
   else 
   {
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;
   } 
} 

/*
 *Purpose:Insert a node at the back of the list
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param value - the data we want to add to the list
 * @param key - the unique key used to distinguish data
 * @return - none
*/
// Insert a node at the back of the list
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value,
  int key)
{
  
  ListNode<NODETYPE> *newPtr = getNewNode( value, key );
  
  if(isEmpty())
	firstPtr = lastPtr = newPtr;
  
  else
  {
	  lastPtr->nextPtr = newPtr;
	  lastPtr = newPtr;
  }
  
  
  
  
}

/*
 *Purpose:removes a node from the front of a linked list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param value - the location we want the removed data to be saved
 * @return - true
*/
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;

      delete tempPtr;
      return true;
   }
}

/*
 *Purpose:remove a node from the back of a linked list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param value - the location the node data will be placed once deleted
 * @return - true
*/
template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
	
	 
	 
   if ( isEmpty() )
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else 
      {
		  
         ListNode< NODETYPE > *currentPtr = firstPtr;

while(currentPtr->nextPtr != lastPtr)
         {
			 currentPtr = currentPtr->nextPtr;
		 }
		 lastPtr=currentPtr;
		 currentPtr->nextPtr=NULL;
  
      } 

      value = tempPtr->data;
      delete tempPtr;
      return true;
   } 
} 

/*
 *Purpose:Check if the list is Empty
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param - none
 * @return - true if list is empty, false if list is false
*/
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
}

/*
 *Purpose:return a pointer to a newly allocated node
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param value - the data we want to add to the new node
 * @return - the pointer to the new node
*/
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value, int)
{
   ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
   return ptr;
}

/*
 *Purpose:Display the contents of the List
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param - none
 * @return - none
*/
template< typename NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() )
   {
      cout << "The list is empty\n\n";
      return;
   }

   ListNode< NODETYPE > *currentPtr = firstPtr;


   while ( currentPtr != 0 )
   {
       int i;
       string s;
       double d;
       char c;
       if (typeid(currentPtr->data).name() == typeid(i).name() ||
           typeid(currentPtr->data).name() == typeid(d).name() ||
           typeid(currentPtr->data).name() == typeid(s).name() ||
           typeid(currentPtr->data).name() == typeid(c).name())
       {
        cout << currentPtr->data << ' ';
       }
       else {
         cout <<"Can't print - Not a simple data type (int, string, char, double)\n";
       }
      currentPtr = currentPtr->nextPtr;
   }

   cout << "\n\n";
}

/*
 *Purpose:Retrieve the contents of the list
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param key - the unique key for the data
 * @return - NULL if empty or Data in the node
*/   
// Display the contents of the List
template< typename NODETYPE >
NODETYPE * List< NODETYPE >::getInfo(int myKey)
{
   if ( isEmpty() ) // empty list
   {
      //cout << "The list is empty\n\n";
      return NULL;
   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   //cout << "The list is: ";

   while ( currentPtr != 0 ) // display elements in list
   {
        if (currentPtr->key == myKey )  // found
           return (& currentPtr->data);
 
      currentPtr = currentPtr->nextPtr;
   } // end while

   return NULL;  // can't find
}


/*
 *Purpose:Prints the list out
 * 
 * 
 * @author Ron Sha
 * @version 1.0 5/1/2017
 * 
 * @param nodeList - The list we want to print out
 * @return - none
*/
template< typename NODETYPE >
void printNoteInfo (  List< NODETYPE > & nodeList)
{   
   NODETYPE *wp;
   wp = (NODETYPE *) nodeList.getInfo(0); //get node based on key
   //wp->printInfo();
 
 
   ListNode< NODETYPE > *currentPtr;
     
   currentPtr =  nodeList.getFirstPtr();
   
   //cout << "The node list is: \n";
   //print out all the info in linked list
   while ( currentPtr != 0 ) // display elements in list
   {
      wp = (NODETYPE *) currentPtr; //convert to correct data type
      wp->printInfo();
      currentPtr = currentPtr->getNextPtr();
   } // end while
}   


/*
 * 
 * Wine funtions are initialized in their own files
 * 
 * 
*/
class Wine

{
public:

	Wine() {  }

	Wine(string wine_name,string wine_type, int wine_year,

		int wine_rating, double wine_price);

	void setInfo(string wine_name,string wine_type, int wine_year,

		int wine_rating, double wine_price);

	~Wine() { } 

	void setName(string wine_name);

	void setVintage(int wine_year);

	void setRating(int wine_rating);

	void setPrice(double wine_price);

	void setType(string wine_type);


		void printInfo();


	private:

		string wineName, wineType;

		int wineYear, wineRating;

		double winePrice;

};




