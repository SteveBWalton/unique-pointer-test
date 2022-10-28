/// Header file for the simple class.
///@file simple_class.h

#pragma once

// System headers.
#include <string>

class SimpleClass
{
// Constructors.
public:
    SimpleClass();
    SimpleClass(std::string_view);
    SimpleClass(const SimpleClass&);
    virtual ~SimpleClass();

// Member variables.
private:
//  char label_[STRING_LENGTH];
    std::string label_;

// Methods.
public:
    void action() const;
};
