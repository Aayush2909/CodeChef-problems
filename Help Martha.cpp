#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m = 2e16;

ll minSteps(pair<ll, ll> start, string S, pair<ll, ll> dest)
{
    if(start.first == dest.first && start.second==dest.second) return 0;
    if(start.first>dest.first || start.second>dest.second || S.empty()) return m;

    pair <ll, ll> upd = start;
    if(S[0] == 'R') upd.first = start.first+1;
    else if(S[0] == 'L') upd.first = start.first-1;
    else if(S[0] == 'D') upd.second = start.second-1;
    else upd.second = start.second+1;

    ll inc = 1 + minSteps(upd, S.substr(1), dest);
    ll exc = minSteps(start, S.substr(1), dest);

    return min(inc, exc);
}


void solver(pair <ll, ll> s, string S, pair<ll, ll> q[], ll n)
{

    for(int i=0; i<n; i++)
    {
        ll ans = minSteps(s, S, q[i]);
        if(ans < m)
        {
            cout<<"YES "<<ans<<"\n";
        }
        else
            cout<<"NO\n";
    }

}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);


    int t;
    cin>>t;

    while(t--)
    {

        string S;
        cin>>S;

        pair<ll, ll> s;
        ll x,y;
        cin>>x>>y;
        s.first = x;
        s.second = y;

        ll n;
        cin>>n;

        pair <ll,ll> q[n];
        for(ll i=0; i<n; i++)
        {
            ll x2,y2;
            cin>>x2>>y2;

            q[i].first = x2;
            q[i].second = y2;
        }

        solver(s, S, q, n);

    }

    return 0;
}
