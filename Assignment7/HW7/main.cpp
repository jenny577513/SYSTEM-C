#include "HalfAdder.h"
#include "FullAdder.h"

int sc_main(int argc, char* argv[]) {

    sc_signal<bool> A, B, Cin, Sum, Carry, S, Cout;
    sc_time t(20, SC_NS); // t = 20ns

    HalfAdder HA("HalfAdder");
    HA.A(A);
    HA.B(B);
    HA.Sum(Sum);
    HA.Carry(Carry);
    
    FullAdder FA("FullAdder");
    FA.A(A);
    FA.B(B);
    FA.Cin(Cin);
    FA.Cout(Cout);
    FA.S(S);
    

    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, A, "HA_A");
    sc_trace(tf, B, "HA_B");
    sc_trace(tf, Sum, "HA_Sum");
    sc_trace(tf, Carry, "HA_Carry");
    
    sc_trace(tf, A, "FA_A");
    sc_trace(tf, B, "FA_B");
    sc_trace(tf, Cin, "FA_Cin");
    sc_trace(tf, S, "FA_S");
    sc_trace(tf, Cout, "FA_Cout");
    
    A.write(0);
    B.write(0);
    Cin.write(0);
    sc_start(t);
    
    A.write(0);
    B.write(0);
    Cin.write(1);
    sc_start(t);
    
    A.write(0);
    B.write(1);
    Cin.write(0);
    sc_start(t);
    
    A.write(0);
    B.write(1);
    Cin.write(1);
    sc_start(t);
    
    A.write(1);
    B.write(0);
    Cin.write(0);
    sc_start(t);
    
    A.write(1);
    B.write(0);
    Cin.write(1);
    sc_start(t);
    
    A.write(1);
    B.write(1);
    Cin.write(0);
    sc_start(t);
    
    A.write(1);
    B.write(1);
    Cin.write(1);
    sc_start(t);
        
    sc_close_vcd_trace_file(tf);

    return 0;
}
