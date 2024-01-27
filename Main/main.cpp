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
<<<<<<< HEAD
  ll sz; cin >> sz;
  string s; cin >> s;
  
  set<char> ss;

  for(ll i = 0; i < s.size(); i++){
    char p = tolower(s[i]);
    ss.insert(p);
  }

  if(ss.size() == 26) cout << "YES" << nl;
  else cout << "NO" << nl;
=======

  ll test; cin >> test;
  while(test--){
    vector<ll> v;
    ll bobSum = 0; ll ans = -INF; ll totalSum = 0;
    ll n, k, x; cin >> n >> k >> x;

    for(ll i = 0; i < n; i++){
      ll e; cin >> e;
      v[i] = e;
                
    }
    
    sort(v.begin(), v.end());

    for(ll i = 0; i < k; i++){
      ll j = 0, l = 0;



        for(j = 0; j < x; j++){
          if(i+j < n) bobSum += v[i+j];
        }

        for(l = i+j; l < n; l++){
          totalSum += v[l];
        }

        if((totalSum - bobSum) > (ans)) ans = totalSum - bobSum;

          
    }

    cout << ans << nl;
  }
>>>>>>> 53f80df22f37160c14ec88cdc832636c05408438
}


int main(){
 //FST_IO
  NoCiLLaX();

}
  

