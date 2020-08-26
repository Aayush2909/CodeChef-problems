#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1000
#define Q 1000000

int chefWork(int a[], int size, int max_weight)
{
    int result = 0;
    int add = 0;


    for(int i=0; i<size; ++i)
    {
        add = add + a[i];

        if(add <= max_weight)
        {
            continue;
        }
        else
        {
            add = a[i];

            if(add > max_weight)
            {
                return -1;
            }

            result = result + 1;
            continue;
        }


    }

    result = result + 1;
    return result;
}

int main()
{

    int testcases;
    cin>>testcases;

    while(testcases > 0)
    {

        int size, max_weight;
        cin>>size>>max_weight;
        
        int a[size];
        for(int i=0; i<size; ++i)
        {
            int x;
            cin>>x;
            a[i] = x;
        }

        int result = chefWork(a, size, max_weight);
        cout<<result<<"\n";

        testcases -= 1;
    }

    return 0;
}
