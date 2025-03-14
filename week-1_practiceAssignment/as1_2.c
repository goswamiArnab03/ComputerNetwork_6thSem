/*Input a string of alphabets. Now count the frequency of each alphabet present in that string.*/

#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	printf("Enter a string\n");
	fgets(str,sizeof(str),stdin);
	int cap[26]={0};
	int small[26]={0};
	for(int i=0;i<strlen(str);i++){
		char ch=str[i];
		if(ch>='A' && ch<='Z') cap[ch-'A']++;
		if(ch>='a' && ch<='z') small[ch-'a']++;
	}
	printf("The frequency of each character: \n");
	for(int i=0;i<26;i++){
		if(cap[i]>0){
			printf("%c : %d \n",'A'+i,cap[i]);
		}
	}
	for(int i=0;i<26;i++){
		if(small[i]>0){
			printf("%c : %d \n",'a'+i,small[i]);
		}
	}
	return 0;
}
