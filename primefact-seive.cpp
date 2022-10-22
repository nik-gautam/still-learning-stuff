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

int prime[100001];

void seive()
{
    int maxN = 100000;

    FOR(i, 1, maxN + 1)
    {
        prime[i] = -1;
    }

    for (int i = 2; i <= maxN; i++)
        if (prime[i] == -1)
        {
            
            
            for (int j(i); j <= maxN; j += i)
            {
                if (prime[j] == -1)
                    prime[j] = i;
            }
        }
}

void solve()
{
    seive();

    for (int i = 2; i < 11; i++)
    {
        int s = i;
        
        string ans = "";

        unordered_set<int> pp;

        while (s > 1 && prime[s] != 0)
        {
            //cout << s << " " << prime[s] << endl;
            
            //ans.append(to_string(prime[s]) + " ");
            pp.insert(prime[s]);
            
            s /= prime[s];
        }

        for(int k: pp) {
            ans += to_string(k) + " ";
        }
            

        cout << i << ": " << ans << endl;
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
