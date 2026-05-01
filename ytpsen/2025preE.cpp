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

using namespace std;

ll A, B, C, D;
ll dp[3005][3005];
int F[3005];

ll f(int x, int y){
    if(x==y){
        return 0ll;
    } else if(x>y){
        return A+(x-y)*(C+D);
    } else{
        return A+(y-x)*(B+D);
    }
}

int main(){
    fastio;
    redir("in.txt", "out.txt");

    for(int i=0; i<3005; i++){
        for(int j=0; j<3005; j++){
            dp[i][j] = 1e17;
        }
    }

    int n; cin>>n;
    cin>>A>>B>>C>>D;

    F[0] = 1;
    for(int i=1; i<=n; i++){
        cin>>F[i];
    }

    //dp[j][i] 一個打完Fi 另一個在Fj的min cost
    dp[0][1] = f(F[0], F[1]);
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            if(j!=i-1){
                dp[j][i] = min(dp[j][i], dp[j][i-1]+f(F[i-1], F[i]));
            }
            else{
                for(int k=0; k<i-1; k++){
                    dp[j][i] = min(dp[j][i], dp[k][i-1]+f(F[k], F[i]));
                }
            }
        }
    }

    ll ans = 1e17;
    for(int i=0; i<n; i++){
        ans = min(ans, dp[i][n]);
    }
    cout << ans;
}