# This program calculates the aproximate grade level needed to comprehend text bases on Coleman-Liau index.

Coleman-Liau index
is just one of many formulas for computing the reading level of a text.

index = 0.0588 * L - 0.296 * S - 15.8

in this programm i ask the user for input of a text

## how it works ##
First my programm counts the letters of the text
Secondly it counts the number of words in input
After that i count the sentences.

we get the two variables:

float L = ((letter_count / (float) word_count) * 100);
float S = ((sentences_count / (float) word_count) * 100);

Lastly we put these two variables to Coleman-Liau index

index = 0.0588 * L - 0.296 * S - 15.8

and we have the aproximate grade level of input

# this was part of CS50x - Harvard
