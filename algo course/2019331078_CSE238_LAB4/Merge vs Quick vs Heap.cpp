#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
using ll = long long;
const int sz = (int)(1e4);


//Merge Sort

void merge(vector<int>&arr,int st,int en,int mid) {
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
void mergesort(vector<int>&arr,int st,int en) {
    if(st>=en)return;
    int mid = ((st+en)>>1);
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,en);
    merge(arr,st,en,mid);
}


//Quick Sort

int partition(int arr[],int left,int right) {
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
void quicksort(int arr[],int left,int right) {
    if(left>=right)return;
    int p = partition(arr,left,right);
    quicksort(arr,left,p-1);
    quicksort(arr,p+1,right);
}


//Heap Sort

void heapify(int arr[], int n, int i) {
    int mx = i;
    int left = 2*i + 1;
    int right = left+1;
    if (left < n && arr[left] > arr[mx])
        mx = left;
    if (right < n && arr[right] > arr[mx])
        mx = right;
    if (mx != i) {
        swap(arr[i], arr[mx]);
        heapify(arr,n,mx);
    }
}

void heapsort(int arr[],int n) {
    for (int i = n/2-1; i >= 0; i--) {
        heapify(arr,n,i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    srand(time(0));
    double mergetime = 0.0, quicktime = 0.0, heaptime = 0.0;
    for (int cs = 1; cs <= 1000; cs++) {
        cout << cs << ' ';
        vector <int> v(sz);
        int u[sz+10],w[sz+10];
        for (int i = 0; i < sz; i++) {
            v[i] = rand();
            w[i] = u[i] = v[i];
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
        cout << "Quick Sort : " << fixed << due << setprecision(10) << " sec  ";
        quicktime+=due;

        start = clock();
        heapsort(w,sz-1);
        term = clock();
        due = double(term - start)/double(CLOCKS_PER_SEC);
        cout << "Heap Sort : " << fixed << due << setprecision(10) << " sec \n";
        heaptime+=due;

    }
    cout << "\n\nTotal Time taken for Merge Sort : " << mergetime << " sec \n";
    cout << "Total Time taken for Quick Sort : " << quicktime << " sec \n";
    cout << "Total Time taken for Heap Sort : " << heaptime << " sec \n";
    return 0;
}
