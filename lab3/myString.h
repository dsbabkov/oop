#pragma once

#include <cstddef>

char *DuplicateCString(const char *);

class MyString
{
public:
	MyString();
    MyString(const char *cstring);
	MyString(const MyString &other);
    MyString(MyString &&other);
    MyString(char *&& cstring);
	~MyString();

	const char *GetString() const;
	void SetNewString(const char *cstring);

    MyString &operator = (const MyString &other);
    MyString &operator +=(const MyString &other);

private:
	char* m_pStr;	//строка-член класса
};

MyString operator +(MyString left, const MyString &right);

MyString concatenate(size_t pointerCount, ...);
MyString concatenate(const char * string1, ...);
