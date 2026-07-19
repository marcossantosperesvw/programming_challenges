#include  <bits/stdc++.h>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> paper = vector<int>(N+1, 0);
    vector<int> hoof  = vector<int>(N+1, 0);
    vector<int> scissors = vector<int>(N+1, 0);


    for (int i = 1; i <=N; i++){
        char c;
        cin >> c;
        if (c == 'P'){
            scissors[i] = 1;   
        }

        else if (c == 'H'){
            paper[i] = 1;
        }
        else{
            hoof[i] = 1;
        }
        
        
    }

    for (int i = 1; i <= N; i++){
        paper[i] += paper[i-1];
        hoof[i] += hoof[i-1];
        scissors[i] += scissors[i-1];

    }


    int max_wins = 0;

    for (int i = 1; i<=N; i++){
        int before_wins = max(max(paper[i], hoof[i]), scissors[i]);
        int after_wins = max(max(paper[N] - paper[i], hoof[N] - hoof[i]), scissors[N] - scissors[i]);
        max_wins = max(max_wins, before_wins + after_wins);




    }

    cout << max_wins << endl;

    return 0;


}