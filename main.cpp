#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include <string>
using namespace std;

int main()
{
    Sequence  <char>*  seq ;
    char ch ;
    do {
    cout << "\nEnter the sequence or enter E to exit: \n";
    cout << "1- DNA \n2- RNA \n3- Protein\n";
    cin >> ch ;
    if (ch== '1')
        {
            char * c = new char [100];
            try{
                cout << "Enter DNA Sequence(A,C,G,T) \n";
                cin >> c ;
                seq = new DNA (c , promoter);
            }
            catch (DNA::DNA_error x)
            {
                    cout << x.ShowError();
                    break;
            }
            catch (DNA::DNA_error2 x)
            {
                    cout << x.ShowError();
                    break;
            }
            DNA D (c,promoter);
            int ch1;
            cout<<"select what you want to do with the sequence you entered: \n";
            cout<<" 1- convert to RNA \n 2- convert to protein \n 3- compare to another DNA sequence \n " <<
            "4- check if your DNA equals another DNA "<<endl ;
            cin>>ch1;
             if (ch1 == 1)
                 {
                     RNA R;
                     R = D.ConvertToRNA();
                     cout << "Convert DNA To RNA : ";
                     R.Print();
                     }
            if (ch1 == 2)
                    {
                          RNA R ;
                          R = D.ConvertToRNA();
                          Protein p;
                          CodonsTable C;
                          C.LoadCodonsFromFile("codon.txt");
                          p= R.ConvertToProtein(C);
                          cout << "Convert DNA To Protein : ";
                          p.Print();
                    }

            if (ch1 == 3)
                    {
                       D.LCSAlignment();
                    }
              if (ch1 == 4) {
                cout << "Enter the other DNA :" ;
                char * k = new char [100];

            try{
                cin >> k ;
                seq = new DNA (k , promoter);
            }
            catch (DNA::DNA_error x)
            {
                    cout << x.ShowError();
                    break;
            }
            catch (DNA::DNA_error2 x)
            {
                    cout << x.ShowError();
                    break;
            }
            DNA D2 (k,promoter);
            if (D == D2)
            {
                cout << "they are equal " << endl ;
            }
            else
              cout << "they are not equal " << endl ;
              }
             }
    else if (ch == '2')
        {
            char * c = new char [100];
            try{
                cout << "Enter RNA Sequence(A,C,G,U) \n";
                cin >> c ;
                seq = new RNA(c , mRNA);
            }
            catch (RNA::RNA_error x)
            {
                    cout << x.ShowError();
                    break;
            }
            catch (RNA::RNA_error2 x)
            {
                    cout << x.ShowError();
                    break;
            }
            int ch1;
            DNA D ;
            RNA R(c,mRNA);
            Protein p;
            cout<<"select what you want to do with the sequence you entered: \n";
            cout<<" 1- convert to DNA \n 2- convert to protein \n 3- compare to another RNA sequence \n"<<
            " 4- check if your RNA = another RNA "<<endl ;
            cin>>ch1;
             if (ch1 == 1) {
            D = R.ConvertToDNA();
            cout << "Convert RNA To DNA : ";
            D.Print();
            cout<<endl;
            }
            if (ch1 == 2) {
            CodonsTable C;
            C.LoadCodonsFromFile("codon.txt");
            p=R.ConvertToProtein(C);
            cout << "Convert RNA To Protein : ";
            p.Print();
            }
            if (ch1 == 3) {
            R.LCSAlignment();
            }
            if (ch1 == 4)  {
                char * F = new char [100];
            try{
                cout << "Enter the other RNA : ";
                cin >> F ;
                seq = new RNA (F , mRNA);
            }
            catch (RNA::RNA_error x)
            {
                    cout << x.ShowError();
                    break;
            }
            catch (RNA::RNA_error2 x)
            {
                    cout << x.ShowError();
                    break;
            }
            RNA R2(F,mRNA);
            if (R == R2)
            {
                cout << "they are equal " << endl ;
            }
            else
              cout << "they are not equal " << endl ;
              }
            }
    else if (ch == '3')
        {
            char * c = new char [100];
            try{
                cout << "Enter protein Sequence(A,C,G,T) \n";
                cin >> c ;
                seq = new Protein (c , Hormon);
            }
            catch (Protein::protein_error x)
            {
                    cout << x.ShowError();
                    break;
            }
            catch (Protein::protein_error2 x)
            {
                cout << x.ShowError();
                break;
            }
            int ch1 ;
            cout << "1 - Get DNA Strands Encoding " << endl ;
            cin >> ch1 ;
            if (ch1 == 1) {
            DNA a ;
            Protein p (c,Hormon);
            p.GetDNAStrandsEncodingMe(a);
        }
     }}
    while (ch != 'E') ;
    return 0;
}
