
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
#include <netinet/in.h>
#include <thread>
#include <string.h>

// #include "test_function.h"

// using namespace std;

int main()
{
    int port = 4500;
    int server_fd;
    int new_socket;
    int opt = 1;
    sockaddr_in address;
    int addrlen = sizeof(address);
    int valread;
    char buffer[1024] = {0};
    std::string s = "Hi first client";
    char *hello = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cout << "socket failed" << std::endl;
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        std::cout << "setsockopt failed" << std::endl;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (sockaddr *)&address, sizeof(address)) < 0) // 将创建的socket绑定在对应的地址和端口
    {
        std::cout << "bind failed" << std::endl;
    }

    if (listen(server_fd, 3) < 0) // 监听，3是负载的最大长度
    {
        std::cout << "listen failed" << std::endl;
    }
    if ((new_socket = accept(server_fd, (sockaddr *)(&address), (socklen_t *)&(addrlen)) < 0)) // 接收并创建新套接字
    {
        std::cout << "accept failed" << std::endl;
    }
    else
    {
        std::cout << "accept!" << std::endl;
    }

    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // std::cout << "okk" << std::endl;

    valread = read(new_socket, buffer, 1024);
    std::cout << std::string(buffer) << std::endl;

    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Server msg sent" << std::endl;

    return 0;
}
