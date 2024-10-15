#include <bits/stdc++.h>
using namespace std;

void kmp(string str, string p, vector<int> &pi)
{
    int n = str.size();
    int m = p.size();
    int q = 0;
    cout << m << endl;
    /* for(int i=1;i<pi.size();i++){
            cout<<pi[i]<<" ";
        }

    */
    for (int i = 1; i <= n; i++)
    {

        while (q > 0 && p[q + 1] != str[i])
        {
            q = pi[q];
        }
        if (p[q + 1] == str[i])
        {
            q++;
        }
        if (q == m - 1)
        {
            cout << "Found " << i - q + 1 << " " << i << endl;
            return;
        }
        // q=pi[q];
    }
    cout << "Not Matched";
}

vector<int> prefix(string p)
{
    int m = p.size();
    vector<int> pi(m + 1);
    pi[0] = 0;
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q < m; q++)
    {
        while (k > 0 && (p[k + 1] != p[q]))
        {
            k = pi[k];
        }
        if (p[k + 1] == p[q])
        {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

int main()
{

    // string str="xbacbabababacaca";
    //  string p="xababaca";
    string str = " rabiul";
    string p = " iul";
    vector<int> pi;
    pi = prefix(p);
    /*
    for(int i=1;i<pi.size();i++){
        cout<<pi[i]<<" ";
    }
*/
    kmp(str, p, pi);
}
