/*
 * PointLight.h
 *
 *
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "core/LightSource.h"


namespace rt{

class PointLight: public LightSource{

public:

    // Constructors
    PointLight(Vec3f position, Vec3f intensity);

    Vec3f direction(Vec3f hitpoint);

    // Destructors
//    ~PointLight(){};


};



} //namespace rt




#endif /* POINTLIGHT_H_ */
