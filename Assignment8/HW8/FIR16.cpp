#include "FIR16.h"

void FIR16::fir(){

    b = 0x00000F0F;

    for(int i=0; i<16; i++){
		mid[i] = 0;
		sum[i] = 0;
    }

    while(1) {
        wait();
        
        mid[0] = x;
        for(int i=1; i<16; i++) mid[i] = mid[i-1];
        
        sum[0] = x.read() * b;

		sum[0] += mid[0].read() * b;
		
		for(int i=1; i<16; i++){
            sum[i] = sum[i-1] + (mid[i].read() * b);
            y = sum[i];
        }
    }
}
