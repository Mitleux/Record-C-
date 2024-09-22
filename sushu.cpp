#include <stdio.h>
int isprime(int n)
{
	for(int i=2;i<n/2+1;i++){
		if(n%i==0){
			return 0; 
		}
	}
	return 1;
}
int fun(int *a,int n)
{
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(isprime(a[i]))
		{
			a[j]=a[i];
			j++;
		}
	}
	return j;
}
int main()
{
	int a[100],k,i;
	for(i=1;i<=100;i++)
		a[i-1] = i;
	k = fun(a,100);
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	return 0;
}
