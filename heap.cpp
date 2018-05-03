#include<iostream>
#include <cmath>
using namespace std; 
int count=0;
void print(int a[],int n)
{
	for(int i=1;i<=n;i++)
	cout<<i<<"\t"<<a[i]<<endl;
}
void heap(int a[],int k,int sz)
{		int l=2*k;
		int r=2*k+1;
		int largest=0;
		if(l>sz && r>sz)
			return;
		if(l<=sz && a[l]>a[k]) {
			count++;
			largest=l;
			}
		else {
			largest=k;
			count++;}
		if(r<=sz && a[r]>a[largest])
		{
			count++;
			largest=r;
		}		
		else if(a[r]<a[largest])
			count++;					
		if(largest!=k)
		{	
			int temp=a[k];
			a[k]=a[largest];		
			a[largest]=temp;
		}
		
		else
		return;
			heap(a,largest,sz);		
	
}
void Maxheap(int a[],int n)
{
	int non_l=floor(n/2);
	for(int i=non_l;i>=1;i--)
		heap(a,i,n);
		
}
void sort(int a[],int n)
{
	Maxheap(a,n);

	for(int i=n;i>=2;i--)
	{		
		int temp;
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		heap(a,1,i-1);
	}
	
}
int main()
{
	int a[50],sz,root;
	cout<<"Enter the number of elements\n";
	cin>>sz;
	cout<<"Enter  the elements\n";
	for(int i=1;i<=sz;i++)
	  cin>>a[i];
	cout<<"array after sorting\n";
	sort(a,sz);
	cout<<"Index\tElement\n";	
	print(a,sz);
	cout<<"no. of comparisons"<<count<<endl;
	return 0;
}
	
