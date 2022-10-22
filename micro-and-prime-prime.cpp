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

int prime[1000001];
int pp[1000001];

void seive()
{

    int maxN = 1000000;

    ITR(i, maxN)
    prime[i] = 1;
    prime[0] = prime[1] = 0;

    for (ll i = 2; i * i <= maxN; i++)
    {
        if (prime[i] == 1)
        {
            for (ll j = i * i; j <= maxN; j += i)
                prime[j] = 0;
        }
    }

    int cnt = 0;

    FOR(i, 1, maxN + 1)
    {

        if (prime[i] == 1)
            cnt++;

        if (prime[cnt] == 1)
            pp[i] = 1;
        else
            pp[i] = 0;
    }

    FOR(i, 1, maxN + 1)
    {
        pp[i] += pp[i - 1];
    }
}

void solve()
{
    int l(0), r(0);

    cin >> l >> r;

    cout << pp[r] - pp[l - 1] << endl;
}

int main()
{
    FAST;

    int tc = 1;
    cin >> tc;

    seive();

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
