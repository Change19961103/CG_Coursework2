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

    bool checkIntersection();

    void BVHTree(std::vector<Shape *> shape_list);
};



} //namespace rt



#endif /* BVH_H_ */
