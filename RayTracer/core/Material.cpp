/*
 * Material.cpp
 *
 */
#include "Material.h"


namespace rt{

    Material::Material(float ks, float kd, float specularexponent, Vec3f diffusecolor, std::string imageDir):
    ks(ks), kd(kd), specularexponent(specularexponent), diffusecolor(diffusecolor), imageDir(imageDir) {}
} //namespace rt


