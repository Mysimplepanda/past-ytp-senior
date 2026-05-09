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
#include <algorithm>

using namespace std;

int main(){
    fastio;
    redir("in.txt", "out.txt");

    ll n, a, b, c;
    cin>>n>>a>>b>>c;

    ll mxdiff = max({a, b, c}) - min({a, b, c});

    if(n>=mxdiff){
        cout << n-mxdiff+1;
    } else{
        cout << 0;
    }
}