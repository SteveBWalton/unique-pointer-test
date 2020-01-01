/// Implementation of a simple class to test unique pointers.
///@file simple_class.cpp

// File header.
#include "simple_class.h"

// System headers.
#include <iostream>
#include <string.h>

// Application headers.



/// Class constructor.
SimpleClass::SimpleClass()
{
    // Save a default label for the object.
    strcpy(label_, "Empty");

    // Display a message.
    std::cout << "Hello from '" << label_ << "' object." << std::endl;
}



/// Class constructor.
SimpleClass::SimpleClass
    (
    const char* label      ///< Specifies the label for the object.
    )
{
    // Save the label for the object.
    // strcpy_s(label_, STRING_LENGTH, label);   Not available in gcc ?
    strcpy(label_, label);

    // Display a message.
    std::cout << "Hello from '" << label_ << "' object." << std::endl;
}



/// Class destructor.
SimpleClass::~SimpleClass()
{
    // Display a message.
    std::cout << "Goodbye from '" << label_ << "' object." << std::endl;
}



/// A simple action.
void SimpleClass::action()
{
    // Display a message.
    std::cout << "Action from '" << label_ << "' object." << std::endl;
}
