/*Check whether the given input string contains
a. only alphabets
b. only digits
c. only 0s and 1s.
*/

#include<stdio.h>
#include<string.h>

int main(){
	int alpha=0,dig=0,zero=0;
	char str[50];
	printf("Enter :");
	fgets(str,sizeof(str),stdin);
	for(int i=0;i<strlen(str);i++){
		if(str[i]>='2' && str[i]<='9'){
			dig++;
		}
		else if(str[i]=='0' || str[i]=='1'){
			zero++;
		}
		else{
			alpha++;
		}
	}
	
	if(alpha && !dig && !zero ){
		printf("Only alphabate\n");
	}
	else if(!alpha && dig){
		printf("Only digit\n");
	}
	else if(!alpha && !dig && zero ){
		printf("Only zeros and ones\n");
	}
	else{
		printf("Neither\n");
	}
	return 0;
}
	
		
