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

#define N 64


int adamat(int arr[N][N], int n)
{
    int mark[n];

    for(int j=0; j<n; j++)
    {
        if(arr[0][j] != (j+1)) mark[j] = 0;
        else mark[j] = 1;
    }

    int k = -1;
    for(int i=n-1; i>=0; i--)
    {
        if(mark[i]==0)
        {
            k=i;
            break;
        }
    }

    if(k == -1) return 0;
    
    int count=0;

    for(int i=1; i<=k; i++)
    {
        if(i==1 && mark[i]==1)
        {
            count+=1;
        }
        else if(mark[i]==1 && mark[i-1]!=1)
        {
            count+=2;
        }
        
    }

    return count+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[N][N];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }

        cout<<adamat(arr, n)<<"\n";
    }

    return 0;
}
