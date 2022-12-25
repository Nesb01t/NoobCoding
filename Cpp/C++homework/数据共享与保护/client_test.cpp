#include <iostream>
#include "client.h"

int main()
{
    std::cout << "ClientNum: " << Client::ClientNum << std::endl;
    std::cout << "ServerName: " << Client::ServerName << std::endl;

    Client::ClientNum++;
    Client::ServerName = "Server 1";

    std::cout << "ClientNum: " << Client::ClientNum << std::endl;
    std::cout << "ServerName: " << Client::ServerName << std::endl;

    Client::ChangeServerName("Server 2");

    std::cout << "ClientNum: " << Client::ClientNum << std::endl;
    std::cout << "ServerName: " << Client::ServerName << std::endl;

    return 0;
}

// 运行 client_test.cpp 文件后，输出结果如下：

// ClientNum: 0
// ServerName:
// ClientNum: 1
// ServerName: Server 1
// ClientNum: 1
// ServerName: Server 2