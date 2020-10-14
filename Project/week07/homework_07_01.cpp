#include <fstream>
#include <iostream>
#include <string>
#include <ostream>
using namespace std;
class AnyString {
    std::string anyString;

public:
    AnyString(const std::string& anyString) : anyString(anyString) {};
    std::string getAnyString() {
        return "Stored String :: " + anyString;
    }
};
ostream& operator<<(ostream& out, AnyString& a)
{
    out << a.getAnyString();
    return out;
}

int main() {
    std::ofstream out("testOverloading.txt");
    AnyString a("Hello, this is operator overloading test!!!");
    /* std::string output = a.getAnyString();
     out << output << std::endl;*/
    out << a << std::endl;
    return 0;
}