// Resource Aquisition in Initialization (RAII)
// -> Pointers wrapped inside a Class
#include <iostream>

// -> using generics you can make the array work for any data type
template <typename T>
class DynamicArray
{
    size_t arraySize;
    T *intArray;

public:
    DynamicArray(size_t size) : arraySize(size), intArray(new T[arraySize])
    {
        std::cout << "Array Constructor" << std::endl;
    }

    ~DynamicArray()
    {
        delete[] intArray;
        std::cout << "Array Destructor" << std::endl;
    };

    T get(size_t index) const
    {
        return intArray[index];
    }

    void set(size_t index, T value)
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

    // if you want to access and modify the value of the array by the standard syntax like:
    // myArray[5] = 10;
    // instead of using setters/getters, then we can use the following:
    T &operator[](size_t index)
    {
        return intArray[index];
    };
    // where "T & operator [] (size_t index)" the:
    // operator: indicates a operator is being declared ahead.
    // []: indicates that we will use this to pass a index and perform something; in our case it would be accessing the element of the array.
    // T &: indicate that the operation will return reference to the value of type "T".

    // const version of the above method.
    // method overload
    // now when I try to access the array element, compiler will use this version of the method
    // for assigning the value it will use the above version (without const)
    const T &operator[](size_t index) const
    {
        return intArray[index];
    };
};

int main(int argc, char *argv[])
{
    DynamicArray<float> myArray(10);
    myArray.set(0, 5.345);
    myArray[1] = 75.57;
    myArray.set(3, 10.788);
    myArray[4] = 98.666;
    myArray.set(5, 15.274);

    std::cout << myArray[1] << std::endl;

    myArray.print();

    return 0;
};