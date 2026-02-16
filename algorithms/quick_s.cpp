#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int l,int r){
    int piv=arr[r];
    int i=l-1;
    for (int j=l;j<r;j++){
        if(arr[j]<=piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;

}

void Quick_Sort(vector<int>&arr,int l,int r){
    if(l<r){
        int pivot=partition(arr,l,r);
        Quick_Sort(arr,l,pivot-1);
        Quick_Sort(arr,pivot+1,r);
    }
}
int main(){
    vector<int>test={5,3,6,9,2,1,-1,2,4,7};
    Quick_Sort(test,0,9);
    for(int x:test){
    cout << x << ' ';
    }
}