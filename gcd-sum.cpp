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

int phi[1000001];

void init(int maxN)
{

    FOR(i, 1, maxN + 1)
    phi[i] = i;

    FOR(i, 2, maxN + 1)
    if (phi[i] == i)
    {

        for (int j = i; j <= maxN; j += i)
        {
            phi[j] /= i;
            phi[j] *= (i - 1);
        }
    }
}

int getCount(int d, int n)
{
    return phi[n / d];
}

void solve()
{
    int q, n;
    cin >> q;

    while (q--)
    {

        cin >> n;
        int res = 0;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int d1 = i;
                int d2 = n / i;

                res += d1 * getCount(d1, n);

                if (d1 != d2)
                {
                    res += d2 * getCount(d2, n);
                }
            }
        }

        cout << res << endl;
    }
}

int main()
{
    FAST;

    init(1000000);

    int tc = 1;
    // cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
