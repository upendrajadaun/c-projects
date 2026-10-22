#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

int main(int argc, char *argv[])
{ 
    // if(argv[1] = NULL) that will work fine too but with limitations of more than 1 argument
        if (argc != 2 )
        {
        printf("i was right\n");
        return 1;
        }
        else
         printf("kalkuu");
}