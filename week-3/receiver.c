#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int isValidBinary(char *str){
	for(int i=0; str[i]!= '\0';i++){
		if(str[i]!='0' && str[i] !='1'){
			return 0;
		}
	}
	return 1;
}

int parityChecker(char *str){
	int count=0;
	if(isValidBinary(str)){
		for(int i=0; str[i]!= '\0';i++){
			if(str[i] == '1')
				count++;
		}
		return count;
	}
	return -1;
}


void isEven(char *str){

	char s[60];
	for(int i=0; (str[i+1]!= '\0') || (s[i] = '\0') ;i++){
		s[i] = str[i];	
	}
	
	if(parityChecker(str)%2 == 0){
		printf("Good Message. The bits = %s",s);	
	}
	else if(parityChecker(str)%2 != 0){
		printf("Bad Message.\n");
	}
	else if(parityChecker(str) == -1)
		printf("Error. \n");
}





int main(){
	int sd,cd,cadl;
	struct sockaddr_in sad,cad;
	char str[50];
	
	sd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

	sad.sin_family = AF_INET;
	sad.sin_port = htons(9995);
	sad.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind(sd, (struct sockaddr *)&sad,sizeof(sad));
	listen(sd,10);
	
	cadl = sizeof(cad);
	cd = accept(sd,(struct sockaddr *)&cad,&cadl);
	
	recv(cd, str, sizeof(str), 0);
	printf("Client Says : %s\n",str);
	isEven(str);	
	close(cd);
	close(sd);
	
}
