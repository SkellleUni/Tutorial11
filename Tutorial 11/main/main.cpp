#include <iostream>
#include "Vector2.hpp"

using Maths::Vector2;

int main(int argc, char* argv[])
{
    std::cout << "Hello World" << std::endl;

    Maths::Vector2<float> v1(1.0f, 2.0f);
    Maths::Vector2<float> v2(3.0f, 3.0f);

    std::cout << "v1 is ";
    std::cout << "[" << v1.x() << "," << v1.y() << "]" << std::endl;

    std::cout << "v2 is ";
    std::cout << "[" << v2.x() << "," << v2.y() << "]" << std::endl;


    v1 = v1 + v2;
    std::cout << "v1 = v1 + v2";
    std::cout << "[" << v1.x() << "," << v1.y() << "]" << std::endl;

    // testing overloaded scale. 
    v1 *= 2.0f;
    std::cout << "v1 *= 2.0f is ";
    std::cout << "[" << v1.x() << "," << v1.y() << "]" << std::endl;

    std::cout << "Length squared of v1 is " << v1.lengthSquared() << std::endl;

    //  Using get and set operations

    Vector2<int> v3(2, 3);
    v3.x(3);
    v3.y(4);

    std::cout << "v3 is ";
    std::cout << "[" << v3.x() << "," << v3.y() << "]" << std::endl;




}
