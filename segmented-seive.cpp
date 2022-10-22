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

vector<int> primes;
int prime[100001];

void seive(int maxN)
{
    vector<int> arr(maxN + 1, 0);

    arr[1] = 1;

    FOR(i, 2, maxN + 1)
    if (arr[i] == 0)
    {
        for (int j = 2 * i; j <= maxN; j += i)
        {
            arr[j] = 1;
        }
    }

    FOR(i, 1, maxN + 1)
    if (arr[i] == 0)
    {
        primes.push_back(i);
    }
}

void init(int l, int r)
{

    if (l == 1)
        l++;

    int maxN = r - l + 1;

    vector<int> arr(maxN, 0);

    for (ll p : primes)
        if (p * p <= r)
        {

            int i = (l / p) * p;
            if (i < l)
                i += p;

            for (; i <= r; i += p)
            {
                if (i != p)
                    arr[i - l] = 1;
            }
        }

    ITR(i, maxN)
    if (arr[i] == 0)
        cout << l + i << endl;
}

void solve()
{
    int l, r;

    cin >> l >> r;

    init(l, r);

    cout << endl;
}

int main()
{
    FAST;

    seive(100001);

    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
