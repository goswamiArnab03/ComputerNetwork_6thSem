/*Input a string of 0 and 1.
a. Divide it into segments of equal length.
b. If the string length is not an exact multiple of segment length then use left padding with 0s.
c. Now count the number of 1’s present in each segment.
Sample Input-output:
Input: 1000111010
Segment length: 4
Output:
Segment 1: 0010 <Bold indicates padding with 0>
Segment 2: 0011
Segment 3: 1010
Frequency:
Segment 1: 1
Segment 2: 2
Segment 3: 2

*/

#include<stdio.h>
#include<string.h>

int main(){
	char str[50];
	printf("Enter string: ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str, "\n")] = '\0';
	int segment;
	printf("Enter the segment length");
	scanf("%d",&segment);
	int n=strlen(str)%segment;
	//printf("%d\n",strlen(str));
	 int len = strlen(str);

    
    for (int i=len;i>= 0;i--){
        str[i+n] = str[i];
    }

    for (int i=0;i < n;i++){
        str[i] = '0';
    }
	//printf("%s",str);
	len = strlen(str);
	int i=0,c=0;
	while(i+segment<len){
		printf("Segment %d: ",++c);int count=0;
		for(int j=0;j<segment;j++){
			printf("%c",str[i+j]);
			if(str[i+j]=='1') count++;
		}
		printf("\nThe no of ones here %d\n",count);
		i+=segment-1;
			
	}
	return 0;
}
