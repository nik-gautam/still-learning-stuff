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
const ll MOD = 1e9 + 7;
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

int power(ll a, ll n, ll d)
{

    int res = 1;

    while (n)
    {
        if (n % 2)
        {
            res = ((a % d) * (res % d)) % d;
            n--;
        }
        else
        {
            a = ((a % d) * (a % d)) % d;
            n /= 2;
        }
    }

    return res % MOD;
}

void solve()
{
    ll a, b, n;

    cin >> a >> b >> n;

    if (a == b)
    {
        cout << (power(a, n, MOD) + power(b, n, MOD)) % MOD << endl;
        return;
    }

    ll curr = 1;
    ll num = a - b;

    for (ll i(1); i * i <= num; i++)
    {
        if (num % i == 0)
        {
            ll temp = (power(a, n, i) + power(b, n, i)) % i;

            if (temp == 0)
                curr = max(curr, i);

            temp = (power(a, n, num / i) + power(b, n, num / i)) % (num / i);

            if (temp == 0)
                curr = max(curr, num / i);
        }
    }

    cout << curr % MOD << endl;
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
