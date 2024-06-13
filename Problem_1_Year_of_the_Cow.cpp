#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> yrnumb = {
        {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};

    int N;
    cin >> N;
    map<string, int> cowage;
    cowage["Bessie"] = 0;

    for (int i = 0; i < N; i++)
    {
        string c1, c2, dir, yr, t;
        cin >> c1 >> t >> t >> dir >> yr >> t >> t >> c2;

        int age = cowage[c2], d;
        if (dir == "previous")
        {
            d = -1;
        }
        else if (dir == "next")
        {
            d = 1;
        }

        do
        {
            age += d;
        } while ((12 + age % 12) % 12 != yrnumb[yr]);
        cowage[c1] = age;
    }

    cout << abs(cowage["Elsie"]) << '\n';
    return 0;
}