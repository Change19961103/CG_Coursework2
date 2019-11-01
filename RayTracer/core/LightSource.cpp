/*
 * LightSource.cpp
 *
 */
#include "LightSource.h"
#include <vector>
#include "lights/PointLight.h"
#include "lights/AreaLight.h"

namespace rt{

LightSource* LightSource::createLightSource(Value& LightSourceSpecs){

    Vec3f position;
    Vec3f intensity;

    // traverse all the light sources

    //check if lightsource type is defined
    if (!LightSourceSpecs.HasMember("type")) {
        std::cerr << "LightSource type not specified" << std::endl;
        exit(-1);
    }

    // assign value to position and intensity
    for (int i = 0; i < 3; i++) {
        position[i] = LightSourceSpecs["position"].GetArray()[i].GetFloat();
        intensity[i] = LightSourceSpecs["intensity"].GetArray()[i].GetFloat();
    }

    std::string LightSourceType = LightSourceSpecs["type"].GetString();
    if (LightSourceType.compare("pointlight") == 0) {
        return new PointLight(position, intensity);
    } else if (LightSourceType.compare("arealight") == 0) {

    }

    return 0;

}






} //namespace rt

