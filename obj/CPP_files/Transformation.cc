#include "../header_files/Transformation.h"
#include <cassert>
#include <cmath>
#include "../header_files/Math.h"
using namespace std;

Vec3 RotateX(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = 1;     T(0,1) = 0;         T(0,2) = 0;             T(0,3) = 0;
    T(1,0) = 0;     T(1,1) = cos(angle);T(1,2) = -sin(angle);   T(1,3) = 0;
    T(2,0) = 0;     T(2,1) = sin(angle);T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;     T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}

Vec3 RotateY(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = 0;         T(0,2) = sin(angle);    T(0,3) = 0;
    T(1,0) = 0;             T(1,1) = 1;         T(1,2) = 0;             T(1,3) = 0;
    T(2,0) = -sin(angle);   T(2,1) = 0;         T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}


Vec3 RotateZ(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = -sin(theta);       T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = sin(angle);    T(1,1) = cos(theta);        T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;             T(2,1) = 0;                 T(2,2) = 1;    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;                 T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;


}

Vec3 translate(Vec3& Point,const Vec3& tMat){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = 1;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = tMat.x;
    T(1,0) = 0;    T(1,1) = 1;      T(1,2) = 0;    T(1,3) = tMat.y;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = tMat.z;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}

Vec3 Scale(Vec3& Point,float scale){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = scale;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = 0;    T(1,1) = scale;      T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = 0;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}

//Vec2 world_to_pixel(const Vec3& source ,const Vec3& camera, const Vec3& LookTo,float planeWidth, float planeHeight, float winWidth, float winHeight){
//    //first determine the World to Camera transforming matrix
//    Mat WtoC(4,4);
//    //for that use the concept of N, U and V unit vectors
//    Vec3 N,U,V(0,1,0);
//
//    //calculate the N unit vector
//    //N is the vector from LookTo point to Camera point
//    N = (camera-LookTo).normalize();
////    N = N/ N.mag();
//
//    //U = V X N
//    U = cross(V,N).normalize();
////    U = U / U.mag();
//
//
//    //readjust the V vector
//    V = cross(N,U).normalize();
////    V = V / V.mag();
//
//    //Transpose matrix from World co-ordinate to View co-ordinate
//    Mat T(4,4);
//    T(0,0) = 1 ; T(0,1) = 0; T(0,2) = 0; T(0,3) = -camera.x;
//    T(1,0) = 0 ; T(1,1) = 1; T(1,2) = 0; T(1,3) = -camera.y;
//    T(2,0) = 0 ; T(2,1) = 0; T(2,2) = 1; T(2,3) = -camera.z;
//    T(3,0) = 0 ; T(3,1) = 0; T(3,2) = 0; T(3,3) = 1;
//
//    //Rotation Matrix
//    Mat R(4,4);
//    R(0,0) = U[0] ; R(0,1) = U[1]; R(0,2) = U[2]; R(0,3) = 0;
//    R(1,0) = V[0] ; R(1,1) = V[1]; R(1,2) = V[2]; R(1,3) = 0;
//    R(2,0) = N[0] ; R(2,1) = N[1]; R(2,2) = N[2]; R(2,3) = 0;
//    R(3,0) = 0 ; R(3,1) = 0; R(3,2) = 0; R(3,3) = 1;
//
//
//    //Calculating the WtoC matrix W = T*R (rotate and then translate)
//    WtoC = R*T;
////
////    std::cout << std::endl << " MATRIX START" << std::endl;
////    WtoC.print();
////    std::cout <<"MATRIX END"<< std::endl << std::endl;
//
//    Mat S(4,1); //The source point in matrix form
//    S(0) = source.x ; S(1) = source.y; S(2) = source.z ; S(3) = 1;
//
//    S = WtoC * S;
//    //S now represents the camera co-ordinate system's values
//    //calculate the screen pixels
//
//    // Perspective projection:
//
//    float zprp = 1;
//    Mat Persp(4,4);
//    Mat Projected(4,1);
//    Persp(0,0) = zprp ; Persp(0,1) = 0; Persp(0,2) = 0; Persp(0,3) = 0;
//    Persp(1,0) = 0 ; Persp(1,1) = zprp; Persp(1,2) = 0; Persp(1,3) = 0;
//    Persp(2,0) = 0 ; Persp(2,1) = 0; Persp(2,2) = 0; Persp(2,3) = 0;
//    Persp(3,0) = 0 ; Persp(3,1) = 0; Persp(3,2) = -1; Persp(3,3) = zprp;
//    Projected = Persp * S;
//
//    //normalize the screen pixels
//    Vec2 retVal;
//    retVal.x = Projected(0)/Projected(3);
//    retVal.y = Projected(1)/Projected(3);
//    retVal.z = S(2);
//
//    retVal.x = (retVal.x + planeWidth*0.5)/planeWidth;
//    retVal.y = (retVal.y + planeHeight*0.5)/planeHeight;
//
//    //now to original screen pos in computer
//    retVal.x = (int)(retVal.x * winWidth);
//    retVal.y = (int)((1-retVal.y) * winHeight);
//
//    return retVal;
//}

