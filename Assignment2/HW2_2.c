# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char *argv[]) {

    int val = 'A';
    int size = atoi(argv[1]);
    char *ptr = (char*) malloc(size);
    int *num = (int*) ptr;

    for(int i=0; i<size; i++){
        *ptr = (char)val;
        printf("%c", *ptr);
        ptr++;
        val++;
        if(val == 'Z'+1) val = '1';
        if(val == '9'+1) val = 'A';

    }

    printf("\n");

    int i = 0;

    do{
        printf("num: %d ", *num);
        printf("sub: %d\n", *num - 1);
        num++;
        size -= 4;
    }while(size>4);

    free(ptr);

    return 0;
}
