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
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n, m; cin>>n>>m;
    vector<pair<ll, ll>> score(n);
    vector<ll> day1(n);
    vector<ll> day2(n);
    vector<ll> sum(n);

    for(int i=0; i<n; i++){
        ll tot1 = 0;
        for(int j=0; j<m; j++){
            int x; cin>>x;
            tot1+=x;
        }

        ll tot2 = 0;
        for(int j=0; j<m; j++){
            int x; cin>>x;
            tot2+=x;
        }  
        
        score[i].first = tot1;
        score[i].second = tot2;
        day1[i] = tot1;
        day2[i] = tot2;
        sum[i] = tot1+tot2;
    }

    int k1 = (n+1)/2;
    int k2 = (n+1)/2;
    int k3 = (n+1)/2;

    nth_element(day1.begin(), day1.begin()+k1-1, day1.end(), greater<ll>());
    nth_element(day2.begin(), day2.begin()+k2-1, day2.end(), greater<ll>());
    nth_element(sum.begin(), sum.begin()+k3-1, sum.end(), greater<ll>());

    ll d1pride = day1[k1-1];
    ll d2pride = day2[k2-1];
    ll bronze = sum[k3-1];

    map<ll, int> cnt;

    for(int i=0; i<n; i++){
        if ((score[i].first>=d1pride || score[i].second>=d2pride) \
            && score[i].first+score[i].second < bronze){
            
            cnt[score[i].first+score[i].second]++;
        }   
    }

    ll ans = -1;
    int anstimes = 0;
    for(int i=0; i<n; i++){
        ll total = score[i].first+score[i].second;
        if(cnt[total] > anstimes){
            ans = total;
            anstimes = cnt[total];
        } else if(cnt[total]==anstimes && total<ans){
            ans = total;
        }
    }

    cout << ans;
}