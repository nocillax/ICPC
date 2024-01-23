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
  ll test; cin >> test;
  ll mx, mn, sol;
  
  while(test--){
    mx = 0; mn = INF;
    sol = 0;
    
    vector<ll> greater;
    vector<ll> smaller;
    vector<ll> equal;

    ll n; cin >> n;

    while(n--){
      ll a, k; cin >> a >> k;

      (a == 1) ? greater.pb(k) : (a == 2) ? smaller.pb(k) : (a == 3) ? equal.pb(k) : void();

    }

    sort(greater.begin(), greater.end());
    sort(smaller.begin(), smaller.end());
    sort(equal.begin(), equal.end());

    mn = greater[greater.size()-1]; mx = smaller[0];

    ((mx - mn + 1) > 0) ? sol = (mx - mn + 1) : sol = 0;

    if(sol == 0) sol = 0;

    else {

      for(ll i = 0; i < equal.size(); i++){
        if(equal[i] <= mx && equal[i] >= mn) sol--;
      }

    }

    cout << sol << nl;

  } 

}


int main(){
// FST_IO
  NoCiLLaX();

}
  

