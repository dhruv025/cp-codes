#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s,str,str1,str2,substring = "";
    char ch;
    int q,mag;
    cin >> s >> q;
    int len = s.length();
    while(q--)
    {
        str1 = "", str2 = "";
        cin >> ch >> mag;
        if(ch == 'L')
        {
            for(int i = 0; i < mag; ++i)
                str1 = str1 + s[i];
            for(int i = mag; i < len; ++i)
                str2 = str2 + s[i];
            str = str2 + str1;
            substring = substring + str[0];
        }
        else if(ch == 'R')
        {
            for(int i = len-1; i >= len-mag; --i)
                str1 = str1 + s[i];
            reverse(str1.begin(),str1.end());
            for(int i = 0; i < len-mag; ++i)
                str2 = str2 + s[i];
            str = str2 + str1;
            substring = substring + str[0];
        }
        cout<<str<<" "<<substring<<"\n";
    }
    int fsub[26] = {0}, l = substring.length(),fs[26] = {0},c = 0;
    for(int i = 0; i < l; ++i)
    {
        fsub[substring[i] - 'a']++;
        fs[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(fsub[i] == fs[i])
            c++;
        else
            break;
    }
    for(int i = 1; i < len-l+1; ++i)
    {
        c = 0;
        fs[s[i-1] - 'a'] = fs[s[i-1] - 'a'] - 1;
        fs[s[i-1+l] - 'a'] = fs[s[i-1+l] - 'a'] + 1;
        for(int j = 0; j < 26; ++j)
        {
            if(fsub[j] == fs[j])
                c++;
        }
        if(c == 26)
            break;
    }
    if(c == 26)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
}
