#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);

}

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> preffix_gcd(N,0);
    vector<int> suffix_gcd(N,0);  


    for (int i = 0; i<N; i++){
        cin >> arr[i];
    }

    preffix_gcd[0] = arr[0];
    suffix_gcd[N-1] = arr[N-1];

    for(int i = 1; i <N; i++){
        preffix_gcd[i] = gcd(arr[i], preffix_gcd[i-1]);
        suffix_gcd[N-i-1] = gcd(arr[N-i-1], suffix_gcd[N-i]);
    }

    int max_gcd = 0;

    for(int i = 0; i < N;i++){
        int best_choice =0;
        if (i>0) best_choice = gcd(best_choice, preffix_gcd[i-1]);
        if (i< N-1) best_choice = gcd(best_choice,suffix_gcd[i+1]);


        max_gcd = max(max_gcd, best_choice);
    }

    cout << max_gcd << endl;
    return 0;



    
}