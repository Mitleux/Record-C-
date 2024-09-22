#include "stdio.h"
double pq(int x)
{
	if(x>0){
		x*=pq(x-1);
	}
	else return 1;
	return x;
}
void comp()
{
	int m,n;
	scanf("%d,%d",&m,&n);
	if(m<0||n<0||(m-n)<0){
		printf("error");
		return;
	}
	printf("%.2f",pq(m)/((pq(m-n))*pq(n)));
}
int main()
{
	comp();
	return 0;
	
}
