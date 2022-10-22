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

int F[1000001];

int power(int a, int n)
{

    int res = 1;

    while (n)
    {

        if (n % 2)
        {
            res = (res * 1LL * a) % MOD;
            n--;
        }
        else
        {
            a = (a * 1LL * a) % MOD;
            n /= 2;
        }
    }

    return res;
}

int C(int n, int k)
{
    if (k > n)
    {
        return 0;
    }

    int res = F[n];

    res = (res * 1LL * power(F[k], MOD - 2)) % MOD;
    res = (res * 1LL * power(F[n - k], MOD - 2)) % MOD;

    return res;
}

void solve()
{
    F[0] = F[1] = 1;

    FOR(i, 2, 1000001)
    F[i] = (F[i - 1] * 1LL * i) % MOD;

    int q;
    int n, k;

    cin >> q;

    while (q--)
    {

        cin >> n >> k;

        cout << C(n, k) << endl;
    }
}

int main()
{
    FAST;

    int tc = 1;
    // cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
