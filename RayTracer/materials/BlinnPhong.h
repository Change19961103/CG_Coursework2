/*
 * BlinnPhong.h
 *
 *
 */

#ifndef BLINNPHONG_H_
#define BLINNPHONG_H_

#include <core/RayHitStructs.h>
#include "core/Material.h"


namespace rt{

class BlinnPhong: public Material{

public:
    // Constructor


//    Vec3f HitColor(std::vector<LightSource *> light, float ks, float kd, float se, Vec3f diffuseColor, Ray ray, Hit h,
//                   Vec3f normal);
};



} //namespace rt



#endif /* BLINNPHONG_H_ */
