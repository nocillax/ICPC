// ------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// ------------------------------------------------------------------------------
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
// ------------------------------------------------------------------------------
#define FST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define READ          freopen("in.txt","r",stdin)
#define WRITE         freopen("out.txt","w",stdout);
#define nl            "\n"
#define PI            acos(-1.0)
#define mem(arr,val)  memset(arr,val,sizeof(arr))
#define pb            push_back
#define mp            make_pair
#define mpl           make_pair<ll,ll>
#define PR            pair<ll,ll>
#define ff            first
#define ss            second
#define mod           10000007
#define INF           1e18
#define EPS           1e-2
// ------------------------------------------------------------------------------
  
  void NoCiLLaX(){

  ll t; cin >> t;

  while(t--){
    ll n, m, k; cin >> n >> m >> k;
    ll jSum = 0;
    ll x, y;

    vector<ll> j;
    vector<ll> g;

    for(ll i = 0; i < n; i++){
      ll x; cin >> x;
      jSum += x;
      j.pb(x);
    }

    for(ll i = 0; i < m; i++){
      ll x; cin >> x;
      g.pb(x);
    }

    for(ll i = 1; i <= k; i++){

      if(i%2 != 0){
        sort(j.begin(), j.end());
        sort(g.begin(), g.end());

        if(j[0] < g[m-1]){

          jSum = jSum - j[0] + g[m-1];
          swap(j[0], g[m-1]);

        }
      }

      if(i%2 == 0){
        sort(j.begin(), j.end());
        sort(g.begin(), g.end());

        if(g[0] < j[n-1]){

          jSum = jSum - j[n-1] + g[0];
          swap(g[0], j[n-1]);

        }
      }
    }

  cout << jSum << nl;

  }

}

int main(){
 //FST_IO
  NoCiLLaX();

}
  

