/*
 * Shape.h
 *
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "core/RayHitStructs.h"
#include "core/Material.h"
#include "rapidjson/document.h"


using namespace rapidjson;

namespace rt{

class Shape{
public:

	//
	// Constructors
	//
	Shape(){};


	//
	// Destructor (must be overriden in subclass)
	//
	virtual ~Shape();

	//
	// Shape abstract methods (to be implemented by subclasses)
	//
	virtual Hit intersect(Ray)=0;

    virtual Vec3f CalculateNorm(Hit h)=0;

    virtual void CalculateBox()=0;

    virtual Vec3f getAABBMax()=0;

    virtual Vec3f getAABBMin()=0;

    void ConstructBVHTree(std::vector<Shape*> shape_list);


	// Main Function
	static Shape* createShape(Value& shapeSpecs);

    Shape* returnObj();


    Hit checkHit(Ray ray);

	Material * getMaterial(){
	    return this->material;
	}

//	//Getter
//	Vec3f getShapeCenter(){
//	    return this->center;
//	}
//
//	float getShapeRadius(){
//        return this->radius;
//	}

//    void checkIntersectSphere(Ray r, Vec3f &norm, Hit &h);

protected:

	Material * material;
//	Vec3f center;
//	float radius;




    };


} //namespace rt


#endif /* SHAPE_H_ */
