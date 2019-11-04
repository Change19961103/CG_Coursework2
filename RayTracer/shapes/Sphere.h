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

	Sphere(Vec3f center, float radius, std::string texture_dir):center(center), radius(radius){
	    if (texture_dir == ""){
            hasTexutre = false;
	    } else {
            this->texture_img = cv::imread(texture_dir, 1);
            hasTexutre = true;
        }
	};

	virtual ~Sphere();

    void CalculateBox();

    Vec3f getAABBMin();

    Vec3f getAABBMax();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit intersect(Ray ray);

    Vec3f CalculateNorm(Hit h);

    Vec3f MapTexture(Hit h);


//	float getRadius(){
//	    return this->radius;
//	}
//
//	Vec3f getCenter(){
//	    return this->center;
//	}
//
//
private:

	Vec3f center;
	float radius;
	Vec3f aabbMin;
	Vec3f aabbMax;
	cv::Mat texture_img;
	bool hasTexutre;
};






} //namespace rt




#endif /* SPHERE_H_ */
