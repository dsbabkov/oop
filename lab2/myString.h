#pragma once

char *DuplicateCString(const char *);

class MyString
{
public:
	MyString();
    explicit MyString(const char *cstring);
	MyString(const MyString &other);
	~MyString();

	const char *GetString() const;
	void SetNewString(const char *cstring);

private:
	char* m_pStr;	//строка-член класса
};
