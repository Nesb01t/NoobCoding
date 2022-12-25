#include <string>

class Client
{
public:
    // 声明字符型静态数据成员ServerName，保存其服务器名称
    static std::string ServerName = "";

    // 声明整型静态数据成员ClientNum，记录已定义的客户数量
    static int ClientNum = 0;

    // 定义静态函数ChangeServerName()改变服务器名称
    static void ChangeServerName(const std::string &new_name)
    {
        ServerName = new_name;
    };
};
