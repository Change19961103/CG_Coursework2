/*
 * LightSource.h
 *
 */

#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#include <math/geometry.h>
#include "rapidjson/document.h"

using namespace rapidjson;


namespace rt{

class LightSource{
public:

    // Constructors
//    LightSource();
    LightSource(Vec3f position, Vec3f intensity):position(position), intensity(intensity){};

    // Destructor
    virtual ~LightSource(){};

    // Main function to create a light source with given parameters
    static LightSource* createLightSource(Value& LightSourceSpecs);

    // Getter and Setter
    Vec3f getPosition(){
        return this->position;
    };

    Vec3f getIntensity(){
        return this->intensity;
    }




protected:
    Vec3f position;
    Vec3f intensity;
};

} //namespace rt



#endif /* LIGHTSOURCE_H_ */
