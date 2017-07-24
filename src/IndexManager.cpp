//
//  IndexManager.cpp
//  mySketch
//
//  Created by nami on 2017/07/23.
//
//

#include "IndexManager.h"

IndexManager::IndexManager(ofVboMesh* g_mesh) {
    mesh = g_mesh;
    key_num = 0;
};

// referenceにsetする関数(iがindex, kがkeyのポインタ)
void IndexManager::set(int i, int& k) {
    // k : key, i : index
    k = key_num;
    reference[k] = mesh->getNumIndices();
    mesh->addIndex(ofIndexType(i));
};

void IndexManager::set(vector<int> ks, vector<int> is, vector<int&> rs) {
    // ks : key, is : index, rs : response
    for (int i = 0; i < ks.size(); i++) {
        reference[ks[i]] = mesh->getNumIndices();
        mesh->addIndex(ofIndexType(is[i]));
        rs[i] = ks[i];
    }
};


// 外部からadvanceNumber()を呼び出すための関数
void IndexManager::advanceTriger() {
    advanceNumber();
};

// meshのindexで削除したいものをkeyで指定（実際の削除はadvanceNumber）
void IndexManager::remove(int key) {
    deleted_indices.push_back(key);
};

// referenceからkeyをもとにmeshのindexの中での元のindexのidを取得
int IndexManager::getIndex(int key) {
    return reference[key];
};

void IndexManager::getIndices(vector<int> ks, vector<int*> rs) {
    for (int i = 0; i < ks.size(); i++) rs.push_back(&reference[ks[i]]);
};

// drawコールの前に読んでそれぞれのbaseTypeが持つindexの情報を更新する（一回のみの呼び出し）
void IndexManager::advanceNumber() {
    // referenceの中から削除されたものを削除
    for (int i = 0; i < deleted_indices.size(); i++) reference.erase(deleted_indices[i]);
    // referenceの要素それぞれから、indexが詰まった分、keyを前進
    for (int i = 0; i < reference.size(); i++) reference[i] -= count_if(deleted_indices.begin(), deleted_indices.end(), [i](int ii)->bool{return (ii > i);});
    // deleted_indicesの更新
    deleted_indices.clear();
};