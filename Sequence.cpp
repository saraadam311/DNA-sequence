#include "Sequence.h"
#include <string.h>
using namespace std;
template <class T>
Sequence<T>::Sequence()
{
    seq = new T [100];
}
template <class T>
Sequence<T>::Sequence(int length)
{
    seq = new T [length];
}
template <class T>
Sequence<T>::Sequence(Sequence& rhs)
{
  seq = new T [strlen(rhs.seq)];
  strcpy(seq , rhs.seq) ;
}
// destructor to delete the data entered
template <class T>
Sequence<T>::~Sequence()
{
    delete [] seq;
}

template <class T>
bool Sequence<T>::operator==(const Sequence<T>& S)
{
    bool x = false; // bool variable
    int length1 = strlen(S.seq); // the length of seq1
    int length2 = strlen(seq); // the length of seq

    if (length1 == length2)
    {
        for(int i = 0; i < length1; i++)
        {
            if(S.seq[i] == seq[i])
                x = true; // x become true.
            else
                x = false;
        }
        if (x) // if x true
            return true;
        else
            return false;

    }
    else
        return false;
}
template <class T>
bool Sequence<T>::operator!=(const Sequence<T>& S)
{
     bool x = false; // bool variable
    int length1 = strlen(S.seq);// the length of seq1
    int length2 = strlen(seq);  // the length of seq
    if (length1 == length2)
    {
        for(int i = 0; i < length1; i++)
        {
            if(S.seq[i] == seq[i])
                x = true; // x become true.
            else
                x = false;
        }
        if (x) // if x true
            return false;
        else
            return true;

    }
    else
        return true;
}
template <class T>
Sequence<T>& Sequence<T>::operator+(const Sequence<T>& S)
{

    seq=concat(seq,S.seq);
    return *this;

}
template <class T>
ostream& operator<<(ostream& out,const Sequence<T>& S)
{
    out << S.seq << endl;
    return out ;

}
template <class T>
istream& operator>>(istream& in,Sequence<T>& S)
{
    in>>S.seq ;
    return in ;

}
template <class T>
Sequence<T>& Sequence<T>::operator=(const Sequence<T>& rhs)
{
    delete [] seq;

    seq = new T [strlen(rhs.seq)];
    strcpy (seq,rhs.seq);

    return *this ;
}



template <class T>
void Sequence <T> :: LCSAlignment ()
///AATGCT
///TAATGT


{
    cout << "Enter the other sequance please: \n";
    string seq2;
    string lcs="";
    cin >> seq2;
    int counter=strlen(seq);
    for (int i=seq2.size();i>=0;i--)
    {
        for (int j=counter;j>=0;j--)
        {
            if (seq[j]==seq2[i])
            {
                lcs+=seq2[i];
                counter=j--;
                break;
            }
        }
    }
    cout << "The LCS Alignment is: " ;
    for (int i = lcs.size() ; i>=0; i--) {
        cout << lcs[i] ;
    }
    cout << endl ;
}
