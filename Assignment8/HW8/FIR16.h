#include"systemc.h"

SC_MODULE(FIR16){
    sc_in<sc_uint<32> > x;
    sc_out<sc_uint<32> > y;
    sc_in<bool> clk;
    sc_in<bool> rst;
    
    void fir();
    
    sc_uint<32> b, sum[16];
    sc_signal<sc_uint<32> > mid[16];

    SC_CTOR(FIR16){
    
        SC_CTHREAD(fir, clk.pos());
        reset_signal_is(rst, false);
    }
};
