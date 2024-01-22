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
  ll n; cin >> n;
  string cap = "";
  vector<string> rat;
  vector<string> man;
  vector<string> wc;

  while(n--){
    string s1, s2; cin >> s1 >> s2;
    if(s2 == "captain") cap = s1;
    if(s2 == "man") man.pb(s1);
    if(s2 == "woman" || s2 == "child") wc.pb(s1);
    if(s2 == "rat") rat.pb(s1);
  }

  if(!rat.empty()){
    for(ll i = 0; i < rat.size(); i++){
      cout << rat[i] << nl;
    }
  }

  if(!wc.empty()){
    for(ll i = 0; i < wc.size(); i++){
      cout << wc[i] << nl;
    }
  }

  if(!man.empty()){
    for(ll i = 0; i < man.size(); i++){
      cout << man[i] << nl;
    }
  }

  if(cap != "") cout << cap << nl;

}

int main(){
// FST_IO
  NoCiLLaX();

}
  