Vec2 project(Vec3 p, float width, float height, float angle_x)
{
//    float angle_y, aspect_ratio;
//    aspect_ratio = width / height;
//    angle_x = deg2rad(angle_x);
//    angle_y = 2*atan(tan(angle_x/2) / aspect_ratio);
//
//    Vec2 v;
//    v.x = (1 + p.x/fabs(p.z*tan(angle_x/2))) * (width/2);
//    v.y = (1 + p.y/fabs(p.z*tan(angle_y/2))) * (height/2);
//    v.z = p.z;
//    return v;


    Mat S(4,1); //The source point in matrix form
    S(0) = p.x ; S(1) = p.y; S(2) = p.z ; S(3) = 1;
    float zprp = -1;
    Mat Persp(4,4);
    Mat Projected(4,1);
    Persp(0,0) = zprp ; Persp(0,1) = 0; Persp(0,2) = 0; Persp(0,3) = 0;
    Persp(1,0) = 0 ; Persp(1,1) = zprp; Persp(1,2) = 0; Persp(1,3) = 0;
    Persp(2,0) = 0 ; Persp(2,1) = 0; Persp(2,2) = 0; Persp(2,3) = 0;
    Persp(3,0) = 0 ; Persp(3,1) = 0; Persp(3,2) = -1; Persp(3,3) = zprp;
    Projected = Persp * S;

    //normalize the screen pixels
    Vec2 retVal;
    retVal.x = Projected(0)/Projected(3);
    retVal.y = Projected(1)/Projected(3);
    retVal.z = S(2);

    float  planeWidth = .3;
    float planeHeight = .3;
    retVal.x = (retVal.x + planeWidth*0.5)/planeWidth;
    retVal.y = (retVal.y + planeHeight*0.5)/planeHeight;

    //now to original screen pos in computer
    retVal.x = (int)(retVal.x * width);
    retVal.y = (int)((1-retVal.y) * height);

    return retVal;
}



Vec2 world_to_pixel_wireFrame(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x){

    p = world_to_pixel(p,cam,target,win_height,win_height);
        float angle_y, aspect_ratio;
    aspect_ratio = win_width / win_height;
    angle_x = deg2rad(angle_x);
    angle_y = 2*atan(tan(angle_x/2) / aspect_ratio);

    Vec2 v;
    v.x = (1 + p.x/fabs(p.z*tan(angle_x/2))) * (win_width/2);
    v.y = (1 + p.y/fabs(p.z*tan(angle_y/2))) * (win_height/2);
    v.z = p.z;
    return v;


}

Vec3 world_to_pixel(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x)
{
    //first determine the World to Camera transforming matrix
    Mat WtoC(4,4);
    //for that use the concept of N, U and V unit vectors
    Vec3 N,U,V(0,1,0);

    //calculate the N unit vector
    //N is the vector from LookTo point to Camera point
//    N = (cam-target).normalize();
    target = {-target.x, -target.y, -target.z};
    N = translate(cam,target).normalize();


    //U = V X N
    U = cross(V,N).normalize();


    //readjust the V vector
    V = cross(N,U).normalize();

    //Transpose matrix from World co-ordinate to View co-ordinate
    Mat T(4,4);
    T(0,0) = 1 ; T(0,1) = 0; T(0,2) = 0; T(0,3) = -cam.x;
    T(1,0) = 0 ; T(1,1) = 1; T(1,2) = 0; T(1,3) = -cam.y;
    T(2,0) = 0 ; T(2,1) = 0; T(2,2) = 1; T(2,3) = -cam.z;
    T(3,0) = 0 ; T(3,1) = 0; T(3,2) = 0; T(3,3) = 1;

    //Rotation Matrix
    Mat R(4,4);
    R(0,0) = U[0] ; R(0,1) = U[1]; R(0,2) = U[2]; R(0,3) = 0;
    R(1,0) = V[0] ; R(1,1) = V[1]; R(1,2) = V[2]; R(1,3) = 0;
    R(2,0) = N[0] ; R(2,1) = N[1]; R(2,2) = N[2]; R(2,3) = 0;
    R(3,0) = 0 ; R(3,1) = 0; R(3,2) = 0; R(3,3) = 1;


    //Calculating the WtoC matrix W = T*R (rotate and then translate)
    WtoC = R*T;

    Mat S(4,1); //The source point in matrix form
    S(0) = p.x ; S(1) = p.y; S(2) = p.z ; S(3) = 1;

    S = WtoC * S;
    //S now represents the camera co-ordinate system's values

    p = {S(0), S(1), S(2)};





//    // calculate u, v, n vectors
//    Vec3 n = (cam - target).normalize();
//    Vec3 u = cross(Vec3(0,1,0), n).normalize();
//    Vec3 v = cross(n, u).normalize();
//
//    // translate cam to origin
//    Vec3 temp_cam = {-cam.x, -cam.y, -cam.z};
//    p = translate(p, temp_cam);
//    //cout << "Translated point = " << p << endl; // DEBUG
//
//    // rotate to align the axes
//    Mat R(4,4);
//    R.set({u.x, u.y, u.z, 0,
//           v.x, v.y, v.z, 0,
//           n.x, n.y, n.z, 0,
//           0, 0, 0, 1});
//    Mat P(4,1); P.set({p.x, p.y, p.z, 1});
//    P = R * P;
//    p = {P(0), P(1), P(2)};

//    return project(p, win_width, win_height, angle_x);
    return p;

}

