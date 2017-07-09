//
//  basisCube.hpp
//  mySketch
//
//  Created by nami on 2017/07/04.
//
//

#pragma once

#include "ofMain.h"
#include "baseType.h"

using namespace glm;

class basisCube : public baseType {
public:
    basisCube(ofVboMesh* g_mesh);
    void update();
    void remove();
private:
    vec3 size;
};