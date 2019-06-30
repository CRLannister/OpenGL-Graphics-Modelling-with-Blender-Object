#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "Math.h"
#include <vector>
#include "load.h"
#include "main.h"

class Window {
public:
    int width, height;
    float nearz, farz;
    std::vector<float> zbuffer;

public:
    Window(int w=640, int h=480, float nearz=-1, float farz=-100);

public:
    void clear();
    void refresh();
    void start();

//    void setPixel(const Vec2& p, const Vec3& c={1,1,1}, float i=1);
    void setPixel(int x, int y, float d, const Vec3& c={1,1,1}, float i=1);

    void drawLine(const Vec2& p1, const Vec2& p2, const Vec3& c={1,1,1});

    void fillTriangle(const Vec2&, const Vec2&, const Vec2&);

    void wireframe(const Scene& scene, const Vec3& camera={0,0,10},
            const Vec3& target={0,0,0}, float angle_x=50, float scale=1.0, int axis_type=2, float Angle_x=0, float angle_y=0, float angle_z=0);
    void render(const Scene& scene, const Vec3& camera={0,0,10},
            const Vec3& target={0,0,0}, const Vec3& light={10,10,10},
            float angle_x=45, float scale=1.0, int axis_type=2, float Angle_x=0, float angle_y=0, float angle_z=0);
};

#endif // GRAPHICS_H
