#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int lo = 0;
   int mid = 0;
   int hi = n-1;

   while(mid<=hi){
      switch(arr[mid]){
         case 0 :
            swap(arr[lo++],arr[mid++]);
            break;
         
         case 1 : 
            arr[mid++];
            break;
         
         case 2 :
            swap(arr[mid],arr[hi--]);
            break;
      }
   }
}