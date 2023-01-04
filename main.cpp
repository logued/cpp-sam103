// sam103
//
// Functions using value parameters versus reference parameters
// Comparing Pass-by-Value and Pass-by-Reference

#include <iostream>
using namespace std;

int add(int,int);
void swap_by_value(int,int);
void swap_by_reference(int&,int&) ;
int multiply( const int & a, const int & b );

int main() {
    cout << "sam103 - Functions - pass-by-value v. pass-by-reference" << endl;

    // PASS-BY-VALUE example
    // The variables x and y contain integer values 3 and 4.
    // Copies of the values in x and y are passed into the add() function
    int x=3;
    int y=4;
    cout << "Initial variable values: x=" << x << ", y="<<y << endl;
    int sum = add(x,y);
    cout << "Sum of x and y = " << sum << endl;

    swap_by_value(x,y); // attempt to swap around the values of x and y
    cout << "After attempted swap : x=" << x << ", y="<<y << endl;
    cout << "You should see that the values in x and y have NOT been swapped." << endl;
    cout << "This is because the function simply swapped copies of the values taken from x and y, " << endl;
    cout << "but not the actual contents of x and y." << endl;


    // Using REFERENCE Parameters (or Pass-By-Reference)
    //
    swap_by_reference( x, y ) ;
    cout << "After attempted swap : x=" << x << ", y="<<y << endl;
    cout << "You should see that the values in x and y HAVE BEEN Swapped." << endl;
    cout << "This is because the function used REFERENCES to the variables x and y, " << endl;
    cout << "which allowed it to access and swap the contents of x and y." << endl;

    int product = multiply( x, y );
    cout << "X multiplied by Y = " << product << endl;

    return 0;
}

// The two arguments are passed into the function By Value
// This is the default (normal behaviour)
// a receives a copy of the value 3 (from x)
// b receives a copy of the value 4 (from y)
// (this is the same as happens in Java)
int add( int a, int b) {
    return a+b;
}

// Function to attempt swapping of the two arguments.
// This will swap the local values in a and b, however, it will not change the
// values in the original variables x and y, because copies of the values from x and y
// have been passed into the corresponding a and b, but a and b have NO access to
// the variables x and y in main().
// This function has access only to copies of values from main() that were passed in by value.
//
void swap_by_value( int a, int b) {
    int temp = a;
    b = a;
    a = temp;
}

// The parameters in this function are declared as References to type int.
// a is a reference to an int, and when called, a is bound to the variable x.
// 'a' really becomes another name for the variable x, and anything done to 'a' is
// actually really carried out on x.   Similarly, b is another name for y.
// 'b' is a reference to 'y'.
// These are reference parameters.
// Unlike pass-by-value, no copies of the values are passed into the function.
//
void swap_by_reference( int& a, int & b) {
    int temp = a;
    b = a;
    a = temp;
}

// We can specify that a parameter is of type "reference to a constant int", so that it can
// not be used to change the value in the variable that it is accessing (referring to).
// If we know that we don't need to change the value, then it is good practice to always use
// a reference to const.
// Note, for the swap above, we don't use const as we need to change the values in x and y.
//
int multiply( const int & a, const int & b ) {      // reference parameters
    //a = 666; // the compiler will not allow this statement, due to const type
    return a * b;
}

// We will see later that reference parameters are usually more efficient than pass-by-value.

//TODO
// In main(), declare a  variable "double height = 1.86;"
// Call a method named grow(height);
// Write the grow() method to use a reference parameter that will increase the value in the
// variable height by 50%  (so, multiply by 1.5 ).
// The grow() function will not return a value. (return type will be void).