// pointer is een * en dat wijst naar iets dat in het geheugen zit
// en een & is een reference en dat wijst naar het echte object
// een abstract class is een class die tenminste 1 virtual function heeft en die worden aangegeven met = 0 (dat is bijvoorbeeld Object bij ons )



//include liberarys
#include <iostream>
#include "math.h"
#include <vector>
//zou eigelijk meerdere classes moeten zijn bijvoorbeeld alle objecten bij elkaar en dan vec3d in een andere class maar vond dit duidelijker 
#include "classes.hpp"
//maakt namespace st voor std dus als je std:: zou gebruiken kan je nu st:: gebruiken
namespace st = std;
//weer hetzelfde als de vorige maar ipv std is het nu ei ipv eindopdracht 
 namespace ei = eindopdracht; 
 //definieerd de naam VPO als vector voor object objecten 
#define VPO st::vector<eindopdracht::Object *>

int main() {
    //maakt een niew VPO aan genaamd objects 
    VPO objects = VPO();

    //maakt objecten aan met parameters je gebruikt auto zodat je niet hoeft te vertellen wat voor type het is dus je kan auto gebruiken ipv ei::Sphere
    auto object1 = ei::Sphere(0.3, 0.1, 0.2, 0.3);
    auto object2 = ei::Sphere(-0.4, 0.3, 0.5, 0.2);
    auto object3 = ei::Sphere(-0.1, 0.4, -0.3, 0.4);
    //maakt een object aan van vloer met parameters 
    auto object4 = ei::Floor(1,2,7);

    //zet het object1 in de vector van objects die we in regel 16 en 12 gemaakt hebben  
    //ik gebruik het & symbool dat geeft reference aan reference is dat ik naar het echte object kijk die ik een paar regels eerder heb toe gevoegd 
    objects.push_back(&object1);
    objects.push_back(&object2);
    objects.push_back(&object3);
    objects.push_back(&object4);

    //gebruikt de functie rayscan die in Class Rayscanner gemakat is en gebruikt de vector objects(VPO) die we net gemakat hebben
    ei::RayScanner rayscan(objects);
    //print eigelijk alle objecten die we gemaakt hebben zien (die in objects zitten)
    rayscan.scan();

    return 0;
}