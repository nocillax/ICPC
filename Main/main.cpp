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
#define pl            pair<ll,ll>
#define all(x)        x.begin(), x.end()
#define ff            first
#define ss            second
#define mod           10000007
#define INF           2e18
#define EPS           1e-2
#define tt            ll t; cin>>t; while(t--)
#define sp(n)         fixed<<setprecision(n)
// ------------------------------------------------------------------------------
  
string bigSum(string a, string b){

  ll carry = 0;
  vector<string> v;

  reverse(all(a));
  reverse(all(b));

  ll sz = max(a.size(),b.size());

  for (ll i = 0; i < sz; i++){

      ll x, y, z;

      if (i < a.size()) x = a[i] - '0';
      else x = 0;

      if (i < b.size()) y = b[i] - '0';
      else y = 0;

      z = x + y + carry;

      if(z >= 10){
          z = z - 10;
          v.pb(to_string(z));
          carry = 1;
      }
      else{
          v.pb(to_string(z));
          carry = 0;
      }

  }

  if(carry == 1) v.pb(to_string(carry));

  string s = "";

  reverse(all(v));

  for(ll i = 0; i < v.size(); i++){
      s += v[i];
  }

  return s;
}

void NoCiLLaX(){
  string a, b;
  cin >> a >> b;
  cout << bigSum(a,b) << nl;
}

int main(){
  FST_IO
  NoCiLLaX();


}
  

