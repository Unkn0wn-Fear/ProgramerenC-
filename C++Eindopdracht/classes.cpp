#include <iostream>
#include "math.h"
#include <vector>
#include "classes.hpp"
namespace st = std;


#define VF std::vector<float>
#define VVF std::vector<VF>

namespace eindopdracht{


    Vec3D::Vec3D(float x, float y, float z):
            x(x),y(y),z(z)
    {

    }

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


    Vec3D Vec3D::minus () const {
        //die een vector returnt die de
        //andere kant op wijst als self
        return Vec3D(-x, -y, -z);
    }





    Vec3D Vec3D::add ( Vec3D const &other) const{

        // de som van self en other returnt
        return Vec3D(x + other.x,  y + other.y,  z + other.z);


    }



    Vec3D Vec3D::sub ( Vec3D const &other) const{

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
        return Vec3D( x / normsvector,  y / normsvector,  z / normsvector);
    }

    float Vec3D::dot ( Vec3D const &other) const{

        // het inproduct (dot product) van self en other returnt

        return ( x * other.x) + ( y * other.y) + ( z * other.z);
    }

    Vec3D Vec3D::cross (Vec3D const &other) const{

        //het uitproduct (cross product) van self en other returnt
        return Vec3D(( y*other.z -  z*other.y), ( z*other.x -  x*other.z), ( x*other.y -  y*other.x));
    }


    Sphere::Sphere(float x, float y, float z, float radius) : Object(x, y, z), radius(radius)
    {
        center = Vec3D(x,y,z);

    }
    Floor::Floor(float x, float y, float z) : Object(x,y,z)  {
        center.x = x;
        center.y = y;
        center.z = z;
    }

    Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir){
        support.x = xSup;
        support.y = ySup;
        support.z = zSup;
        direction.x = xDir;
        direction.y = yDir;
        direction.z = zDir;
    }

    Ray::Ray(float xStart, float yStart, VPO &objects) : objects(objects) {
        support=Vec3D(0,0,3);
        direction = Vec3D(xStart, yStart, 0).sub(support);

    }


    float Sphere::distFromRay (Ray const &ray)const
    {
        return ray.support.sub (center).cross(ray.direction).norm ();
    }



    Vec3D Sphere::hitPoint(Ray const &ray){
        auto blabla = ray.support.sub(center);
        auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
        auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
        return ray.support.add(ray.direction.mul(distFromSupport));
    }

    Object::Object (float x, float y, float z): center (x, y, z) {}

    //Deze method test in derived classes of het betreffende object geraakt wordt door de straal en
    //wat de support vector en de direction vector van de weerkaatste straal zijn.

    bool Ray::scan() {
        for (auto OBJ : objects) {

            if (OBJ->hit(*this)) {
                return true;
            }
        }
        return false;

    }


    bool Sphere::hit(Ray const &ray) const{
        return distFromRay(ray) <= radius;
    }

    bool Object::hit(Ray const &ray)const {}

    bool Floor::hit(Ray const &ray) const
    {
    // mischien https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
    //formule wit en zwart rowindex%2 == columnindex%2

    auto widthSquares = 3;
    auto normalVector = Vec3D(0, 1, 0);

    // Calculate distance between hit point and start of Ray
    auto dot = center.sub(ray.support).dot(normalVector) / ray.direction.dot(normalVector);

    // Calculate hit point
    auto hitpoint = ray.support.add(ray.direction.mul(dot));

    // Check if hit point is on the floor
    return (hitpoint.z > 0 && ((int)(hitpoint.z / widthSquares) % 2 == 0 ^ (int)(hitpoint.x / widthSquares) % 2 == 0));
    }


    void RayScanner::scan() {
        auto const RijXas = 96;
        auto const RijYas = 3 * RijXas;
        auto const aspectRatio = 0.4;
        auto const ScreenDist = 3.00;

        auto const ascii = std::string(" M");

        auto const minRadius = 0.2;
        auto const maxRadius = 0.4;

        auto image = VVF (RijXas, VF(RijYas));

        for (auto rowIndex = 0; rowIndex < RijXas;rowIndex++) {
            auto y = (RijXas / 2. - rowIndex) / RijXas;
            for (auto colIndex = 0; colIndex < RijYas; colIndex++) {
                auto x = (RijYas / 2 - colIndex ) / (aspectRatio * RijYas);
                auto VisionRay = Ray(x,y,objects);
            

                if (VisionRay.scan()== true ) {
                    //std::cout << "a";
                    image [rowIndex][colIndex] = 1;
                }
                else if(VisionRay.scan()== false) {
                    //std::cout << "b";
                    image [rowIndex][colIndex] = 0;
                }

            }
        }
        for (auto rowIndex = 0; rowIndex < RijXas; rowIndex++) {
            for (auto colIndex = 0; colIndex < RijYas; colIndex++) {
                if (image [rowIndex][colIndex] == 1) {
                    std::cout << ascii[1];
                }
                else {
                    std::cout << ascii[0];
                }
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

}