#include <bits/stdc++.h>

using namespace std;
void merge(vector<int> &arr, vector<int> &idx_vector, int p, int m, int q){
    vector<int> temp;
    vector<int> temp_idx;
    int i = p;
    int j = m + 1;
    
    while (i <= m && j <= q){
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            temp_idx.push_back(idx_vector[i]);

            i++;
        }
        else{
            temp.push_back(arr[j]);
            temp_idx.push_back(idx_vector[j]);
            j++;
        } 
    }

    while (i <= m){
        temp.push_back(arr[i]);
        temp_idx.push_back(idx_vector[i]);
        i++;
    }

    while (j <= q){
        temp.push_back(arr[j]);
        temp_idx.push_back(idx_vector[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++){
        arr[p + i] = temp[i];
        idx_vector[p+i] = temp_idx[i];  
    }

}
void merge_sort(vector<int> &arr, vector<int> &idx_vector, int p, int q){
    if (p >= q) return;
    int m = (p + q) / 2;
    merge_sort(arr, idx_vector,p, m);
    merge_sort(arr, idx_vector ,m+1, q);
    merge(arr, idx_vector, p, m, q);

}

int main(){

    long long n, x;

    cin >> n >> x;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> idx_vector(n);
    for(int i = 0; i < n;  i++){
        idx_vector[i] = i + 1;
    }

    merge_sort(arr, idx_vector, 0, n-1);

    // Verificar janela com tres elementos

    for(long long ptr1 = 0; ptr1 < n - 2; ptr1++){
        long long ptr2 = ptr1 + 1;
        long long ptr3 = n - 1;
        while(ptr2 < ptr3){
            long long current_sum = arr[ptr1] + arr[ptr2] + arr[ptr3];
            if (current_sum == x){
                cout << idx_vector[ptr1] << " "<< idx_vector[ptr2] << " " << idx_vector[ptr3] << endl;
                return 0;

            }
            else if (current_sum > x){
                ptr3--;
            }
            else if (current_sum < x){
                ptr2++;
            }
        }


    }

    cout << "IMPOSSIBLE" << endl;

    
    return 0;
}