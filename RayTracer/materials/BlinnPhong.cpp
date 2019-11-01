/*
 * BlinnPhong.cpp
 *
 *
 */

#include <vector>
#include "BlinnPhong.h"



namespace rt{

    // Constructor


    // Return the Hit Color by using BlinnPhong
//    Vec3f BlinnPhong::HitColor(std::vector<LightSource*> light, float ks, float kd, float se,
//            Vec3f diffuseColor, Ray ray, Hit h, Vec3f normal){
//
//        Vec3f rayDir = (ray.origin - h.point).normalize();
//        Vec3f ColorOfAllLights;
//        Vec3f AmbientLight;
//
//        // We traverse all the light source
//        for (auto & i : light){
//            Vec3f lightDir = (i->getPosition() - h.point).normalize();
//            Vec3f halfwayVec = (lightDir + rayDir).normalize();
//            float HdotV = std::max(0.f, halfwayVec.dotProduct(rayDir));
//            float LdotN = std::max(0.f, lightDir.dotProduct(normal));
//            Vec3f diffuse = kd * LdotN * diffuseColor;
//            Vec3f specula = ks * powf(HdotV, se) * i->getIntensity();
//            for (int j=0; j<3; j++){
//                AmbientLight[j] += (i->getIntensity() * LdotN)[j]
//                ColorOfAllLights[j] += (diffuse + specula)[j];
//            }
//        }
//        return (AmbientLight + ColorOfAllLights);
//    }


} //namespace rt
