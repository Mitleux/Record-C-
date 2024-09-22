#include <stdio.h>
void palindrome(int *data,int n)
{
	int i;
	for(i=0;n>0;i++,n/=10){
		data[i]=n%10;
	}
	i--;
	for(int j=0;j<=i;j++,i--){
		if(data[j]!=data[i]){
			printf("no");
			return;
		}
	}
	printf("yes");
}
int main()
{
	int x;
	int a[99];
	scanf("%d",&x);
	palindrome(a,x);
	return 0;
}
