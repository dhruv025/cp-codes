#include<iostream>
using namespace std;
int main()
{
    int t,n,m,len;
    string txt,patt;
    cin >> t;
    while(t--)
    {
        cout<<"Enter text : ";
        cin >> txt;
        cout<<"Enter patt : ";
        cin >> patt;
        n = txt.length();
        m = patt.length();
        len = 0;
        int lps[m],i = 1;
        lps[0] = 0;
        //finding LPS array
        while(i < m)
        {
            if(patt[len] == patt[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len != 0)
                    len = lps[len-1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        //KMP search
        int k = 0, j = 0;
        while(k < n)
        {
            if(txt[k] == patt[j])
            {
                k++;
                j++;
            }
            if(j == m)
            {
                cout<<"Pattern found at index : "<<k-j;
                j = lps[j-1];
            }
            else if(k < n && txt[k] != patt[j])
            {
                if(j != 0)
                    j = lps[j-1];
                else
                    k = k + 1;
            }
        }
    }
}
