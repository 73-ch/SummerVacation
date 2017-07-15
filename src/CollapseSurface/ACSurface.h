//
//  Surface.hpp
//  mySketch
//
//  Created by nami on 2017/07/10.
//
//
//
#include "ofMain.h"
#include "settings.h"

using namespace glm;

class ACSurface {
    public:
        ACSurface(ofVboMesh* g_mesh);
        void update(float time);
    
private:
    array<int, 2> positions;
    array<int, 2> axis;
    float generate_time;
    ofVboMesh* mesh;
};