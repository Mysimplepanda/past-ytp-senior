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

int board[2005][2005];

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n, m; cin>>n>>m;
    int id = 1;    
    if(n%2==1 && m%2==1){
        cout << "NO";
        return 0;
    }
    
    if(n%2==0 && m%2==0){
        for(int i=0; i<n; i+=2){
            for(int j=0; j<m; j+=2){
                //r+c even --> horz.
                //r+c odd  --> vert.
                if((i/2 + j/2) % 2==0){
                    board[i][j] = id;
                    board[i][j+1] = id;
                    id++;

                    board[i+1][j] = id;
                    board[i+1][j+1] = id;
                    id++;
                } else{
                    board[i][j] = id;
                    board[i+1][j] = id;
                    id++;

                    board[i][j+1] = id;
                    board[i+1][j+1] = id;
                    id++;
                }
            }
        }
    }
    if(n%2==1 && m%2==0){
        if(n==1){
            if(m==2){
                cout << "YES\n";
                cout << "1 1";
            } else{
                cout << "NO";
            }

            return 0;
        }

        for(int j=0; j<m; j+=2){
            if((j/2)%2 == 0){
                board[0][j] = id;
                board[1][j] = id;
                id++;

                board[0][j+1] = id;
                board[1][j+1] = id;
                id++;

                board[2][j] = id;
                board[2][j+1] = id;
                id++;
            }else {
                board[1][j] = id;
                board[2][j] = id;
                id++;

                board[1][j+1] = id;
                board[2][j+1] = id;
                id++;

                board[0][j] = id;
                board[0][j+1] = id;
                id++;
            }
        }
        
        for(int i=3; i<n; i+=2){
            for(int j=0; j<m; j+=2){
                if(((i-3+j)/2)%2==0){
                    board[i][j] = id;
                    board[i+1][j] = id;
                    id++;

                    board[i][j+1] = id;
                    board[i+1][j+1] = id;
                    id++;
                } else{
                    board[i][j] = id;
                    board[i][j+1] = id;
                    id++;

                    board[i+1][j] = id;
                    board[i+1][j+1] = id;
                    id++;
                }
            }
        }
    }

    if(n%2==0 && m%2==1){
        if(m==1){
            if(n==2){
                cout << "YES\n";
                cout << "1\n1";
            } else{
                cout << "NO";
            }

            return 0;
        }

        for(int i=0; i<n; i+=2){
            if((i/2)%2==0){
                board[i][0] = id;
                board[i][1] = id;
                id++;

                board[i+1][0] = id;
                board[i+1][1] = id;
                id++;

                board[i][2] = id;
                board[i+1][2] = id;
                id++;
            } else{
                board[i][1] = id;
                board[i][2] = id;
                id++;

                board[i+1][1] = id;
                board[i+1][2] = id;
                id++;

                board[i][0] = id;
                board[i+1][0] = id;
                id++;
            }
        }
        for(int i=0; i<n; i+=2){
            for(int j=3; j<m; j+=2){
                if(((i+j-3)/2)%2==1){
                    board[i][j] = id;
                    board[i+1][j] = id;
                    id++;

                    board[i][j+1] = id;
                    board[i+1][j+1] = id;
                    id++;
                } else{
                    board[i][j] = id;
                    board[i][j+1] = id;
                    id++;

                    board[i+1][j] = id;
                    board[i+1][j+1] = id;
                    id++;
                }
            }
        }
    }

    cout << "YES\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}