//
//  Surface.cpp
//  mySketch
//
//  Created by nami on 2017/07/10.
//
//

#include "ACSurface.h"

ACSurface::ACSurface(ofVboMesh* g_mesh) {
//    start_index = mesh->getIndices().size();
    delete_flag = false;
    
    mesh = g_mesh;
    
    int i = floor(ofRandom(2)) + 4 * floor(ofRandom(2));
    axis[0] = i;
    positions[0] = mesh->getVertices().size();
    mesh->addVertex(mesh->getVertex(i + 2));
    
    if (i == 0) {
        axis[1] = 1;
    } else if (i == 1) {
        axis[1] = 5;
    } else if (i == 4) {
        axis[1] = 0;
    } else if (i == 5) {
        axis[1] = 4;
    }
    
    positions[1] = positions[0] + 1;

    mesh->addVertex(mesh->getVertex(axis[1] + 2));
    
    indices.push_back(axis[0]);
    indices.push_back(positions[0]);
    indices.push_back(positions[0]);
    indices.push_back(positions[1]);
    indices.push_back(positions[1]);
    indices.push_back(axis[1]);
    indices.push_back(axis[1]);
    indices.push_back(axis[0]);
    
    mesh->addIndices(indices);
    
    generate_time = ofGetElapsedTimef();
}

void ACSurface::update(float time) {
    float t = exp(time - generate_time) / 4.;
    
    float v = sqrt(t) * BASIS_SIZE;
    mesh->getVertex(positions[0]);
    
    if (axis[0] == 0) {
        mesh->setVertex(positions[0], vec3(v, BASIS_SIZE * (1 - t), 0));
        mesh->setVertex(positions[1], vec3(v, BASIS_SIZE * (1 - t), BASIS_SIZE));
    } else if (axis[0] == 1) {
        mesh->setVertex(positions[0], vec3(0, BASIS_SIZE * (1 - t), BASIS_SIZE - v));
        mesh->setVertex(positions[1], vec3(BASIS_SIZE, BASIS_SIZE * (1 - t), BASIS_SIZE - v));
    } else if (axis[0] == 4) {
        mesh->setVertex(positions[0], vec3(BASIS_SIZE, BASIS_SIZE * (1 - t), v));
        mesh->setVertex(positions[1], vec3(0, BASIS_SIZE * (1 - t), v));
    } else if (axis[0] == 5) {
        mesh->setVertex(positions[0], vec3(BASIS_SIZE - v, BASIS_SIZE * (1 - t), BASIS_SIZE));
        mesh->setVertex(positions[1], vec3(BASIS_SIZE - v, BASIS_SIZE * (1 - t), 0));
    }
    
    if (t > 1 && !delete_flag) {
        for (int i = 0; i < indices.size(); i++) {
//            mesh->removeIndex(start_index + i);
        }
        delete this;
        delete_flag = true;
    };
}