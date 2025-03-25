#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Enter three numbers: ";
    int x;
    int y;
    int z;
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", and " << z << "\n";
    return 0;
}