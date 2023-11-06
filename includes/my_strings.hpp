#ifndef INCLUDES_MY_STRING_HPP
#define INCLUDES_MY_STRING_HPP

#include <iostream>
#define DEBUG

namespace MyString_ns // start of namespace MyString_ns
{
    class MyString
    {   
        public:
            MyString();
            MyString(const char* const str_ptr);
            ~MyString();

            void operator ++ (); // works
            void operator -- (); // works
            bool operator == (MyString& rhs) const; // works
            MyString operator + (const MyString& rhs) const;
            void operator = (const MyString& rhs); // works

            void print_data() const;
            void print() const;
            size_t size() const;
            char* begin() const;
            char* end() const;

        private: 
            size_t m_size;
            char*  m_string_ptr;
            char*  m_begin;
            char*  m_end;

            class EXC_ERR_NEW{}; // must be implemented
    };

    size_t get_str_size(const char* str_ptr);

} // end of namespace MyString_ns

#endif
