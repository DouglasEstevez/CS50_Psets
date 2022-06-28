#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
//Loop para comparar o nome dos votos com o nome dos candidatos, se for igual adiciona um voto para a pessoa
    for (int i = 0; i < candidate_count; i++)
    {
// compara o voto com os candidatos
        if (strcmp(name, candidates[i].name) == 0)
        {
//adiciona um voto para os candidatos
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
//Criar uma variavel para guardar os valores dos votos
    int maximo = 0;
//Loop para passar os mairoes valores de votos para a nova variavel
    for (int i = 0; i < candidate_count; i++)
    {
//Como candidatos [i] vai passar por todos os valores de votos o maior valor ficara na variavel maximo
        if (candidates[i].votes > maximo)
        {
            maximo = candidates[i].votes;
        }
    }
//Loop para identificar quem tem mais votos
    for (int i = 0; i < candidate_count; i++)
    {
//Comparando o array dos votos com a variavel maximo todos candidatos com o valor de maximo vao ser vencedores
        if (candidates[i].votes == maximo)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}