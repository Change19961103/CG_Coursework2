/*
 * BVH.cpp
 *
 *
 */
#include "BVH.h"
#include "fstream"


namespace rt{

    bool BVH::checkIntersection() {
        return true;
    }

    std::vector<Vec3f> surroundBox(Shape* a, Shape* b){

        std::vector<Vec3f> surroundingBox;
        Vec3f box1Min = a->getAABBMin();
        Vec3f box2Min = b->getAABBMin();
        Vec3f box1Max = a->getAABBMax();
        Vec3f box2Max = b->getAABBMax();
        Vec3f min = (fmin(box1Min[0], box2Min[0]),
                fmin(box1Min[1], box2Min[1]),
                fmin(box1Min[2], box2Min[2]));
        Vec3f max = (fmax(box1Max[0], box2Max[0]),
                fmax(box1Max[1], box2Max[1]),
                fmax(box1Max[2], box2Max[2]));
        surroundingBox.push_back(min);
        surroundingBox.push_back(max);

        return surroundingBox;
    }


    static bool compare_x(Shape* a, Shape* b) {
        return (a->getAABBMin()[0] < b->getAABBMin()[0]);
    }

    static bool compare_y(Shape* a, Shape* b) {
        return (a->getAABBMin()[1] < b->getAABBMin()[1])
    }

    static int compare_z(Shape* a, Shape* b) {
        return (a->getAABBMin()[2] < b->getAABBMin()[2]);
    }

    void BVH::BVHTree(std::vector<Shape*> shape_list){
        std::vector<std::vector<Vec3f>> *object_list;
        for (int i=0; i<shape_list.size(); i++){
            object_list.push_back(shape_list[i]->getBox());
        }
        int axis = static_cast<int>(3 * lvgm::rand01());
        if (axis == 0){
            qsort(object_list, 10, sizeof(std::vector<Vec3f>), compare_x);
        } else if (axis == 1){
            qsort(object_list, 10, sizeof(std::vector<Vec3f>), compare_y);
        } else {
            qsort(object_list, 10, sizeof(std::vector<Vec3f>), compare_z);
        }

    }




} //namespace rt


