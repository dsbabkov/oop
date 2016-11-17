#include "MyString.h"

MyString::MyString(const char *str)
{

}

MyString::MyString(const MyString &other){

}

MyString::MyString(MyString &&other){

}

MyString &MyString::operator = (const MyString &other){
    return *this;
}

MyString &MyString::operator = (MyString &&other){
    return *this;
}
