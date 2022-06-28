#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, string argv[])
{

//Se a linah de comando estiver errada deve retornar um valor diferente de 0
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string chave = argv[1];
    // a linha de comando so poder aceitar UM valor e POSITIVO
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
//mostrar plaintext: para pegar a frase para ser emcriptada
    string plaintext = get_string("plaintext:  ");

    int k = atoi(chave);

//ciphertext: vai ser a resposta encripitada
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + k) % 26 + 65));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) % 26 + 97));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
// no fim o programa retorna 0 e incera o programa
    return 0;
}
