#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence<char>
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * seq, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
        class RNA_error{
        public:
            const char * ShowError()
            {
                return "Error length must be divisible by 3 ";
            }
            };
        class RNA_error2
            {
            public:
              const char * ShowError()
              {
                return "Error sequence must contain A,C,G,U only";
              }
            };

 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable &  table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};

#endif // RNA_H
