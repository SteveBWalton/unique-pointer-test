/// Implementation of a simple class to test unique pointers.
///@file simple_class.cpp

// File header.
#include "simple_class.h"

// System headers.
#include <iostream>
#include <string.h>
using namespace std;

// Application headers.



/// Class constructor.
CSimpleClass::CSimpleClass
    (
    const char* sLabel
    )
{
    // Save the label for the object.
    // strcpy_s(m_sLabel, STRING_LENGTH, sLabel);
    strcpy(m_sLabel, sLabel);

    // Display a message.
    cout << "Hello from '" << m_sLabel << "' object." << endl;
}



/// Class destructor.
CSimpleClass::~CSimpleClass()
{
    // Display a message.
    cout << "Goodbye from '" << m_sLabel << "' object." << endl;
}

