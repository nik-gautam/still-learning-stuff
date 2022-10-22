#include <bits/stdc++.h>

using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long
#define ld long double
#define ull unsigned long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pnl printf("\n")

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define ITR(i, n) for (int i = 0; i < (n); i++)
#define ITRR(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)

const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int power(int a, int n, int m)
{

    int res = 1;

    while (n--)
    {
        if (n % 2)
        {
            a = a * n;
            n--;
        }
        else
        {
            a = a * a;
            n /= 2;
        }
    }

    return res;
}

int modInverse(int a, int m)
{
    return power(a, m - 2, m);
}

void solve()
{
    int n;

    cin >> n;

    int temp = n * (n + 1) / 2;

    temp %= MOD;

    if ((n + 1) % 2)
    {
        temp *= (n + 1);
    }
    else
    {
        temp *= (n + 1) / 2;
    }

    temp %= MOD;

    int modInv = modInverse((n + 1) % 2 + 1, MOD);

    cout << (modInv * temp) % MOD << endl;
}

int main()
{
    FAST;

    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
