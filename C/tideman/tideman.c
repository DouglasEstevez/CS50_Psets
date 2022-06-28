#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int index_found = -1;
// andar pelo array
    for (int i = 0, n = candidate_count; i < n; i++)
    {
// comparar o nome que esta no voto com o nome dos candidatos
        if (strcmp(name, candidates[i].name) == 0)
        {
// mudando a variavel para localizar qual e o candidato
            index_found = i;
            break;
        }
//candidato nao axiste
        if (index_found == -1)
        {
            return false;
        }
//atualizando o array de rank
    ranks[rank] = index_found;
    return true;
    }

}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        for (int j = i + 1, x = candidate_count; j < x; j++)
        {
            preferences[rank[i][rank[j]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
        for (int linha = 0, n = MAX; linha < n; linha++)
    {
        for (int coluna = linha + 1, x = MAX; coluna < x; coluna++)
        {
           int Ci = preferences[linha][coluna];
           int Cj = preferences[coluna][linha];
           if (Ci != Cj)
           {
               pair p;
               if (Ci > Cj)
               {
                   p.winner = linha;
                   p.loser = coluna;
               }
               else
               {
                   p.winner = coluna;
                   p.loser = linha;
               }
               pairs[pair_count++] = p;
           }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0, n = pair_count; i < n; i++)
    {
        int mas_index = i;
        int força_a = preference[pairs[i].winner][pairs[i].loser] - preference[pairs[i].loser][pairs[i].winner];
        for (int j = i +1, x = pair_count; j < n; j++)
        {
            int força_b = preference[pairs[j].winner][pairs[j].loser] - preference[pairs[j].loser][pairs[j].winner];
            if (força_b > força_a)
            {
                mas_index = j;
                força_a = preference[pairs[j].winner][pairs[j].loser] - preference[pairs[j].loser][pairs[j].winner];
            }
        }
        pair_temp = pairs[mas_index];
        pairs[mas_index]; = pairs[i];
        pairs[i] = temp;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}