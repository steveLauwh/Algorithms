#include <stdexcept>
#include <new>
#include <cstring>
#include <cmath>
#include "hashtbl.h"

using namespace std;

template < class DT, class KF >
HashTbl<DT,KF>:: HashTbl ( int initTableSize )
    : tableSize(initTableSize)
{
    dataTable = new List<DT>[tableSize];
}

template < class DT, class KF >
HashTbl<DT,KF>:: ~HashTbl ()
{
    delete[] dataTable;
}

template < class DT, class KF >
void HashTbl<DT,KF>:: insert ( const DT &newDataItem ) throw ( bad_alloc )
{
	// apply two hash functions: 1. convert string (username) to integer
	// 2. use the division method (% tableSize) to get the index
    int index = newDataItem.hash(newDataItem.getKey()) % tableSize;

    if ( dataTable[index].isEmpty() )
        dataTable[index].insert( newDataItem );
    else
    {
        dataTable[index].gotoBeginning();
		//if there is a linked list at that index, then cycle through the linked
		//list until you reach the end of the link
        do
        {
			//if you find the exact same username, then replace it
            if ( dataTable[index].getCursor().getKey() == newDataItem.getKey() )
            {
                dataTable[index].replace( newDataItem );
                return;
            }
        } while ( dataTable[index].gotoNext() );
		//then insert the data (Password stuff) into the HashTable
        dataTable[index].insert( newDataItem );
    }
}

template < class DT, class KF >
bool HashTbl<DT,KF>:: remove ( KF searchKey )
{
    DT temp;
    int index = temp.hash( searchKey ) % tableSize;

    if ( dataTable[index].isEmpty() )
        return false;

    dataTable[index].gotoBeginning();
    do 
    {
        if ( dataTable[index].getCursor().getKey() == searchKey )
        {
            dataTable[index].remove();
            return true;
        }
    } while ( dataTable[index].gotoNext() );

    return false;
}

template < class DT, class KF >
bool HashTbl<DT,KF>:: retrieve ( KF searchKey, DT &dataItem )
{
	// apply two hash functions: 1. convert string (searchkey) to integer
	// 2. use the division method (% tableSize) to get the index
    int index = dataItem.hash ( searchKey ) % tableSize;

	//if there is nothing at that index, then the searchkey isn't in the
	//table
    if ( dataTable[index].isEmpty() )
        return false;

    dataTable[index].gotoBeginning();
	//cycle through the linked list comparing the names (the keys)
    do 
    {
        if ( dataTable[index].getCursor().getKey() == searchKey )
        {
			//a match has been found, store it in dataitem so that you 
			//can compare the password information in main
            dataItem = dataTable[index].getCursor();
            return true;
        }
    } while ( dataTable[index].gotoNext() );

    return false;
}

template < class DT, class KF >
void HashTbl<DT,KF>:: clear ()
{
    for (int i=0; i<tableSize; i++)
    {
        dataTable[i].clear();
    }
}

template < class DT, class KF >
bool HashTbl<DT,KF>:: isEmpty () const
{
    for (int i=0; i<tableSize; i++)
    {
        if ( ! dataTable[i].isEmpty() )
            return false;
    }

    return true;
}

template < class DT, class KF >
bool HashTbl<DT,KF>:: isFull () const
{
    for (int i=0; i<tableSize; i++)
    {
        if ( ! dataTable[i].isFull() )
            return false;
    }

    return true;
}

template < class DT, class KF >
void HashTbl<DT,KF>:: showStructure() const
{
	cout << "The Hash Table has the following entries" <<endl;
    for ( int i=0; i<tableSize; i++ )
    {
        cout << i << ": ";
        if ( dataTable[i].isEmpty() )
            cout << "_";
        else
        {
            dataTable[i].gotoBeginning();
            do
            {
                cout << dataTable[i].getCursor().getKey() << " ";
            } while ( dataTable[i].gotoNext() );
        }
        cout << endl << endl;
    }
}
