#include "Protein.h"
#include "RNA.h"
#include "DNA.h"
#include "CodonsTable.h"
#include <cstring>
#include <iostream>
using namespace std;
Protein::Protein()
{

}
Protein::Protein(char* p, Protein_Type atype)
{

    //strcpy (seq, p );
    seq = p;
    type = atype ;
}
Protein::~Protein()
{

}
Protein& Protein::operator=(const Protein& rhs)
{
    delete [] seq;
    seq = new char [strlen(rhs.seq)];
    //strcpy (seq,rhs.seq);
    seq= rhs.seq;
    type=rhs.type;
    return *this ;
}
ostream& operator<<(ostream& out,const Protein& p)
{
    out << p.seq << "  " << p.type << endl;
    return out ;
}
istream& operator>>(istream& in,Protein& R)
{
    in >> R.seq ;
    return in ;
}
void Protein::Print()
{
    cout <<seq << endl;
}
// return an array of DNA sequences that can possibly generate
// that protein sequence
DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA)
{
    DNA * D = new DNA [100] ;
    char * temp = new char [100];
    int n =0 ;
    for(unsigned int i = 0 ; i < strlen(bigDNA.seq)-2 ; i++ )
    {
        int k=0;
        for (unsigned int j = i ; j < i+3 ; j++)
        {
            temp[k] = bigDNA.seq[j];
            k++;
        }
        CodonsTable  co;
        for(int m =0 ; m<10 ; m++)
        {
            if(strcmp (co.codons[m].value, temp ) == 0 )
            {
                for(unsigned int a=0 ; a<strlen(seq) ; a++)
                {
                    if(co.codons[m].AminoAcid == seq[a])
                    {
                        //strcpy(D[n].seq,temp) ;
                        D[n].seq = temp;
                        n++;
                    }
                }

            }
        }
    }
    return D ;
}
