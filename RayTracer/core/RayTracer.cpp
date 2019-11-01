/*
 * RayTracer.cpp
 *
 */
#include <shapes/Sphere.h>
#include "RayTracer.h"


namespace rt{


/**
 * Performs ray tracing to render a photorealistic scene
 *
 * @param camera the camera viewing the scene
 * @param scene the scene to render, including objects and lightsources
 * @param nbounces the number of bounces to consider for raytracing
 *
 * @return a pixel buffer containing pixel values in linear RGB format
 */
Vec3f* RayTracer::render(Camera* camera, Scene* scene, int nbounces){

	Vec3f* pixelbuffer=new Vec3f[camera->getWidth()*camera->getHeight()];
	Vec3f *pix = pixelbuffer;
	//----------main rendering function to be filled------
    float scale = tan((camera->getFov() * M_PI / 180 * 0.5));
    float imageAspectRatio = camera->getWidth() / (float)camera->getHeight();
    std::vector<Shape*> shapes_list = scene->getShapes();
    std::vector<LightSource*> lights_list = scene->getLightSources();
    Vec3f bgcolor = scene->getBGColor();
	for (int j=0; j<camera->getHeight(); ++j){
	    for (int i=0; i<camera->getWidth(); ++i){
	        Ray ray;
	        ray.origin = Vec3f(0, 0, 0);
            float x = (2 * (i + 0.5) / (float)camera->getWidth() - 1.) * imageAspectRatio * scale;
            float y = (1 - 2 * (j + 0.5) / (float)camera->getHeight()) * scale;
            ray.dir = (Vec3f(x, y, -1)).normalize();
            *(pix++) = RayTracer::castRay(nbounces, shapes_list, lights_list, ray, bgcolor);
	    }
	}

	return pixelbuffer;

}


Vec3f RayTracer::castRay(int nbounces, const std::vector<Shape*>& shapes_list,
                         const std::vector<LightSource*>& lights_list, Ray ray, Vec3f bgcolor){

    // Check whether it reaches max bounce
    if (nbounces < 0){
        return bgcolor;
    }

    for (auto i : shapes_list){
        Hit h = i->intersect(ray);
        Vec3f norm = i->CalculateNorm(h);
        if (h.intersection){
            return RayTracer::HitColor(lights_list, i->getMaterial()->getKs(), i->getMaterial()->getKd(),
            i->getMaterial()->getSe(), i->getMaterial()->getDc(), ray, h, norm);
        } else {
            return bgcolor;
        }
    }

}

Vec3f RayTracer::HitColor(const std::vector<LightSource*>& light, float ks, float kd, float se,
                          Vec3f diffuseColor, Ray ray, Hit h, Vec3f normal){

    Vec3f rayDir = (ray.origin - h.point).normalize();
    Vec3f ColorOfAllLights;
    Vec3f AmbientLight;

    // We traverse all the light source
    for (auto & i : light){
        Vec3f lightDir = (i->getPosition() - h.point).normalize();
        Vec3f halfwayVec = (lightDir + rayDir).normalize();
        float HdotV = std::max(0.f, halfwayVec.dotProduct(rayDir));
        float LdotN = std::max(0.f, lightDir.dotProduct(normal));
        Vec3f diffuse = kd * LdotN * diffuseColor;
        Vec3f specula = ks * powf(HdotV, se) * i->getIntensity();
        AmbientLight = AmbientLight + (i->getIntensity() * LdotN);
        ColorOfAllLights = ColorOfAllLights + (diffuse + specula);
    }
    return (AmbientLight + ColorOfAllLights);
}

/**
 * Tonemaps the rendered image (conversion of linear RGB values [0-1] to low dynamic range [0-255]
 *
 * @param pixelbuffer the array of size width*height containing linear RGB pixel values
 *
 * @return the tonemapped image
 */
Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer){

	//---------tonemapping function to be filled--------





	return pixelbuffer;

}





} //namespace rt


