
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
#include "PortChecker.h"

// #include "test_function.h"

// using namespace std;

int main()
{
    // PortChecker ptck;
    // std::cout << ptck.Check(23333) << std::endl;
    // PortChecker ptck2;
    // std::cout << ptck.Check(10000) << std::endl;


    int port = 10000;
    int server_fd;  // 服务器的file descriptor
    int new_socket; //
    int opt = 1;
    sockaddr_in address;
    int addrlen = sizeof(address);
    int valread;
    char buffer[1024] = {0};
    std::string s = "Hi first client";
    char *hello = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) // communication domain: the protocol family used AF_INET: IPv4 protocols; communication semantics SOCK_STREAM: reliable, SOCK_DGRAM: connectionless, unreliable; Normally only a single protocol exists to support a particular socket type within a given protocol family, in which case protocol can be specified as 0
    {
        std::cout << "socket failed" << std::endl;
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) // 设置一些选项，完全可选的。但是设置这个helps in reuse of address and port. Prevents error such as "address already in use"
    {
        std::cout << "setsockopt failed" << std::endl;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // 因为将IP绑定到本机，所以使用了INADDR_ANY(0.0.0.0)指定了IP
    address.sin_port = htons(port);       // 将unsigned short integer hostshort from host byte order to network byte order 即从本机可能是小端的字节序转换成网络字节序（大端）

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
