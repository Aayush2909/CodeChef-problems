#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void calc(char arr[], int n)
{
    int disA[n];
    int best = INT_MAX;

    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] == 'A')
        {
            disA[i] = 0;
            best = i;
            continue;
        }

        disA[i] = best!=INT_MAX ? best-i : INT_MAX;
        
    }

    int a = 0, b = 0;

    best = INT_MAX;
    int disB;

    for(int i=0; i<n; i++)
    {
        if(arr[i] == 'B')
        {
            b++;
            best = i;
            continue;
        }
        if(arr[i] == 'A')
        {
            a++;
            continue;
        }

        disB = best!=INT_MAX ? i-best : INT_MAX;

        if(arr[i] == '-')
        {
            if(disB < disA[i])
            {
                arr[i] = 'B';
                b++;
            }
            else if(disA[i] < disB)
            {
                arr[i] = 'A';
                a++;
            }
        }
        
    }


    if(a>b) cout<<"A";
    else if(b>a) cout<<"B";
    else cout<<"Coalition government";
}


int main()
{
    int n;
    cin>>n;

    char arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    calc(arr,n);


}
