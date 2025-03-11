#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

void generateCRC(char* data,char* key,char* crc){
	int datalen=strlen(data);
	int keylen=strlen(key);
	char temp[100];
	strcpy(temp,data);
	for(int i=0;i<keylen-1;i++){
		temp[datalen+i]='0';
	}
	temp[datalen+keylen-1]='\0';
	for(int i=0;i<datalen;i++){
		if(temp[i]=='1'){
			for(int j=0;j<keylen;j++)
				temp[i+j]=(temp[i+j]==key[j])?'0':'1';
		}
	}
	strncpy(crc,temp+datalen,keylen-1);
	crc[keylen-1]='\0';
}
int main(){
	int sd,cd,cadl;
	struct sockaddr_in sad,cad;
	char str[50];
	sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sad.sin_family=AF_INET;
	sad.sin_port=htons(9995);
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(sd,(struct sockaddr*)&sad,sizeof(sad));
	char data[100];
	char poly[100];
	char crc[20];
	printf("Enter the data: ");
	scanf("%s",&data);
	printf("Enter the poly: ");
	scanf("%s",&poly);
	generateCRC(data,poly,crc);
	strcat(data,crc);
	printf("Data with crc bits: %s",data);
	send(sd,data,sizeof(data),0);
	close(sd);
	return 0;
}
