#include "RNA.h"
#include <string>
#include <cstring>
using namespace std;
// constructor that sets the RNA type to a default: mRNA
RNA::RNA()
{
  type = mRNA;
}
// constructor that takes sequence and RNA type from the user
RNA::RNA(char * seq, RNA_Type atype)
{
   if(strlen(seq)%3!=0)
    {
        throw RNA_error();
    }
    for (unsigned int i=0 ; i<strlen(seq) ; i++)
    {
        if(seq[i]!='A' && seq[i]!='C' && seq[i]!='G' && seq[i]!='U' )
            throw RNA_error2();
    }


  //strcpy (this->seq, seq);
  this->seq = seq;
  type = atype;
}
RNA::RNA(RNA& rhs)
{
  //strcpy (seq, rhs.seq);
  seq = rhs.seq;
  type = mRNA;
}
// destructor
RNA::~RNA()
{

}
// function print to print the RNA sequence
void RNA::Print()
{
     cout << seq ;
}
Protein RNA::ConvertToProtein(CodonsTable &  table)
{
    Codon a ; // object from struct codon
    Protein obj; //object from protein
    int length = strlen(seq); // length of seq.
    obj.seq = new char [length/3]; // divide sequence to codon
    char* value= new char[3]; // value = 3 chat like AAA
    int k=0;
    for (int i=0; i<length/3; i++)
    {
        // first codon.
        value[0]=seq[k];
        value[1]=seq[k+1];
        value[2]=seq[k+2];
        // second codon
        k+=3;
        a =  table.getAminoAcid(value); // Get amino acid according the value
        obj.seq[i] = a.AminoAcid;  // set every seq to amino acid
    }
    return obj;
}
// converting a RNA sequence to a DNA sequence
DNA RNA::ConvertToDNA()
{
  DNA obj; // object from DNA,
    obj.seq = seq; // and initialize it with the same sequence.
    // loop on the length of seq.
    for (unsigned int i=0; i < strlen(seq); i++)
    {
        // Replace every U with T.
        if (seq[i]=='U')
        {
            obj.seq[i]='T';
        }
        else
        {
            obj.seq[i]=seq[i];
        }
    }
    return obj;
}
