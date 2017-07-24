//
//  dropSurface.hpp
//  mySketch
//
//  Created by nami on 2017/07/09.
//
//

#pragma once

#include "settings.h"
#include "baseType.h"
#include "ACSurface.h"

using namespace glm;

class CollapseSurface : public baseType {
public:
    CollapseSurface(ofVboMesh* g_mesh);
    void setup();
    void update(float time);
    void remove();
private:
    vec3 size;
    
    vector <ACSurface*> surfaces;
};