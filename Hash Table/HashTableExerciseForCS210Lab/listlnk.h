//--------------------------------------------------------------------
//
//  Laboratory 7                                           listlnk.h
//
//  Class declarations for the linked list implementation of the
//  List ADT
//
//--------------------------------------------------------------------
#pragma warning( disable : 4290 )  // 编译器警告

#include <new>
#include <stdexcept>

using namespace std;

template < class DT >         // Forward declaration of the List class
class List;

template < class DT >
class ListNode                // Facilitator class for the List class
{
private:

    // Constructor
    ListNode ( const DT &nodeData, ListNode *nextPtr );

    // Data members
    DT dataItem;      // List data item
    ListNode *next;   // Pointer to the next list node

    friend class List<DT>;
};

//--------------------------------------------------------------------

template < class DT >
class List
{
public:

    // Constructor
    List ( int ignored = 0 );

    // Destructor
    ~List ();

    // List manipulation operations
    void insert ( const DT &newData )        // Insert after cursor
        throw ( bad_alloc );
    void remove ()                           // Remove data item
        throw ( logic_error );
    void replace ( const DT &newData )       // Replace data item
        throw ( logic_error );
    void clear ();                           // Clear list

    // List status operations
    bool isEmpty () const;                   // List is empty
    bool isFull () const;                    // List is full

    // List iteration operations
    void gotoBeginning ()                    // Go to beginning
        throw ( logic_error );
    void gotoEnd ()                          // Go to end
        throw ( logic_error );
    bool gotoNext ();                        // Go to next data item
    bool gotoPrior ();                       // Go to prior item
    DT getCursor () const                    // Return item
        throw ( logic_error );

    // Output the list structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    void moveToBeginning ()                    // Move to beginning
        throw ( logic_error );
    void insertBefore ( const DT &newElement ) // Insert before cursor
        throw ( bad_alloc );

private:

    // Data members
    ListNode<DT> *head,     // Pointer to the beginning of the list
                 *cursor;   // Cursor pointer
};
