/// Header file for the simple class.
///@file simple_class.h

#pragma once

#define STRING_LENGTH 20

class CSimpleClass
{
// Constructors.
public:
    CSimpleClass(const char*);
    virtual ~CSimpleClass();

// Member variables.
private:
    char m_sLabel[STRING_LENGTH];
};
