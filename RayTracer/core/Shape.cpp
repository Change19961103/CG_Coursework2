/*
 * Shape.cpp
 *
 */
#include "shapes/Sphere.h"
#include <iostream>
#include <shapes/BVH.h>
#include <shapes/Triangle.h>
#include <shapes/Planar_quad.h>
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
                                      materialSpecs["specularexponent"].GetFloat(), diffuseColor);

                Shape *shape = new Sphere(center, shapeSpecs["radius"].GetFloat(), imageDir);
                shape->CalculateBox();
                shape->material = m;
                return shape;


            } else if (shapeType.compare("triangle") == 0) {

                Vec3f v0;
                Vec3f v1;
                Vec3f v2;
                Vec3f diffuseColor;
                Value &materialSpecs = shapeSpecs["material"];

                for (int i = 0; i < 3; i++) {
                    v0[i] = shapeSpecs["v0"].GetArray()[i].GetFloat();
                    v1[i] = shapeSpecs["v1"].GetArray()[i].GetFloat();
                    v2[i] = shapeSpecs["v2"].GetArray()[i].GetFloat();
                    diffuseColor[i] = materialSpecs["diffusecolor"].GetArray()[i].GetFloat();
                }
                std::string imageDir = materialSpecs["texture_dir"].GetString();
                Material * m = new Material(materialSpecs["ks"].GetFloat(), materialSpecs["kd"].GetFloat(),
                                            materialSpecs["specularexponent"].GetFloat(), diffuseColor);

                Shape *shape = new Triangle(v0, v1, v2, imageDir);
                shape->CalculateBox();
                shape->material = m;

                return shape;



            } else if (shapeType.compare("planar_quad") == 0) {

                Vec3f v0;
                Vec3f v1;
                Vec3f v2;
                Vec3f v3;
                Vec3f diffuseColor;
                Value &materialSpecs = shapeSpecs["material"];

                for (int i = 0; i < 3; i++) {
                    v0[i] = shapeSpecs["v0"].GetArray()[i].GetFloat();
                    v1[i] = shapeSpecs["v1"].GetArray()[i].GetFloat();
                    v2[i] = shapeSpecs["v2"].GetArray()[i].GetFloat();
                    v3[i] = shapeSpecs["v3"].GetArray()[i].GetFloat();
                    diffuseColor[i] = materialSpecs["diffusecolor"].GetArray()[i].GetFloat();
                }
                std::string imageDir = materialSpecs["texture_dir"].GetString();
                Material * m = new Material(materialSpecs["ks"].GetFloat(), materialSpecs["kd"].GetFloat(),
                                            materialSpecs["specularexponent"].GetFloat(), diffuseColor);

                Shape *shape = new Planar_quad(v0, v1, v2, v3, imageDir);
                shape->CalculateBox();
                shape->material = m;

                return shape;


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

