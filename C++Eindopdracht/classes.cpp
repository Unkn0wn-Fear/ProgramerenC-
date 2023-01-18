//include de liberarys 
#include <iostream>
#include "math.h"
#include <vector>
//include waar de classes zijn 
#include "classes.hpp"
//weer namespace zelfde als in main 
namespace st = std;

//definieerd de VF vector en VVF vf is een vector van floats en VVF is een vector van VF
#define VF std::vector<float>
#define VVF std::vector<VF>

//laten zien dat ik weet wat namespace is 
namespace eindopdracht{

    //zet de ingevulde waardes in float x y en z die in clas vec3d staan 
    Vec3D::Vec3D(float x, float y, float z): x(x),y(y),z(z)
    {    }

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

    //zet alle objecten in object xy en z en radius in radius van sphere en zecht dan dat center vec3d is met de x y en z zodat het de center van de circle weet 
    Sphere::Sphere(float x, float y, float z, float radius) : Object(x, y, z), radius(radius)
    {
        center = Vec3D(x,y,z);

    }
    //als er een niew floor object word gemaakt zet hij dat als center en als object x y en z
    Floor::Floor(float x, float y, float z) : Object(x,y,z)  {
        center.x = x;
        center.y = y;
        center.z = z;
    }
    //zet de informatie over ray neer je heb 2 punten met x y en z suport is waar hij is en direction waa rhij naartoe gaat 
    Ray::Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir){
        support.x = xSup;
        support.y = ySup;
        support.z = zSup;
        direction.x = xDir;
        direction.y = yDir;
        direction.z = zDir;
    }
    //maakt een niewe ray aan voor xstart en ystart en vervolgens geeft hij met een reference een object mee en berekend hij de direction van de ray (support is 0.0.3 omdat het scherm 3 merter weg staat)
    Ray::Ray(float xStart, float yStart, VPO &objects) : objects(objects) {
        support=Vec3D(0,0,3);
        direction = Vec3D(xStart, yStart, 0).sub(support);

    }

    //berekend de afstand van de ray (const is dat het niet veranderd kan worden )
    float Sphere::distFromRay (Ray const &ray)const
    {
        //vervolgens de ray die hij als reference krijgt pakt hij de support van en  pakt hij de formule van sub en plakt daa center in vervolgens pakt hij het crossproduct en plakt daa direction in zodat er uiteinderlijk een afstand uitkomt

        return ray.support.sub (center).cross(ray.direction).norm ();
    }



    Vec3D Sphere::hitPoint(Ray const &ray){
        //pakt de support van het object ray en haalt het af van center
        auto a = ray.support.sub(center);
        //gebruitk dot product norm  en kwadraat  om vervolgens b uit te rekenen 
        auto b = pow(ray.direction.dot(a), 2) - pow(a.norm(), 2) + pow(radius, 2);
        //berekend de afstand van supoort door direction van ray dan het dot product van het antwoord a en vervolgens word daar de wortel van berekend 
        auto distFromSupport = -ray.direction.dot(a) - sqrt(b);
        //vervolgens returnt hij dit 
        return ray.support.add(ray.direction.mul(distFromSupport));
    }

    //dit is de funcit Object die al vaker gebruikt zijn  daar zet hij object als center x y en z 
    Object::Object (float x, float y, float z): center (x, y, z) {}
    // het is een bool dus ja of nee antwoord 
    bool Ray::scan() {
        //hij loopt hier door alle objecten (dit is de vector die ik in de main alemaal erin gezet hebben)
        for (auto OBJ : objects) {
            //als het een object heeft dan roept hij de functie hit van dat object aan daaarom word er ook een een virtual method van hit gebruikt zodat het niet uit maakt welk object het is elk object heeft die fucntie 
            //
            if (OBJ->hit(*this)) {
                //vervolgens als de hit functie true returned word deze functie ook gereturned als true
                return true;
            }
        }
        //als de for loop klaar is (dus als alle objecten getest zijn) en het niet geraakt word for het een false gereturned 
        return false;

    }

    //pakt een reference van ray (dus de echte ray)
    bool Sphere::hit(Ray const &ray) const{
        //vult het in de formule dist from ray in vervolgens komt daar een getal uit die zecht hoever de 2 objecten van elkaar verwijderd zijn en als die kleine ris dan radius dan is het warschijnlijk dat deze ekaar snijden
        return distFromRay(ray) <= radius;
    }

    bool Object::hit(Ray const &ray)const {
        //weer een hit functie omdat hit
    }

    bool Floor::hit(Ray const &ray) const
    {
    // mischien https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
    //formule wit en zwart rowindex%2 == columnindex%2

    //initialiseerd waardes 
    auto widthSquares = 3;
    //normaal vector die precies de recht op het vak staat 
    auto normalVector = Vec3D(0, 1, 0);
    //berekend het dot product 
    auto dot = center.sub(ray.support).dot(normalVector) / ray.direction.dot(normalVector);
    //berekend waar de ray en het vak elkaar raken 
    auto hitpoint = ray.support.add(ray.direction.mul(dot));
    //met de fucnctie die in de les gegeven is berkenenen of het vlak wit of zwart is 
    return (hitpoint.z > 0 && ((int)(hitpoint.z / widthSquares) % 2 == 0 ^ (int)(hitpoint.x / widthSquares) % 2 == 0));
    }


    void RayScanner::scan() {
        //initaliseerd 
        auto const RijXas = 96;
        auto const RijYas = 3 * RijXas;
        auto const aspectRatio = 0.4;
        auto const ScreenDist = 3.00;
        //definieerd ascii en black 
        auto const ascii = std::string(" M");
        auto const black = ascii.length() -1;
        //maakt een auto image aan met vvf en vf die boven in gedefinieerd is 
        auto image = VVF (RijXas, VF(RijYas, black));

        //2 for loops zodat hij alle punten van x en y af
        for (auto rowIndex = 0; rowIndex < RijXas;rowIndex++) {
            //berkend y omdat het bestand niet 100 meter groot is moet het kleiner worden opgeschreven drm is deze formule er 
            auto y = (RijXas / 2. - rowIndex) / RijXas;
            //weer de 2e forloop 
            for (auto colIndex = 0; colIndex < RijYas; colIndex++) {
                //zelfde als y want anders is hij te groot en aspect ratio zodat je het niet te groot laat zien 
                auto x = (RijYas / 2 - colIndex ) / (aspectRatio * RijYas);
                //maakt een ray aan genaamd vision ray waar je de x en de y die je net gemaakt heb inzet samen met alle objecten
                auto VisionRay = Ray(x,y,objects);
                //vervolgens word de ray in de scan functie gezet en als die waar is returned hij een image met 2 punten terug geefd 
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
        //gaat nu weer alle punten af van x en y 
        for (auto rowIndex = 0; rowIndex < RijXas; rowIndex++) {
            for (auto colIndex = 0; colIndex < RijYas; colIndex++) {
                //print vervolgens het getal af dat is opgeslagen in image
                std::cout << ascii [int (image [rowIndex][colIndex])];
            }
            //zet een niew line
            std::cout << '\n';
        }
        //zet een niew line 
        std::cout << '\n';
    }

}