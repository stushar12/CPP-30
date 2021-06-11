#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
    int j = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(string txt, string pat)
{
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return 1;
            //cout<<"Found pattern from index "<< i - j<<" to "<<i-1<<"\n";
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return 0;
}

bool rotation(string s1, string s2)
{
    string s3;
    if (s1.length() != s2.length())
        return false;

    s3 = s1.append(s1);
    if (KMPSearch(s3, s2))
        return true;
    else
        return false;
}
int main()
{
    string s1 = "rambo";
    string s2 = "bramo";

    cout << rotation(s1, s2);
}
