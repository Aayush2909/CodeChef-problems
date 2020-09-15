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


void covid(int arr[], int n, int i, int infect[], double time_elapsed)
{

    for(int j=0; j<n; j++)
    {
        if(j==i || infect[j] == 1 || arr[i]==arr[j]) continue;

        if(arr[i]==arr[j]) continue;
        else if(j<i && arr[j]>arr[i] )
        {
            double time = ((double)(i-j))/(arr[j]-arr[i]);

            if(time>=time_elapsed)
            {
                infect[j] = 1;
                covid(arr, n, j, infect, time);
            }
        }
        else if(j>i && arr[j]<arr[i])
        {

            double time = ((double)(j-i))/(arr[i]-arr[j]);
            
            if(time>=time_elapsed)
            {
                infect[j] = 1;
                covid(arr, n, j, infect, time);
            }
            
        }
    }

    return;
}

pair<int,int> solver(int arr[], int n)
{
    int count[n] = {0};

    for(int i=0; i<n; i++)
    {
        int infect[n] = {0};
        infect[i] = 1;

        covid(arr, n, i, infect, 0.0);

        for(int j=0; j<n; j++)
        {
            if(infect[j]==1) count[i]+=1;
        }
    }

    int maxx=1, minn=5;
    for(int i=0; i<n; i++)
    {
        maxx = max(maxx, count[i]);
        minn = min(minn, count[i]);
    }

    return make_pair(minn, maxx);
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

        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        pair<int, int> res = solver(arr, n);
        int a = res.first;
        int b = res.second;

        cout<<a<<" "<<b<<"\n";
    }


    return 0;
}
