# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[]) {
    
    char str[20];

    strcpy(str, " says ");

    printf("%s", argv[0]);
    printf("%s", str);
    printf("Hello World!\n");
    return (0);
}
