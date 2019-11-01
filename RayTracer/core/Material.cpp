/*
 * Material.cpp
 *
 */
#include "Material.h"


namespace rt{

    Material::Material(float ks, float kd, float specularexponent, Vec3f diffusecolor):
    ks(ks), kd(kd), specularexponent(specularexponent), diffusecolor(diffusecolor) {}
} //namespace rt


