#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string str, string p, long long prime, long long hp)
{
    long long hs = 0;
    int i, j = 0;
    for (i = 0; i < p.size(); i++)
    {
        hs = hs + (str[i] - 96) * pow(prime, i);
    }
    int m = p.size();
    if (hp == hs)
    {
        cout << "Found " << j + 1 << " " << j + m;
        return;
    }
    for (i, j = 0; j <= str.size() - m; i++, j++)
    {
        int x = str[i] - 96;
        int y = str[j] - 96;
        hs = (hs - y) / 3;
        x = (x * pow(prime, 2));
        hs = hs + x;
        if (hp == hs)
        {
            cout << "Found " << j + 1 << " " << j + m;
            return;
        }
    }
    cout << "Not Found" << endl;
    return;
}

int main()
{
    string str = "aaaaaaaaaaaaaaaaaaaha";
    string p = "aha";
    long long prime = 3;
    long long hp = 0;
    for (int i = 0; i < p.size(); i++)
    {
        hp = hp + (p[i] - 96) * pow(3, i);
    }

    rabinKarp(str, p, prime, hp);
}
