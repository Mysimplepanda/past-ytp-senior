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
#include <string>
using namespace std;

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n; cin>>n;
    int maxi = 0;
    string winner;

    while(n--){
        string name;
        int score;
        cin>>name>>score;

        if (score > maxi){
            winner = name;
            maxi = score;
        }
    }

    cout << winner;
}