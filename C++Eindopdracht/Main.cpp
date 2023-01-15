#include <iostream>
#include "math.h"
#include <vector>
#include "classes.hpp"

namespace st = std;
 
 namespace ei = eindopdracht; 
#define VPO st::vector<eindopdracht::Object *>

int main() {
    VPO objects = VPO();

    // Create objects Sphere/Floor
    auto object1 = ei::Sphere(1, 1, 1, 1);
    auto object2 = ei::Sphere(-0.4, -0.3, 0.5, 0.2);
    auto object3 = ei::Sphere(-0.1, -0.4, -0.3, 0.4);
    //auto object4 = ei::Floor(0.3,2,2);

    // Push objects into vector
    //objects.push_back(&object1);
    //objects.push_back(&object2);
    //objects.push_back(&object3);
    //objects.push_back(&object4);

    // Raytracer
    ei::RayScanner rayscan(objects);
    rayscan.scan();

    return 0;
}
