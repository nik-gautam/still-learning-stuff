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

int pre[100005], suff[100005], arr[100001];

void solve()
{
    int n, q, l, r;

    cin >> n >> q;

    FOR(i, 1, n + 1)
    cin >> arr[i];

    pre[0] = suff[n + 1] = 0;

    FOR(i, 1, n + 1)
    {
        // cout << pre[i - 1] << endl;
        pre[i] = __gcd(arr[i], pre[i - 1]);
    }

    FORR(i, n, 1)
    {
        // cout << suff[i + 1] << endl;
        suff[i] = __gcd(arr[i], suff[i + 1]);
    }

    ITR(i, q)
    {
        cin >> l >> r;

        // cout << pre[l - 1] << " " << suff[r] << endl;

        cout << __gcd(pre[l - 1], suff[r + 1]) << endl;
    }
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
