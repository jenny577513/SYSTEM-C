#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

int main(int argc, char *argv[]){

    ifstream fin;
    unsigned int double_len, str_len;
    
    if(argc != 3){
        cout << "file name not exist or not 2 file" <<endl;
        return 0;
    }

//File 1
    fin.open(argv[1], ios::in);
    if(!fin){
        cout << "File open fail" << endl;
        return 0;
    }
    
    fin >> double_len;
    cout << "Double file length: " << double_len << endl;
    List<double>DList1(double_len); //create List 1 (double)


    while(!fin.eof()) fin >> DList1;
    cout << "Store the inputs into DList1..." << endl;
    cout << "DList1 content: " << DList1<< endl;
    fin.close();
    
//File 2 
    fin.open(argv[2], ios::in);
    if(!fin){
        cout << "File 2 open fail" << endl;
        return 0;
    }

    fin >> str_len;
    cout << "String file length: " << str_len << endl;
    List<string>SList1(str_len); //create List 1 (string)
    
    while(!fin.eof()) fin >> SList1;
    cout << "Store the inputs into SList1..." << endl;
    cout << "SList1 content: " << SList1 << endl;
    fin.close();
    
    //Copy to DList2
    List<double> DList2(DList1);
    cout << "DList2: copy from DList1 (copy constructor)" << endl;
    cout << "DList2 content: " << DList2 << endl;
    
    //Copy to SList2
    List<string> SList2 = SList1;
    cout << "SList2: copy from SList1 (assign)" << endl;
    cout << "SList2 content: " << SList2 << endl;
    
    //Compare
    if(DList1 == DList2)
        cout << "2 double lists are the same\n" << endl;
    else cout << "2 double lists are not the same!\n" << endl;
        
    if(SList1 == SList2)
        cout << "2 String lists are the same\n" << endl;
    else cout << "2 String lists are not the same!\n" << endl;

    //Set element
    DList1.setElement(1,100.58);
    cout << "Set element in DList1: " << DList1 << endl;
    
    DList2.setElement(2,99.99);
    cout << "Set element in DList2: " << DList2 << endl;
    
    SList1.setElement(1,"set");
    cout << "Set element in SList1: " << SList1 << endl;
    
    SList2.setElement(1,"change");
    cout << "Set element in SList2: " << SList2 << endl;

    return 0;

}

