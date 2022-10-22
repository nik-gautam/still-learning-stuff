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

int arr[101][101], I[101][101];

void mul(int A[][101], int B[][101], int dim)
{

    int res[dim][dim];

    ITR(i, dim)
    ITR(j, dim)
    {
        res[i][j] = 0;

        ITR(k, dim)
        {
            res[i][j] = (res[i][j] % MOD + (A[i][k] % MOD * B[k][j] % MOD) % MOD) % MOD;
        }
    }

    ITR(i, dim)
    ITR(j, dim)
    A[i][j] = res[i][j];
}

void print(int A[][101], int dim)
{

    ITR(i, dim)
    {
        ITR(j, dim)
        cout << A[i][j] << " ";

        cout << endl;
    }
}

void solve()
{
    int dim(0), n(0);

    cin >> dim >> n;

    ITR(i, dim)
    ITR(j, dim)
    cin >> arr[i][j];

    ITR(i, dim)
    ITR(j, dim)
    {
        if (i == j)
            I[i][j] = 1;
        else
            I[i][j] = 0;
    }

    // naive method:
    // ITR(i, n)
    // mul(I, arr, dim);

    while (n)
    {
        if (n % 2 == 0)
        {
            mul(arr, arr, dim);
            n /= 2;
        }
        else
        {
            mul(I, arr, dim);
            n--;
        }
    }

    ITR(i, dim)
    ITR(j, dim)
    arr[i][j] = I[i][j];

    print(arr, dim);
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
