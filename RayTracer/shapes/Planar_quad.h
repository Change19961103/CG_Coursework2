
#ifndef PLANAR_QUAD_H
#define PLANAR_QUAD_H
#include "core/Shape.h"
#include "Triangle.h"

namespace  rt {

    class Planar_quad : public Shape {

    public:

        Planar_quad(Vec3f a, Vec3f b, Vec3f c, Vec3f d, std::string texture_dir)
                : triangle2(Triangle(d,b,c, texture_dir)), triangle1(Triangle(a,b,c, texture_dir)) {
        }

        Hit intersect(Ray ray);

        Vec3f CalculateNorm(Hit h);

        void CalculateBox();

        Vec3f getAABBMax();

        Vec3f getAABBMin();

        Vec3f MapTexture(Hit h);

    private:
        Triangle triangle1;
        Triangle triangle2;
        Vec3f aabbMax;
        Vec3f aabbMin;
    };
}

#endif //PLANAR_QUAD_H
