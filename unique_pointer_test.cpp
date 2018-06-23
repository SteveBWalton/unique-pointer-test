/// Project to test unique pointers.
///@file unique_pointer_test.cpp

// File header.
#include "unique_pointer_test.h"

// System headers.
#include <stdio.h>
#include <iostream>
#include <memory>           // unique_ptr
using namespace std;

// Applications headers.
#include "simple_class.h"



/// A function that create an object and then throws an exception.
int ErrorFunction()
{
    // Create a unique pointer object.
    CSimpleClass* pObject1 = new CSimpleClass("ErrorFunction");
    unique_ptr<CSimpleClass> upObject1 (pObject1);

    // Throw an exception.
    throw(1);
}




/// A function that creates a couple of unique pointers.
int Function()
{
    // Create an object with an attached unique pointer object.
    CSimpleClass* pObject1 = new CSimpleClass("Function.One");
    unique_ptr<CSimpleClass> upObject1 (pObject1);

    // Call a function that throws an exception.
    try
    {
        ErrorFunction();
    }
    catch(...)
    {
        cout << "An exception was caught." << endl;
    }

    // Create a unique pointer object.
    CSimpleClass* pObject2 = new CSimpleClass("Function.Two");
    unique_ptr<CSimpleClass> upObject2 (pObject2);


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
    // Welcome message.
    cout << "Hello from unique pointer test." << endl;

    // Make a static object.
    CSimpleClass oObject("Static");
    oObject.Action();

    // Create a simple object.
    CSimpleClass* pObject = new CSimpleClass("Standard");
    pObject->Action();

    // Call a function that creates unique pointer objects.
    Function();

    // Create a simple object that we will attach a unique pointer object to.
    CSimpleClass* pObject2 = new CSimpleClass("UniquePtr");
    // Create a unique pointer object.
    unique_ptr<CSimpleClass> upObject2 (pObject2);
    pObject2->Action();
    upObject2->Action();

    // Create an array of unique pointer objects, using empty constructor.
    CSimpleClass* pObjectArray = new CSimpleClass[3];
    unique_ptr<CSimpleClass[]> upObjectArray (pObjectArray);    // [] to use delete[] to release each object.
    pObjectArray[0].Action();
    pObjectArray[1].Action();
    pObjectArray[2].Action();

    // Release the standard object.
    delete pObject;

    // Return success.
    return 0;
}

