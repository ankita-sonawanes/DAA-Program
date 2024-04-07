#include<iostream>
using namespace std;
void quick(int a[],int l,int up);
int partition(int a[],int low,int up);
int main()
{
int i,n;
 int arr[10];
 cout<<"\nenter the size of array:\n";
 cin>>n;
 cout<<"Enter elements in array:\n";
  for(i=0;i<n;i++)
  {
    cin>>arr[i];
   }
 quick(arr,0,n-1);
 cout<<"\n Quick sort result is:";
 for(i=0;i<n;i++)
 cout<<arr[i]<<" ";
 return 0;
 }
 void quick(int a[],int l,int up)
 {
   int pvt;
   if(l>=up)
    return;
   pvt=partition (a,l,up);
   quick(a,l,(pvt-1));
   quick(a,(pvt+1),up);
 }
int partition(int a[],int low,int up)
{
 int t,pvt;
  int i=low+1;
  int j=up;
  pvt=a[low];
  while(i<=j)
  {
    while((a[i]<pvt)&&(i<up))
     i++;
    while(a[j]>pvt)
     j--;
   if(i<j)
   {
     int temp=a[i];
     a[i]=a[j];
     a[j]= temp;
      i++;
      j--;
    }
  else{
   i++;
   }
 }
   a[low]=a[j];
   a[j]=pvt;  
   return j;
}

/*
output:

OUTPUT:
enter the size of array:
10
Enter elements in array:
11
3
4
77
66
34
99
43
22
34
Quick sort result is:3 4 11 22 34 34 43 66 77 99
*/