/// Project to test unique pointers.
///@file unique_pointer_test.cpp

// File header.
#include "unique_pointer_test.h"

// System headers.
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>           // unique_ptr

// Applications headers.
#include "simple_class.h"



/// A function that create an object and then throws an exception.
int errorFunction()
{
    // Create a unique pointer object.
    std::unique_ptr<SimpleClass> errorFunctionObject (new SimpleClass("errorFunction"));

    // Throw an exception.
    throw(1);
}




/// A function that creates a couple of unique pointers.
int testFunction()
{
    using std::cout;
    using std::endl;

    // Create an object with an attached unique pointer object.
    std::unique_ptr<SimpleClass> functionOneObject (new SimpleClass("testFunction.One"));

    // Call a function that throws an exception.
    try
    {
        errorFunction();
    }
    catch(...)
    {
        cout << "An exception was caught." << endl;
    }

    // Create a unique pointer object.
    std::unique_ptr<SimpleClass> functionTwoObject (new SimpleClass("testFunction.Two"));

    // Return success.
    return 0;
}



/// The main entry point for the "unique_pointer_test" program.
///@returns 0 for success, otherwise an error code.
int main
(
    int             argc,   ///< Specifies the number of command line arguments.
    const char**    argv    ///< Specifies the actual command line arguments.
)
{
    using std::cout;
    using std::endl;

    // Welcome message.
    cout << "Hello from unique pointer test." << endl;

    // Make a static object.
    SimpleClass staticObject("Static");
    staticObject.action();

    // Create a simple object.
    SimpleClass* localObject = new SimpleClass("Standard");
    localObject->action();

    // Call a function that creates unique pointer objects.
    testFunction();

    // Create a unique pointer object.
    std::unique_ptr<SimpleClass> anotherLocalObject (new SimpleClass("UniquePtr"));
    anotherLocalObject->action();

    // Create an array of unique pointer objects, using empty constructor.
    std::unique_ptr<SimpleClass[]> objectArray (new SimpleClass[3]);    // [] to use delete[] to release each object.
    objectArray[0].action();
    objectArray[1].action();
    objectArray[2].action();

    // A vector can be used to create an array of objects.
    // This looks nicer than unique_ptr but seems equivalent.
    std::vector<SimpleClass> objectVector (3);
    objectVector[0].action();
    objectVector[1].action();
    objectVector[2].action();

    // Release the standard object.
    delete localObject;

    // Return success.
    return 0;
}

