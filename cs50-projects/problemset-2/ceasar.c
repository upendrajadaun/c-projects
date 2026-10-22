// taking a cla from the user and incrpting it using ceasar's mathod

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

int power(int tm);
static char keymath(char x, char *key);
    
int main(int argc, char *argv[])
{ 
    // if(argv[1] = NULL) that will k work fine too but with limitations of more than 1 argument
    if(argc != 2)
    {
      return 1;
    }
    

    char pt[MAX];
    int i = -1;

    printf("plaintext : ");
    
    if(fgets(pt, sizeof(pt), stdin) != 0)
    {
     i++;
    }

    int len = strlen(pt);
    while(i < len)
    {
      char y = keymath(pt[i], argv[1]);
      printf("%c", y);
      i++;
    }

}








static char keymath(char x, char *key)
{
    
        int c_code;
        int i;
        int p = 0;
        int len = strlen(key);
        int k1 = 0;
        int k = 0;
      
        for(i = 0; i < len; i++) 
        {   
            
            char z = key[i];
            k1 = z - '0';
            k = k + (k1*power(len - i));
           
        
        }
  

        if( x == ' ')
        {
          return ' ';
        }

        else if(isupper(x)) 
        {   
            p = x - 'A';
            int c1 = (p + k)%26;
            char c = c1 + 65;
            return c;
        }

        else if(islower(x))
        {   
            p = x - 'a';
            int c1 = (p + k)%26;
            char c = c1 + 97;
            return c; 
        } 

}






int power(int tm)
{
    int i;
    for(i = 1; i < tm ; i++ )
    {
        i *= 10;
    }
    if(tm == 0 )
     i = 1;

    return i;
}

