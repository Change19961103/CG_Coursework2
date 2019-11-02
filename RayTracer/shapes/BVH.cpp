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

        // sort all shapes
        if (axis == 0) {
            sort(shape_list.begin(), shape_list.end(), compare_x);
        } else if (axis == 1){
            sort(shape_list.begin(), shape_list.end(), compare_y);
        } else {
            sort(shape_list.begin(), shape_list.end(), compare_z);
        }

        if (shape_list.size() == 1){
            left = right = shape_list[0];
        } else if (shape_list.size() == 2){
            left = shape_list[0];
            right = shape_list[1];
        } else {
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
                minZ = shape_list[i]->getAABBMin()[1];
            }
            if (shape_list[i]->getAABBMax()[0] < maxX){
                maxX = shape_list[i]->getAABBMax()[0];
            }
            if (shape_list[i]->getAABBMax()[1] < maxY){
                maxY = shape_list[i]->getAABBMax()[1];
            }
            if (shape_list[i]->getAABBMax()[2] < maxZ){
                maxZ = shape_list[i]->getAABBMax()[2];
            }
        }
        this->aabbMin = (minX, minY, minZ);
        this->aabbMax = (maxX, maxY, maxZ);
    }

    Hit BVH::intersect(Ray ray){

    }

    std::vector<Hit> BVH::TraverseBVHTree(Ray ray){
        CalculateBox();
        std::vector<Hit> hit_shape_list = {};
        if (checkIntersection(ray, aabbMin, aabbMax)){
            if (shape_list.size() == 1){
                hit_shape_list.push_back(shape_list[0]);
                return hit_shape_list;
            } else {
                if (left->TraverseBVHTree(ray).size() > 0){

                }
                right->intersect(ray);
            }
        } else {
            return hit_shape_list;
        }
    }

    Vec3f BVH::CalculateNorm(Hit h){
        return NULL;
    }


} //namespace rt


