/*
 * Material.h
 *
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <math/geometry.h>
#include "LightSource.h"
#include <vector>
#include <core/RayHitStructs.h>

namespace rt{

class Material{
public:

    // Constructor
    Material(float ks, float kd, float specularexponent, Vec3f diffusecolor);

//    Vec3f HitColor(std::vector<LightSource *> light, float ks, float kd, float se, Vec3f diffuseColor, Ray ray, Hit h,
//                   Vec3f normal);


    // Getter and Setters
    void setKs(float Ks){
        this->ks = Ks;
    }

    void setKd(float Kd){
        this->kd = Kd;
    }

    void setSe(float Se){
        this->specularexponent = Se;
    }

    void setDc(Vec3f Dc){
        this->diffusecolor = Dc;
    }

    float getKs(){
        return this->ks;
    }

    float getKd(){
        return this->kd;
    }

    float getSe(){
        return this->specularexponent;
    }

    Vec3f getDc(){
        return this->diffusecolor;
    }



private:
    float ks;
    float kd;
    float specularexponent;
    Vec3f diffusecolor;
};


} //namespace rt



#endif /* MATERIAL_H_ */
