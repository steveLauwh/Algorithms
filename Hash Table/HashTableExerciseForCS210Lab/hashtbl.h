//--------------------------------------------------------------------
//
//  Laboratory 12                                          hashtbl.h
//
//  Class declaration for the Hash Table ADT
//
//--------------------------------------------------------------------

#include <stdexcept>
#include "listlnk.cpp"

using namespace std;

template < class DT, class KF >
class HashTbl
{
    public:
        HashTbl ( int initTableSize );
        ~HashTbl ();

        void insert ( const DT &newDataItem) throw ( bad_alloc );
        bool remove ( KF searchKey );
        bool retrieve ( KF searchKey, DT &dataItem );
        void clear ();

        bool isEmpty () const;
        bool isFull () const;

        void showStructure () const;

    private: 
        int tableSize;
        List<DT> *dataTable;
};
