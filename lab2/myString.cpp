#include <cstring>
#include "myString.h"

using namespace std;

MyString::MyString()
	: m_pStr{ new char[1] }
{
	m_pStr[0] = '\0';
}

MyString::MyString(const char * cstring)
    : m_pStr{ DuplicateCString(cstring) }
{
}

MyString::MyString(const MyString & other)
    : m_pStr{ DuplicateCString(other.m_pStr) }
{
}

MyString::~MyString()
{
	delete[] m_pStr;
}

const char * MyString::GetString() const
{
    return this ?
                m_pStr :
                "nullptr";
}

void MyString::SetNewString(const char * cstring)
{
	delete[] m_pStr;
    m_pStr = DuplicateCString(cstring);
}

char *DuplicateCString(const char *cstring)
{
    char *result = new char[strlen(cstring) + 1];
    strcpy(result, cstring);
    return result;
}
