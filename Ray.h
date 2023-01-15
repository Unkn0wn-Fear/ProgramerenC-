 
#define RAY_H

 

   class Ray{
    friend class Vec3D;
    friend class Sphere;

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
 
  
