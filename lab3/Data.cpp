#include "Data.h"

Data::Data()
    : age{}
    , sex{}
    , profession{}
    , salary{}
{

}

Data::Data(unsigned char age, Data::Sex sex, const MyString &profession, double salary)
    : age{age}
    , sex{sex}
    , profession{profession}
    , salary{salary}
{
}
