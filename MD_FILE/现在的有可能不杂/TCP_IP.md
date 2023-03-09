## server 服务端函数

### 构建套接字
>
>```c
>#include <sys.socket.h>
>int socket(int domain,int type,int protocol);
> //成功返回0 失败返回-1
>```
>
>

### 绑定 bind 函数

>分配地址信息 ip和端口号
>
>```c
>#include <sys/socket.h>
>int bind(int sockfd,stuct sockeaddr * myaddr,socklen_t addrlen);
> // 成功返回0 失败返回-1
>```
>
>

### 调用listen函数

>转为可接受请求状态
>
>```c
>#include<sys/socket.h>
>int listen(int sockfd,int backlog);
>	//成功返回0,失败返回-1
>```
>
>

### 调用accept函数

>
>
>```c
>#include <sys.sockt.h>
>int accept(int sockfd,struct sockaddr *addr,socklen_t * addrlen);
>	//成功时返回文件描述符 失败时返回-1
>
>```
>
>



## 客户端服务端代码

### 完整的服务端代码

>
>
>```c++
>#include <stdio.h> 
>#include <stdlib.h>
>#include <string.h> 
>#include <unistd.h>
>#include <arpa/inet.h> 
>#include <sys/socket.h>
>
>void error_handling(char *message);
>
>int main(int argc, char *argv[])
>{
>    int serv_sock; 
>    int cInt_sock;
>    struct sockaddr_in serv_addr;
>    struct sockaddr_in clnt_addr; 
>    socklen_t cInt_addr_size;
>    char message[]="\n\nHello World!\nfuck you\n";
>    if(argc!=2) {
>        printf("Usage : %s ‹port›In", argv[0]); 
>        exit(1);
>    }
>    serv_sock=socket (PF_INET,SOCK_STREAM, 0); 
>    if(serv_sock == -1) 
>        error_handling("socket() error");
>    memset (&serv_addr, 0, sizeof (serv_addr)); 
>    serv_addr.sin_family=AF_INET; 
>    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); 
>    serv_addr.sin_port=htons(atoi(argv[1]));
>
>    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof (serv_addr))==-1) 
>            error_handling("bind() error");
>
>    if(listen(serv_sock, 5)==-1)
>        error_handling("listen() error");
>
>    cInt_addr_size=sizeof(clnt_addr);
>    cInt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr, &cInt_addr_size); 
>    if (cInt_sock==-1)
>        error_handling("accept () error");
>    write(cInt_sock, message, sizeof(message)); 
>    close(cInt_sock);
>    close(serv_sock);
>    return 0;
>    }
>
>void error_handling (char*message){
>    fputs (message, stderr);
>    fputc('\n', stderr);
>    exit(1);
>}
>
>```
>
>



### 完整的客户端代码

>
>
>```c++
>#include <stdio.h>
>#include <stdlib.h> 
>#include <string.h>
>#include <unistd.h>
>#include <arpa/inet.h>
>#include <sys/socket.h>
>void error_handling(char *message);
>
>int main(int argc, char* argv[]){
>
>    int sock;
>    struct sockaddr_in serv_addr; 
>    char message[30];
>    int str_len;
>
>    if(argc!=3){
>        printf("Usage : %s <IP> ‹port›\n", argv[0]); 
>        exit (1);
>    }
>    sock=socket (PF_INET, SOCK_STREAM, 0 ); 
>    if(sock == -1)
>        error_handling("socket () error");
>    memset (&serv_addr, 0, sizeof(serv_addr)); 
>    serv_addr.sin_family=AF_INET; 
>    serv_addr.sin_addr.s_addr=inet_addr(argv[1]); 
>    serv_addr.sin_port=htons(atoi(argv[2]));
>    if(connect (sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
>        error_handling("connect() error!");
>    str_len=read(sock, message, sizeof(message)-1); 
>    if(str_len==-1)
>        error_handling("read() error!");
>    printf("Message from server :%s In", message); 
>    close(sock);
>
>    return 0;
>}
>
>void error_handling (char*message){
>    fputs (message, stderr);
>    fputc('\n', stderr);
>    exit(1);
>}
>
>```
>
>
