#include "Planar_quad.h"
#include "Triangle.h"

namespace  rt {


    Hit Planar_quad::intersect(Ray ray){
        Hit h1;
        Hit h2;
        h1 = triangle1.intersect(ray);
        h2 = triangle2.intersect(ray);
        if (h1.intersection){
            return h1;
        } else if (h2.intersection) {
            return h2;
        } else {
            return h1;
        }
    }


    Vec3f Planar_quad::getAABBMax(){
        return this->aabbMax;
    }

    Vec3f Planar_quad::getAABBMin(){
        return this->aabbMin;
    }

    void Planar_quad::CalculateBox() {
        triangle1.CalculateBox();
        triangle2.CalculateBox();
        float min1 = triangle1.getAABBMin().norm();
        float min2 = triangle2.getAABBMin().norm();
        if (min1 < min2) {
            aabbMin = triangle1.getAABBMin();
        } else {
            aabbMin = triangle2.getAABBMin();
        }
        float max1 = triangle1.getAABBMax().norm();
        float max2 = triangle2.getAABBMax().norm();
        if (max1 > max2){
            aabbMax = triangle1.getAABBMax();
        } else {
            aabbMax = triangle2.getAABBMax();
        }
    }

    Vec3f Planar_quad::CalculateNorm(Hit h) {
        return triangle1.CalculateNorm(h);
    }

    Vec2f Planar_quad::MapTexture(Hit h) {
        return Vec2f();
    }


}