#include<iostream>
using namespace std;
void print(int a[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
int maximum(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
		if(a[i]>max)
		  max=a[i];
	return max;
}
void countsort(int a[],int n, int exp)
{
	int count[10]={0};
	int output[n];
	for(int i=0;i<n;i++)
		count[(a[i]/exp)%10]++;
	int k=sizeof(count)/sizeof(count[0]);
	for(int i=1;i<k;i++)
		count[i]+=count[i-1];
	for(int j=n-1;j>=0;j--)
	{
		output[count[(a[j]/exp)%10]-1]=a[j];
		count[(a[j]/exp)%10]--;
	}
	for(int i=0;i<n;i++)
		a[i]=output[i];
} 
void radixsort(int a[],int n) 
{
	int m=maximum(a,n);
	for(int exp=1;m/exp>0;exp*=10)
		countsort(a,n,exp);
}
int main()
{
	int a[10]={987,456,234,64,346,776,234,875,123,953};
	radixsort(a,10);
	print(a,10);
	return 0;
}
