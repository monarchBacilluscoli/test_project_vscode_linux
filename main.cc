
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <limits>
#include <algorithm>
#include <random>
#include <map>
#include <stack>
#include <unordered_set>
#include <set>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#include "test_function.h"

int main()
{
    std::string s = "test";
    char *msg = "sssss";
    int port = 4500;

    int sock = 0;
    int valread;
    char buffer[1024] = {0};

    sockaddr_in serv_addr; // IP和端口
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "Creation error" << std::endl;
    }

    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        std::cout << "Invalid address" << std::endl;
    } // 将string地址转换成二进制并赋值

    if (connect(sock, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cout << "Connection failed" << std::endl;
    }
    send(sock, msg, strlen(msg), 0);
    std::cout << "Client msg sent" << std::endl;
    std::cout << valread << std::endl;
    valread = read(sock, buffer, 1024);
    std::cout << valread << std::endl;
    std::cout << buffer << std::endl;

    return 0;
}
