#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
const int sz = (int)(1e4);

void merge(vector<int>&arr,int st,int en,int mid)
{
    vector<int>temp(arr.size());
    int i,j;
    for(i=0; i<arr.size(); i++)
        temp[i]=arr[i];
    int n=mid-st+1,m=en-mid,k=st;
    i=j=0;
    while(i<n && j<m)
    {
        if(temp[st+i]<=temp[mid+1+j])
            arr[k++]=temp[st + i++];
        else arr[k++]=temp[mid + 1 + j++];
    }
    while(i<n)arr[k++]=temp[st + i++];
    while(j<m)arr[k++]=temp[mid + 1 + j++];
}
void mergesort(vector<int>&arr,int st,int en)
{
    if(st>=en)return;
    int mid = ((st+en)>>1);
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,en);
    merge(arr,st,en,mid);
}

int partition(int arr[],int left,int right)
{
    bool r=true;
    while(left<right)
    {
        if(arr[left]>arr[right])
        {
            swap(arr[left],arr[right]);
            if(r) r = false;
            else r = true;
        }
        if(r)right--;
        else left++;
    }
    return left;
}
void quicksort(int arr[],int left,int right)
{
    if(left>=right)return;
    int p = partition(arr,left,right);
    quicksort(arr,left,p-1);
    quicksort(arr,p+1,right);
}

int main() {
    srand(time(0));
    double mergetime = 0.0, quicktime = 0.0;
    for (int cs = 1; cs <= 1000; cs++) {
        cout << cs << ' ';
        vector <int> v(sz);
        int u[sz+10];
        for (int i = 0; i < sz; i++) {
            v[i] = rand();
            u[i] = v[i];
        }
        clock_t start,term;
        start = clock();
        mergesort(v,0,sz-1);
        term = clock();
        double due = double(term - start)/double(CLOCKS_PER_SEC);
        cout << "Merge Sort : " << fixed << due << setprecision(10) << " sec  ";
        mergetime+=due;
        start = clock();
        quicksort(u,0,sz-1);
        term = clock();
        due = double(term - start)/double(CLOCKS_PER_SEC);
        cout << "Quick Sort : " << fixed << due << setprecision(10) << " sec \n";
        quicktime+=due;
    }
    cout << "Total Time taken for Merge Sort : " << mergetime << " sec \n";
    cout << "Total Time taken for Quick Sort : " << quicktime << " sec \n";
    return 0;
}
