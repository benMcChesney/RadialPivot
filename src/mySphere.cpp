//
//  mySphere.cpp
//  sphereDraw
//
//  Created by Ben McChesney on 9/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "mySphere.h"

void mySphere::setSphereParmaters( int lats , int longs , float radius, ofVec3f _color , int _index ) 
{
    color = _color ; 
    
    /*
    mesh.addVertex( ofVec3f( -1 , 0 , 1 ) ) ; 
    mesh.addVertex( ofVec3f( 1 , 0 , 1 ) ) ; 
    mesh.addVertex( ofVec3f( 1 , 0 , -1 ) ) ; 
    mesh.addVertex( ofVec3f( -1 , 0 , -1 ) ) ; 
    
    mesh.addColor( ofFloatColor( color.x , color.y , color.z , 0.5 ) ) ;
    mesh.addColor( ofFloatColor( color.x * .75 , color.y * .9 , color.z * .8 , 0.5 ) ) ;
    mesh.addColor( ofFloatColor( color.x * .75 , color.y * .8 , color.z * .8, 0.5 ) ) ;
    mesh.addColor( ofFloatColor( color.x * .65 , color.y * .65 , color.z * .65  , 0.5 ) ) ;
    
    */
    
    radius = 1.0f ;
    index = _index ;
    float total = (float)lats * (float)longs ; 
    //  int lats = 16 ; //latitude ( horizontal ) 
    //  int longs = 16 ; //longitude ( vertical ) 
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
            
            int index = latNumber + longNumber * lats ; 
            float ratio = (float)index / total ; 
            
            ofVec3f position = ofVec3f( cosPhi * sinTheta * radius , 
                                       cosTheta * radius ,
                                       sinPhi * sinTheta * radius ) ; 
            
            mesh.addVertex( position ) ;
            mesh.addColor( ofFloatColor( color.x * ratio , color.y * ratio , color.z * ratio , 0.45 ) ) ;
            spherePoints.push_back( position ) ; 
            // UVs for later 
            // ofVec2f uv = ofVec2f( 1.0f - ( 1.0 * longNumber / longs ) , 1.0f * latNumber / lats ) ; 
        }
    }
    
     vbo.setMesh( mesh , GL_DYNAMIC_DRAW ) ;

}

void mySphere::draw() 
{
    ofEnableAlphaBlending() ; 
    float s = 100.0f ; 
    setScale ( s , s, s ) ; 
    glDisable( GL_CULL_FACE ) ; 
    
    const int len = spherePoints.size() ; 
    vbo.draw ( GL_TRIANGLE_FAN , 0 , len ) ; 
    
    //ofScale ( 1.1 , 1.1 , 1.1 ) ; 
    //vbo.draw ( GL_LINE_LOOP , 0 , len ) ; 
    
    ofDisableAlphaBlending() ; 
    /*
    ofSetHexColor ( hexColor ) ; 
    glBegin ( GL_TRIANGLE_FAN ) ;
    //glBegin( GL_LINES ) ; 
    
    int const len = spherePoints.size() ; 
    
    for (int i=0 ; i <= len ; ++i ) 
    {
        glVertex3f( spherePoints[i].x , spherePoints[i].y , spherePoints[i].z ) ; 
    }
    
    glEnd(); 
     */
}