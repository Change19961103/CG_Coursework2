/*
 * PointLight.cpp
 *
 *
 */
#include "PointLight.h"



namespace rt{

    // PointLight Constructor
    PointLight::PointLight(Vec3f position, Vec3f intensity):LightSource(position, intensity){}

    Vec3f PointLight::direction(Vec3f hitpoint){
        return (position - hitpoint).normalize();
    }

} //namespace rt
