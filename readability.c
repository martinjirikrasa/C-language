#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string message = get_string("Text: ");

    //letters
    int letter_count = count_letters(message);

    //words
    int word_count = count_words(message);

    //sentences
    int sentences_count = count_sentences(message);

    //Coleman-liau index index
    float L = ((letter_count / (float) word_count) * 100);
    float S = ((sentences_count / (float) word_count) * 100);

    float index = (0.0588 * L - 0.296 * S - 15.8);


    int index_int = round(index);

    //printing result
    if (index_int < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index_int >= 1 && (int) index_int < 16)
    {
        printf("Grade %i\n", index_int);
    }
    if (index_int > 16)
    {
        printf("Grade 16+\n");
    }
}

// count the letters in text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            count++;
        }
        if (islower(text[i]))
        {
            count++;
        }
    }
    return count;
}

//count the words in text
int count_words(string text)
{
    int words_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // if space than count++
        if (text[i] == ' ')
        {
            words_count++;
        }
    }
    return words_count + 1;
}

// count sentences
int count_sentences(string text)
{
    int sentences_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        //ending of a sentence
        if (text[i] == '.' && text[i + 1] == '\0')
        {
            sentences_count++;
        }
        if (text[i] == '.' && isupper(text[i + 2]))
        {
            sentences_count++;
        }
        if (text[i] == '?' && text[i + 1] == '\0')
        {
            sentences_count++;
        }
        if (text[i] == '?' && isupper(text[i + 2]))
        {
            sentences_count++;
        }
        if (text[i] == '!' && text[i + 1] == '\0')
        {
            sentences_count++;
        }
        if (text[i] == '!' && isupper(text[ i + 2]))
        {
            sentences_count++;
        }
    }
    //return
    return sentences_count;
}