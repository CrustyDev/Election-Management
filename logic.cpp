#include <iostream>
#include <cstring>

#define MAX 9

using namespace std;

typedef struct
{
    int winner;
    int loser;
}
arrpair;

int preferences[MAX][MAX];
bool locked[MAX][MAX];
string candidates[MAX];
arrpair arrpairs[MAX * (MAX - 1) / 2];

int arrpair_count;
int candidate_count;

bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_arrpairs(void);
void sort_arrpairs(void);
void lock_arrpairs(void);
void print_winner(void);
bool lock_check(int ii, int jj);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage: tideman [candidate ...]" << endl;
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        cout << "Maximum number of candidates is " << MAX << endl;
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    arrpair_count = 0;
    int voter_count;
    cout << "Number of voters: ";
    cin >> voter_count;

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            cout << "Rank " << j + 1 << ": ";
            string name;
            cin >> name;

            if (!vote(j, name, ranks))
            {
                cout << "Invalid vote." << endl;
                return 3;
            }
        }

        record_preferences(ranks);

        cout << endl;
    }

    add_arrpairs();
    sort_arrpairs();
    lock_arrpairs();
    print_winner();
    return 0;
}

bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (name == candidates[i])
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[]){
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_arrpairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                arrpairs[arrpair_count].winner = i;
                arrpairs[arrpair_count].loser = j;
                arrpair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                arrpairs[arrpair_count].winner = j;
                arrpairs[arrpair_count].loser = i;
                arrpair_count++;
            }
        }
    }
}

void sort_arrpairs(void)
{
    for (int i = 0; i < arrpair_count; i++)
    {
        for (int j = 0; j < arrpair_count - i - 1; j++)
        {
            int i1 = arrpairs[j].winner;
            int j1 = arrpairs[j].loser;
            int strength_arrpair1 = preferences[i1][j1] - preferences[j1][i1];

            int i2 = arrpairs[j + 1].winner;
            int j2 = arrpairs[j + 1].loser;
            int strength_arrpair2 = preferences[i2][j2] - preferences[j2][i2];

            if (strength_arrpair1 < strength_arrpair2)
            {
                swap(arrpairs[j], arrpairs[j+1]);
            }
        }
    }
}

void lock_arrpairs(void)
{
    for (int i = 0; i < arrpair_count; i++)
    {
        int ii = arrpairs[i].winner;
        int jj = arrpairs[i].loser;
        locked[ii][jj] = true;

        if (lock_check(ii, jj))
        {
            locked[ii][jj] = false;
        }
    }
}

void print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        int counter1 = 0;

        for (int i = 0; i < candidate_count; i++)
        {
            if (!locked[i][j])
            {
                counter1++;
                if (counter1 == candidate_count)
                {
                    cout << candidates[j] << endl;
                }
            }
        }
    }
}

bool lock_check(int ii, int jj)
{
    if (candidate_count == 1)
        return false;

    if (ii == jj)
        return true;

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[jj][i])
        {
            if (lock_check(ii, i))
                return true;
        }
    }

    return false;
}
