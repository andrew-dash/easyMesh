#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(40, 40, 40);
    addMode = true;
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // DISPLAY HELP MENU
    if (helpMenu) {
        ofDrawBitmapStringHighlight("'h' = help menu", 10,20);
        ofDrawBitmapStringHighlight("'d' = debug view", 10,40);
        ofDrawBitmapStringHighlight("'p' = present mode", 10,60);
        ofDrawBitmapStringHighlight("'1-6' = change mesh mode", 10,80);
        ofDrawBitmapStringHighlight("'a' = add mode", 10,100);
        ofDrawBitmapStringHighlight("'f' = fullscreen", 10,120);
    }
    
    
    // CHANGE MESH DRAWING MODE
    if (drawFaces) { newMesh.drawFaces(); }
    if (drawWireframe) { newMesh.drawWireframe(); }
    if (drawVerticies) { newMesh.drawVertices(); }
    
    
    // Determine mesh vertex closest to the cursor
    int n = newMesh.getNumVertices();
    float nearestDistance = 0;
    ofVec2f nearestVertex;
    int nearestIndex;
    
    ofVec2f mouse(mouseX, mouseY);
    
	for(int i = 0; i < n; i++) {
		ofVec3f cur = newMesh.getVertex(i);
		float distance = cur.distance(mouse);
		if(i == 0 || distance < nearestDistance) {
			nearestDistance = distance;
			nearestVertex = cur;
			nearestIndex = i;
            dragVertex = nearestIndex;
		}
	}
    
    ofSetColor(ofColor::gray);
	ofLine(nearestVertex, mouse);
    
    ofNoFill();
	ofSetColor(ofColor::yellow);
	ofSetLineWidth(2);
	ofCircle(nearestVertex, 4);
	ofSetLineWidth(1);
	
	ofVec2f offset(10, -10);
	ofDrawBitmapStringHighlight(ofToString(nearestIndex), mouse + offset);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    switch(key) {
		case 'f':
			ofToggleFullscreen();
			break;
        case 'a':
			addMode = true;
            debugView = false;
			break;
        case 'p':
			addMode = false;
            debugView = false;
            helpMenu = false;
			break;
        case 'd':
			addMode = false;
            debugView = true;
			break;
        case 'h':
            helpMenu = true;
            break;
        case '1':
            newMesh.setMode(OF_PRIMITIVE_TRIANGLES);
            break;
        case '2':
            newMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            break;
        case '3':
            newMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
            break;
        case '4':
            newMesh.setMode(OF_PRIMITIVE_LINES);
            break;
        case '5':
            newMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
            break;
        case '6':
            newMesh.setMode(OF_PRIMITIVE_POINTS);
            break;
        case 'w':
            drawFaces = false;
            drawWireframe = true;
            drawVerticies = false;
            break;
        case 'q':
            drawFaces = true;
            drawWireframe = false;
            drawVerticies = false;
            break;
        case 'e':
            drawFaces = false;
            drawWireframe = false;
            drawVerticies = true;
	}
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (addMode == false) {
        newMesh.setVertex(dragVertex, ofPoint(x,y));
    }
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    if (addMode) {
        newMesh.addVertex(ofPoint(x,y,0));
        newMesh.addIndex(indexCounter);
        newMesh.addColor(ofFloatColor(255,255,0));
        
        indexCounter++;
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}