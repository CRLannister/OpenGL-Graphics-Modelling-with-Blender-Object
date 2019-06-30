#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "Math.h"
#include <cmath>

// conversions
inline float deg2rad(float deg) { return deg*M_PI/180; }
//inline float rad2deg(float rad) { return rad*180/M_PI; }

Vec3 translate(Vec3 p, float tx, float ty, float tz);
Vec3 rotate_y(Vec3 p, float angle);
Vec3 rotate(Vec3 p, float angle, Vec3 axis);
Vec2 project(Vec3 p, float width, float height, float angle_x=45);
Vec2 world_to_pixel(Vec3 p, Vec3 cam, Vec3 target,
        float win_width, float win_height, float angle_x=45);

#endif // TRANSFORMATION_H
