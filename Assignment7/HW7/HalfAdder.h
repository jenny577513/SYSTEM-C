#include "systemc.h"

SC_MODULE(HalfAdder){
    sc_in<bool> A, B;				// ports
    sc_out<bool> Carry, Sum;
    
    void process_HA();

    SC_CTOR(HalfAdder) {				// constructor
        SC_METHOD(process_HA);
        sensitive << A << B;
    }
};
