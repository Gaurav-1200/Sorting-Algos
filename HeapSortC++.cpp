#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back

// Reference from Geeks for Geeks 

void heapify(vector<ll> &v, ll i, ll n)
{
    ll largest=i;
    ll left=2*i+1, right=2*i+2;
    
    if(left<n && v[left]>v[largest])
    largest=left;
    
    if(right<n && v[right]>v[largest])
    largest=right;
    
    if(largest!=i)
    {
        swap(v[i],v[largest]);
        heapify(v,largest,n);
    }
}
void heapsort(vector<ll> &v)
{
    ll n=v.size(),i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(v,i,n);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        
        heapify(v,0,i);
    }
    
}
int main()
{
    ll n,i,j;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    heapsort(v);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
    
}