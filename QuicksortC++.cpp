#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll partition(vector<ll> &v, ll s, ll e)
{
    ll i,j;
    i=s-1;
    j=s;
    ll p=e;
    for(j=s;j<=e-1;j++)
    {
        if(v[j]>v[p])
        {
        }
        else
        {
            i++;
            swap(v[i],v[j]);
            
        }
    }
    swap(v[i+1],v[p]);
    return i+1;
}

 void quick(vector<ll> &v, ll s, ll e)
{
    if(s<e)
    {
        ll pivot=partition(v,s,e);
        quick(v,s,pivot-1);
        quick(v,pivot+1,e);
    }
}

int main()
{
    ll n,i,j,k;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    quick(v,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}