#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<long long>occurrences(n);
    occurrences[0] = 1;

    int prefsum = 0;
    for(int i = 0; i < n; i++){
        prefsum += v[i];
        occurrences[(prefsum % n + n) % n] += 1;
        
    }

    long long ans = 0;

    for(long long x: occurrences){
        ans += x * (x - 1) / 2;

    }

    cout << ans << endl;






    return 0;
}