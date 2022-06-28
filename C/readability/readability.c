#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);
int cl = 0;
int cw = 1;
int cs = 0;

int main(void)
{
    // receber o texto da pessoa
    string t = get_string("Text: ");

    // numero de letras
    float letters = count_letters(t);
    // numero de palavras
    float words = count_words(t);
    // numero de setenças
    float sentences = count_sentences(t);

    // variaveis da conta
    int L = (letters / words) * 100.0;
    int S = (sentences / words) * 100.0;

    //Coleman-Liau index
    float index = ((0.0588 * L) - (0.296 * S)) - 15.8;

    // resposta adequada minima maxima e entre
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
// formula para calculo de letras 
int count_letters(string t)
{

    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (isalpha(t[i]))
        {
            cl++;
        }
    }
    return cl;
}
// formula para contar palavras
int count_words(string t)
{
    for (int j = 0, k = strlen(t); j < k; j++)
    {
        if (isspace(t[j]))
        {
            cw++;
        }
    }
    return cw;
}
// formula para contar as sentencas
int count_sentences(string t)
{
    for (int x = 0, y = strlen(t); x < y; x++)
    {
        if (t[x] == '.' || t[x] == '?' || t[x] == '!')
        {
            cs++;
        }
    }
    return cs;
}