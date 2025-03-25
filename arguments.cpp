#include <iostream>

// pass by value
void assignByValue(int i)
{
    i = 10;
    std::cout << &i << std::endl;
};

// pass by pointer
void assignByPointer(int *i)
{
    *i = 12;
    std::cout << &i << std::endl;
};

// pass by reference
void assignByReference(int &i)
{
    i = 14;
    std::cout << &i << std::endl;
};

void display(int &i)
{
    std::cout << &i << " " << i << " " << sizeof(i) << std::endl;
}

int main(int argc, char *argv[])
{
    int a = 4;
    int b = 6;
    int c = 8;

    assignByValue(a);
    assignByPointer(&b);
    assignByReference(c);

    std::cout << "a: " << a << " " << sizeof(a) << std::endl;
    std::cout << "b: " << b << " " << sizeof(b) << std::endl;
    std::cout << "c: " << c << " " << sizeof(c) << std::endl;

    int stackArray[10] = {};
    int *heapArray = new int[10];

    for (size_t index = 0; index < 10; index++)
    {
        display(stackArray[index]);
    }

    std::cout << "-- HEAP ARRAY --" << std::endl;

    for (size_t index = 0; index < 10; index++)
    {
        display(heapArray[index]);
    }

    int x = 10;
    int y = 20;
    int *px = &x;
    int *py = &y;

    std::cout << "Memory Address of x: " << &x << std::endl;
    std::cout << "Memory Address of y: " << &y << std::endl;

    *(px) = 13;    // overwrites the value of x
    *(px - 1) = 9; // overwrite the value of y without even explicitly calling it. As it knows px is a int pointer so subtracting 1 from it actually subtracts 4 bytes from the reference and goes to y which is stored before x, and modifies its value.
    *(&x) = 18;

    display(x);
    display(y);

    return 0;
};