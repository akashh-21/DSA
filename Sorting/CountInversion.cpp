#include<iostream>
#include<vector>
using namespace std;
int c=0;
int inversion(vector<int> &a, vector<int> &b)
{
    int c=0;
    int i=0;
    int j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]>b[j]) {
            c+= (a.size()-i);
            j++;
        }
        else  i++;//a[i]<=b[i] 
    }
    return c;
}
void merge( vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<=b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
    }
    if(i==a.size())
    {
        while(j<b.size()) res[k++] = b[j++];
    }
    else while(i<a.size()) res[k++] = a[i++];
}
void mergesort(vector<int>& v)
{
    int n=v.size();
    if(n==1) return;
    int n1=n/2 , n2=n-n/2;
    vector<int> a(n1),b(n2);
    for(int i=0;i<n1;i++) a[i]=v[i];
    for(int i=0;i<n2;i++) b[i]=v[i+n1];
    int count=0;
    mergesort(a);// divide array upto n==1;
    mergesort(b);// "                  "
    c += inversion(a,b);
    merge(a,b,v);
    a.clear();
    b.clear();
    
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n1);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    mergesort(v);
    cout<<endl;
    cout<<c;
}