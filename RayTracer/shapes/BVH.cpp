/*
 * BVH.cpp
 *
 *
 */
#include "BVH.h"
#include "stdlib.h"
#include "limits.h"

namespace rt{

    bool BVH::checkIntersection(Ray ray, Vec3f min, Vec3f max) {
            float tmax = MAXFLOAT;
            float tmin = 0;
              for (int i = 0; i < 3; ++i) {
                float t0 = (min[i] - ray.origin[i]) / ray.dir[i];
                float t1 = (max[i] - ray.origin[i]) / ray.dir[i];
                if (t0 > t1) {
                    float tmp = t0; t0 = t1; t1 = tmp;
                }
                if (t0 > tmin) {
                    tmin = t0;
                }
                if (t1 < tmax) {
                    tmax = t1;
                }
                if (tmin > tmax) {
                    return false;
                }
            }
            return true;
    }

    static bool compare_x(Shape* a, Shape* b) {
        return (a->getAABBMin()[0] < b->getAABBMin()[0]);
    }

    static bool compare_y(Shape* a, Shape* b) {
        return (a->getAABBMin()[1] < b->getAABBMin()[1]);
    }

    static bool compare_z(Shape* a, Shape* b) {
        return (a->getAABBMin()[2] < b->getAABBMin()[2]);
    }

    BVH::BVH(std::vector<Shape*> shape_list) {

        // randomly choose an axis to separate boxes
        int axis = (rand() % (2 - 0 + 1)) + 0;
        std::vector<Shape*> left_shape_list;
        std::vector<Shape*> right_shape_list;
        this->shape_list = shape_list;
        CalculateBox();

        // sort all shapes
        if (axis == 0) {
            sort(shape_list.begin(), shape_list.end(), compare_x);
        } else if (axis == 1){
            sort(shape_list.begin(), shape_list.end(), compare_y);
        } else {
            sort(shape_list.begin(), shape_list.end(), compare_z);
        }

        if (shape_list.size() > 1){
            int size = shape_list.size()/2;
            for (int i=0; i< size; i++) {
                left_shape_list.push_back(shape_list[i]);
            }
            for (int j=size; j<shape_list.size(); j++){
                right_shape_list.push_back(shape_list[j]);
            }
            left = new BVH(left_shape_list);
            right = new BVH(right_shape_list);
        }
    }

    // Getter
    Vec3f BVH::getAABBMin() {
        return this->aabbMin;
    }

    Vec3f BVH::getAABBMax() {
        return this->aabbMax;
    }

    void BVH::CalculateBox() {
        float maxX=-MAXFLOAT;
        float maxY=-MAXFLOAT;
        float maxZ=-MAXFLOAT;
        float minX=MAXFLOAT;
        float minY=MAXFLOAT;
        float minZ=MAXFLOAT;
        // To get the aabb for a list of object
        for (int i=0; i<shape_list.size(); i++){
            if (shape_list[i]->getAABBMin()[0] < minX){
                minX = shape_list[i]->getAABBMin()[0];
            }
            if (shape_list[i]->getAABBMin()[1] < minY){
                minY = shape_list[i]->getAABBMin()[1];
            }
            if (shape_list[i]->getAABBMin()[2] < minZ){
                minZ = shape_list[i]->getAABBMin()[2];
            }
            if (shape_list[i]->getAABBMax()[0] > maxX){
                maxX = shape_list[i]->getAABBMax()[0];
            }
            if (shape_list[i]->getAABBMax()[1] > maxY){
                maxY = shape_list[i]->getAABBMax()[1];
            }
            if (shape_list[i]->getAABBMax()[2] > maxZ){
                maxZ = shape_list[i]->getAABBMax()[2];
            }
        }
        Vec3f a = Vec3f(minX, minY, minZ);
        Vec3f b = Vec3f(maxX, maxY, maxZ);
        this->aabbMin = a;
        this->aabbMax = b;
    }

    Hit BVH::intersect(Ray ray){
        Shape* closest;
        float distance = MAXFLOAT;
        Hit h;
        std::vector<Shape*> hit_shape_list = TraverseBVHTree(ray);
        std::vector<Shape*> object_hit_list;
        for (int j=0; j<hit_shape_list.size(); j++){
            Hit test = hit_shape_list[j]->intersect(ray);
            if (test.intersection){
                object_hit_list.push_back(hit_shape_list[j]);
            }
        }

        for (int i=0; i<object_hit_list.size(); i++){
            if (object_hit_list[i]->getAABBMin().norm() < distance){
                distance = object_hit_list[i]->getAABBMin().norm();
                closest = object_hit_list[i];
            }
        }
        if (object_hit_list.size() > 0) {
            this->closest_obj = closest;
            return closest->intersect(ray);
        } else {
            return h;
        }


    }

    std::vector<Shape*> BVH::TraverseBVHTree(Ray ray){
//        CalculateBox();
        std::vector<Shape*> hit_shape_list;
        if (checkIntersection(ray, aabbMin, aabbMax)){
            if (shape_list.size() == 1){
                hit_shape_list.push_back(shape_list[0]);
                return hit_shape_list;
            } else {
                std::vector<Shape*> left_side = left->TraverseBVHTree(ray);
                std::vector<Shape*> right_side = right->TraverseBVHTree(ray);
                if (left_side.size() > 0) {
                    for (int i = 0; i < left_side.size(); i++) {
                        hit_shape_list.push_back(left_side[i]);
                    }
                }
                if (right_side.size() > 0){
                    for (int j=0; j<right_side.size(); j++){
                        hit_shape_list.push_back(right_side[j]);
                    }
                    return hit_shape_list;
                }
                return hit_shape_list;
            }
        } else {
            return hit_shape_list;
        }
    }

    Vec3f BVH::CalculateNorm(Hit h){
        return NULL;
    }

    Vec3f BVH::MapTexture(Hit h) {
        return Vec3f();
    }


} //namespace rt


