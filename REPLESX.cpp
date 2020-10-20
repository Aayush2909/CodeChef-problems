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


int solver(int arr[], int n, int x, int p, int k, bool present)
{
    sort(arr, arr+n);

    if(present)
    {
        if(p == k)
        {
            if(arr[k] == x) return 0;
            else
            {
                if(arr[k] > x)
                {
                    int found;
                    for(int i=k-1; i>=0; i--)
                    {
                        if(arr[i] == x)
                        {
                            found = i;
                            break;
                        }
                    }

                    return k-found;
                }
                else
                {
                    int found;
                    for(int i=k+1; i<n; i++)
                    {
                        if(arr[i] == x)
                        {
                            found = i;
                            break;
                        }
                    }

                    return found-k;
                }
                
            }
            
        }

        else if(p < k)
        {
            if(arr[p] == x) return 0;
            else if(arr[p]<x) return -1;
            else
            {
                int found;
                for(int i=p-1; i>=0; i--)
                {
                    if(arr[i]==x)
                    {
                        found = i;
                        break;
                    } 
                }

                return p-found;
            }
            
        }
        else
        {
            if(arr[p] == x) return 0;
            else if(arr[p]>x) return -1;
            else
            {
                int found;
                for(int i=p+1; i<n; i++)
                {
                    if(arr[i]==x)
                    {
                        found = i;
                        break;
                    } 
                }

                return found-p;
            }
        }
        
    }
    else
    {
        arr[k] = x;
        int rec = solver(arr, n, x, p, k, true);
        if(rec != -1)
        {
            return 1+rec;
        }
        else return -1;
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
        int n,x,p,k;
        cin>>n>>x>>p>>k;

        bool present = false;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i] == x)
            {
                present = true;
            }
            
        } 

        cout<<solver(arr, n, x, p-1, k-1, present)<<endl;
    }

    return 0;
}
