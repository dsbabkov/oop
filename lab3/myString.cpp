#include <cstring>
#include "myString.h"
#include <cstdarg>
#include <utility>

using namespace std;

ostream &operator <<(ostream &os, const MyString &string)
{
    if (string.m_pStr){
        os << string.m_pStr;
    }

    return os;
}

MyString::MyString()
    : m_pStr{ new char[1]{0} }
{
}

MyString::MyString(const char * cstring)
    : m_pStr{ DuplicateCString(cstring) }
{
}

MyString::MyString(const MyString & other)
    : m_pStr{ DuplicateCString(other.m_pStr) }
{
}

MyString::MyString(MyString &&other)
    : m_pStr{other.m_pStr}
{
    other.m_pStr = nullptr;
}

MyString::MyString(char *&&cstring)
    : m_pStr{cstring}
{
    cstring = nullptr;
}

MyString::~MyString()
{
	delete[] m_pStr;
}

const char * MyString::GetString() const
{
    return m_pStr;
}

void MyString::SetNewString(const char * cstring)
{
	delete[] m_pStr;
    m_pStr = DuplicateCString(cstring);
}

MyString &MyString::operator =(const MyString &other)
{
    if (this == &other){
        return *this;
    }

    delete[] m_pStr;
    m_pStr = DuplicateCString(other.m_pStr);
    return *this;
}

MyString &MyString::operator =(MyString &&other)
{
    delete[] m_pStr;
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;

    return *this;
}

MyString &MyString::operator =(const char *cstring)
{
    delete[] m_pStr;
    m_pStr = DuplicateCString(cstring);
    return *this;
}

MyString &MyString::operator +=(const MyString &other)
{
    size_t thisLength = strlen(m_pStr);
    char *tmp = new char[thisLength + strlen(other.m_pStr) + 1];
    strcpy(tmp, m_pStr);
    strcpy(tmp + thisLength, other.m_pStr);

    delete[] m_pStr;
    m_pStr = tmp;

    return *this;
}

MyString &MyString::operator +=(const char *cstring)
{
    size_t thisLength = length();
    char *result = new char[thisLength + strlen(cstring) + 1];
    strcpy(result, m_pStr);
    strcpy(result + thisLength, cstring);
    delete[] m_pStr;
    m_pStr = result;
    return *this;
}

size_t MyString::length() const
{
    return strlen(m_pStr);
}

bool MyString::operator ==(const MyString &other) const
{
    if (this == &other){
        return true;
    }

    return !strcmp(m_pStr, other.m_pStr);
}

bool MyString::operator !=(const MyString &other) const
{
    return !(*this == other);
}

char *DuplicateCString(const char *cstring)
{
    char *result = new char[strlen(cstring) + 1];
    strcpy(result, cstring);
    return result;
}

MyString concatenate(size_t pointerCount, ...)
{
    va_list args;
    va_start(args, pointerCount);
    MyString result;
    for (size_t i = 0; i < pointerCount; ++i){
        result += *va_arg(args, MyString *);
    }
    return result;
}

MyString operator +(MyString left, const MyString &right)
{
    return left += right;
}

MyString concatenate(const char *string1, ...)
{
    size_t string1Length{};
    size_t resultLength = string1Length = strlen(string1);

    va_list args;
    va_start(args,string1);

    while (const char *string = va_arg(args, const char *)){
        resultLength += strlen(string);
    }

    va_start(args,string1);
    char *result = new char [resultLength + 1];
    strcpy(result, string1);
    size_t pos = string1Length;

    while (const char *string = va_arg(args, const char *)){
        strcpy(result + pos, string);
        pos += strlen(string);
    }
    return std::move(result);
}
//MyString concatenate(const char *string1, ...)
//{
//    size_t string1Length{};
//    size_t resultLength{};

//    va_list args;
//    va_start(args,string1);

//    const char *string = string1;

//    while (string){
//        resultLength += strlen(string);
//        string = va_arg(args, const char *);
//    }

//    va_start(args,string1);
//    char *result = new char [resultLength + 1];
//    strcpy(result, string1);
//    size_t pos = string1Length;

//    string = string1;
//    while (string){
//        strcpy(result + pos, string);
//        pos += strlen(string);
//        string = va_arg(args, const char *);
//    }
//    return std::move(result);
//}
