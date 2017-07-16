//
//  dropSurface.cpp
//  mySketch
//
//  Created by nami on 2017/07/09.
//
//

#include "CollapseSurface.h"

CollapseSurface::CollapseSurface(ofVboMesh* g_mesh):baseType(g_mesh){
    color = ofColor(255, 0, 0);
    
    surfaces.push_back(new ACSurface(mesh));
};

void CollapseSurface::update(float time) {
    int r = ofRandom(8);
    if (r == 0) surfaces.push_back(new ACSurface(mesh));
    for (int i = 0; i < surfaces.size(); i++) surfaces[i]->update(time);
}

void CollapseSurface::remove() {
    
}