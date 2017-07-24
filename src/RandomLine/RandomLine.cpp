//
//  RandomLine.cpp
//  mySketch
//
//  Created by nami on 2017/07/22.
//
//

#include "RandomLine.h"

RandomLine::RandomLine(ofVboMesh* g_mesh):baseType(g_mesh){
    color = ofColor(255, 0, 0);
    
    for (int i = 0; i < 10; i++) {
        indices.push_back(ofIndexType(ofRandom(8)));
    }
    
    mesh->addIndices(indices);
};

void RandomLine::update(float time) {
    if (int(time * 100) % 10 == 0) {
        mesh->removeIndex(ofIndexType(24));
        mesh->removeIndex(ofIndexType(24));
        mesh->addIndex(int(ofRandom(8)));
        mesh->addIndex(int(ofRandom(8)));
    }
}

void RandomLine::remove() {
    
}