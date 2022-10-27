/// Implementation of a simple class to test unique pointers.
/// std::string_view requires C++ 17.
///@file simple_class.cpp

// File header.
#include "simple_class.h"

// System headers.
#include <iostream>
#include <string>

// Application headers.



/// Class constructor.
SimpleClass::SimpleClass()
{
    // Save a default label for the object.
    label_ = "Empty";

    // Display a message.
    std::cout << "Hello from '" << label_ << "' object." << std::endl;
}



/// Class constructor.
SimpleClass::SimpleClass
(
    std::string_view label  ///< Specifies the label for the object.
)
{
    // Save the label for the object.
    label_ = label;

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
void SimpleClass::action() const
{
    // Display a message.
    std::cout << "Action from '" << label_ << "' object." << std::endl;
}
