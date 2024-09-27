# include <stdio.h>
# include <ctype.h>
# define True 1
# define False 0

void count(FILE *text){
    int line = 0;
    int word = 0;
    int repeat = False;
    int charac = 0;
    int up = 0;
    char ch = 0;

    while((ch = fgetc(text)) != EOF){

        if(ch == '\n'){
            line++;
            if(!repeat) word++;
            repeat == False;

        }

        if(ch == ' ' && !repeat){
           word++;
           repeat = True;
        }

        if(isalnum(ch)){
            repeat = False;
            charac++;
            if(ch >= 'A' && ch <= 'Z') up++;
        }
    }

    printf("Line: %d \n", line);
    printf("Char: %d \n", charac);
    printf("Upper: %d \n", up);
    printf("Word: %d \n", word);

}

void write(FILE *text){
    char ch = 0;

    FILE *upper = fopen("UPPER", "w");

    while((ch = fgetc(text)) != EOF){
        
        if(islower(ch)) fputc(toupper(ch), upper);
        else fputc(ch, upper);
    }
}

int main(int argc, char *argv[]) {

    FILE *text = fopen(argv[1], "r"); //read the file

    if(text == NULL) printf("Not exist\n");

    count(text);
    rewind(text);
    write(text);

    return 0;
}

