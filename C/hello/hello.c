#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Pedindo o nome da pessoa
    string answer = get_string("What is your name? ");

    //Utilizando a resposta da pergunta para uma resposta personalizada
    printf("Hello, %s\n", answer);
}