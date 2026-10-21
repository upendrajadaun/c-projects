// making the redeabillity programm using colemun liau index formula 
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text,
//  and S is the average number of sentences per 100 words in the text.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// prototypes

// global variables


int main(void)
{
    //taking input from the user
    char text[10000];
    int i = -1;
    printf("what is your text: \t");
    
    if(fgets(text, sizeof(text), stdin) != 0)
    {
      i += 1;
    }


 
    int n_letter = strlen(text);                                //it also includes the whitespace
    int nt_let = n_letter - 1;
    int n_space = 0;                                            //also no of words - 1

//     printf(" number of total letters : %d\n", nt_let);
                                              

    for(i = 0; i < n_letter; i++ )
    {
          if(text[i] == ' ')
          {
          n_space += 1;
          }
    }
//    printf(" number of spaces : %d\n", n_space);

   int n_ster = 0;
   int j;
   
    for(j = 0; j < n_letter; j++ )
    {
          if(  text[j] == '.'
             ||text[j] == '!'
             ||text[j] == ','
             ||text[j] == '?'
             )
          {
          n_ster += 1;
          }
    }
//     printf(" number of terminator : %d\n", n_ster);



   int n_stop = 0;
   int k;
   
    for(k = 0; k < n_letter; k++ )
    {
          if(text[k] == '.')
          {
          n_stop += 1;
          }
    }
//     printf(" number of stop : %d\n", n_stop);





    // ===================================================================================================
    
    int no_let = nt_let - (n_space + n_ster);
    int no_wrd = n_space + 1;
    int no_snt = n_ster;

//     printf("no of the letters : %d\n", no_let);

//     printf("no of words : %d\n", no_wrd);
//     printf("no of sentances : %d\n", no_snt);
//     printf("no of s1 : %d\n", no_snt/no_wrd);


    float L = (float)(no_let*100) / no_wrd;
    float S = (float)(no_snt*100) / no_wrd;
//     printf(" L : %.2f\n", L);
//     printf(" S : %.2f\n", S);

    
    int index = 0.0588 * L - 0.296 * S - 15.8 + 0.5; // 0.5 for rounding up 
    
    if(index < 0)
     printf("you are at grade before 1");
    else
     printf("you are at grade : %d", index);

}
