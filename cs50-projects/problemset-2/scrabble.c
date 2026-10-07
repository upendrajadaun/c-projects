// making an working prototype of scarbble game

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wordMath(char word1[20]);

int points[26] = {1,	3,	3,	2,	1,	4,	2,	4,	1,	8,	5,	1,	3,	1,	1,	3,	10,	1,	1,	1,	1,	4,	4,	8,	4,	10
};

int main(void)
{
    // taking the two inputes as word1 and word2
    char word1[20];
    char word2[20];

    printf("what is your word player 1: ");
    scanf(" %s", word1);

    printf("what is your word player 2: ");
    scanf(" %s", word2);

 
    // computing the scores
    int score1 = wordMath(word1);
    int score2 = wordMath(word2);

    // output with four cases
    if (score1 > score2)
    {
        printf("player 1 is the winner HUREYY!! with %d", score1);
    }
    else if (score1 < score2)
    {
        printf("player 2 is the winner HUREYY!! with %d", score2);
    }
    else if(score1 == 0 || score2 == 0)
     printf("dont ry to be smart and put only words"); // it terminates all the answers without any words

    else if (score1 = score2)
     printf("uhh!! its an draw :( ");
   



}

// making a fn that gives an score integer as output
int wordMath(char word[20])
{    
    // declearing the variables
    int score = 0;
    int i;
    int len = strlen(word);

    // making a loop that checks evey value of the word
    for (i = 0, len = strlen(word); i < len ; i++)
    {
        if(isupper(word[i]))
        {
           score += points[word[i] - 'A']; // using ASCII arthmetics 
        }

        if(islower(word[i]))
        {
          score += points[word[i] - 'a'];
        }
    

    }
return score;// retuning score value
}