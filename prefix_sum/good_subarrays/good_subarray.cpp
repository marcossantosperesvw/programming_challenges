#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    map <long long, long long>freq;
    freq[0] = 1;
    long long sum = 0;
    long long count = 0;
    for(int i = 0; i < n;i++){
        int digit = s[i] - '0';
        sum += digit - 1;
        count += freq[sum];
        freq[sum] += 1;
    }
    cout << count << endl;
}
int main(){

    int t;
    cin >> t;
    while (t>0){
        solve();
        t--;
    }
    return  0;
}