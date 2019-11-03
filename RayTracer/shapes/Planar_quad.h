
#ifndef PLANAR_QUAD_H
#define PLANAR_QUAD_H
#include "core/Shape.h"
#include "Triangle.h"

namespace  rt {

    class Planar_quad : public Shape {

    public:

        Planar_quad(float a, float b, float c, float d)
                : triangle2(Triangle(d,b,c)), triangle1(Triangle(a,b,c)) {
        }

        Hit intersect(Ray ray);

        Vec3f CalculateNorm(Hit h);

        void CalculateBox();

        Vec3f getAABBMax();

        Vec3f getAABBMin();

        Vec2f MapTexture(Hit h);

    private:
        Triangle triangle1;
        Triangle triangle2;
        Vec3f aabbMax;
        Vec3f aabbMin;
    };
}

#endif //PLANAR_QUAD_H
