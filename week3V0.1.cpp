#include <iostream>
#include "math.h"
#include <vector>

namespace st = std;

class Vec3D {
    friend class Ray;
    private:
    float x;
    float y;
    float z;

    public:
    void show (st::string label, Vec3D const &self) const;
    void show(st::string label, float scalar) const;
    void show () const;
    Vec3D(float x, float y, float z);
    Vec3D minus (Vec3D const &self) const;
    Vec3D add (Vec3D const &self, Vec3D const &other) const;
    Vec3D sub (Vec3D const &self, Vec3D const &other) const;
    Vec3D mul (Vec3D const &self, float scalar) const;
    Vec3D div (Vec3D const &self, float scalar) const;
    float norm (Vec3D const &self) const; 
    Vec3D unit (Vec3D const &self) const;
    float dot (Vec3D const &self, Vec3D const &other) const;
    Vec3D cross (Vec3D const &self, Vec3D const &other) const;
};



Vec3D::Vec3D(float x, float y, float z):
    x(x),y(y),z(z)
{}

void Vec3D::show (st::string label, Vec3D const &self) const{
    //variablen van dit type afdrukt in een console window, gelabeld met hun naam en afgesloten
    //met een newline

          std::cout << label << ' ' << self.x << ' ' << self.y << ' ' << self.z;
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

 

Vec3D Vec3D::minus (Vec3D const &self) const {
    //die een vector returnt die de
    //andere kant op wijst als self
return Vec3D(-x, -y, -z);
}



 

Vec3D Vec3D::add (Vec3D const &self, Vec3D const &other) const{

    // de som van self en other returnt
  return Vec3D(self.x + other.x, self.y + other.y, self.z + other.z);
 

}

 

Vec3D Vec3D::sub (Vec3D const &self, Vec3D const &other) const{

 //het verschil van self en other returnt

  return Vec3D(self.x - other.x, self.y - other.y, self.z - other.z);

}

 

Vec3D Vec3D::mul (Vec3D const &self, float scalar) const{

//het product van self en scalar returnt

return Vec3D(self.x * scalar, self.y * scalar, self.z * scalar);

}

 

Vec3D Vec3D::div (Vec3D const &self, float scalar) const{

//het quotient van self en scalar returnt

   return Vec3D(self.x / scalar, self.y / scalar, self.z / scalar);
 

}


 

float Vec3D::norm (Vec3D const &self) const{

    //de norm (lengte) van self returnt

return sqrt(pow(self.x, 2) + pow(self.y, 2) + pow(self.z, 2));
 

}

 

 Vec3D Vec3D::unit (Vec3D const &self) const{

    //en vector returnt met dezelfde richting als z'n self, maar met lengte 1
    auto normsvector = norm(self);
    return Vec3D(self.x / normsvector, self.y / normsvector, self.z / normsvector);
 }

 float Vec3D::dot (Vec3D const &self, Vec3D const &other) const{

    // het inproduct (dot product) van self en other returnt

    return (self.x * other.x) + (self.y * other.y) + (self.z * other.z);
 }

 Vec3D Vec3D::cross (Vec3D const &self, Vec3D const &other) const{

    //het uitproduct (cross product) van self en other returnt
      return Vec3D((self.y*other.z - self.z*other.y), (self.z*other.x - self.x*other.z), (self.x*other.y - self.y*other.x));
  }



   class Ray{
    friend class Vec3D;

    protected:
        Vec3D direction = Vec3D(0,0,0);
        Vec3D support = Vec3D(0,0,0);
    public:

    Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) {
     support.x = xSup;
     support.y = ySup;
     support.z = zSup;
     direction.x = xDir;
     direction.y = yDir;
     direction.z = zDir;
    }
 
 };



 class Sphere
 {
 protected:
 Vec3D center = Vec3D(0,0,0);
 float radius;
 
 public:
 Sphere (float x, float y, float z, float radius) {
    center.x = x;
    center.y = y;
    center.z = z;
    radius = radius;

 }
 
 };


 float distFromRay (Ray const &ray) const {
     return ray.support.sub (center) .cross (ray.direction) .norm ();
 }

bool hit (Ray const &ray) const {
            if (distFromRay(ray) < radius){
                ray.support = hitPoint(ray);
                auto normaal = ray.support.sub(center) .unit();
                auto radial = normaal.mul(ray.direction.dot(normaal));
                auto tangential = ray.direction.sub(radial);
                ray.direction = tangential.sub(radial).unit();
                return true;
            }
            return false ;
        }

}

Vec3D hitPoint (Ray const &ray) const {
        Vec3D Sphere::hitPoint(Ray &ray){
        auto blabla = ray.support.sub(center);
        auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
        auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
        return ray.support.add(ray.direction.mul(distFromSupport));
    }
    
}

 
int main() {
    
std::cout <<"kaas tostie" << std:endl;
}