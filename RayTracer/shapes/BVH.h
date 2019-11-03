/*
 * BVH.h
 *
 *
 */

#ifndef BVH_H_
#define BVH_H_

#include "core/Shape.h"

namespace rt{

class BVH: public Shape{

public:
    bool checkIntersection(Ray ray, Vec3f min, Vec3f max);

//    void BVHTree(std::vector<Shape *> shape_list);

    Vec3f getAABBMin();

    Vec3f getAABBMax();

    Hit intersect(Ray ray);

    Vec3f CalculateNorm(Hit h);

    void CalculateBox();

    Vec2f MapTexture(Hit h);



    std::vector<Shape*> TraverseBVHTree(Ray ray);

    // Getter
    Shape* getClosestOBJ(){
        return this->closest_obj;
    }





// Constructor
    BVH(std::vector<Shape*> shape_list);
//        static Shape* closest_obj;

private:
    std::vector<Shape*> shape_list;
    Shape* closest_obj;
    BVH* left;
    BVH* right;
    Vec3f aabbMin;
    Vec3f aabbMax;



    };


} //namespace rt



#endif /* BVH_H_ */
