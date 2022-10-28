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



/// Test that the object is not destroyed by function going out of scope but by the vector going out of scope.
void testPushToVector
(
    std::vector<std::unique_ptr<SimpleClass>>& theVector
)
{
    theVector.push_back(std::make_unique<SimpleClass>("Inside Function 1"));
    theVector.push_back(std::make_unique<SimpleClass>("Inside Function 2"));

    std::cout << "testPushToVector() has finished." << std::endl;
}



/// Test passing unique_ptr objects to functions.
void useObject
(
    const SimpleClass& localObject
)
{
    std::cout << "Inside useObject() function." << std::endl;
    localObject.action();
}



/// Test of creating a unique_ptr in a function.
std::unique_ptr<SimpleClass> makeObject()
{
    std::unique_ptr<SimpleClass> localObject (new SimpleClass("CreatedInsideFunction"));
    // std::move() is not needed because of copy elision.
    return localObject;
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
    std::cout << std::endl << "Use inside function." << std::endl;
    testFunction();

    // Create a unique pointer object.
    std::cout << std::endl << "Use function." << std::endl;
    std::unique_ptr<SimpleClass> anotherLocalObject (new SimpleClass("UniquePtr"));
    anotherLocalObject->action();
    useObject(*anotherLocalObject);

    // Create an array of unique pointer objects, using empty constructor.
    std::cout << std::endl << "Array of unique pointers." << std::endl;
    std::unique_ptr<SimpleClass[]> objectArray (new SimpleClass[3]);    // [] to use delete[] to release each object.
    objectArray[0].action();
    objectArray[1].action();
    objectArray[2].action();

    // A vector can be used to create an array of objects.
    // This has some problems with extra SimpleClass copy constructions and then destructions.
    std::cout << std::endl << "Simple Vector." << std::endl;
    std::vector<SimpleClass> objectVector;
    objectVector.reserve(10);
    // In the following, a copy constructor is used to put an object in the vector.
    objectVector.push_back(SimpleClass("Simple Vector 1"));
    objectVector.push_back(SimpleClass("Simple Vector 2"));
    objectVector.emplace_back(SimpleClass("Simple Vector 3"));
    objectVector[0].action();
    objectVector[1].action();
    objectVector[2].action();

    // This does not have the copy constructor problems since unique_ptr can not be copied only moved.
    std::cout << std::endl << "Vector (1)." << std::endl;
    std::vector<std::unique_ptr<SimpleClass>> uniqueObjectVector;
    // Even without (or too small) a reserve, then are no object copies only moves.
    uniqueObjectVector.reserve(10 - 9);
    // This is much better than the push_back() on objectVector because the object is moved into the vector not copied.
    uniqueObjectVector.push_back(std::make_unique<SimpleClass>("Not unique_ptr 1"));
    uniqueObjectVector.push_back(std::make_unique<SimpleClass>("Not unique_ptr 2"));
    // This shows that the vector destroys the object not the original scope ending.
    testPushToVector(uniqueObjectVector);
    uniqueObjectVector[0]->action();
    uniqueObjectVector[1]->action();
    uniqueObjectVector[2]->action();
    uniqueObjectVector[3]->action();

    // Another way of moving objects into a vector.
    // The vector.push_back() example above shows that this is not needed.
    std::cout << std::endl << "Vector (2)." << std::endl;
    uniqueObjectVector.clear();
    uniqueObjectVector.resize(3);
    for (int i = 0; i < 3; i++)
    {
        // Create a new SimpleClass object.
        std::unique_ptr<SimpleClass> tempObject(new SimpleClass("UniqueObjectVector " + std::to_string(i)));
        // Allow the vector to own the tempObject.
        uniqueObjectVector[i] = std::move(tempObject);
    }
    uniqueObjectVector[0]->action();
    uniqueObjectVector[1]->action();
    uniqueObjectVector[2]->action();

    // Return a unique pointer from a function.
    std::cout << std::endl << "Return from a function." << std::endl;
    std::unique_ptr<SimpleClass> functionObject = makeObject();
    functionObject->action();

    std::cout << std::endl << "End of the program." << std::endl;

    // Release the standard object.
    delete localObject;

    // Return success.
    return 0;
}

