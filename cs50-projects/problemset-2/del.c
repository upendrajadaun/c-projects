/**
 * Readability calculator using the Coleman-Liau index.
 *
 * Formula: index = 0.0588 * L - 0.296 * S - 15.8
 * L is letters per 100 words; S is sentences per 100 words.
 * Letters are alphabetic characters, words are whitespace-delimited tokens,
 * and sentence endings are '.', '!' and '?'.
 *
 * Reads one line from standard input. Build with a C11 compiler, for example:
 *     cc -std=c11 -Wall -Wextra -Wpedantic -Werror readability.c -lm -o readability
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct text_counts
{
    size_t letters;
    size_t words;
    size_t sentences;
};

/** Count Coleman-Liau features in one pass over text. */
static struct text_counts
count_features(const char *text)
{
    struct text_counts counts = {0U, 0U, 0U};
    int inside_word = 0;

    for (const unsigned char *cursor = (const unsigned char *) text;
         *cursor != '\0';
         ++cursor)
    {
        if (isalpha(*cursor))
        {
            ++counts.letters;
        }

        if (isspace(*cursor))
        {
            inside_word = 0;
        }
        else if (!inside_word)
        {
            ++counts.words;
            inside_word = 1;
        }

        if (*cursor == '.' || *cursor == '!' || *cursor == '?')
        {
            ++counts.sentences;
        }
    }

    return counts;
}

/** Return the Coleman-Liau index, or zero when there are no words. */
static double
coleman_liau_index(struct text_counts counts)
{
    if (counts.words == 0U)
    {
        return 0.0;
    }

    const double words_per_hundred = (double) counts.words / 100.0;
    const double letters_per_hundred = (double) counts.letters / words_per_hundred;
    const double sentences_per_hundred = (double) counts.sentences / words_per_hundred;

    return (0.0588 * letters_per_hundred)
         - (0.296 * sentences_per_hundred)
         - 15.8;
}

int
main(void)
{
    char *text = NULL;
    size_t capacity = 0U;

    fputs("Text: ", stdout);
    (void) fflush(stdout);

    const long input_length = getline(&text, &capacity, stdin);
    if (input_length < 0L)
    {
        fputs("Error: unable to read text.\n", stderr);
        free(text);
        return EXIT_FAILURE;
    }

    const struct text_counts counts = count_features(text);
    const int grade = (int) lround(coleman_liau_index(counts));

    if (grade < 1)
    {
        puts("Before Grade 1");
    }
    else if (grade >= 16)
    {
        puts("Grade 16+");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    free(text);
    return EXIT_SUCCESS;
}
