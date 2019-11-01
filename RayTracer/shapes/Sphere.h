/*
 * Sphere.h
 *
 *
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <core/Shape.h>
#include "math/geometry.h"
#include "core/RayHitStructs.h"


namespace rt{

class Sphere:public Shape{

public:

	//
	// Constructors
	//
	Sphere();

	Sphere(Vec3f center, float radius){
        Shape::radius = radius;
        for (int i=0; i<3; i++){
            Shape::center[i] = center[i];
        }
	};

	virtual ~Sphere();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit intersect(Ray ray);

    Vec3f CalculateNorm(Hit h);

//	float getRadius(){
//	    return this->radius;
//	}
//
//	Vec3f getCenter(){
//	    return this->center;
//	}
//
//
//private:
//
//	Vec3f center;
//	float radius;
};



} //namespace rt




#endif /* SPHERE_H_ */
