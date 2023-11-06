#include "my_strings.hpp"

int main()
{
    MyString_ns::MyString string1("Hello,");
    MyString_ns::MyString string2(" World!");
    // string1.print_data();
    // string2.print_data();
    // string3.print_data();
    // ++string3;
    // string3.print_data();

    // std::cout << "Result is " << string1.operator==(string2) << "\n";
    MyString_ns::MyString result;
    result = string1 + string2;
    string1.print_data();
    string2.print_data();
    result.print_data();


    return 0;
}

