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

#define N 100


ll swapCount(ll n)
{
    ll total_sum = (n*(n+1))/2;

    if(total_sum%2!=0) return 0;

    ll count = 0;
    ll avg = total_sum/2;

    ll eq = 2*n*n + 2*n + 1;
    ll k = floor((sqrt(eq)-1)/2);
    

    if(sqrt(eq) == floor(sqrt(eq)))
    {
        if(k>=2)
        {
            count += (k*(k-1))/2;
        }
        if((n-k)>=2)
        {
            count += ((n-k)*(n-k-1))/2;
        }

        k -= 1;
    }


    ll sum = (k*(k+1))/2;

    
    ll req = avg - sum;
    if((k+1)==req)
    {
        count += n-(k+1);
    }
    else if((k+1-req)>=1)
    {

        count += n-k;
    }

    return count;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        cout<<swapCount(n)<<"\n";
        

    }

    return 0;
}
