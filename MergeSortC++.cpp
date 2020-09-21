#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX_SIZE 100
void merge(vector<ll> & v, ll s, ll e)
{
    if(s>=e)
    return ;
    vector<ll> temp(MAX_SIZE);
    ll i,j,k=s,mid=s+(e-s)/2;
    i=s;
    j=mid+1;
    while(i<=mid&&j<=e)
    {
        if(v[i]<v[j])
        {
            temp[k]=v[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=v[j];
            k++;
            j++;
        }
    }
    while(j<=e)
    {
        temp[k]=v[j];
        k++;
        j++;
    }
    while(i<=mid)
    {
        temp[k]=v[i];
        i++;
        k++;
    }
    //copying contents 
    for(i=s;i<=e;i++)
    {
        v[i]=temp[i];
    }

}
void merge_sort(vector<ll> &v, ll s, ll e)
{
    if(s>=e)
    return ;
    ll mid=s+(e-s)/2;
    
    merge_sort(v,s,mid);
    merge_sort(v,mid+1,e);
    
    merge(v,s,e);
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
    merge_sort(v,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}