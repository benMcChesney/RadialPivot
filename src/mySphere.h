//
//  mySphere.h
//  sphereDraw
//
//  Created by Ben McChesney on 9/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofVec3f.h"
#include "ofMain.h"

class mySphere : public ofNode
{
    public:
        mySphere() {} ; 
        void setSphereParmaters( int numLat , int numLong , float radius , ofVec3f _color , int index ) ;
        void draw( ) ;
    
        vector<ofVec3f> spherePoints ; 
        ofVec3f color ; 
        int index ; 
    
    
    
        //vbo stuff
        ofVbo vbo ; 
        ofMesh mesh ; 
    
};