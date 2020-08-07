#include<iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low-1;
    for(int j = low; j < high; ++j)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
int quicksort(int a[], int low, int high, int k)
{
    if(low <= high)
    {
        int pi = partition(a,low,high);
        if(pi == k)
            return pi;
        else if(pi < k)
            return quicksort(a,pi+1,high,k);
        else
            return quicksort(a,low,pi-1,k);
    }
}
int main()
{
    int n;
    double median = 0.0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if(n&1)
    {
        int m = quicksort(a,0,n-1,n/2);
        median = 0.0 + a[m];
    }
    else
    {
        int m1 = quicksort(a,0,n-1,n/2-1);
        int m2 = quicksort(a,0,n-1,n/2);
        median = (a[m1] + a[m2]) / 2.0;
    }
    cout<<median;
}
