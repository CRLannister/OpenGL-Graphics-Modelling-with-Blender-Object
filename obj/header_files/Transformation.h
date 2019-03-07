#pragma once

#include "Math.h"
#include <cmath>
const float pi = 3.1415926535897;

inline float deg2rad(float deg) { return deg*M_PI/180; }

Vec3 RotateX(Vec3& Point,float theta);
Vec3 RotateY(Vec3& Point,float theta);
Vec3 RotateZ(Vec3& Point,float theta);
Vec3 translate(Vec3& Point,const Vec3& tMat);
Vec3 Scale(Vec3& Point,float scale);
Vec2 project(Vec3 p, float width, float height, float angle_x=45);
Vec3 Reflect_Y(Vec3& Point,const Vec3& tMat);


Vec3 world_to_pixel(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x=45);

Vec2 world_to_pixel_wireFrame(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x=45);


//Vec3 world_to_pixel(Vec3 p, Vec3 cam, Vec3 target);

//Vec2 world_to_pixel(const Vec3& source ,          //World pofloat to convert floato pixel pofloat
//                        const Vec3& camera,       //Point from where you are watching
//                        const Vec3& LookTo,       //Where are we looking at from the camera pos
//                        float planeWidth,         //width of the perspective plane
//                        float planeHeight,        //height of the perspectice plane
//                        float winWidth,           //width of the screen window
//                        float winHeight);         //height of the screen window
