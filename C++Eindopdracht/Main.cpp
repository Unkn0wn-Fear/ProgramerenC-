#include <iostream>
#include "math.h"
#include <vector>
// #include "classes.hpp"
#include "/home/marijn/Documents/C++Eindopdracht/classes.hpp"

namespace st = std;
 
 namespace ei = eindopdracht; 
int main() {
    
    // // auto a = Vec3D(1,2,3);
    // auto vec1 = ei::Vec3D(1,2,3);
    // auto vec2 = ei::Vec3D(1,2,3);
    // auto vec3 = vec2.sub(vec1);
    // vec3.show("Vec3");
    // auto a = ei::Sphere(1,2,3,1);
    // std::cout <<"kaas tostie" << std::endl; 

    auto sphe1 = ei::Sphere (-0.4, 0.23, -1, 0.4); 
    auto sphe2 = ei::Sphere (0.4, 0.4, -1.2, 0.3);
    auto sphe3 = ei::Sphere (0.7, -0.15, -1.5, 0.2);
    auto far = 100000000;
    auto ray1 = ei::Ray (-far, 0.23, -1, far, 0, 0);
    auto ray2 = ei::Ray (0.4, -far, -1.2, 0, far, 0);
    auto ray3 = ei::Ray (0.7,-0.15, -far, 0, 0, far);

    auto a =(sphe1.hit(ray1));
    std::cout <<a << std::endl; 

    auto b =(sphe2.hit(ray1));
    std::cout <<a << std::endl; 

    auto c =(sphe2.hit(ray1));
    std::cout <<a << std::endl; 
    

return 0;
}
