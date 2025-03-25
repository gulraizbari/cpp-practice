// Resource Aquisition in Initialization (RAII)
// -> Pointers wrapped inside a Class
#include <iostream>

class IntArray
{
    size_t arraySize;
    int *intArray;

public:
    IntArray(size_t size) : arraySize(size), intArray(new int[arraySize])
    {
        std::cout << "Array Constructor" << std::endl;
    }

    ~IntArray()
    {
        delete[] intArray;
        std::cout << "Array Destructor" << std::endl;
    };

    int get(size_t index) const
    {
        return intArray[index];
    }

    void set(size_t index, int value)
    {
        intArray[index] = value;
    };

    void print() const
    {
        for (size_t i = 0; i < arraySize; ++i)
        {
            std::cout << i << " " << intArray[i] << std::endl;
        };
    };
};

int main(int argc, char *argv[])
{
    IntArray myArray(5);
    myArray.set(0, 5);
    myArray.set(3, 10);
    myArray.print();

    return 0;
};