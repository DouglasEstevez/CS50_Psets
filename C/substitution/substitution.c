#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
//Conferindo se é so mente um comando
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
//Conferindo se sao somente letras
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("key must only contain alphabetic charaters\n");
            return 1;
        }
    }
//Conferindo se são 26 caracteres
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 charaters\n");
        return 1;
    }
//Conferindo letrar por letra
    for (int x = 0, a = strlen(key); x < a; x++)
    {
        for (int y = x + 1, b = strlen(key); y < b; y++)
        {
            if (tolower(key[x]) == tolower(key[y]))
            {
                printf("key must not contain repeated charaters\n");
                return 1;
            }
        }
    }
//Pegar o texto da pessoa
    string plaintext = get_string("plaintext: ");

//Convertendo a chave para letra mais cula para facilitar
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }
//Resolvendo o ciphertext
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
//Convertendo as letras maiusculas
        if (isupper(plaintext[i]))
        {
            int l = plaintext[i] - 65;
            printf("%c", key[l]);
        }
//Convertendo as letras minusculas
        else if (islower(plaintext[i]))
        {
            int l = plaintext[i] - 97;
            printf("%c", key[l] + 32);
        }
//Mantendo os nao alfabeticos
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}