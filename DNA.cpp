#include "DNA.h"
#include "RNA.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
// DNA constructor that creates a new strand that points to DNA
// and sets the DNA type to its default: promoter
DNA::DNA()
{
    type = promoter;
    startIndex = 0;
    endIndex = 0;
}
// constructor that creates a DNA sequence
// takes a sequence from user and points it to a new DNA sequence
// and sets the DNA type to what the user entered
DNA::DNA(char * seq, DNA_Type atype)
{
    if(strlen(seq)%3!=0)
    {
        throw DNA_error();
    }
    for (unsigned int i=0 ; i < strlen(seq) ; i++)
    {
        if(seq[i]!='A' && seq[i]!='C' && seq[i]!='G' && seq[i]!='T' )
            throw DNA_error2();
    }

  //strcpy (this->seq, seq);
  this->seq = seq;
  type = atype;
}
DNA::DNA(DNA& rhs)
{
  //strcpy (seq, rhs.seq);
  seq = rhs.seq;
  type = promoter;
}
// destructor to delete all the data stored as DNA
DNA::~DNA()
{

}
// function print to print the DNA sequence
void DNA::Print()
{
    cout << seq ;
}
// Converting DNA sequence to RNA sequence
// take one strand and changing every T with a U
// and store it in aa a RNA sequence. (sends it to RNA class)
RNA DNA::ConvertToRNA()
{
  RNA obj; // object from RNA,
  obj.seq = seq;// and initialize it with the same sequence.
    // loop on the length of seq.
    for (unsigned int i = 0; i < strlen(seq); i++)
    {
        if (seq[i] == 'T') // Replace every T with U.
        {
            obj.seq[i] = 'U';
        }
        else
        {
            obj.seq[i] = seq[i];
        }
    }

    return obj; //return obj.
}
// function to build a second strand for the DNA entered if user
// entered one strand only.
void DNA::BuildComplementaryStrand()
{
  for(unsigned int i =0 ; i< strlen(seq) ; i++)
  {
      if(seq[i] == 'T')
      {
         seq[i] = 'A';
      }
      else if(seq[i] == 'A')
      {
         seq[i] = 'T';
      }

      else if(seq[i] == 'C')
      {
         seq[i] = 'G';
      }
      else if(seq[i] == 'G')
      {
         seq[i] = 'C';
      }
  }
}
DNA& DNA::operator=(const DNA& rhs)
{
    delete [] seq;
    seq = new char [strlen(rhs.seq)];
    //strcpy (seq,rhs.seq);
    seq = rhs.seq;
    type=rhs.type;
    return *this ;
}

ostream& operator<<(ostream& out,const DNA& D)
{
    out << D.seq << "  " << D.type << endl;
    return out ;
}
istream& operator>>(istream& in,DNA& D)
{
    in >> D.seq ;
    return in ;
}
