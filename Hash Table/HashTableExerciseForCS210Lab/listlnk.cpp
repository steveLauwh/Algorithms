//--------------------------------------------------------------------
//
//  Laboratory 7                                         listlnk.cpp
//
//  SOLUTION: Linked list implementation of the List ADT
//
//--------------------------------------------------------------------

#include <new>
#include <iostream>
#include <stdexcept>
#include "listlnk.h"

using namespace std;

//--------------------------------------------------------------------

template < class DT >
ListNode<DT>:: ListNode ( const DT &nodeDataItem, ListNode<DT> *nextPtr )

// Creates a list node containing item elem and next pointer
// nextPtr.

  : dataItem(nodeDataItem),
    next(nextPtr)
{}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: List ( int ignored )

// Creates an empty list. The argument is included for compatibility
// with the array implementation and is ignored.

  : head(0),
    cursor(0)
{}

//--------------------------------------------------------------------

template < class DT >
List<DT>:: ~List ()

// Frees the memory used by a list.

{
    clear ();
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insert ( const DT &newDataItem ) throw ( bad_alloc )

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
    if ( head == 0 )             // Empty list
    {
       head = new ListNode<DT>(newDataItem,0);
       cursor = head;
    }
    else                         // After cursor
    {
       cursor->next = new ListNode<DT>(newDataItem,cursor->next);
       cursor = cursor->next;
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: remove () throw ( logic_error )

// Removes the item marked by the cursor from a list. Moves the
// cursor to the next item in the list. Assumes that the first list
// item "follows" the last list item.

{
    ListNode<DT> *p,   // Pointer to removed node
                 *q;   // Pointer to prior node

    // Requires that the list is not empty
    if ( head == 0 )
        throw logic_error ("list is empty");

    if ( cursor == head )             // Remove first item
    {
       p = head;
       head = head->next;
       cursor = head;
    }
    else if ( cursor->next != 0 )     // Remove middle item
    {
       p = cursor->next;
       cursor->dataItem = p->dataItem;
       cursor->next = p->next;
    }
    else                              // Remove last item
    {
       p = cursor;
       for ( q = head ; q->next != cursor ; q = q->next );
       q->next = 0;
       cursor = head;
    }

    delete p;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: replace ( const DT &newDataItem )
    throw ( logic_error )

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
    // Requires that the list is not empty
    if ( head == 0 )
        throw logic_error ("list is empty");

    cursor->dataItem = newDataItem;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: clear ()

// Removes all the items from a list.

{
    ListNode<DT> *p,      // Points to successive nodes
                 *nextP;  // Points to next node
    p = head;
    while ( p != 0 )
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    head = 0;
    cursor = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool List<DT>:: isEmpty () const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
    return ( head == 0 );
}

//--------------------------------------------------------------------

template < class DT >
bool List<DT>:: isFull () const

// Returns true if a list is full. Otherwise, returns false.

{
    // This is a somewhat hacked way to test if the list is full.
    // If a node can be successfully allocated than the list is not
    // full.  If the allocation fails it is implied that there is no
    // more free memory therefore the list is full.
    
    DT testDataItem;
    ListNode<DT> *p;
    

    try
    {
        p = new ListNode<DT>(testDataItem, 0);
    }
//    catch ( bad_alloc &e )
	catch ( bad_alloc)
    {
        return true;
    }

    delete p;
    return false;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: gotoBeginning () throw ( logic_error )

// If a list is not empty, then moves the cursor to the beginning of
// the list 

{
   if ( head != 0 )
      cursor = head;
   else
      throw logic_error ("list is empty");

}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: gotoEnd () throw ( logic_error )

// If a list is not empty, then moves the cursor to the end of the
// list and returns 1. Otherwise, returns 0.

{
   int result;   // Result returned

   if ( head != 0 )
      for (   ; cursor->next != 0 ; cursor = cursor->next );
   else
      throw logic_error ("list is empty");

}

//--------------------------------------------------------------------

template < class DT >
bool List<DT>:: gotoNext ()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns 1. Otherwise,
// returns 0.

{
   bool result;   // Result returned

   if ( cursor->next != 0 )
   {
      cursor = cursor->next;
      result = true;
   }
   else
      result = false;

   return result;
}

//--------------------------------------------------------------------

template < class DT >
bool List<DT>:: gotoPrior ()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns 1.
// Otherwise, returns 0.

{
   ListNode<DT> *p;   // Pointer to prior node
   int result;        // Result returned

   if ( cursor != head )
   {
      for ( p = head ; p->next != cursor ; p = p->next );
      cursor = p;
      result = true;
   }
   else
      result = false;

   return result;
}

//--------------------------------------------------------------------

template < class DT >
DT List<DT>:: getCursor () const throw ( logic_error )

// Returns the item marked by the cursor.

{
    // Requires that the list is not empty
    if ( head == 0 )
        throw logic_error("list is empty");

    return cursor->dataItem;
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: showStructure () const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    ListNode<DT> *p;   // Iterates through the list

    if ( head == 0 )
       cout << "Empty list" << endl;
    else
    {
       for ( p = head ; p != 0 ; p = p->next )
           if ( p == cursor )
              cout << "[" << p->dataItem << "] ";
           else
              cout << p->dataItem << " ";
       cout << endl;
    }
}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>:: moveToBeginning() throw ( logic_error )

// Removes the item marked by the cursor from a list and
// reinserts it at the beginning of the list. Moves the cursor to the
// beginning of the list.

{
    ListNode<DT> *p;   //  Pointer to prior node

    // Requires that the list is not empty
    if ( head == 0 )
        throw logic_error("list is empty");

    if ( cursor != head)
    {
        for ( p = head ; p->next != cursor ; p = p->next );
        p->next = cursor->next;
        cursor->next = head;
        head = cursor;
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insertBefore ( const DT &newDataItem )
    throw ( bad_alloc )

// Inserts newDataItem before the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
    if ( head == 0 )             // Empty list
    {
       head = new ListNode<DT>(newDataItem, 0);
       cursor = head;
    }
    else                         // Before cursor
    {
       cursor->next = new ListNode<DT>(cursor->dataItem, cursor->next);
       cursor->dataItem = newDataItem;
    }
}
