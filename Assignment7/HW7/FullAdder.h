#include "systemc.h"

SC_MODULE(FullAdder){
    sc_in<bool> A, B, Cin;				// ports
    sc_out<bool> S, Cout;
    
    void process_FA();

    SC_CTOR(FullAdder) {				// constructor
        SC_METHOD(process_FA);
        sensitive << A << B << Cin;
    }
};
