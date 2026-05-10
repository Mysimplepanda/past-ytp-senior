///template
#ifdef LOCAL
#define redir(X, Y)            \
    freopen((X), "r", stdin);  \
    freopen((Y), "w", stdout); 
#else
#define redir(X, Y)
#endif

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
#define SZ(X) ((int)((X).size()))
typedef long long int ll;

///template

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n, k; cin>>n>>k;
    deque<ll> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums;
    }
}