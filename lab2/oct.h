#pragma once

class Oct
{
    friend union MyByte;

private:
    void show() const;

private:
    unsigned right_: 3;
    unsigned mid_: 3;
    unsigned left_: 2;
};
