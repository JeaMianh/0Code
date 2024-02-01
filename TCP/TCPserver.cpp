#include <iostream>
#include <winsock2.h> // 使用 winsock2.h 而不是 winsock.h
#include <ws2tcpip.h> // 使用 ws2tcpip.h 来支持 IPv6
#include <string.h>
#include <windows.h> // 包含 windows.h 头文件
#pragma comment(lib, "Ws2_32.lib"); // 链接 ws2_32 库文件
#define WIN32_LEAN_AND_MEAN // 定义这个宏以避免和 windows.h 冲突
using namespace std;
// #include <arpa/inet.h> // IP地址转换函数
// #include <unistd.h> // 提供对POSIX操作系统API的访问

int main()
{   

    // 初始化 Winsock 库
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2); // 指定 Winsock 版本为 2.2
    int err = WSAStartup(wVersionRequested, &wsaData); // 调用 WSAStartup 函数
    if (err != 0) { // 检查 WSAStartup 函数的返回值
        cerr << "WSAStartup() failed with error: " << err << endl;
        return -1;
    }

    // AF_INT:ipv4, SOCK_STREAM:tcp协议
    // 创建了一个套接字，返回该套接字的描述符。
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) { // 检查 socket 函数的返回值
        cerr <<  "socket() failed with error: " << WSAGetLastError() << endl; // 使用 WSAGetLastError 函数来获取错误代码
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
        cerr << "bind() failed with error: " << WSAGetLastError() << endl; // 使用 WSAGetLastError 函数来获取错误代码
        return -1;
    }

    // listen(sockfd);
    if (-1 == listen(sockfd, 2048))
    {
        cerr << "listen() failed with error: " << WSAGetLastError() << endl; // 使用 WSAGetLastError 函数来获取错误代码
        return -1;
    }
    cout << "Listening..." << endl;
    int connfd;
    while (true)
    {
        connfd = accept(sockfd, NULL, NULL);
        if (connfd == INVALID_SOCKET) // 检查 accept 函数的返回值
        {
            cerr << "accept() failed with error: " << WSAGetLastError() << endl; // 使用 WSAGetLastError 函数来获取错误代码
            return -1;
        }
        char buff[2048];
        memset(buff, 0, sizeof(buff));
        recv(connfd, buff, sizeof(buff), 0); // 使用 sizeof 函数来指定接收缓冲区的大小
        cout << "Recv: " << buff << endl;
        send(connfd, buff, strlen(buff), 0);

    }
    closesocket(connfd); // 使用 closesocket 函数而不是 close 函数
    // 释放 Winsock 库资源
    WSACleanup(); // 调用 WSACleanup 函数

    return 0;

}
