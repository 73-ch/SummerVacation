//
//  IndexManager.hpp
//  mySketch
//
//  Created by nami on 2017/07/23.
//
//

#pragma once

#include "ofMain.h"
#include "settings.h"

class IndexManager {
    public:
    IndexManager(ofVboMesh* g_mesh);
    void set(int i, int &k);
    void set(vector <int> ks, vector <int> is, vector <int> &rs);
    void advanceTriger();
    void remove(int key);
    int getIndex(int key);
    void getIndices(vector<int> ks, vector <int> &rs);
    
    private:
    void advanceNumber();
    
    unordered_map <int, int> reference;
    vector <int> deleted_indices;
    ofVboMesh* mesh;
    int key_num;
};