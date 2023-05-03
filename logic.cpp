#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
    int winner;
    int loser;
}pairr;

int main(int argc, string argv[] ){
    int preferences[10][10];
    bool locked[10][10];
    pairr swap[0];
    pairr pairs[40];

    string candidates[argc - 1];

    for(int i = 1; i < argc; i++){
        candidates[i - 1] = argv[i];
    }
    

}

bool vote(int rank, string name, int ranks[], int count, string candidates[]){

    for(int i = 0; i < count; i++){
        
        if(candidates[i] == name){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[], int count, int preferences[10][10]){

    for(int i = 0; i < count; i++){

        for(int j = i + 1; j < count; j++){

            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

void add_pairs(int count, int preferences[10][10], int paircount, pairr pairs[]){
    
    for(int i = 0; i< count; i++){
        
        for(int j = 0; j < count; j++){
            if(preferences[i][j] > preferences[j][i]){
                pairs[paircount].winner = i;
                pairs[paircount].loser = j;
                paircount++;
            }
            else if(preferences[i][j] < preferences[j][i]){
                pairs[paircount].winner = j;
                pairs[paircount].loser = i;
                paircount++;
            }
        }
    }
    return;
}

void sortpairs(pairr pairs[], int paircount, int preferences[10][10]){

    for(int i = 0; i < paircount; i++){

        for(int j = 0; j < paircount - i - 1; j++){

            int temp = pairs[j].winner;
            int temp2 = pairs[j].loser;

            int firstpairstrength = preferences[temp][temp2] - preferences[temp2][temp];

            int temp3 = pairs[j + 1].winner;
            int temp4 = pairs[j + 1].loser;

            int secondpairstrength = preferences[temp3][temp4] - preferences[temp4][temp3];

            if(firstpairstrength < secondpairstrength){
                
                swap(pairs[j], pairs[j + 1]);
            }
        }
    }
    return;
}

void lockpairs(int paircount, pairr pairs[], bool locked[10][10], int count){

    for(int i = 0; i < paircount; i++){

        int temp = pairs[i].winner;
        int temp2 = pairs[i].loser;

        locked[temp][temp2] = true;

        if(checklock(temp, temp2, count, locked)){
            locked[temp2][temp] = false;
        }

    }
    return;
}

bool checklock(int temp, int temp2, int count, bool locked[10][10]){
    if(count == 1){
        return false;
    }

    if( temp == temp2){
        return true;
    }

    for(int i = 0; i < count; i++){

        if(locked[temp2][i] == true){

            if(checklock(temp, i, count, locked)){

                return true;
            }
        }
    }
    return false;
}