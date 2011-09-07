//
//  mySphere.cpp
//  sphereDraw
//
//  Created by Ben McChesney on 9/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "mySphere.h"

void mySphere::setSphereParmaters( int lats , int longs , float radius, int color , int _index ) 
{
    hexColor = color ; 
    index = _index ;
    //  int lats = 16 ; //latitude ( horizontal ) 
    //  int longs = 16 ; //longitude ( vertical ) 
    for ( int latNumber = 0 ; latNumber <= lats ; ++latNumber ) 
    {
        for ( int longNumber = 0 ; longNumber <= longs ; ++longNumber ) 
        {
            if ( latNumber %2 == 0 && longNumber % 2 == 0 ) 
            {
            float theta = latNumber * PI / lats ; 
            float phi = longNumber * PI / longs ; 
            float sinTheta = sin(theta) ; 
            float sinPhi = sin (phi) ; 
            float cosTheta = cos(theta) ; 
            float cosPhi = cos(phi) ; 
            
            
            
            ofVec3f position = ofVec3f( cosPhi * sinTheta * radius , 
                                       cosTheta * radius ,
                                       sinPhi * sinTheta * radius ) ; 
            
            spherePoints.push_back( position ) ; 
            }
            // UVs for later 
            // ofVec2f uv = ofVec2f( 1.0f - ( 1.0 * longNumber / longs ) , 1.0f * latNumber / lats ) ; 
        }
    }

}

void mySphere::draw() 
{
    
    ofSetHexColor ( hexColor ) ; 
    glBegin ( GL_TRIANGLE_FAN ) ;
    //glBegin( GL_LINES ) ; 
    
    int const len = spherePoints.size() ; 
    
    for (int i=0 ; i <= len ; ++i ) 
    {
        glVertex3f( spherePoints[i].x , spherePoints[i].y , spherePoints[i].z ) ; 
    }
    
    glEnd(); 

}