#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = (int) round(index);

    // Print the grade level
    if (rounded < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else if (rounded > 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\nGrade %d\n", rounded);
    }
}
// count the number of letters function
int count_letters(string text)
{
    int count = 0;
    int i = 0;

    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count++;
        }
    }
    // Return the number of letters in text
    return count;
}

// count the number of words function
int count_words(string text)
{
    int count = 0;
    int i = 0;

    // check if the first characters are a space
    while (isspace(text[i]) != 0)
    {
        i++;
    }

    for (i = 0; i < strlen(text); i++)
    {
        // check if a character is a space
        if (isspace(text[i]) != 0)
        {
            count++;
            // check for multiple spaces
            while (isspace(text[i + 1]) != 0)
            {
                i++;
            }
        }
    }
    // check if the last character is a space
    if (isspace(text[strlen(text) - 1]) != 0)
    {
        count--;
    }
    // Return the number of words in text
    return count + 1;
}
// count the number of sentences
int count_sentences(string text)
{

    int count = 0;
    int i = 0;

    while (text[i] == '!' || text[i] == '?' || text[i] == '.')
    {
        i++;
    }

    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count++;
            while (text[i] == '!' || text[i] == '?' || text[i] == '.')
            {
                i++;
            }
        }
    }
    // Return the number of sentences in text
    return count;
}
