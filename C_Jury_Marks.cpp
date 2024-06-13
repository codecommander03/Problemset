#include <bits/stdc++.h>

// Time Complexity: O(nk)
using namespace std;
int nxt()
{
    int a;
    cin >> a;
    return a;
}

int k = nxt(), n = nxt();
vector<int> b(n);
set<int> a_sums;
unordered_map<int, int> possible;
int main()
{
    int sum = 0, solution = 0;
    for (int i = 0; i < k; ++i)
    {
        sum += nxt();
        a_sums.insert(sum);
    }
    generate(b.begin(), b.end(), nxt);

    bool found = true;
    for (int i : b)
    {
        for (int j : a_sums)
        {
            if (possible.count(i - j))
            {
                found = true;
            }
            if (found)
                possible[i - j]++;
            if (possible[i - j] == n)
                solution++;
        }
        if (!found)
        {
            cout << 0 << endl;
            exit(0);
        }
        found = false;
    }

    cout << solution << endl;

    return 0;
}