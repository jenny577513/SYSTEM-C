#include "timer.h"

int sc_main(int argc, char* argv[]) {

    sc_signal<bool> start, timeout;
    sc_time t(10, SC_NS); // t = 10ns
    sc_clock clock("clock", t, 0.50, SC_ZERO_TIME, true);

    timer t1("Timer");
    t1.start(start);
    t1.timeout(timeout);
    t1.clock(clock);

    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    sc_trace(tf, clock, "clock");
    sc_trace(tf, start, "start");
    sc_trace(tf, timeout, "timeout");
    sc_trace(tf, t1.count, "count");
    
    cout << "Start" << endl;

    sc_start(t*0);
    start.write(0);
    
    sc_start(t*3);
    start.write(1);
    sc_start(t*3);
    start.write(0);
    sc_start(t*5);
    start.write(1);
    sc_start(t*2);
    
    start.write(0);
    sc_start(t*10);
    start.write(1);
    sc_start(t*7);
    start.write(0);

    
    cout << "Timeout\n" << endl;
    sc_close_vcd_trace_file(tf);

    return 0;
}
