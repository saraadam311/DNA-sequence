#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include <iostream>
using namespace std;

class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class Protein : public Sequence<char>{
private:
    Protein_Type type;
public:
    // constructors and destructor
    Protein();
    Protein(char* p, Protein_Type atype);
    ~Protein();
    Protein& operator=(const Protein&);
    friend ostream& operator<<(ostream& ,const Protein&);
    friend istream& operator>>(istream& ,Protein&);
    void Print();
    // return an array of DNA sequences that can possibly generate
    // that protein sequence
    DNA* GetDNAStrandsEncodingMe(DNA & bigDNA);
    class protein_error{
      public:
            const char * ShowError()
            {
                return "Error length must be divisible by 3.";
            }};
    class protein_error2
    {
    public:
              const char * ShowError()
              {
                return "Error sequence must contain A,C,G,T only";
              }
    };
};
#endif // PROTEIN_H
