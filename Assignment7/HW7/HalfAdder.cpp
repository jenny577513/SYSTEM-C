#include "HalfAdder.h"

void HalfAdder::process_HA(){

    Sum.write(A ^ B);
    Carry.write(A & B);
    
}
