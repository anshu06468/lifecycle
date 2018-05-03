//Insertion sort
#include<iostream>
using namespace std;
int comp=0;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void insertion(int a[],int l) 
{
	int temp;
	for(int i=1;i<l;i++)
	{
	 int n=i;
	 for(int j=i; j>=0;j--)
	 {	
		if(a[n]<a[j])
		 { 
		   comp++;
		   swap(a[n],a[j]);
		   n--;
		 }
	  }
	}
}
int main()
{
	int a[8]={6,5,3,1};
	insertion(a,4);
	for(int i=0;i<4;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	cout<<"Number of Comparisons:- "<<comp<<endl;
}
