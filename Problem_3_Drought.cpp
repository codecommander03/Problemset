#include <iostream>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int h[n + 2];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    long long answer = 0;
    for (int i = 0; i < n - 2; i++)
    {
        // lets say that we want to make h[i]=h[i+1]
        // We would have to reduce h[i+1] and h[i+2] until h[i+1]==h[i];
        // lets say h[i]> h[i+1]. Then we would never make h[i]==h[i+1], without reducing h[i]
        if (h[i] >= h[i + 1])
            continue;
        int dif = h[i + 1] - h[i];
        h[i + 1] = h[i];
        h[i + 2] = h[i + 2] - dif;
        answer += dif;
    }
    // notice how they may not be equal. We can reverse our initial process now!
    for (int i = n - 1; i >= 2; i--)
    {
        if (h[i] >= h[i - 1])
        {
            continue;
        }
        // lets now make h[i]==h[i-1]
        int dif = h[i - 1] - h[i];
        h[i - 1] = h[i];
        h[i - 2] = h[i - 2] - dif;
        answer += dif;
    }
    for (int i = 0; i < n; i++)
    {
        if (h[i] < 0)
            answer = -1;
    } // invalid
    for (int i = 0; i < n - 1; i++)
    {
        if (h[i] != h[i + 1])
            answer = -1;
    }
    if (answer == -1)
    {
        cout << -1 << endl;
    }
    else
        cout << answer * 2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}