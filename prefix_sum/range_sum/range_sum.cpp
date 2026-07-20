#include <bits/stdc++.h>


using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> nums = vector<int>(N);
    vector<int> preffix = vector<int>(N+1, 0);
    for (int i = 0; i < N; i++){
        cin >> nums[i];
        
    }

    for (int i = 1; i <= N; i++){
        preffix[i] = nums[i-1] + preffix[i-1];
    }


    int left, right;
    for (int i = 0 ; i < Q; i++){
        cin >> left >>right;
        cout << preffix[right] - preffix[left]<< endl;
    }


}