#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h> 
#include <unistd.h>
#include<string.h> 
#include <arpa/inet.h>

void main()
{
int b,sockfd,connfd,connfd1,sockfd1,sin_size,l,n,len,i,j;
int arr[3][3];
int arr1[3][3];
int diff;
char operator;
int op1,op2,result;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");
struct sockaddr_in servaddr;              
struct sockaddr_in clientaddr;

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;

if((bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)))==0)
printf("bind sucessful\n");
    

if((listen(sockfd,5))==0) 
printf("listen sucessful\n");


sin_size = sizeof(struct sockaddr_in);
if((connfd=accept(sockfd,(struct sockaddr *)&clientaddr,&sin_size))>0);
printf("accept sucessful\n");

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        read(connfd,&arr[j][i],10);
    }
}


if((sockfd1=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");  

struct sockaddr_in servaddr1;              
struct sockaddr_in clientaddr1;

servaddr1.sin_family=AF_INET;
servaddr1.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr1.sin_port=6007;

if((bind(sockfd1, (struct sockaddr *)&servaddr1,sizeof(servaddr1)))==0)
printf("bind sucessful\n"); 



if((listen(sockfd1,5))==0) 
printf("listen sucessful\n");


sin_size = sizeof(struct sockaddr_in);
if((connfd1=accept(sockfd1,(struct sockaddr *)&clientaddr1,&sin_size))>0);
printf("accept sucessful\n");

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        read(connfd1,&arr1[j][i],10);
    }
}

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        diff = arr[i][j] - arr1[i][j];
        printf("%d\t",diff);
    }
    printf("\n");
}

write(connfd,&result,sizeof(result));
close(sockfd);
}