/*********************************************************************
 *-------------------------------------------------------------------*
 *                                                                   *
 *   Life is just a life. Lead it, Feel it & Enjoy It Properly.      *
 *   Nothing is impossible. Just believe in yourself & Almighty.     *
 *                                                                   *
 *-------------------------------------------------------------------*
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;

///######################### Typedef Section #########################

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

///###################################################################

///######################### Input Section ###########################

#define si1(x)        scanf("%d",&x)
#define si2(x,y)      scanf("%d %d", &x, &y)
#define si3(x,y,z)    scanf("%d %d %d", &x, &y, &z)

#define sd1(x)        scanf("%lf",&x)
#define sd2(x,y)      scanf("%lf %lf", &x, &y)
#define sd3(x,y,z)    scanf("%lf %lf %lf", &x, &y, &z)

#define sli1(x)       scanf("%lld",&x)
#define sli2(x,y)     scanf("%lld %lld", &x, &y)
#define sli3(x,y,z)   scanf("%lld %lld %lld", &x, &y, &z)

///###################################################################

///######################### Define Section ##########################

#define nl            "\n"
#define pi            acos(-1.0)
#define mem(arr,val)  memset(arr,val,sizeof(arr))
#define pb            push_back
#define mp            make_pair
#define pr            pair<ll,ll>
#define mod           1000000007

///###################################################################

///######################### Index Section ###########################

///A) Number Theory
///    1.Bit Set
///    2.GCD & LCM
///    3.Divisor
///    4.Primality test
///    5.Probably Prime Fermat
///    6.Miller Rabin
///    7.Bitwise Sieve
///    8.Segment Sieve
///    9.Prime Factorization
///    10.Big Mod & Inverse Mod
///    11.Extended Euclid
///    12.Euler's totient function
///    13.Matrix Exponentiation
///    14.Fast Doubling Method

///###################################################################

///######################### 1.Number Theory #########################

///------------------------- 1.Bit set -------------------------------

int BitSetUp(int x, int idx){ return x = x | (1<<idx); }
int BitUnSet(int x, int idx){ return x = x & (~(1<<idx)); }
bool BitCheking(int x, int idx){ return x & (1<<idx); }
bool PowerOfTwo(int x){ return (x && !(x&(x-1))); }

///-------------------------------------------------------------------

///------------------------- 2.GCD & LCM -----------------------------

ll GCD(ll a, ll b){ return b==0 ? a : GCD(b,a%b); }
ll LCM(ll a, ll b) { return (a/GCD(a,b))*b; }

///-------------------------------------------------------------------

///------------------------- 3.Divisor -------------------------------

ll Divisor(ll n)
{
    ll cnt=0;
    for(ll i=1; i*i<=n; i++)
    {
        if(i*i==n) cnt++;
        else if(n%i==0) cnt+=2;
    }
    return cnt;
}

///-------------------------------------------------------------------

///------------------------- 4.Primality test ------------------------

bool Primality(ll n)
{

    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;

    for(ll i=3; i*i<=n; i+=2)
        if(n%i==0) return false;

    return true;
}

bool Wheel(ll n){
    bool chk = true;
    ll b[8] = {7, 11, 13, 17, 19, 23, 29, 31};
    if(n%2==0 || n%3==0 || n%5==0) return false;

    for(ll i=0; i<sqrt(n); i+=30){
        for(ll j=0; j<8; j++){
            if(b[j]>sqrt(n)) break;
            else{
                if(n%(b[j]+i)==0){
                    chk = false;
                    break;
                }
            }
        }
        if(!chk) break;
    }
    return chk;
}
///-------------------------------------------------------------------

///----------------------- 5.Probably Prime Fermat -------------------

bool ProbablyPrimeFermat(ll n, int iter=5) {
    /// Fastest Primality check
    /// Work in 10^9 easily
    /// Fail in Carmichael numbers
    if (n < 4)
        return n == 2 || n == 3;

    for (ll i = 0; i < iter; i++) {
        ll a = 2 + rand() % (n - 3);
        if (BigMod(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

///-------------------------------------------------------------------

///----------------------- 6.Miller Rabin ----------------------------

ll mult(ll a, ll b, ll mod) {
    ll result = 0;
    while(b){
        if(b & 1) result = (result + a) % mod;
        a=(a + a)%mod;
        b>>=1;
    }
    return result;
}

ll BigMod(ll a, ll b, ll mod) {
    ll result=1;
    while (b){
        if (b&1) result = mult(result,a,mod);
        a=mult(a,a,mod);
        b >>= 1;
    }
    return result;
}

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;

    ll d = n - 1;
    while(d%2==0) d >>= 1;

    int RR[]={2, 3, 5, 7, 11, 13, 17};
    for (int i=0; i<7; i++) {
        ll x = RR[i]%(n-2), pk=d;
        if(x<2) x+=2;

        ll a = BigMod(x,d,n);
        while(pk!=n-1 && a!=1 && a!=n-1)
        {
            a=mult(a,a,n);
            pk<<=1;
        }
        if(a!=n-1 && (pk&1)==0) return false;
    }
    return true;
}

///-------------------------------------------------------------------

///----------------------- 7.Bitwise Sieve ---------------------------

#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void sieve(ll n) {
  for (ll i = 3; i * i < n; i += 2) {
    if (!on(i)) {
      for (ll j = i * i; j <= n; j += i + i) {
        mark(j);
      }
    }
  }
}
bool isPrime(ll num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
vector<ll>ArP;
void Prime_Store()
{
    sieve(M);
    /// Store Prime 10^8
    for(ll i=2; i<=M; i++)
        if(isPrime(i)) ArP.push_back(i);
}

///-------------------------------------------------------------------

///-------------------------- 8.Segment Sieve ------------------------

ll Segment_Sieve(ll l, ll r){
    bool isPrime[r - l + 1]; //filled by true
    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
    ll cnt = 0;
    for (long long i = max(l, 2); i <= r; ++i) {
        if (isPrime[i - l]) {
            cnt++;//then i is prime
        }
    }
    return cnt;
}

///-------------------------------------------------------------------

///----------------------- 9.Prime Factorization ---------------------

void Prime_Factorization(ll n)
{
    map<ll,ll>m;   // work on this line
    for(ll j=2;j*j<=n;j++) while(n%j==0) n/=j,m[j]++;
		if(n>1) m[n]++;
    map<ll,ll>::iterator it;
	for(it=m.begin(); it!=m.end(); it++)
        cout << it->first << "^" << it->second << nl;
}


vector<ll> Wheel_factoriation(ll n) {
    vector<ll> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    int increments[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
///-------------------------------------------------------------------
ll fermat(ll n) {
    ll a = ceil(sqrt(n));
    ll b2 = a*a - n;
    ll b = round(sqrt(b2));
    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = round(sqrt(b2));
    }
    return a - b;
}
///-------------------- 10.Big Mod & Inverse Mod ----------------------

ll BigMod(ll b, ll p)
{
    ll res=1;
    p=p%mod;
    //if(p==0) return 1;
    while(p)
    {
        if(p&1) res=(res*b)%mod;
        b=(b*b)%mod;
        p=p>>1;
    }
        return res;
}

ll Inverse_Mod(ll b)
{
    return BigMod(b,mod-2);
}

///-------------------------------------------------------------------
ll pollards_p_minus_1(ll n) {
    ll B = 10;
    ll g = 1;
    while (B <= 1000000 && g < n) {
        long long a = 2 + rand() %  (n - 3);
        g = gcd(a, n);
        if (g > 1)
            return g;

        /// compute a^M
        for (ll p : primes) {
            if (p >= B)
                continue;
            long long p_power = 1;
            while (p_power * p <= B)
                p_power *= p;
            a = BigMod(a, p_power, n);

            g = gcd(a - 1, n);
            if (g > 1 && g < n)
                return g;
        }
        B *= 2;
    }
    return 1;
}
///----------------------- 11.Extended Euclid ------------------------

ll Extended_Euclid(ll a, ll b) {
	if (b == 0)
		return 1;
	if (b % 2)
		return Extended_Euclid(a, b - 1) * a % M;
	return Extended_Euclid(a * a % M, b / 2);
}

ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

///-------------------------------------------------------------------

///-------------------- 15.Diophantine Equation ----------------------

bool Diophantine_Check(ll a, ll b, ll c) {
    ll x, y, g;
    g = GCD(abs(a), abs(b));
    if (c % g) {
        return false;
    }

    x *= c / g;
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

///-------------------------------------------------------------------

///-------------------- 15.Diophantine Equation ----------------------

///-------------------------------------------------------------------

///------------------- 12.Euler's totient function -------------------

ll Phi_Functoin(ll n)
{
    ll ret=n;
    for(ll i=2; i*i<=n; i++)
        if(n%i==0)
        {
            while(n%i==0) n /= i;
            ret -= ret / i;
        }
    if(n>1) ret-=ret/n;
    return ret;
}

ll phi[M];
void Phi_table()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= M; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= M/2; i++)
        for (int j = 2 * i; j <= M; j += i)
              phi[j] -= phi[i];
}

///-------------------------------------------------------------------

///-------------------- 13.Matrix Exponentiation ---------------------

struct Matrix
{
    ll v[3][3];
};

Matrix Multiply(Matrix A, Matrix B){
    Matrix C;
    ll x=2, y=2, z=2;

     for(ll i=0; i<x; i++){
        for(ll j=0; j<z; j++){
            ll sum=0;
            for(ll k=0; k<y; k++){
                sum+=(A.v[i][k]*B.v[k][j])%mod;
            }
            C.v[i][j]=sum%mod;
        }
    }

    return C;
}

Matrix M_BigMod(Matrix M, ll p){
    if(p==1) return M;
    if(p&1) return Multiply(M,M_BigMod(M,p-1));

    p=p>>1;
    Matrix Q = M_BigMod(M,p);
    Q = Multiply(Q,Q);
    return Q;
}

///-------------------------------------------------------------------

///-------------------- 14.Fast Doubling Method ----------------------

void FastDoubling(ll n, ll res[])
{
    if (n == 0) {
        res[0] = 0;
        res[1] = 1;
        return;
    }
    FastDoubling((n / 2), res);

    a = res[0];
    b = res[1];
    c = 2 * b - a;

    if (c < 0)
        c += MOD;

    c = (a * c) % MOD;
    d = (a * a + b * b) % MOD;

    if (n % 2 == 0) {
        res[0] = c;
        res[1] = d;
    }
    else {
        res[0] = d;
        res[1] = c + d;
    }
}

///-------------------------------------------------------------------


///----------------------- 6.Miller Rabin ----------------------------
///-------------------------------------------------------------------


///###################################################################

int main(){
    while(1){
        ll A, B;
        cin >> A >> B;
        extendedEuclid(A,B);
        cout << x << " to " << y << nl;
    }
    return 0;
}
