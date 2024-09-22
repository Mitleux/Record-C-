#include "stdio.h"
int facsum(int n)
{
	int a=0,b=0;
	for(int i=1;i<n;i++){
		if(n%i==0){
			a+=i;
		}
	}
	for(int i=1;i<a;i++){
		if(a%i==0){
			b+=i;
		}
	}
	if(n==b){
		return a+b;
	}
	return 0;
}
void output()
{
	int array[500]={0};
	for(int i=3;i<500;i++){
		int a=facsum(i);
		if(a&&array[i]==0)
		{
			array[i]=1;array[a-i]=1;
			printf("%d,%d\n",i,a-i);
		}
	}
}
int main()
{
	output();
	return 0;
}
