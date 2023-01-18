//include weer alle liberaries
#include <iostream>
#include "math.h"
#include <vector>
//maakt een vector VPO voor object Object 
#define VPO std::vector<eindopdracht::Object *>
//weer namespace zodat je st kan gegbruiken ipv std 
namespace st = std;



namespace eindopdracht{
    //maakt alvast de classes aan zodat je geen gekke errors krijgt als je al iets probeert te gebruiken van een class maar die class is nog niet gemaakt
    class Ray;
    class Sphere;
    class Vec3D;
    class Floor;
    class Object;
    class RayScanner;

    class Vec3D
    {
        //zorgd ervoor dat ik dingen van andere classes kan aanroepen 
        friend class Ray;
        friend class Sphere;
        friend class Floor;
        friend class RayScanner;


    //maakt floats aan voor x y en z staat in protected z zodat het veiliger is dan als je het in public zet 
    protected:
        float x;
        float y;
        float z;

    public:
    //initialiseerd alle functies die vervolgens worden gemaakt in classes.cpp 
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
        //zorgd ervoor dat ik dingen van andere classes kan aanroepen 
        friend class Vec3D;
        friend class Sphere;
        friend class Floor;
        friend class Object;
        friend class RayScanner;

    protected:
        //maaakt voor ray direction en support aan (hoeft niet met = vec3D 0.0.0 maar vond ik feiner om te doen tijdens debuggen)
        Vec3D direction = Vec3D(0, 0, 0);
        Vec3D support = Vec3D(0, 0, 0);


    public:
        //makat weer functies aan die in de cpp worden uitgelegt 
        VPO objects;
        Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);
        Ray(float xStart, float yStart, VPO &objects);
        bool scan();

    };

    //abstract base class 
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
        //zorgd ervoor dat de functie kan worden overreden door derrived classes 
        virtual bool hit(Ray const &ray) const = 0;      

    };

    //derived class dus de members van Object zijn geinherit door Floor
    class Floor : public Object{
        friend class Vec3D;
        friend class Ray;
        protected:
        Vec3D center = Vec3D(0, 0, 0);
        public:
            Floor(float x, float y, float z);
            bool hit(Ray const &ray) const;
    };

    //derived class dus members van Object zijn geinherit door Sphre
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
        bool hit(Ray const &ray)const;
        Vec3D hitPoint(Ray const &ray);
     
    };

    class RayScanner{
        friend class Vec3D;
        friend class Ray;
        friend class Object;
        friend class Floor;
        friend class Sphere;
    protected:
       VPO objects;

    public:
     
        RayScanner(VPO objects) : objects(objects){}
        void scan();

    };

}