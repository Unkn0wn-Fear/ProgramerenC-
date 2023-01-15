#include <iostream>
#include "math.h"
#include <vector>
#define VPO std::vector<eindopdracht::Object *>
namespace st = std;



namespace eindopdracht{

    class Ray;
    class Sphere;
    class Vec3D;
    class Floor;
    class Object;
    
    class RayScanner;

    class Vec3D
    {
        friend class Ray;
        friend class Sphere;
        friend class Floor;
        friend class RayScanner;



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


    class Ray
    {
        friend class Vec3D;
        friend class Sphere;
        friend class Floor;
        friend class Object;
        friend class RayScanner;

    protected:
        
        Vec3D direction = Vec3D(0, 0, 0);
        Vec3D support = Vec3D(0, 0, 0);


    public:
        VPO objects;
        Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);
        Ray(float xStart, float yStart, VPO &objects);
        bool scan();

    };

    //parentclass
    class Object
    {
    friend class Vec3D;
    friend class Ray;
    friend class Sphere;
    friend class Floor;
    friend class RayScanner;
    
    protected:
        Vec3D center = Vec3D(0, 0, 0);
       
    public:
   
        Object (float x, float y, float z);
        virtual bool hit(Ray &ray) = 0;      

    };

    //childclass
    class Floor : public Object{
        friend class Vec3D;
        friend class Ray;
        protected:
        Vec3D center = Vec3D(0, 0, 0);
        public:
            Floor(float x, float y, float z);
            bool hit(Ray const &ray) const;
    };

    //childclass
        class Sphere : public Object
    {
        friend class Vec3D;
        friend class Ray;
        friend class Floor;
        friend class RayScanner;
        friend class Object;

    protected:
        Vec3D center = Vec3D(0, 0, 0);
        float radius;

    public:
        Sphere(float x, float y, float z, float radius);
        float distFromRay(Ray const &ray) const;
        bool hit(Ray &ray);
        Vec3D hitPoint(Ray const &ray);
        //Vec3D hitPoint(Ray &ray);
    };

    class RayScanner{
        friend class Vec3D;
        friend class Ray;
        friend class Object;
        friend class Floor;
        friend class Sphere;
    protected:
    

    public:
        VPO objects;
        RayScanner(VPO objects) : objects(objects){}
        void scan();

    };

}