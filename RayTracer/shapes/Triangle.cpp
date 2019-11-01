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

    ;
} //namespace rt
