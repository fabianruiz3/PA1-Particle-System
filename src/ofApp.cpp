#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	p.assign(num, Particle());
	currentMode = PARTICLE_MODE_ATTRACT;
	lastMode = NONE;
	currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 

	resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){


	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);	
		p[i].setModeBeforePause(lastMode);	
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].setModeBeforePause(lastMode);	
		p[i].update();
	}

	if(replay){
		if( keysPressed.size() == 0 ){
			isReplaying = "";
			replay = false;
		}
		else if(time==0){
			keyPressed(*keysPressed.begin());
			keysPressed.erase(keysPressed.begin());
			time = 50;
		}
		else{
			time--;
		}
	}

	
		//lets add a bit of movement to the attract points
	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
		p[i].changeParticleColor(countTpresses);
		p[i].magnifyParticle(drawRectangle, originalMouseX, endMouseX, originalMouseY, endMouseY);
	}

	if(drawRectangle){
		ofNoFill();
		ofDrawRectangle(min(originalMouseX, endMouseX), min(originalMouseY, endMouseY), abs(originalMouseX - endMouseX), abs(originalMouseY - endMouseY));
		ofFill();
	}
	
	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofDrawCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofDrawCircle(attractPointsWithMovement[i], 4);
		}
	}

	ofSetColor(230);	
	ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-4 to change mode. \n" + isRecording + isReplaying, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if(replay){
		if( key == 'c'){
			replay = false;
			isReplaying = "";
			keysPressed.clear();
		}
		if( key != *keysPressed.begin() ){
			return;
		}
	}

    if (record && (key == 'a' || key == 'd' || key == '1' || key == '2' || key == '3' || key == '4' || key == 't' || key == 's' || key == ' ')) {
		keysPressed.push_back(key);
	}

	if( key == '1' ){
		if(currentMode == PARTICLE_MODE_PAUSE){
			lastMode = PARTICLE_MODE_ATTRACT; 
		}
		else{
			currentMode = PARTICLE_MODE_ATTRACT;    
		}
		currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse";	
	}
	if( key == '2' ){
		if(currentMode == PARTICLE_MODE_PAUSE){
			lastMode = PARTICLE_MODE_REPEL;
		}
		else{
			currentMode = PARTICLE_MODE_REPEL;
		}
		currentModeStr = "2 - PARTICLE_MODE_REPEL: repels from mouse";
	}
	if( key == '3' ){
		if(currentMode == PARTICLE_MODE_PAUSE){
			lastMode = PARTICLE_MODE_NEAREST_POINTS;
		}
		else{
			currentMode = PARTICLE_MODE_NEAREST_POINTS;
		}
		currentModeStr = "3 - PARTICLE_MODE_NEAREST_POINTS:"; 						
	}
	if( key == '4'){
		if(currentMode == PARTICLE_MODE_PAUSE){
			lastMode = PARTICLE_MODE_NOISE;
		}
		else{
			currentMode = PARTICLE_MODE_NOISE;
		}
		currentModeStr = "4 - PARTICLE_MODE_NOISE: snow particle simulation"; 						
		resetParticles();
	}	

	if( key == ' ' ){
		countTpresses = 0;
		resetParticles();
	}

	if( key == 't' ){
		if (countTpresses >= 3){
			countTpresses = 0;
		}
		countTpresses += 1;
	}

	if( key == 's' ){
		if(currentMode == PARTICLE_MODE_PAUSE){
			currentMode = lastMode;
			lastMode = NONE;
		}
		else{
			lastMode = currentMode;
			currentMode = PARTICLE_MODE_PAUSE;
		}
	}

	if( key == 'd'){
		for(unsigned int i = 0; i < p.size(); i++){
			p[i].vel.x *= 2;
			p[i].vel.y *= 2;
		}
	}

	if( key == 'a'){
		for(unsigned int i = 0; i < p.size(); i++){
			p[i].vel.x /= 2;
			p[i].vel.y /= 2;
		}
	}

	if( key == 'r'){
		if (record){
			isRecording = "";
			record = false;
		} 

		else {
			isRecording = "Recording";
			keysPressed.clear();
			record = true;
		}
	}

	if( key == 'p' && !record){
		replay = true;
		isReplaying = "Replaying";
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
	if((button == 1) && (min(originalMouseX, endMouseX) <= ofGetMouseX()) && (ofGetMouseX() <= max(originalMouseX, endMouseX)) && (min(originalMouseY, endMouseY)<= ofGetMouseY()) && (ofGetMouseY() <= max(originalMouseY, endMouseY))){
       int middleOfRectangleX = abs(originalMouseX + endMouseX)/2;
       int middleOfRectangleY = abs(originalMouseY + endMouseY)/2;
 
       originalMouseX -= middleOfRectangleX - x;
       endMouseX -= middleOfRectangleX - x;
       originalMouseY -= middleOfRectangleY - y;
       endMouseY -= middleOfRectangleY - y;
      
 
   }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(button == 0){
		originalMouseX = x;
		originalMouseY = y;
		drawRectangle = false;
	}
	if((button == 2) && (min(originalMouseX, endMouseX) <= ofGetMouseX()) && (ofGetMouseX() <= max(originalMouseX, endMouseX)) && (min(originalMouseY, endMouseY)<= ofGetMouseY()) && (ofGetMouseY() <= max(originalMouseY, endMouseY))){
		originalMouseX = 0;
		originalMouseY = 0;
		endMouseX = 0;
		endMouseY = 0;
		drawRectangle = true;
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(button == 0){
		endMouseX = x;
		endMouseY = y;
		drawRectangle = true;
	}

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
