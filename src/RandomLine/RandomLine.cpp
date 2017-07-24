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
    indices.push_back(ofIndexType(ofRandom(8)));
    indices.push_back(indices[indices.size() - 1]);
    for (int i = 0; i < 4; i++) {
        int a = indices[indices.size() - 1];
        indices.push_back(a);
        indices.push_back(selectVertex(a));
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

int RandomLine::selectVertex(int g_vert) {
    array<int, 4> a;
    switch (g_vert) {
        case 0:
            a = {3,5,6,7};
            break;
            
        case 1:
            a = {2,4,6,7};
            break;
            
        case 2:
            a = {1,4,5,7};
            break;
            
        case 3:
            a = {0,4,5,6};
            break;
            
        case 4:
            a = {1,2,3,7};
            break;
            
        case 5:
            a = {0,2,3,6};
            break;
            
        case 6:
            a = {0,1,3,5};
            break;
            
        case 7:
            a = {0,1,2,4};
            break;
            
        default:
            break;
    }
    return a[int(ofRandom(4))];
}