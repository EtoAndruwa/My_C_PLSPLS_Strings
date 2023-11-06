#include "my_strings.hpp"

MyString_ns::MyString::MyString() // ok
{
    m_size       = 0;
    m_string_ptr = nullptr;
    m_begin      = nullptr;
    m_end        = nullptr;

    #ifdef DEBUG
        std::cout << "MyString common constructor called\n";
    #endif
};

MyString_ns::MyString::MyString(const char* str_ptr)
{
    m_size = MyString_ns::get_str_size(str_ptr);
    #ifdef DEBUG
        std::cout << "MyString(const char* const str_ptr) constructor called\n";
    #endif

    m_string_ptr = new char(m_size + 1);    
    if (m_string_ptr == nullptr)
    {
        std::cout << "EXCEPTION: error occured when tried to new()\n";
        // here must be exception
    }

    for (size_t i = 0; i <= m_size; i++)
    {
        m_string_ptr[i] = *str_ptr;
        str_ptr++;
    }
    
    m_string_ptr[m_size + 1] = '\0';
    m_begin = m_string_ptr;
    m_end   = m_string_ptr + m_size + 1; 
};

MyString_ns::MyString::~MyString()
{
    #ifdef DEBUG
        std::cout << "MyString destructor called\n";
    #endif

    if (m_string_ptr != nullptr)
    {
        m_begin = nullptr;
        m_end   = nullptr;
        m_size  = -1;     

        delete [] m_string_ptr;
        m_string_ptr = nullptr;
    }
};

void MyString_ns::MyString::print_data() const
{
    std::cout << "\n===========================================\n";
    std::cout << "m_size: " << m_size << "\n";
    std::cout << "m_string_ptr: " << (void*)m_string_ptr << "\n";
    if (m_string_ptr != nullptr)
    {
        std::cout << "string: ";
        print();
        std::cout << "\n";
    }
    else
    {
        std::cout << "string: nullptr\n";
    }
    std::cout << "m_begin: " << (void*)m_begin << "\n";
    std::cout << "m_end: " << (void*)m_end << "\n"; 
    std::cout << "===========================================\n";
}

size_t MyString_ns::MyString::size() const // ok
{
    return m_size;
}

size_t MyString_ns::get_str_size(const char* str_ptr) // ok
{
    size_t size = 0;

    while (*str_ptr != 0)
    {
        str_ptr++;
        size++;
    }

    return size;
}

void MyString_ns::MyString::print() const // ok
{
    for (size_t i = 0; i <= m_size; i++)
    {
        std::cout << m_string_ptr[i];
    }
};

char* MyString_ns::MyString::begin() const // ok
{
    return m_begin;
};

char* MyString_ns::MyString::end() const // ok
{
    return m_end;
};

void MyString_ns::MyString::operator++()
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_string_ptr[i]++;
    }
}

void MyString_ns::MyString::operator--()
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_string_ptr[i]--;
    }
}

bool MyString_ns::MyString::operator==(MyString& rhs) const
{
    if (m_size != rhs.m_size)
    {
        return false;
    }
    else
    {
        for (size_t i = 0; i <= m_size; i++)
        {
            if (m_string_ptr[i] != rhs.m_string_ptr[i])
            {
                return false;
            }
        }

        return true;
    }
}

MyString_ns::MyString MyString_ns::MyString::operator+(const MyString_ns::MyString &rhs) const
{
    MyString_ns::MyString temp;
    temp.m_size = m_size + rhs.m_size;
    
    temp.m_string_ptr = new char(temp.m_size + 1);
    if (temp.m_string_ptr == nullptr)
    {
        std::cout << "EXCEPTION: error occured when tried to new()\n";
        // here must be exception
    }
    else
    {
        temp.m_begin = temp.m_string_ptr;
        temp.m_end   = temp.m_string_ptr + temp.m_size + 1;

        size_t i_temp = 0;
        for (size_t i = 0; i <= m_size; i++, i_temp++)
        {
            temp.m_string_ptr[i_temp] = m_string_ptr[i];
        }   

        for (size_t i = 0; i <= rhs.m_size; i++, i_temp++)
        {
            temp.m_string_ptr[i_temp] = rhs.m_string_ptr[i];
        }

        temp.m_string_ptr[temp.m_size + 1] = '\0';

        return temp;
    }
}

void MyString_ns::MyString::operator=(const MyString& rhs)
{
    delete [] m_string_ptr;

    m_size = rhs.m_size;

    if (rhs.m_string_ptr != nullptr)
    {
        m_string_ptr = new char(m_size + 1);

        if (m_string_ptr == nullptr)
        {
            std::cout << "EXCEPTION: error occured when tried to new()\n";
            // here must be exception
        }

        for (size_t i = 0; i <= m_size; i++)
        {
            m_string_ptr[i] = rhs.m_string_ptr[i];
        }

        m_string_ptr[m_size + 1] = '\0';
        m_begin = m_string_ptr;
        m_end   = m_string_ptr + m_size + 1; 
    }
    else
    {
        m_string_ptr = nullptr;
        m_end        = nullptr;
        m_begin      = nullptr;
    }
}

