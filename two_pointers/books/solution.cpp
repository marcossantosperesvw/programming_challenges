#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    int n, t;
    if (!(cin >> n >> t)) return 0;

    vector<int> books(n);
    for (int k = 0; k < n; k++) {
        cin >> books[k];
    }

    int i = 0;
    int j = 0;
    int current_time = 0;
    int ans = 0;

    while (j < n) {
        if (current_time + books[j] <= t) {
            current_time += books[j];
            j++;
            ans = max(ans, j - i); 
        } 

        else {
            current_time -= books[i];
            i++;
        }
    }

    cout << ans << "\n";
    return 0;
}