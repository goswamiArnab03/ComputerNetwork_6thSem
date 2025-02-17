//Check whether a number is a power of 2 or not.

#include<stdio.h>

int main(){
	printf("Enter a no (>1)\n");
	int n;scanf("%d",&n);
	while(n>=1 && n%2==0){
		n=n/2;
	}
	if(n==1){
		printf("The no is power of 2\n");
	}
	else{
		printf("The no is not power of 2\n");
	}
	return 0;
}
