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
    SimpleClass* errorFunctionObject = new SimpleClass("ErrorFunction");
    std::unique_ptr<SimpleClass> upObject (errorFunctionObject);

    // Throw an exception.
    throw(1);
}




/// A function that creates a couple of unique pointers.
int function()
{
    using std::cout;
    using std::endl;

    // Create an object with an attached unique pointer object.
    SimpleClass* functionOneObject = new SimpleClass("Function.One");
    std::unique_ptr<SimpleClass> upObject1 (functionOneObject);

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
    SimpleClass* functionTwoObject = new SimpleClass("Function.Two");
    std::unique_ptr<SimpleClass> upObject2 (functionTwoObject);

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
    function();

    // Create a simple object that we will attach a unique pointer object to.
    SimpleClass* anotherLocalObject = new SimpleClass("UniquePtr");
    // Create a unique pointer object.
    std::unique_ptr<SimpleClass> upObject2 (anotherLocalObject);
    anotherLocalObject->action();
    upObject2->action();

    // Create an array of unique pointer objects, using empty constructor.
    SimpleClass* objectArray = new SimpleClass[3];
    std::unique_ptr<SimpleClass[]> upObjectArray (objectArray);    // [] to use delete[] to release each object.
    objectArray[0].action();
    objectArray[1].action();
    objectArray[2].action();

    // A vector can be used to create an array of objects.
    // This works well for int and double where there is no constructor / destructor.
    // For an actual object. need to be carefull that the constructors / destructors are called.
    std::vector<SimpleClass> objectVector (3);
    objectVector[0].action();
    objectVector[1].action();
    objectVector[2].action();

    // Release the standard object.
    delete localObject;

    // Return success.
    return 0;
}

