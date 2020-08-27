#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>

int hostname_to_ip(char * hostname , char* ip) //function to get the ip address from the provided ip address.
{
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
		
	if ( (he = gethostbyname( hostname ) ) == NULL) 
	{
		// get the host info
		herror("gethostbyname");
		return 1;
	}

	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) 
	{
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
		return 0;
	}
	
	return 1;
}

int main(int argc , char *argv[])//main function
{
	if(argc <2)
	{
		printf("Please provide a hostname to resolve");//error message in case the user does not give a hostname to resolve
		exit(1);
	}
	
	char *hostname = argv[1];
	char ip[100];
	
	hostname_to_ip(hostname , ip);//calling the function
	printf("Hostname  %s" , hostname);//printing the result
	printf("\n");
    printf("IP : %s", ip);
	printf("\n");
	
}

