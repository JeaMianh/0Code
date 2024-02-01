#include <iostream>
#include <winsock.h>
#include <string.h>
#pragma comment(lib, "Wsock32.lib");
using namespace std;
// #include <arpa/inet.h> // IP地址转换函数
// #include <unistd.h> // 提供对POSIX操作系统API的访问

int main()
{   
    // AF_INT:ipv4, SOCK_STREAM:tcp协议
    // 创建了一个套接字，返回该套接字的描述符。
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cerr <<  strerror(errno) << endl;
        return -1;
    }

    // 设置服务器地址和端口
    sockaddr_in serverAddress;
    // bzero(&serverAddress, sizeof(serverAddress));
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET; // IPv4
    serverAddress.sin_addr.s_addr = INADDR_ANY; // 使用任意可用的IP地址
    serverAddress.sin_port = htons(8080); // 端口号 
    if (-1 == bind(sockfd, (sockaddr*)&serverAddress, sizeof(serverAddress)))
    {
        cerr << strerror(errno) << endl;
    }

    // listen(sockfd);
    if (-1 == listen(sockfd, 2048))
    {
        cerr << strerror(errno) << endl;
        return -1;
    }
    cout << "Listening..." << endl;
    int connfd;
    while (true)
    {
        connfd = accept(sockfd, NULL, NULL);
        if (-1 == connfd)
        {
            cerr << strerror(errno) << endl;
            return -1;
        }
        char buff[2048];
        memset(buff, 0, sizeof(buff));
        recv(connfd, buff, strlen(buff), 0);
        cout << "Recv: " << buff << endl;
        send(connfd, buff, strlen(buff), 0);
        closesocket(connfd); 
    }

    return 0;

}
