#include<bits/stdc++.h>
using namespace std;

int iterativeBinarySearch(vector<int> arr, int target){
    int n = arr. size();
    int low = 0;
    int high = n - 1;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(target>arr[mid])  low = mid + 1;
        else    high = mid - 1;
    }
    return -1;
}

int recursiveBinarySearch(vector<int> arr, int target, int low, int high){
    if(low>high)   return -1;
    int mid = (low + high)/2;
    if(arr[mid] == target) return mid;        // tc = O(log2(n))
    else if(target > arr[mid])
        return  recursiveBinarySearch(arr, target, mid + 1, high);
    return   recursiveBinarySearch(arr, target, low, mid - 1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int target ;
    cout<<"Enter the number that you want to search in the array.... : ";
    cin>>target;
    // int Idx = iterativeBinarySearch(arr, target);
    int Idx = recursiveBinarySearch(arr, target, 0, arr.size() - 1);
    cout<<Idx;
    return 0;
}