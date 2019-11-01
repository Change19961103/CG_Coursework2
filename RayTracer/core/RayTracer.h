/*
 * RayTracer.h
 *
 */
#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "math/geometry.h"
#include "core/Camera.h"
#include "core/Scene.h"

namespace rt{



/*
 * Raytracer class declaration
 */
class RayTracer {
public:

	RayTracer();

	static Vec3f* render(Camera* camera, Scene* scene, int nbounces);
	static Vec3f* tonemap(Vec3f* pixelbuffer);
	static Vec3f castRay(int nbounces, const std::vector<Shape*>& shapes_list,
	        const std::vector<LightSource*>& lights_lis, Ray ray, Vec3f bgcolor);
    static Vec3f HitColor(const std::vector<LightSource *>& light, float ks, float kd, float se, Vec3f diffuseColor, Ray ray, Hit h,
                          Vec3f normal);

private:



};




} //namespace rt



#endif /* RAYTRACER_H_ */

