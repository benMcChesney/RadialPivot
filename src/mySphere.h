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

class mySphere
{
    public:
        mySphere() {} ; 
        void setSphereParmaters( int numLat , int numLong , float radius , int color , int index ) ;
        void draw( ) ;
    
        vector<ofVec3f> spherePoints ; 
        int hexColor ; 
        int index ; 
};