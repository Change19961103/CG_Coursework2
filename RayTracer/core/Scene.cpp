/*
 * Scene.cpp
 *
 */
#include "Scene.h"
#include "shapes/Sphere.h"




namespace rt{

/**
 * Parses json scene object to generate scene to render
 *
 * @param scenespecs the json scene specificatioon
 */
void Scene::createScene(Value& scenespecs){

	//----------parse json object to populate scene-----------
	Value& lightSpecs = scenespecs["lightsources"];
	Value& shapeSpecs = scenespecs["shapes"];

    //assign value to background color
    for (int i=0; i<3; i++) {
        BGColor[i] = scenespecs["backgroundcolor"].GetArray()[i].GetFloat();
    }

    // traverse all the lightsources and add them to std::vector<LightSource*> lightSources;
    for (int j=0; j<lightSpecs.Size(); j++){
        lightSources.push_back(LightSource::createLightSource(lightSpecs[j]));
    }

    // traverse all the shapes and add them to std::vector<Shape*> shapes;
    for (int k=0; k<shapeSpecs.Size(); k++){
        shapes.push_back(Shape::createShape(shapeSpecs[k]));
    }

}








} //namespace rt
