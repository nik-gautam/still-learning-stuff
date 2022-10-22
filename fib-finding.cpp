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

ll arr[2], I[2][2], T[2][2];

void mul(ll A[2][2], ll B[2][2], int dim)
{

    int res[dim][dim];

    ITR(i, dim)
    ITR(j, dim)
    {
        res[i][j] = 0;

        ITR(k, dim)
        {
            ll temp = (A[i][k] * B[k][j]) % MOD;
            res[i][j] = (res[i][j] + temp) % MOD;
        }
    }

    ITR(i, dim)
    ITR(j, dim)
    A[i][j] = res[i][j];
}

void solve()
{
    int n;

    cin >> arr[0] >> arr[1] >> n;

    if (n <= 1)
    {
        cout << arr[n] << endl;

        return;
    }

    I[0][0] = I[1][1] = 1;
    I[0][1] = I[1][0] = 0;

    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;

    while (n)
    {

        if (n % 2)
        {
            mul(I, T, 2);
            n--;
        }
        else
        {
            mul(T, T, 2);
            n /= 2;
        }
    }

    ll fn = (arr[0] * I[0][0] + arr[1] * I[1][0]) % MOD;

    cout << fn << endl;
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
