//Input a string of 0 and 1. Count the number of 1’s present in that string.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	printf("Enter a string(0&1): ");
	fgets(str,sizeof(str),stdin);
	int count=0;
	for(int i=0;i<strlen(str);i++){
		/*if(str[i]!='0' && str[i]!='1'){
			printf("Error!\n");exit(0);
		}*/
		if(str[i]=='1')count++;
	}
	printf("No of 1: %d\n",count);
	return 0;
}
