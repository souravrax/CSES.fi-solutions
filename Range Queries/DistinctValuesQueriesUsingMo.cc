#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
 
struct mo{
	int l, r, id;
};
 
int ans, v[300005], bloco, freq[300000];
 
void add(int idx){
    freq[v[idx]]++;
    if(freq[v[idx]] == 1)
        ans++;
}
 
void remove(int idx){
    freq[v[idx]]--;
    if(freq[v[idx]] == 0)
        ans--;
}
 
bool comp(mo a, mo b){
    if(a.l /bloco != b.l/bloco)
        return a.l/bloco < b.l/bloco;
    return a.r < b.r;
}
 
int main(){
    int n, q, resp[200001];
    map <int, int> aux;
    int cnt = 1;
    mo queries[200001];
    scanf("%d %d", &n, &q);
    ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
        if(aux.find(v[i]) == aux.end())
            aux[v[i]] = cnt++;
        v[i] = aux[v[i]];
    }
    for(int i = 0; i < q; i++){
        scanf("%d %d", &queries[i].l, &queries[i].r);
        queries[i].id = i;
    }
    bloco = sqrt(n)+1;
    sort(queries, queries+q, comp);
    int curl = 0, curr = 0;
    for(int i = 0; i < q; i++){
        int l = queries[i].l-1, r = queries[i].r-1;
        while(curl < l){
            remove (curl);
            curl++;
        }
        while(curl > l){
            add (curl - 1);
            curl--;
        }
        while(curr <= r){
            add (curr);
            curr++;
        }
        while(curr > r+1){
            remove (curr-1);
            curr--;
        }
        resp[queries[i].id] = ans;
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", resp[i]);
    return 0;
}
