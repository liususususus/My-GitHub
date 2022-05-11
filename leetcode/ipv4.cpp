//需求1. 完成这个类的编写 class ValidIpWrapper { public: explicit ValidIpWrapper(const char* input) { size_t size = strlen(input); content_ = new char[size + 1]; content_[size] = '\0'; memcpy(content_, input, size); } // 说明：如果content_ 是一个合法的IPV4则返回 true，否则返回 false bool IsAValidIpv4() const { /*
// 2.实现该函数（请尽量不要用库函数） */ } private: char* content_ = nullptr; }; int main() { ValidIpWrapper valid_ip("12.258.25.2"); std::cout << (valid_ip.IsAValidIpv4() ? "true" : "false") << std::endl; return 0; }
#include <iostream>
#include <cstring>
using namespace std;

class ValidIpWrapper
{
public:
    explicit ValidIpWrapper(const char *input)
    {
        size_t size = strlen(input);
        content_ = new char[size + 1];
        content_[size] = '\0';
        memcpy(content_, input, size);
    } // 说明：如果content_ 是一个合法的IPV4则返回 true，否则返回 false bool IsAValidIpv4() const { /*
    bool IsAValidIpv4()
    {
        int count = 0;
        int dot_count = 0;
        for (int i = 0; i < strlen(content_); i++)
        {
            if (content_[i] == '.')
            {
                dot_count++;
                if (dot_count > 3)
                {
                    return false;
                }
                if (count > 255)
                {
                    return false;
                }
                count = 0;
            }
            else if (content_[i] >= '0' && content_[i] <= '9')
            {
                count = count * 10 + content_[i] - '0';
            }
            else
            {
                return false;
            }
        }
        if (count > 255)
        {
            return false;
        }
        if (dot_count != 3)
        {
            return false;
        }
        return true;
    }
private:
    char *content_ = nullptr;
};
int main()
{
    ValidIpWrapper valid_ip("12.258.25.2");
    std::cout << (valid_ip.IsAValidIpv4() ? "true" : "false") << std::endl;
    ValidIpWrapper valid_ip1("12.255.25.2");
    std::cout << (valid_ip1.IsAValidIpv4() ? "true" : "false") << std::endl;
    return 0;
}