#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

int main(int argc, char *argv[]){

    ifstream fin;
    ofstream fout;
    //cout << "ENTER" << endl;
    
    if(argc != 2){
        cout << "file name not exist" <<endl;
        return 1;
    }

    fin.open(argv[1], ios::in);
    if(!fin){
        cout << "File open fail" << endl;
        return 1;
    }

    fout.open("RESULT.", ios::out);
    if(!fout){
        cout << "output file open fail" << endl;
        return 1;
    }

    unsigned int flen;
    fin >> flen;
    fout << "Total file length: " << flen << endl;

    List L_ori(flen); //List_original

    while(!fin.eof()) fin >> L_ori;
    fout << "Store the inputs into Original List (L_ori)..." << endl;
    fout << "L_ori content: " << L_ori;
    fout << "Size of L_ori: " << L_ori.getLength() << endl << endl;
    fin.close();

    fout << "Copy the content to 3 Lists:" << endl << endl;

    List L1(flen);
    for(unsigned int i=0; i<flen; i++)
        L1.setElement(i, L_ori.getElement(i));

    fout << "L1: copy from L_ori (for loop)" << endl;
    fout << "L1 content: " << L1;
    fout << "L1 size: " << L1.getLength() << endl << endl;

    List L2 = L_ori;
    fout << "L2: copy from L_ori (assign)" << endl;
    fout << "L2 content: " << L2;
    fout << "L2 size: " << L2.getLength() << endl << endl;

    List L3(L_ori);
    fout << "L3: copy from L_ori (copy constructor)" << endl;
    fout << "L3 content: " << L3;
    fout << "L3 size: " << L3.getLength() << endl << endl;

    fout << "\nImplement Function:\n"<< endl;
    //add
    L3 = L1 + L2;
    fout << "Add 2 lists: L3 = L1+L2" << endl;
    fout << "L3 content: " << L3;
    fout << "L3 size: " << L3.getLength() << endl << endl;

    L3 = L_ori;
    fout << "Reset L3 (by assign)" << endl;
    fout << "L3 content: " << L3;
    fout << "L3 size: " << L3.getLength() << endl << endl;

    //add 1(postfix)
    L3++;
    fout << "Add 1 (postfix): L3 ++" << endl;
    fout << "L3 content: " << L3;
    fout << "L3 size: " << L3.getLength() << endl << endl;

    //sub 1(prefix)
    --L3;
    fout << "Substract 1 (prefix): --L3" << endl;
    fout << "L3 content: " << L3;
    fout << "L3 size: " << L3.getLength() << endl << endl;

    //+=
    L1 += L2;
    fout << "L1 += L2" << endl;
    fout << "L1 content: " << L1;
    fout << "L1 size: " << L1.getLength() << endl;


    fout.close();

    return 0;

}

