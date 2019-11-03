/*
 * Shape.cpp
 *
 */
#include "shapes/Sphere.h"
#include <iostream>
#include <shapes/BVH.h>
#include "Shape.h"
#include "Scene.h"


namespace rt {


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
            std::string imageDir = materialSpecs["texture_dir"].GetString();
                Material * m = new Material(materialSpecs["ks"].GetFloat(), materialSpecs["kd"].GetFloat(),
                                      materialSpecs["specularexponent"].GetFloat(), diffuseColor, imageDir);

                Shape *shape = new Sphere(center, shapeSpecs["radius"].GetFloat());
                shape->CalculateBox();
                shape->material = m;
                return shape;


            } else if (shapeType.compare("planar_quad") == 0) {

            } else if (shapeType.compare("TriMesh") == 0) {

            } else if (shapeType.compare("triangle") == 0) {

            }

    }

//    void Shape::ConstructBVHTree(std::vector<Shape*> shape_list){
//        Shape* a = new BVH(shape_list);
//    }
//
//    Hit Shape::checkHit(Ray ray){
//        Hit h = BVHTree->intersect(ray);
//        return h;
//    }
//     Shape* Shape::returnObj(){
//        return BVH::closest_obj;
//    }


//        void Shape::checkIntersectSphere(Ray r, Vec3f &norm, Hit &h) {
//
//            Shape *shape1 = new Sphere(center, radius);
//            h = shape1->intersect(r);
//            norm = shape1->CalculateNorm(h);
//
//        }





}//namespace rt

