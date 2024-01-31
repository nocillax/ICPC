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
    ll sum = 0;

    vector<ll> jelly;
    vector<ll> gelly;

    for(ll i = 0; i < n; i++){
      ll x; cin >> x;
      jelly.pb(x);
    }

    for(ll i = 0; i < m; i++){
      ll x; cin >> x;
      gelly.pb(x);
    }

    for(ll i = 1; i <= k; i++){

      sort(jelly.begin(), jelly.end());
      sort(gelly.begin(), gelly.end());
      reverse(gelly.begin(), gelly.end());

      if((i%2 == 0) && (jelly[0] < gelly[0])) {

        sort(jelly.begin(), jelly.end());
        sort(gelly.begin(), gelly.end());
        reverse(gelly.begin(), gelly.end());

        swap(jelly[0], gelly[0]);

        sort(gelly.begin(), gelly.end());
        sort(jelly.begin(), jelly.end());
      }

      else if((i%2 != 0) && (gelly[0] < jelly[0])) {

        sort(jelly.begin(), jelly.end());
        sort(gelly.begin(), gelly.end());
        reverse(jelly.begin(), jelly.end());

        swap(gelly[0], jelly[0]);

        sort(gelly.begin(), gelly.end());
        sort(jelly.begin(), jelly.end());
      }
      else continue;

    }

    for(ll i = 0; i < jelly.size(); i++){
      sum += jelly[i];
    }

  cout << sum << nl;

  }

}


int main(){
 //FST_IO
  NoCiLLaX();

}
  

