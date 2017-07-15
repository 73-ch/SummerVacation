//
//  baseType.h
//  mySketch
//
//  Created by nami on 2017/07/06.
//
//

#pragma once

#include "ofMain.h"

class baseType {
    public:
    int verts_num;
    int index_num;
    int start_index;
    ofColor color;
    ofVboMesh* mesh;
    vector<ofIndexType> indices;
    
    baseType(ofVboMesh* g_mesh) {
        mesh = g_mesh;
        start_index = mesh->getIndices().size();
        verts_num = 0;
    }
    
    void set() {
        mesh->addIndices(indices);
    };
    
    virtual void update(float time) {};
    virtual void remove() {};
};
