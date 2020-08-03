#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) 0x30
#endif

using ll = long long;

bool check(const int& queen, const vector<vector<char>>& mat, const vector<int>& arr){
    if(mat[queen][arr[queen-1]] == '*') return false;
    for(int i=queen-1; i>0; i--){
        if(arr[queen-1] == arr[i-1]) return false;
        if(abs(arr[queen-1]-arr[i-1]) == abs(queen - i)) return false;
    }
    return true;
}

int32_t main(){
    fast; 
    vector<vector<char>> mat(9, vector<char>(9));
    for(int i=1; i<9; i++){
        for(int j=1; j<9; j++){
            char c;
            cin>>c;
            mat[i][j] = c;
        }
    }
    vector<int> arr(8);
    iota(all(arr), 1);
    int cnt = 0; 
    do{
        int queen;
        for(queen=1; queen<9; queen++){
            if(!check(queen,mat, arr)) break;
        }
        if(queen== 9) cnt++;
    }while(next_permutation(all(arr)));
    cout<<cnt<<'\n';
}

