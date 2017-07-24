//
//  RandomLine.hpp
//  mySketch
//
//  Created by nami on 2017/07/22.
//
//
#pragma once

#include "settings.h"
#include "baseType.h"

using namespace glm;

class RandomLine : public baseType {
public:
    RandomLine(ofVboMesh* g_mesh);
    void setup();
    void update(float time);
    void remove();
private:
    vec3 size;
    int selectVertex(int g_vert);
    
    vector <ofIndexType> indices;
};