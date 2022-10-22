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

void solve()
{
    ll n, q, tot(1), N;
    cin >> n >> q;

    vector<ll> pf_n;

    N = n;

    for (ll i(2); i * i <= N; i++)
    {
        if (N % i == 0)
        {
            pf_n.push_back(i);
            int cnt = 0;

            while (N % i == 0)
                N /= i, cnt++;

            tot *= (cnt + 1);
        }
    }

    if (N > 1)
    {
        tot *= 2;

        pf_n.push_back(N);
    }

    for (ll i = 0; i < q; i++)
    {
        int t(0), cnt(0), ans(0);
        ll k = 0L;
        cin >> t >> k;

        if (t == 1)
        {
            ans = 1;
            ll g = __gcd(k, n);

            for (ll j(0); j < pf_n.size(); j++)
            {
                cnt = 0;

                while (g % pf_n[j] == 0)
                    g /= pf_n[j], cnt++;

                ans *= (cnt + 1);
            }

            cout << ans << endl;
        }
        else
        {
            ans = 0;

            if (n % k == 0)
            {
                ll g = n / k;
                ans = 1;

                for (ll j(0); j < pf_n.size(); j++)
                {
                    cnt = 0;
                    while (g % pf_n[j] == 0)
                        g /= pf_n[j], cnt++;
                    ans *= (cnt + 1);
                }
            }

            if (t == 3)
            {
                ans = tot - ans;
            }

            cout << ans << endl;
        }
    }
}

int main()
{
    FAST;

    int tc = 1;
    // cin >> tc;

    // for (int t = 1; t <= tc; t++)
    // {
    // cout << "Case #" << t << ": ";
    solve();
    // }
}
