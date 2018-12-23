#include "CodonsTable.h"
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
//constructor and destructor
CodonsTable::CodonsTable()
{

}
CodonsTable::~CodonsTable()
{

}
 //function to load all codons from the given text file
 void CodonsTable::LoadCodonsFromFile(string codonsFileName)
 {
     ifstream in (codonsFileName.c_str());
     int i =0 ;
     Codon c;
     while (!in.eof()) //for i = 0 >> 64
     {
         in >> c.value;
         in >>c.AminoAcid;
         codons[i] = c ;
         i++;
     }
 }

Codon CodonsTable::getAminoAcid(char * value)
{
Codon c;
    char am ;
    for(int i =0 ; i<64 ; i++)
    {
        if(strcmp(value , codons[i].value) == 0 )
        {
            am = codons[i].AminoAcid;
        }
    }
     //strcpy(c.value ,value);
     c.AminoAcid = am;
     return c;
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for (int i = 0 ; i<4 ; i++)
    {
        codons[index].value[i]= value[i] ;
    }
   // codons[index].value= value ;
    codons[index].AminoAcid= AminoAcid ;
}
