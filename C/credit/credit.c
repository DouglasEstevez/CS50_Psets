#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long CartaoCredito;

    do
    {
        CartaoCredito = get_long("Credit Card Number? ");
    }
    while (CartaoCredito <= 0);

    long TrabalhoCC = CartaoCredito;
    int sum = 0;
    int contador = 0;
    long divisor = 10;

    // Soma dos nao multiplicavieis
    while (TrabalhoCC > 0)
    {
        int UltimoDigito = TrabalhoCC % 10;
        sum = sum + UltimoDigito;
        TrabalhoCC = TrabalhoCC / 100;
    }

    // Soma com multiplicaçao
    TrabalhoCC = CartaoCredito / 10;
    while (TrabalhoCC > 0)
    {
        int UltimoDigito = TrabalhoCC % 10;
        int VezesDois = UltimoDigito * 2;
        sum = sum + (VezesDois % 10) + (VezesDois / 10);
        TrabalhoCC = TrabalhoCC / 100;
    }

    // Tamanho do numero
    TrabalhoCC = CartaoCredito;
    while (TrabalhoCC != 0)
    {
        TrabalhoCC = TrabalhoCC / 10;
        contador++;
    }

    // divisao
    for (int i = 0; i < contador - 2; i++)
    {
        divisor = divisor * 10;
    }

    int PrimeiroDigito = CartaoCredito / divisor;
    int SegundoDigito = CartaoCredito / (divisor / 10);

    // Checagem de bandeira
    if (sum % 10 == 0)
    {
        if (PrimeiroDigito == 4 && (contador == 13 || contador == 16))
        {
            printf("VISA\n");
        }
        else if ((SegundoDigito == 34 || SegundoDigito == 37) && contador == 15)
        {
            printf("AMEX\n");
        }
        else if ((50 < SegundoDigito && SegundoDigito < 56) && contador == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}