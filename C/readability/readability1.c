#include <cs50.h>
#include <stdio.h>
#include <string.h>

int counterSP = 0;
int counterF = 0;
int letters_total = 0;
int words_total = 0;
int sentences_total = 0;
float L = 0;
float S = 0;
int index = 0;
int j = 0;

int main(void)
{
    string t = get_string("Text: ");

    for(int i = 0, n = strlen(t); i < n; i++)
    {
        if(t[i] == ' ')
        {
            counterSP++;
        }
        else if(t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            counterF++;
        }
        j = i;
    }

        letters_total = j - (counterSP + counterF);
        words_total = counterSP + 1;
        sentences_total = counterF;

        L = (letters_total / words_total) * 100.0;
        S = (sentences_total / words_total) * 100.0;

        index = 0.0588 * L - 0.296 * S - 15.8;

        if(index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if(index >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }

}