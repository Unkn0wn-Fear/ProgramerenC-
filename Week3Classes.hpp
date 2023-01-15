#define VEC3D_H
#define VEC3D_H

#include <iostream>
#include "math.h"
#include <vector>

#pragma once
 namespace st = std;

class Vec3D {
   
    friend class Ray;
    friend class Sphere;
    private:
    float x;
    float y;
    float z;

    public:
    void show (st::string label) const;
    void show(st::string label, float scalar) const;
    void show () const;
    Vec3D(float x, float y, float z);
    Vec3D minus ( ) const;
    Vec3D add (  Vec3D const &other) const;
    Vec3D sub ( Vec3D const &other) const;
    Vec3D mul ( float scalar) const;
    Vec3D div ( float scalar) const;
    float norm ( ) const; 
    Vec3D unit ( ) const;
    float dot ( Vec3D const &other) const;
    Vec3D cross ( Vec3D const &other) const;
};



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

 };



 class Sphere
 {
    friend class Vec3D;
    friend class Ray;
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
    float distFromRay (Ray const &ray) const;
    bool hit (Ray const &ray) const;
    Vec3D hitPoint (Ray const &ray) const;
 
 };

int main() {


}

