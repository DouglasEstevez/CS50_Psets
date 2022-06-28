#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int answer;
int contadorQ = 0;
int contadorD = 0;
int contadorP = 0;
int contadorN = 0;


int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

//Perguntar a pessoa sobre sobre os centavos recusando negativos
int get_cents(void)
{
    do
    {
        answer = get_int("how many cents? ");
    }
    while (answer < 0);
    return answer;
}

// Calculando 25 centavo
//Usando while para fazer a contagem de quantas moedas sao precisas para cada moeda
int calculate_quarters(int cents)
{
    while (cents >= 25)
    {
        cents = cents - 25;
        contadorQ ++;
    }
    return contadorQ;
}

// Calculando 10 centavo
int calculate_dimes(int cents)
{
    while (cents >= 10)
    {
        cents = cents - 10;
        contadorD ++;
    }
    return contadorD;
}

// Calculando 5 centavo
int calculate_nickels(int cents)
{
    while (cents >= 5)
    {
        cents = cents - 5;
        contadorN ++;
    }
    return contadorN;
}

// Calculando 1 centavo
int calculate_pennies(int cents)
{
    while (cents >= 1)
    {
        cents = cents - 1;
        contadorP ++;
    }
    return contadorP;
}
