//Ques.2) Find Majority Element (Medium).
//Sol.
#include <bits/stdc++.h>
using namespace std;
bool isMajorityElement(int arr[], int n, int x){
   int freq = 0;
   for(int i = 0; i<n; i++){
      if(arr[i] == x )
         freq++;
      if(arr[i] > x)
         break;
   }
   return (freq > n/2);
}
int main() {
   int arr[] = {1, 2, 3, 3, 3, 3, 6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 3;
   if (isMajorityElement(arr, n, x))
      cout << x << " is the majority element of the array";
   else
      cout << x << " is not the majority element of the array";
}
