#include <iostream>
#include <string>
#include <vector>

#define MAX 9

using namespace std;

class Candidate {
    public:
        Candidate(const string& name) : name(name) {}
        const string& getName(void) const { 
            return name; 
        }
    private:
        std::string name;
};

class ArrPair {
    public:
        ArrPair(int winner, int loser) : winner(winner), loser(loser) {}
        int getWinner() const { 
            return winner; 
        }
        int getLoser() const { 
            return loser; 
        }
    private:
        int winner;
        int loser;
};

class Tideman {
    public:
        Tideman(int argc, char* argv[]) {
            if (argc < 2) {
                cout << "Usage: tideman [candidate ...]" << endl;
                exit(1);
            }

            candidate_count = argc - 1;
            if (candidate_count > MAX) {
                cout << "Maximum number of candidates is " << MAX << endl;
                exit(2);
            }

            candidates.reserve(candidate_count);
            for (int i = 0; i < candidate_count; i++) {
                candidates.push_back(Candidate(argv[i + 1]));
            }

            locked.resize(candidate_count, vector<bool>(candidate_count, false));

            arrpair_count = 0;
            int voter_count;
            cout << "Number of voters: ";
            cin >> voter_count;

            for (int i = 0; i < voter_count; i++) {
                vector<int> ranks(candidate_count);

                for (int j = 0; j < candidate_count; j++) {
                    cout << "Rank " << j + 1 << ": ";
                    std::string name;
                    cin >> name;

                    if (!vote(j, name, ranks)) {
                        cout << "Invalid vote." << endl;
                        exit(3);
                    }
                }

                record_preferences(ranks);

                cout << endl;
            }

            add_arrpairs();
            sort_arrpairs();
            lock_arrpairs();
            print_winner();
        }

    private:
        int candidate_count;
        vector<Candidate> candidates;
        vector<vector<int>> preferences;
        vector<vector<bool>> locked;
        vector<ArrPair> arrpairs;
        int arrpair_count;

        bool vote(int rank, const std::string& name, vector<int>& ranks) {
            for (int i = 0; i < candidate_count; i++) {
                if (name == candidates[i].getName()) {
                    ranks[rank] = i;
                    return true;
                }
            }
            return false;
        }

        void record_preferences(const vector<int>& ranks) {
            preferences.resize(candidate_count, vector<int>(candidate_count, 0));
            for (int i = 0; i < candidate_count; i++) {
                for (int j = i + 1; j < candidate_count; j++) {
                    preferences[ranks[i]][ranks[j]]++;
                }
            }
        }

        void add_arrpairs() {
            for (int i = 0; i < candidate_count; i++) {
                for (int j = i + 1; j < candidate_count; j++) {
                    if (preferences[i][j] > preferences[j][i]) {
                        arrpairs.emplace_back(i, j);
                        arrpair_count++;
                    }
                    else if (preferences[i][j] < preferences[j][i]) {
                        arrpairs.emplace_back(j, i);
                        arrpair_count++;
                    }
                }
            }
        }

        void sort_arrpairs() {
            for (int i = 0; i < arrpair_count; i++) {
                int i1 = arrpairs[i].getWinner();
                int j1 = arrpairs[i].getLoser();
                int strength_arrpair1 = preferences[i1][j1] - preferences[j1][i1];
                        int i2 = arrpairs[i + 1].getWinner();
            int j2 = arrpairs[i + 1].getLoser();
            int strength_arrpair2 = preferences[i2][j2] - preferences[j2][i2];

            if (strength_arrpair1 < strength_arrpair2) {
                swap(arrpairs[i], arrpairs[i + 1]);
            }
        }
    }

        void lock_arrpairs() {
            for (int i = 0; i < arrpair_count; i++) {
                int ii = arrpairs[i].getWinner();
                int jj = arrpairs[i].getLoser();
                locked[ii][jj] = true;

                if (lock_check(ii, jj)) {
                    locked[ii][jj] = false;
                }
            }
        }

        void print_winner() {
            for (int j = 0; j < candidate_count; j++) {
                int counter1 = 0;

                for (int i = 0; i < candidate_count; i++) {
                    if (!locked[i][j]) {
                        counter1++;
                        if (counter1 == candidate_count) {
                            cout << candidates[j].getName() << endl;
                        }
                    }
                }
            }
        }

        bool lock_check(int ii, int jj) {
            if (candidate_count == 1)
                return false;

            if (ii == jj)
                return true;

            for (int i = 0; i < candidate_count; i++) {
                if (locked[jj][i]) {
                    if (lock_check(ii, i))
                        return true;
                }
            }

            return false;
        };
};

int main(void) {
    int seats;
    char** partycandidates;
    Tideman tideman(seats, partycandidates);
    return 0;
}
