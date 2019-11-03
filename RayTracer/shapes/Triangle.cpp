/*
 * Triangle.cpp
 *
 *
 */
#include "Triangle.h"
#include "math/geometry.h"



namespace rt{


    Triangle::~Triangle(){}

    Hit Triangle::intersect(Ray ray) {

        Hit h;

        Vec3f edge1 = v1-v0;
        Vec3f edge2 = v2-v0;
        Vec3f p = ray.dir.crossProduct(edge2);
        float det = edge1.dotProduct(p);
        Vec3f t;
        if (det > 0){
            Vec3f t = ray.origin - v0;
        } else {
            Vec3f t = v0 - ray.origin;
            det = -det;
        }

        if (det <= 0){
            h.intersection = false;
            return h;
        }

        float u = t.dotProduct(p);
        if (u < 0 || u > det){
            h.intersection = false;
            return h;
        }

        Vec3f q = t.crossProduct(edge1);
        float v = ray.dir.dotProduct(q);
        if (v < 0 || u + v > det){
            h.intersection = false;
            return h;
        }

        t = edge2.dotProduct(q);
        float fInvDet = 1 / det;
        t = edge2.dotProduct(q) * fInvDet;

        h.point = ray.origin + t * ray.dir;
        h.intersection = true;
        return h;



    }
    Vec3f Triangle::CalculateNorm(Hit h){
        Vec3f edge1 = v1 - h.point;
        Vec3f edge2 = v2 - h.point;
        Vec3f norm = edge1.crossProduct(edge2);
        return norm;
    };

    void Triangle::CalculateBox(){
        float minX = fmin(fmin(v0[0], v1[0]), v2[0]);
        float minY = fmin(fmin(v0[1], v1[1]), v2[1]);
        float minZ = fmin(fmin(v0[2], v1[2]), v2[2]);
        float maxX = fmax(fmax(v0[0], v1[0]), v2[0]);
        float maxY = fmax(fmax(v0[1], v1[1]), v2[1]);
        float maxZ = fmax(fmax(v0[2], v1[2]), v2[2]);
        aabbMax = Vec3f(maxX, maxY, maxZ);
        aabbMin = Vec3f(minX, minY, minZ);

    }

    Vec3f Triangle::getAABBMax(){
        return this->aabbMax;
    };

    Vec3f Triangle::getAABBMin(){
        return this->aabbMin;
    }

    Vec2f Triangle::MapTexture(Hit h) {
        return Vec2f();
    };

    ;
} //namespace rt
