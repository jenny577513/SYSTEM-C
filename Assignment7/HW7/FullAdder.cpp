#include "FullAdder.h"

void FullAdder::process_FA(){

    S.write((A^B) ^ Cin);
    Cout.write((A&Cin)|((A^B)&Cin));
    
}
