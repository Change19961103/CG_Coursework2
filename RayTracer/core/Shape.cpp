/*
 * Shape.cpp
 *
 */
#include "shapes/Sphere.h"
#include <iostream>
#include "Shape.h"


namespace rt {

    Shape::~Shape() {};

    Shape *Shape::createShape(Value &shapeSpecs) {

        // Read parameters of material




        // check if shapetype is defined
        if (!shapeSpecs.HasMember("type")) {
            std::cerr << "Shape type not specified" << std::endl;
            exit(-1);
        }

        std::string shapeType = shapeSpecs["type"].GetString();

        // check which type this shape belongs to
        if (shapeType.compare("sphere") == 0) {

            // intialize center and assign value
            Vec3f center;
            Vec3f diffuseColor;
            Value &materialSpecs = shapeSpecs["material"];
            for (int i = 0; i < 3; i++) {
                center[i] = shapeSpecs["center"].GetArray()[i].GetFloat();
                diffuseColor[i] = materialSpecs["diffusecolor"].GetArray()[i].GetFloat();
            }
                Material * m = new Material(materialSpecs["ks"].GetFloat(), materialSpecs["kd"].GetFloat(),
                                      materialSpecs["specularexponent"].GetFloat(), diffuseColor);

                Shape *shape = new Sphere(center, shapeSpecs["radius"].GetFloat());
                shape->material = m;
                return shape;

//                shape->material->setKs(materialSpecs["ks"].GetFloat());
//                shape->material->setKd(materialSpecs["kd"].GetFloat());
//                shape->material->setSe(materialSpecs["specularexponent"].GetFloat());
//                for (int j = 0; j < 3; j++) {
//                    diffuseColor[j] = materialSpecs["diffusecolor"].GetArray()[j].GetFloat();
//                }
//                shape->material->setDc(diffuseColor);

            } else if (shapeType.compare("Plane") == 0) {

            } else if (shapeType.compare("TriMesh") == 0) {

            } else if (shapeType.compare("Triangle") == 0) {

            }

    }

//        void Shape::checkIntersectSphere(Ray r, Vec3f &norm, Hit &h) {
//
//            Shape *shape1 = new Sphere(center, radius);
//            h = shape1->intersect(r);
//            norm = shape1->CalculateNorm(h);
//
//        }





}//namespace rt

