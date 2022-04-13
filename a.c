#include "public.h"

void *tcpRcvProc(void *args)
{
	int recvlen;
	char recvbuff[1024]={0};
	long tcpfd=(long)args;
	while(1)
	{
	memset(recvbuff,0,sizeof(recvbuff));
	if((recvlen=recv(tcpfd,recvbuff,sizeof(recvbuff),0))>0)
		{
			printf("recv:%s\n",recvbuff);
		}

	}

}


int main()
{
	long socketFd = socket(AF_INET,SOCK_STREAM,0);
	if(socketFd<0)
	{
		perror("socket");
		return -1;
	}
	char sendbuff[1024]={0};
	int sendlen=1024;
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family = PF_INET;//协议族
	serveraddr.sin_port = htons(60000);//端口
	serveraddr.sin_addr.s_addr = inet_addr("192.168.72.73");//IP地址
	if(connect(socketFd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0)
	{
		perror("connect");
		return -1;
	}
	pthread_t pid;
	pthread_create(&pid,NULL,tcpRcvProc,(void *)socketFd);
	while(1)
	{
		memset(sendbuff,0,sizeof(sendbuff));
		fgets(sendbuff,sendlen,stdin);
		send(socketFd,sendbuff,sendlen,0);
	
	}

	return 0;
}

 



















