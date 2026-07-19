#include <bits/stdc++.h>

using namespace std;

int main(){

    int cow_num;
    int query_num;
    cin >> cow_num >> query_num;
    vector<int> holsteins(cow_num + 1,0);
    vector<int> guernseys(cow_num + 1,0);
    vector<int> jerseys(cow_num + 1,0);

    for(int i = 0; i < cow_num; i++){
        int breed;
        cin >> breed;
        if(breed == 1){
            holsteins[i + 1] = 1;
        }
        else if(breed == 2){
            guernseys[i + 1] = 1;
        }
        else{
            jerseys[i + 1] = 1;
        }
    }
    
    for(int i = 1; i <= cow_num; i++){
        holsteins[i] += holsteins[i - 1];
        guernseys[i] += guernseys[i - 1];
        jerseys[i] += jerseys[i - 1];

    }


    for(int i = 0; i < query_num; i++){
        int start, end;
        cin >> start >> end;
        cout << holsteins[end] - holsteins[start - 1] << " " << guernseys[end] - guernseys[start - 1] << " " << jerseys[end] - jerseys[start - 1] << endl;
    }



    return 0;
    
    
}