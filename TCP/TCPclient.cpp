#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#pragma comment(lib,"Ws2_32.lib");
#define WIN32_LEAN_AND_MEAN // 定义这个宏以避免和 windows.h 冲突
#define SERVER_IP "192.168.99.165"
#define SERVER_PORT 8080
using namespace std;
int main()
{
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);
    int err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
    {
        cerr << "WSAStartup() failed with error: " << err << endl;
        return -1;
    }

    // sockfd();
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        cerr << "socket() failed with error:" << err << endl;
        return -1;
    }
    
    // connect();
    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    // serverAddress.sin_addr.s_addr = htonl(SERVER_IP); 
    // serverAddress.sin_port = htons(SERVER_PORT);

    //inet_pton(AF_INET, SERVER_IP, &serverAddress.sin_addr);
    int serverAddressSize = sizeof(serverAddress);
    WSAStringToAddress((LPSTR)"192.168.99.165", AF_INET, NULL, (LPSOCKADDR)&serverAddress, &serverAddressSize);
    serverAddress.sin_port = htons(SERVER_PORT);
    if (-1 == connect(sockfd, (sockaddr*)&serverAddress, sizeof(serverAddress)))
    {
        cerr << "connect failed with error: " << err << endl;
        return -1;
    }

    // cin;
    char buff[2048];
    memset(buff, 0, sizeof(buff));
    
    // send();

    // recv();
    //close();
    while(true)
    {
        cout << "Input: ";
        cin >> buff;
        send(sockfd, buff, strlen(buff), 0);
        memset(buff, 0, sizeof(buff));
        recv(sockfd, buff, 2048 - 1, 0);
        cout << "Recv: " << buff << endl;
    }
    
    closesocket(sockfd);


    return 0;

}
