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

// ======================== C O M P U T A T I O N ========================
 
    int n_letter = strlen(text);                                //it also includes the whitespace
    int nt_let = n_letter - 1;
    int n_space = 0;                                            //also no of words - 1

    for(i = 0; i < n_letter; i++ )
    {
          if(text[i] == ' ')
          {
          n_space += 1;
          }
    }
   

 // ---------sypecial symbols-------

   int n_ss = 0;
   int j;
   
    for(j = 0; j < n_letter; j++ )
    {
          if(  text[j] == '.'
             ||text[j] == '!'
             ||text[j] == ','
             ||text[j] == '?'
             ||text[j] == '\''
             ||text[j] == '"'
             ||text[j] == ';'
             ||text[j] == ':'
             )
          {
          n_ss += 1;
          }
    }
 



 //------ sentence logic-------

   int sent = 0;
   int k;
   for(k = 0; k < n_letter; k++)
   {
      if((  text[k] == '.'
          ||text[k] == '!'
          ||text[k] == '?') && isupper(text[k + 2]))
          {
             sent += 1;
          }
   }




// ======================= O U T P U T =====================================
    
    int no_let = nt_let - (n_space + n_ss);
    int no_wrd = n_space + 1;
    int no_snt = sent + 1; // for the last one


      //     printf("no of the letters : %d\n", no_let);   
      //     printf("no of words : %d\n", no_wrd);
      //     printf("no of sentances : %d\n", no_snt);


    float L = (float)(no_let*100) / no_wrd;
    float S = (float)(no_snt*100) / no_wrd;
    

    
    int index = 0.0588 * L - 0.296 * S - 15.8 + 0.5; // 0.5 for rounding up 
    
    if(index < 0)
     printf("you are at grade before 1");

    else if(index > 16)
     printf("you are at grade 16+", index);

    else
     printf("you are at grade : %d", index);

     return 0;
}

