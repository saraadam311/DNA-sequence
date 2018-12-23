#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;
template <class T>
class Sequence
{
    public:
        T * seq;
       // constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);
        Sequence<T>& operator=(const Sequence<T>&);
        Sequence<T>& operator+(const Sequence<T>&);
        bool operator==(const Sequence<T>&);
        bool operator!=(const Sequence<T>&);
        friend ostream& operator<<(ostream& ,const Sequence<T>&);
        friend istream& operator>>(istream& ,Sequence<T>&);
        void LCSAlignment ();
};
#endif // SEQUENCE_H
