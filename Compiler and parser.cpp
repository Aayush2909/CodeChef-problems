#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}


int compiler(string S)
{
    if(S[0]=='>') return 0;

    stack <char> s;
    int count=0, res=0;

    for(int i=0; i<S.length(); i++)
    {
        if(s.empty() && S[i]=='>') return count;

        if(!s.empty() && s.top()=='<' && S[i]=='>')
        {
            count+=2;
            s.pop();
            if(s.empty())
            {
                res = max(res,count);
            }
            continue;
        }
        

        s.push(S[i]);
    }

    if(s.empty()) return count;
    else if(res!=0) return res;
    else return 0;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string S;
        cin>>S;

        cout<<compiler(S)<<"\n";
    }

    return 0;
}
