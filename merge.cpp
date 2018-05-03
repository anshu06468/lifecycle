#include <iostream>
using namespace std;
int comp=0;
void print(int a[],int l)
{
  cout<<endl;
  for(int i=0;i<l;i++)
  cout<<a[i]<<" ";
  cout<<endl;
}
void merge(int a[],int l,int m,int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];
  for(i=0;i<n1;i++)
    L[i]=a[l+i];
  for(j=0;j<n2;j++)
    R[j]=a[m+1+j];
  i=0,j=0,k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
    {
      a[k]=R[j];
      j++;
    }k++;
   comp++;
  }
  while(i<n1)
  {
    a[k]=L[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    a[k]=R[j];
    j++;
    k++;
  }
}
void mergesort(int a[],int l,int r)
{
  if(l<r)
  {
     int m=l+(r-l)/2;
     mergesort(a,l,m);
     mergesort(a,m+1,r);
     merge(a,l,m,r);
  }
}	
int main()
{
  int a[7]= {7,6,5,4,3,2,1};
  print(a,7);
  mergesort(a,0,6);
  print(a,7);
  cout<<"Number of comparisons:- "<<comp<<endl;
  return 0;
}
