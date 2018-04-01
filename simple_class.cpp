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
CSimpleClass::CSimpleClass()
{
    // Save a default label for the object.
    strcpy(m_sLabel, "Empty");

    // Display a message.
    cout << "Hello from '" << m_sLabel << "' object." << endl;
}



/// Class constructor.
CSimpleClass::CSimpleClass
    (
    const char* sLabel      ///< Specifies the label for the object.
    )
{
    // Save the label for the object.
    // strcpy_s(m_sLabel, STRING_LENGTH, sLabel);   Not available in gcc ?
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



/// A simple action.
void CSimpleClass::Action()
{
    // Display a message.
    cout << "Action from '" << m_sLabel << "' object." << endl;
}
