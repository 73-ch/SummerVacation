//
//  basisCube.cpp
//  mySketch
//
//  Created by nami on 2017/07/04.
//
//

#include "basisCube.h"
basisCube::basisCube(ofVboMesh* g_mesh):baseType(g_mesh){
    color = ofColor(0, 255, 0);
    
    size = vec3(200);
    
    for (int i = 0; i < 8; i++) {
        int a = i / 4,b = i % 4 / 2, c = i % 2;
        mesh->addVertex(vec3(size.x * a, size.y * b, size.z * c));
        mesh->addColor(color);
        verts_num++;
        if (a > 0)mesh->addIndex(i - 4),mesh->addIndex(i);
        if (b > 0)mesh->addIndex(i - 2),mesh->addIndex(i);
        if (c > 0)mesh->addIndex(i - 1),mesh->addIndex(i);
    }
    
    index_num = mesh->getIndices().size() - start_index;
};

void basisCube::update() {
    
}

void basisCube::remove() {
    
}