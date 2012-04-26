#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	camara.initGrabber(640,480);
	myImage.setImageType(OF_IMAGE_COLOR); 	
}

//--------------------------------------------------------------
void testApp::update(){
	ofSetWindowTitle("fps: " + ofToString(ofGetFrameRate()));	
	camara.update();
	
	int totalPixeles = camara.getWidth() * camara.getHeight() * 3; 
	
	int mirrorOrigin = camara.getWidth()/2 * 3;
	
	if (camara.isFrameNew()) {
		unsigned char * pixels = camara.getPixels();
		
		// y * 640 * 3 + x * 3
		
		for(int i = 0; i < camara.getWidth()/2; i++){
			
			for(int j = 0; j < camara.getHeight();j++){
				
				int pixOrigen = j * camara.getWidth()*3 + i*3;				
				int pixDestino = j * camara.getWidth()*3 + (camara.getWidth()-i)*3;
				
				pixels[pixDestino] = pixels[pixOrigen];
				pixels[pixDestino+1] = pixels[pixOrigen+1];
				pixels[pixDestino+2] = pixels[pixOrigen+2];
					
				}
			
		}

		myImage.setFromPixels(pixels, 640, 480, OF_IMAGE_COLOR);

	}
	
}



//--------------------------------------------------------------
void testApp::draw(){
	//camara.draw(0, 0);
	myImage.draw(0, 0, 640, 480);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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