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
#include <algorithm>
using namespace std;

int board[100005][2];

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n; cin>>n;
    int I, J, L, O, S, T, Z;
    cin>>I>>J>>L>>O>>S>>T>>Z;

    int now = 1;
    int id = 0;
    
    if(now+2*O<= n+1){
        for(int i=0; i<O; i++){
            id++;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][0] = id;
            board[now++][1] = id;        
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+4*(J/2) <= n+1){
        for(int i=0; i<J/2; i++){
            id++;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][0] = id+1;
            board[now++][1] = id; 
            board[now][0] = id+1;
            board[now++][1] = id; 
            board[now][0] = id+1;
            board[now++][1] = id+1; 
            id++;      
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+4*(L/2) <= n+1){
        for(int i=0; i<L/2; i++){
            id++;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][0] = id;
            board[now++][1] = id+1; 
            board[now][0] = id;
            board[now++][1] = id+1; 
            board[now][0] = id+1;
            board[now++][1] = id+1;  
            id++;
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+4*(I/2) <= n+1){
        for(int i=0; i<I/2; i++){
            id++;
            board[now][0] = id;
            board[now++][1] = id+1;
            board[now][0] = id;
            board[now++][1] = id+1; 
            board[now][0] = id;
            board[now++][1] = id+1; 
            board[now][0] = id;
            board[now++][1] = id+1;
            id++;      
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+6 <= n+1){
        id++;
        board[now][0]=id;
        board[now++][1]=id;
        board[now][0]=id+1;
        board[now++][1]=id;
        board[now][0]=id+1;
        board[now++][1]=id;
        board[now][0]=id+1;
        board[now++][1]=id+2;
        board[now][0]=id+1;
        board[now++][1]=id+2;
        board[now][0]=id+2;
        board[now++][1]=id+2;
        id+=2;
    }else{
        cout << "No";
        return 0;
    }

    if(now+3+2*(S-1) <= n+1){
        for(int i=0; i<S; i++){
            id++;
            board[now++][1] = id;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][0] = id;
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+3+2*(T-1) <= n+1){
        id++;
        board[now++][1] = id;
        board[now][0] = id;
        board[now++][1] = id;
        board[now][1] = id;
        for(int i=1; i<T; i+=2){
            id++;
            board[now++][0] = id;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][0] = id;
            id++;
            board[now++][1] = id;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][1] = id;
        }
    }else{
        cout << "No";
        return 0;
    }

    if(now+3+2*(Z-1) <= n+1){
        id++;
        for(int i=0; i<Z; i++){
            board[now++][0] = id;
            board[now][0] = id;
            board[now++][1] = id;
            board[now][1] = id;
            id++;
        }
    }else{
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    for(int i=1; i<=n; i++){
        cout << board[i][0] << ' ';
    }
    cout << "\n";
    for(int i=1; i<=n; i++){
        cout << board[i][1] << ' ';
    }
}