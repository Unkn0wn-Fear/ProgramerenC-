#include "Week3Classes.hpp"
#include <iostream>
#include "math.h"
#include <vector>



Vec3D::Vec3D(float x, float y, float z):
    x(x),y(y),z(z)
{}

void Vec3D::show (st::string label) const{
    //variablen van dit type afdrukt in een console window, gelabeld met hun naam en afgesloten
    //met een newline

          std::cout << label << ' ' << x << ' ' << y << ' ' << z;
              std::cout << '\n';
}

 

void Vec3D::show (st::string label, float scalar) const{
    //die floating point
    //scalars afdrukt in een console window, gelabeld met hun naam en afgesloten met een
    //newline+

         std::cout << label << ' ' << scalar << ' ';
             std::cout << '\n';

 

}

 

void Vec3D::show() const{
      std::cout << '\n';

}

 

Vec3D Vec3D::minus() const {
    //die een vector returnt die de
    //andere kant op wijst als self
return Vec3D(-x, -y, -z);
}



 

Vec3D Vec3D::add(Vec3D const &other) const{

    // de som van self en other returnt
  return Vec3D(x + other.x, y + other.y,  z + other.z);
 

}

 

Vec3D Vec3D::sub (Vec3D const &other) const{

 //het verschil van self en other returnt

  return Vec3D( x - other.x,  y - other.y,  z - other.z);

}

 

Vec3D Vec3D::mul (float scalar) const{

//het product van self en scalar returnt

return Vec3D( x * scalar,  y * scalar,  z * scalar);

}

 

Vec3D Vec3D::div (float scalar) const{

//het quotient van self en scalar returnt

   return Vec3D( x / scalar,  y / scalar,  z / scalar);
 

}


 

float Vec3D::norm () const{

    //de norm (lengte) van self returnt

return sqrt(pow( x, 2) + pow( y, 2) + pow( z, 2));
 

}

 

 Vec3D Vec3D::unit () const{

    //en vector returnt met dezelfde richting als z'n self, maar met lengte 1
    auto normsvector = norm();
    return Vec3D( x / normsvector, y / normsvector,  z / normsvector);
 }

 float Vec3D::dot (Vec3D const &other) const{

    // het inproduct (dot product) van self en other returnt

    return ( x * other.x) + ( y * other.y) + (z * other.z);
 }

 Vec3D Vec3D::cross (Vec3D const &other) const{

    //het uitproduct (cross product) van self en other returnt
      return Vec3D(( y*other.z -  z*other.y), (z*other.x -  x*other.z), ( x*other.y -  y*other.x));
  }

float Sphere::distFromRay(Ray const &ray) const {
    return ray.support.sub(center).cross(ray.direction).norm();
}


bool Sphere::hit (Ray const &ray) const {
    auto a = pow(ray.direction.norm(), 2);
    auto b = 2 * (ray.direction.dot(ray.support.sub(center)));
    auto c = pow(ray.support.sub(center).norm(), 2) - pow(radius, 2);
    auto D = pow(b, 2) - 4 * a * c;
    if(D >= 0){
        return true;
    }

    return false;
}

Vec3D Sphere::hitPoint (Ray const &ray) const {
        auto blabla = ray.support.sub(center);
        auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
        auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
        return ray.support.add(ray.direction.mul(distFromSupport));
    
}




