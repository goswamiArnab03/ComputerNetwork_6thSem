#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

int checkCRC(char* data,char* key){
	int datalen=strlen(data);
	int keylen=strlen(key);
	char temp[100];
	strcpy(temp,data);
	for(int i=0;i<datalen-keylen+1;i++){
		if(temp[i]=='1'){
			for(int j=0;j<keylen;j++){
				temp[i+j]=(temp[i+j]==key[j])?'0':'1';
			}
		}
	}
	for(int i=datalen-keylen+1;i<datalen;i++){
		if(temp[i]=='1'){
			return 0;
		}
	}
	return 1;
}
int main(){
	char str[50];
	int sd,cd,cadl;
	struct sockaddr_in sad,cad;
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sd,(struct sockaddr*)&sad,sizeof(sad));
	listen(sd,10);
	cadl=sizeof(cad);
	cd=accept(sd,(struct sockaddr*)&cad,&cadl);
	recv(cd,str,sizeof(str),0);
	printf("client says: %s\n",str);
	char poly[50];
	printf("Enter poly :");
	scanf("%s",&poly);
	if(checkCRC(str,poly)){
		printf("No Error\n");
	}
	else printf("Error\n");
	close(cd);
	close(sd);
	return 0;
}
