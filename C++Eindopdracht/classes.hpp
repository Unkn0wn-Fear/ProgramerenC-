#include <iostream>
#include "math.h"
#include <vector>

namespace st = std;
#define VPO = st::vector <Object*>

namespace eindopdracht{

    class Ray;
    class Sphere;
    class Vec3D;

    class Vec3D
    {
        friend class Ray;
        friend class Sphere;

    protected:
        float x;
        float y;
        float z;

    public:
        void show(st::string label) const;
        void show(st::string label, float scalar) const;
        void show() const;
        Vec3D(float x, float y, float z);
        Vec3D minus() const;
        Vec3D add(Vec3D const &other) const;
        Vec3D sub(Vec3D const &other) const;
        Vec3D mul(float scalar) const;
        Vec3D div(float scalar) const;
        float norm() const;
        Vec3D unit() const;
        float dot(Vec3D const &other) const;
        Vec3D cross(Vec3D const &other) const;
    };

    class Sphere : public Object
    {
        friend class Vec3D;
        friend class Ray;

    protected:
        Vec3D center = Vec3D(0, 0, 0);
        float radius;

    public:
        float distFromRay(Ray const &ray) const;
        Sphere(float x, float y, float z, float radius);
        bool hit(Ray &ray);
        // Vec3D hitPoint(Ray const &ray);
        Vec3D hitPoint(Ray &ray);
    };

    class Ray
    {
        friend class Vec3D;
        friend class Sphere;

    protected:
        Vec3D direction = Vec3D(0, 0, 0);
        Vec3D support = Vec3D(0, 0, 0);
        

    public:
        Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);

    };


    class Object
    {

    protected:
        Vec3D center;

        
        Object(float x, float y, float z);
      
        virtual bool hit(Ray &ray) = 0;
    };


    class Floor {



    };
}