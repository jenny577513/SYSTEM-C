#include "FIR16.h"
#include "fstream"

int sc_main(int argc, char* argv[]){
    sc_signal<bool> rst;
    sc_clock clock("clock", 10, SC_NS);
    sc_signal<sc_uint<32> > x, y;
    fstream text;
    int _in;
    
    text.open("firData", ios::in);
    FIR16 f1("FIR16");
    f1 << x << y << clock << rst;

    //Trace
    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, clock, "clk");
    sc_trace(tf, rst, "rst");
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");
    
    sc_start(0, SC_NS);
    rst.write(0);

    sc_start(30, SC_NS);
    rst.write(1);
    while(!text.eof()){
        text >> _in;
        x.write(_in);
        sc_start(20, SC_NS);
    }

    sc_close_vcd_trace_file(tf);
    return 0;
}
