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
  ll n, t; cin >> n >> t;
  ll mx = n; ll mn = 1;
  bool mxChng = false;
  bool mnChng = false;

  while(t--){

    string s1, s2, s3, s4, s5; cin >> s1 >> s2 >> s3 >> s4 >> s5;

    if(s3 == "left") { 

      int x = stoi(s5);
      mx = min(mx, (ll)x);
      mxChng = true;

    }

    if(s3 == "right"){

      int x = stoi(s5);
      mn = max(mn, (ll)x);
      mnChng = true;

    }

  }

  if(mxChng) mx = mx - 1;
  if(mnChng) mn = mn + 1;

  ll sol = mx - mn + 1;

  if(sol < 1) cout << "-1" << nl;
  else cout << sol << nl;

}


int main(){
  // FST_IO
  NoCiLLaX();

  
}
