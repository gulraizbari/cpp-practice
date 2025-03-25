#include <iostream>
#include <vector>

// using namespace std;

int sum(int A)
{
    return A + A;
}

int sum(int A, int B)
{
    return A + B;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;
    int a = 10;
    int b = 20;
    int c = a + b;
    std::string first = "Gulraiz";
    std::string last = "Bari";
    int sum_ = sum(a);
    std::cout << first << " " << last << std::endl;
    std::cout << c << std::endl;
    std::cout << sum_ << std::endl;

    std::vector<int> _vector;
    _vector.push_back(50);
    _vector.push_back(10);
    for (int i = 0; i < _vector.size(); i++)
    {
        std::cout << "i: " << _vector[i] << std::endl;
    }

    std::vector<float> _floatVector;
    _floatVector.push_back(22.5f);
    _floatVector.push_back(63.7f);
    for (auto i : _floatVector)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
