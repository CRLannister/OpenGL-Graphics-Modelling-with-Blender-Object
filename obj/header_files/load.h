#ifndef SCENE_H
#define SCENE_H
#include "Math.h"
#include "Transformation.h"
#include <algorithm>
#include <string>

// 3D vertex
class Vertex {
public: // data
    Vec3 p, n; // position and normal

public: // constructor
    Vertex(Vec3 position = {0,0,0}): p(position), n(0,0,0) {}
};

// a scene is a collection of vertices, edges, normals, and faces
class Scene {
public: // data
    std::vector<Vec3> normals;
    std::vector<int> faces;
    std::vector<Vec3> vertices;

public: // file manipulators
    void load(const std::string& filename);

public:
    void print() const;
    void calculateNormal();
};

#endif // SCENE_H
