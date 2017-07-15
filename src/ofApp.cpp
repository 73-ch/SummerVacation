#include "ofApp.h"
#include "settings.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    
    point_color = false;
    
    basis_size = vec3(BASIS_SIZE);

    
    shapes.push_back(new basisCube(&mesh));
    shapes.push_back(new CollapseSurface(&mesh));
    
    mesh.disableColors();
    mesh.setMode(OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    if (time < 1.) mesh.disableColors();
    
    for (int i = 0; i < shapes.size(); i++) shapes[i]->update(time);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofTranslate(-basis_size/2);
    ofSetColor(255);
    mesh.draw();
    
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 32) {
        if (point_color) {
            mesh.disableColors();
            mesh.setMode(OF_PRIMITIVE_LINES);
        } else {
            mesh.enableColors();
            mesh.setMode(OF_PRIMITIVE_POINTS);
        }
        point_color = !point_color;
    } else if (key == OF_KEY_F1) {
        vector <ofIndexType> indices = mesh.getIndices();
        for (int i = 0; i < indices.size(); i++) cout << ofToString(indices[i]) << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
