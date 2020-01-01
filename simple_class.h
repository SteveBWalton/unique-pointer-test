/// Header file for the simple class.
///@file simple_class.h

#pragma once

#define STRING_LENGTH 20

class SimpleClass
{
// Constructors.
public:
    SimpleClass();
    SimpleClass(const char*);
    virtual ~SimpleClass();

// Member variables.
private:
    char label_[STRING_LENGTH];

// Methods.
public:
    void action();
};
