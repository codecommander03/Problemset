#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x : v) // Inputting all the logs
        cin >> x;

    if (v[0] != -1 && v[0] != 0)
    { // Checking if first Day is breakout or Is uncertain as mentioned in the question.
        cout << -1 << endl;
        return 0;
    }
    v[0] = 0; // Setting first day as breakout.

    for (int i = 0; i < n; i++)
    { // Setting the breakout days based on Positive integeral input values.
        if (v[i] != -1)
        {
            v[i - v[i]] = 0;
        }
    }

    // for(auto x: v)	//Debug Output
    // 	cout<<x<<" ";
    // cout<<endl;

    int breakout = 0, uncertain = 0;
    int lastBreakout = 0;

    for (int i = 0; i < n; i++)
    { // Counting breakout days + Checking the consistency using lastBreakout count.
        if (v[i] == 0)
        {
            lastBreakout = i;
            breakout++;
        }

        if (v[i] != -1 && v[i] != 0 && i - v[i] < lastBreakout)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    { // Counting continuous -1 on which days can be breakout can occur (Right: X-1-1-10) (Wrong: X-1-1-1N)
        int j = i;

        for (; v[j] == -1; j++)
            ;

        if (v[j] == 0)
            uncertain += j - i;

        i = j;
    }

    cout << breakout << ' ' << breakout + uncertain << endl;
}