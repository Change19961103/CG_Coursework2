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

    // Constructor
    BVH(std::vector<Shape*> shape_list);

    bool checkIntersection(Ray ray, Vec3f min, Vec3f max);

//    void BVHTree(std::vector<Shape *> shape_list);

    Vec3f getAABBMin();

    Vec3f getAABBMax();

    Hit intersect(Ray ray);

    Vec3f CalculateNorm(Hit h);

    void CalculateBox();



    std::vector<Hit> TraverseBVHTree(Ray ray);


private:
    std::vector<Shape*> shape_list;
    Shape* left;
    Shape* right;
    Vec3f aabbMin;
    Vec3f aabbMax;


};


} //namespace rt



#endif /* BVH_H_ */
