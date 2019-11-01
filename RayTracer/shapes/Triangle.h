/*
 * Triangle.h
 *
 *
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "core/Shape.h"
#include "core/RayHitStructs.h"

namespace rt{

class Triangle: public Shape{

    // Constructor
    Triangle(Vec3f v0, Vec3f v1, Vec3f v2):v0(v0), v1(v1),v2(v2){};

    // Destructor
    virtual ~Triangle();

    Hit intersect(Ray ray);



private:

    Vec3f v0;
    Vec3f v1;
    Vec3f v2;

};



} //namespace rt




#endif /* TRIANGLE_H_ */
