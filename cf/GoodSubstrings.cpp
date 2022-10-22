/**
 * @file GoodSubstrings.cpp
 * @author nik-gautam
 * @brief 271-D
 * @date 2022-09-04
 */

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
const ll MOD = 1e9 + 9;
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
    const int p = 31;

    string str;
    cin >> str;

    int n = str.size();

    string good_alphabets;
    cin >> good_alphabets;

    int k;
    cin >> k;

    vector<int> prefix(n, 0);
    vector<ll> p_pow(n, 0);
    vector<ll> h(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int is_good = good_alphabets[str[i] - 'a'] == '0' ? 1 : 0;

        if (i == 0)
        {
            prefix[i] = is_good;
        }
        else
        {
            prefix[i] = prefix[i - 1] + is_good;
        }
    }

    p_pow[0] = 1;
    for (int i(1); i < n; i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % MOD;
    }

    for (int i(0); i < n; i++)
    {
        h[i + 1] = (h[i] + (str[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    int count = 0;

    for (int l(1); l <= n; l++)
    {
        set<ll> hs;
        for (int i(0); i <= n - l; i++)
        {
            ll cur_h = (h[l + i] + MOD - h[i]) % MOD;
            cur_h = (cur_h * p_pow[n - i - 1]) % MOD;

            ll bad_count = prefix[l + i - 1];

            if (i > 0)
                bad_count = prefix[l + i - 1] - prefix[i - 1];

            if (bad_count <= k)
            {
                hs.insert(cur_h);
            }

        }

        count += hs.size();
    }

    cout << count;
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
