#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofSetCircleResolution(36);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int base_radius = ofGetWidth() / 14;
	for (int x = base_radius; x < ofGetWidth(); x += base_radius * 2) {

		for (int y = base_radius; y < ofGetHeight(); y += base_radius * 2) {

			ofPushMatrix();
			ofTranslate(x, y);

			int radius = base_radius * 0.95;

			ofNoFill();
			ofDrawCircle(glm::vec2(), radius);

			radius = base_radius * 0.85;

			ofFill();
			ofBeginShape();
			for (int deg = 0; deg < 360; deg += 10) {

				glm::vec2 point = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				float threshold = ofMap(ofNoise((point.x + x) * 0.005, (point.y + y) * 0.005, ofGetFrameNum() * 0.03), 0, 1, 0, -radius);
				if (threshold > point.y) {

					point.y = threshold;
				}

				ofVertex(point);
			}
			ofEndShape(true);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}