//
//  dropSurface.hpp
//  mySketch
//
//  Created by nami on 2017/07/09.
//
//

#pragma once

#include "ofMain.h"
#include "baseType.h"

using namespace glm;

class dropSurface : public baseType {
public:
    dropSurface(ofVboMesh* g_mesh);
    void setup();
    void update();
    void remove();
private:
    vec3 size;
};