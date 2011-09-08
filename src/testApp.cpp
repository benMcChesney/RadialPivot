#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(15,15,15) ; 
    createSphere() ;
    
    for ( int i = 0 ; i <= 2 ; ++i ) 
    {
        mySphere sphere = mySphere() ; 
        ofVec3f color = ofVec3f ( ofRandom( .1 , 1 ) , ofRandom( .1 , 1 ) , ofRandom( .1 , 1 ) ) ; 
        sphere.setSphereParmaters( 128, 128, 120 + 40 * i , color , i ) ;
        spheres.push_back( sphere ) ; 
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw()
{
    
    float mx = (float)mouseX/ofGetWidth() * 360.0f  ;  
    float my = (float)mouseY/ofGetHeight() * 360.0f ; 
    
   
    for ( int i = 0 ; i < spheres.size() ; i++ ) 
    {
        ofPushMatrix();
        ofTranslate( ofGetWidth()/2 , ofGetHeight()/2 );
        
        ofRotateX( mx * (float)(i+1) ) ; 
        ofRotateY( my * (float)(i+1) ) ; 
        ofScale( 100.0f , 100.0f , 100.0f ) ; 
        spheres[i].draw( ) ;
        
        ofPopMatrix();
    }


    ofSetColor( 255 , 255 , 255 ) ; 
    ofDrawBitmapString( ofToString((int)ofGetFrameRate()) , 30 , ofGetHeight() - 60 ) ; 
}

void testApp::createSphere( ) 
{
    /* OBJ C verson from Tim Kautz
    (void) fillVertexData:(FloatArray *)vertexData andIndices:(UShortArray *)indices {
        
        for (int latNumber = 0; latNumber <= _lats; ++latNumber) {
            for (int longNumber = 0; longNumber <= _longs; ++longNumber) {
                float theta = latNumber * M_PI / _lats;
                float phi = longNumber * 2 * M_PI / _longs;
                
                float sinTheta = sin(theta);
                float sinPhi = sin(phi);
                float cosTheta = cos(theta);
                float cosPhi = cos(phi);
            
                float x = cosPhi * sinTheta;    
                float y = cosTheta;
                float z = sinPhi * sinTheta;
                float u = 1.0 - (1.0 * longNumber / _longs);
                float v = 1.0 * latNumber / _lats;
                
                [vertexData add:_radius * x];
                [vertexData add:_radius * y];
                [vertexData add:_radius * z];
                
                [vertexData add:x];
                [vertexData add:y];
                [vertexData add:z];
                
                [vertexData add:u];
                [vertexData add:v];
     */
    
    int lats = 16 ; //latitude ( horizontal ) 
    int longs = 16 ; //longitude ( vertical ) 
    float radius = 150.0f ; 
    for ( int latNumber = 0 ; latNumber <= lats ; ++latNumber ) 
    {
        for ( int longNumber = 0 ; longNumber <= longs ; ++longNumber ) 
        {
            float theta = latNumber * TWO_PI / lats ; 
            float phi = longNumber * TWO_PI / longs ; 
            float sinTheta = sin(theta) ; 
            float sinPhi = sin (phi) ; 
            float cosTheta = cos(theta) ; 
            float cosPhi = cos(phi) ; 
            
            ofVec3f position = ofVec3f( cosPhi * sinTheta * radius , 
                                        cosTheta * radius ,
                                        sinPhi * sinTheta * radius ) ; 
            
            spherePoints.push_back( position ) ; 
            
            // UVs for later 
            // ofVec2f uv = ofVec2f( 1.0f - ( 1.0 * longNumber / longs ) , 1.0f * latNumber / lats ) ; 
        }
    }
}

void testApp::drawPointSphere( )
{
    
    glBegin ( GL_POINTS ) ; 
    glColor3ub( 255 , 255 , 255 );
    
    for (int i=0;i<spherePoints.size();i++) 
    {
        glVertex3f( spherePoints[i].x , spherePoints[i].y , spherePoints[i].z ) ; 
    }
    
    glEnd(); 
}

//void createSphereFromPoints( const ofVec3f center, float radius, int segments );
void testApp::createSphereFromPoints( const ofVec3f center, float radius, int segments )
{
	if( segments < 0 )
		return;

    
	float *verts = new float[(segments+1)*2*3];
	for( int j = 0; j < segments / 2; j++ ) {
		float theta1 = j * 2 * 3.14159f / segments - ( 3.14159f / 2.0f );
		float theta2 = (j + 1) * 2 * 3.14159f / segments - ( 3.14159f / 2.0f );

		for( int i = 0; i <= segments; i++ ) {
			ofVec3f e, p;
			float theta3 = i * 2 * 3.14159f / segments;

			e.x = cos( theta1 ) * cos( theta3 );
			e.y = sin( theta1 );
			e.z = cos( theta1 ) * sin( theta3 );
			p = e * radius + center;

			verts[i*3*2+0] = p.x;
			verts[i*3*2+1] = p.y;
			verts[i*3*2+2] = p.z;

			e.x = cos( theta2 ) * cos( theta3 );
			e.y = sin( theta2 );
			e.z = cos( theta2 ) * sin( theta3 );
			p = e * radius + center;

			verts[i*3*2+3] = p.x;
			verts[i*3*2+4] = p.y;
			verts[i*3*2+5] = p.z;

			spherePoints.push_back(p);
		}
	}
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