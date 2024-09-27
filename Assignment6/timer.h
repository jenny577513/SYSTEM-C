#include "systemc.h"

SC_MODULE(timer) {
    sc_in<bool> start;				// ports
    sc_out<bool> timeout;
    sc_in<bool> clock;
    sc_in<bool> reset;

    int count;					// data and function members
    void runtimer();

    SC_CTOR(timer) {				// constructor
        SC_THREAD(runtimer);
        reset_signal_is(start, true);         // positive_trigger
    }
};
