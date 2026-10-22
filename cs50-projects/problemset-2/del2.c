/**
 * Readability calculator using the Coleman-Liau index.
 *
 * Formula: index = 0.0588 * L - 0.296 * S - 15.8
 * L is the average number of letters per 100 words; S is the average number
 * of sentences per 100 words. Letters are alphabetic characters, words are
 * whitespace-delimited, and '.', '!' and '?' end sentences.
 *
 * This version uses only stdio.h and ctype.h. It reads at most MAX_TEXT_LENGTH
 * characters (excluding the terminating null byte) from standard input.
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_TEXT_LENGTH 100000

struct text_counts
{
    int letters;
    int words;
    int sentences;
};

/** Read one line into a bounded buffer; return 0 if input exceeds capacity. */
static int
read_text(char text[], int capacity)
{
    int length = 0;
    int character;

    while ((character = getchar()) != EOF && character != '\n')
    {
        if (length >= capacity - 1)
        {
            return 0;
        }

        text[length++] = (char) character;
    }

    if (character == EOF && length == 0)
    {
        return 0;
    }

    text[length] = '\0';
    return 1;
}

/** Count Coleman-Liau features in one pass over the input string. */
static struct text_counts
count_features(const char text[])
{
    struct text_counts counts = {0, 0, 0};
    int inside_word = 0;

    for (int i = 0; text[i] != '\0'; ++i)
    {
        unsigned char character = (unsigned char) text[i];

        if (isalpha(character))
        {
            ++counts.letters;
        }

        if (isspace(character))
        {
            inside_word = 0;
        }
        else if (!inside_word)
        {
            ++counts.words;
            inside_word = 1;
        }

        if (character == '.' || character == '!' || character == '?')
        {
            ++counts.sentences;
        }
    }

    return counts;
}

/** Compute the Coleman-Liau index; an empty input has index zero. */
static double
coleman_liau_index(struct text_counts counts)
{
    if (counts.words == 0)
    {
        return 0.0;
    }

    double words_per_hundred = counts.words / 100.0;
    double letters_per_hundred = counts.letters / words_per_hundred;
    double sentences_per_hundred = counts.sentences / words_per_hundred;

    return 0.0588 * letters_per_hundred
         - 0.296 * sentences_per_hundred
         - 15.8;
}

/** Round a double to the nearest integer without requiring math.h. */
static int
round_to_nearest_int(double value)
{
    if (value >= 0.0)
    {
        return (int) (value + 0.5);
    }

    return (int) (value - 0.5);
}

int
main(void)
{
    char text[MAX_TEXT_LENGTH];

    printf("Text: ");
    if (!read_text(text, MAX_TEXT_LENGTH))
    {
        fprintf(stderr, "Error: no input or text exceeds %d characters.\n",
                MAX_TEXT_LENGTH - 1);
        return 1;
    }

    struct text_counts counts = count_features(text);
    int grade = round_to_nearest_int(coleman_liau_index(counts));

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}
