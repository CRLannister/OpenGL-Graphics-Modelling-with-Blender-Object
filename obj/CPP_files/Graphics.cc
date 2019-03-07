#include "../header_files/Graphics.h"
#include "GL/glut.h"
#include <cassert>
using namespace std;

Vec3 ICTC_color = {1,0.4,0};

Window::Window(int w, int h, float nearz, float farz):
    width(w), height(h), nearz(nearz), farz(farz)
{
    // initialize the zbuffer
    zbuffer = vector<float>(w*h, farz-1);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    zbuffer = vector<float>(width*height, farz-1);
}

void Window::refresh()
{
    glutSwapBuffers();
}

void Window::start()
{
    glutMainLoop();
}

//function overloading not used

//void Window::setPixel(const Vec2& p, const Vec3& c, float i)
//{
//    setPixel(ROUND(p.x), ROUND(p.y), p.z, c, i);
//}

void Window::setPixel(int x, int y, float z, const Vec3& c, float i)
{
    // clipping
    if (x < 0 or x > width or y < 0 or y > height)
        return;

    // check z buffer
//    if (z <= zbuffer[x*height + y] or z < farz or z > nearz)
//        return;
//    zbuffer[x*height + y] = z;

    if (z <= zbuffer[width * y + x] or z < farz or z > nearz)
        return;
    zbuffer[width * y + x] = z;


    glColor3f(c.x*i, c.y*i, c.z*i);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


//DDA Algorithm Implementation

void Window::drawLine(const Vec2& p1, const Vec2& p2, const Vec3& c)
{
#ifdef SOLID
    int del_x = ROUND(p2.x) - ROUND(p1.x);
    int del_y = ROUND(p2.y) - ROUND(p1.y);
#else
    float del_x = p2.x - p1.x;
    float del_y = p2.y - p1.y;
#endif
    float d = p1.z, del_d = p2.z - p1.z;
    float i = p1.i, del_i = p2.i - p1.i;
    int step = (abs(del_x) > abs(del_y))? abs(del_x) : abs(del_y);

    float x = p1.x, y = p1.y;
    if (step == 0) {
        setPixel(ROUND(x), ROUND(y), d, c, i);
        return;
    }

    for (int k = 0; k <= step; k++) {
        setPixel(ROUND(x), ROUND(y), d, c, i);
        //setPixel(x, y, d, c, i);

        x += del_x / step;
        y += del_y / step;
        d += del_d / step;
        i += del_i / step;
    }
}

void Window::fillTriangle(const Vec2& v1, const Vec2& v2, const Vec2& v3)
{
    // vec2 comparer
    struct Vec2Comparer{ bool operator()(const Vec2& a, const Vec2& b) {
        return a.y < b.y; }};
    vector<Vec2> v = {v1, v2, v3};
    sort(v.begin(), v.end(), Vec2Comparer());

    float y, x1, z1, i1, x2, z2, i2;
    for (y = v[0].y; y < v[1].y; y++) {
        if (v[1].y == v[0].y) {
            drawLine(Vec2(v[0].x, y, v[0].z, v[0].i), Vec2(v[1].x, y, v[1].z, v[1].i), ICTC_color);
            break;
        }
        x1 = v[0].x + (y - v[0].y) * (v[1].x - v[0].x) / (v[1].y - v[0].y);
        z1 = v[0].z + (y - v[0].y) * (v[1].z - v[0].z) / (v[1].y - v[0].y);
        i1 = v[0].i + (y - v[0].y) * (v[1].i - v[0].i) / (v[1].y - v[0].y);
        x2 = v[0].x + (y - v[0].y) * (v[2].x - v[0].x) / (v[2].y - v[0].y);
        z2 = v[0].z + (y - v[0].y) * (v[2].z - v[0].z) / (v[2].y - v[0].y);
        i2 = v[0].i + (y - v[0].y) * (v[2].i - v[0].i) / (v[2].y - v[0].y);
        drawLine(Vec2(x1,y,z1,i1), Vec2(x2,y,z2,i2), ICTC_color);
    }

    for (y = v[1].y; y <= v[2].y; y++) {
        if (v[2].y == v[1].y) {
            drawLine(Vec2(v[1].x, y, v[1].z, v[1].i), Vec2(v[2].x, y, v[2].z, v[2].i),ICTC_color);
            break;
        }
        x1 = v[1].x + (y - v[1].y) * (v[2].x - v[1].x) / (v[2].y - v[1].y);
        z1 = v[1].z + (y - v[1].y) * (v[2].z - v[1].z) / (v[2].y - v[1].y);
        i1 = v[1].i + (y - v[1].y) * (v[2].i - v[1].i) / (v[2].y - v[1].y);
        x2 = v[0].x + (y - v[0].y) * (v[2].x - v[0].x) / (v[2].y - v[0].y);
        z2 = v[0].z + (y - v[0].y) * (v[2].z - v[0].z) / (v[2].y - v[0].y);
        i2 = v[0].i + (y - v[0].y) * (v[2].i - v[0].i) / (v[2].y - v[0].y);
        drawLine(Vec2(x1,y,z1,i1), Vec2(x2,y,z2,i2), ICTC_color);
    }
}

void Window::wireframe(const Scene& scene, const Vec3& camera,
        const Vec3& target, float angle_x, float scale, int axis_type,  float Angle_x, float angle_y, float angle_z)
{
    // project points to 2d
    vector<Vec2> vertices2d;
    for (unsigned long i = 0; i < scene.vertices.size(); i++) {
        // get the coordinate of vertex
        Vec3 point3d = scene.vertices[i];
        // rotate the vertex about world y-axis
//        if(axis_type == 1)
//            point3d = RotateX(point3d, angle);
//        if(axis_type == 2)
//            point3d = RotateY(point3d, angle);
//        if(axis_type == 3)
//            point3d = RotateZ(point3d, angle);

        point3d = RotateX(point3d, Angle_x);
        point3d = RotateY(point3d, angle_y);
        point3d = RotateZ(point3d, angle_z);


        point3d = Scale(point3d,scale);
        // project
        Vec3 points3d = world_to_pixel(point3d, camera, target, width, height );
//        Vec2 point2d = world_to_pixel_wireFrame(point3d, camera, target, width, height );

        Vec2 point2d = project(points3d,width,height,angle_x);
        vertices2d.push_back(point2d);
    }

    // draw edges
    for (unsigned long i = 0; i < scene.faces.size(); i += 3) {
        // get the 3 vertex's index
        int index1 = scene.faces[i];
        int index2 = scene.faces[i+1];
        int index3 = scene.faces[i+2];
        // get the vertices
        Vec2 p1 = vertices2d[index1];
        Vec2 p2 = vertices2d[index2];
        Vec2 p3 = vertices2d[index3];
        // draw
        drawLine(p1, p2,ICTC_color);
        drawLine(p2, p3,ICTC_color);
        drawLine(p3, p1,ICTC_color);
    }
}

void Window::render(const Scene& scene, const Vec3& camera, const Vec3& target,
        const Vec3& light, float angle_x,float scale, int axis_type,  float Angle_x, float angle_y, float angle_z)
{
    vector<Vec2> vertices2d(scene.vertices.size());
    
    // project to 2d as well as find the intensities
    Vec3 point3d, u, v, n, L, N, R, H, V; Mat M(4,4), P(4,1); float d;
    for (unsigned long i = 0; i < scene.vertices.size(); i++) {
        point3d = scene.vertices[i];

//        // rotate the point in world axis
//        if(axis_type == 1)
//            point3d = RotateX(point3d, angle);
//        if(axis_type == 2)
//            point3d = RotateY(point3d, angle);
//        if(axis_type == 3)
//            point3d = RotateZ(point3d, angle);

        point3d = RotateX(point3d, Angle_x);
        point3d = RotateY(point3d, angle_y);
        point3d = RotateZ(point3d, angle_z);

        point3d = Scale(point3d,scale);

        point3d = world_to_pixel(point3d, camera , target, width , height);  // this is in camera coordinates
//        // translate camera to origin
//        Vec3 temp_camera ={-camera.x, -camera.y, -camera.z};
//        point3d = translate(point3d, temp_camera);
//
//        // calculate u,v,n vectors
//        n = (camera - target).normalize();
//        u = cross({0,1,0}, n).normalize();
//        v = cross(n, u).normalize();
//
//        // align camera axes to world axes
//        M.set({u.x, u.y, u.z, 0,
//               v.x, v.y, v.z, 0,
//               n.x, n.y, n.z, 0,
//               0, 0, 0, 1});
//        P.set({point3d.x, point3d.y, point3d.z, 1});
//        P = M*P;
//        point3d = {P(0), P(1), P(2)}; // this is in camera coordinates

        // calculate point intensity
        N = scene.normals[i].normalize();
        L = (light - point3d).normalize();
        d = (light - point3d).mag();
        R = (N*(dot(N,L)*2) - L).normalize();
        V = (camera - point3d).normalize();
        //H = (L + V).normalize();
        float intensity = 0.4 + 0.5*dot(N,L) + powf(dot(R,V), 50);
        if (intensity > 1) intensity = 1;

        // project to screen coordinates
        vertices2d[i] = project(point3d, width, height, angle_x);
        vertices2d[i].i = intensity;
    }

    // now fill every triangle
    Vec2 v1, v2, v3;
    for (unsigned long i = 0; i < scene.faces.size(); i += 3) {
        // get vertices
        v1 = vertices2d[scene.faces[i]];
        v2 = vertices2d[scene.faces[i+1]];
        v3 = vertices2d[scene.faces[i+2]];

        // fill triangle
        fillTriangle(v1, v2, v3);
    }
}
