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
public:
    Triangle(Vec3f v0, Vec3f v1, Vec3f v2):v0(v0), v1(v1),v2(v2){};

    // Destructor
    virtual ~Triangle();

    Hit intersect(Ray ray);

    Vec3f CalculateNorm(Hit h);

    void CalculateBox();

    Vec3f getAABBMax();

    Vec3f getAABBMin();

    Vec2f MapTexture(Hit h);



private:

    Vec3f v0;
    Vec3f v1;
    Vec3f v2;
    Vec3f aabbMin;
    Vec3f aabbMax;

};



} //namespace rt




#endif /* TRIANGLE_H_ */
