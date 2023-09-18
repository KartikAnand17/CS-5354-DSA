#include <iostream>
#include<vector>
using namespace std;

// ternary Search Function
int TernarySearch(vector<int> &arr, int low, int high, int &key){
  if(high>=low){
    int mid1 = low + (high-low)/3; // first mid division
    int mid2 = high - (high-low)/3; // second mid division
    if(key == arr[mid1]){
      return mid1;
    }
    if(key == arr[mid2]){
      return mid2;
    }
    if(key<arr[mid1]){
      return TernarySearch(arr,low,mid1-1,key);
    }
    else if(key > arr[mid2]){
      return TernarySearch(arr, mid2+1, high, key);
    }
    else{
      return TernarySearch(arr,mid1+1,mid2-1,key);
    }
  }
  return -1; // If key not found return -1
}

int main() {
  vector<int> arr{10,20,30,40,50,324,1233,2333,54322,232344};
  int key = 232344;
  int ans = TernarySearch(arr,0,arr.size()-1,key);
  if(ans == -1){
    cout << "Key is not present in the Array" << endl;
  }
  else{
    cout << "Key is present at " << ans << "th index of the array" << endl;
  }
  
}