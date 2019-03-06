#include "../header_files/load.h"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "../header_files/Math.h"
using namespace std;

void Scene::load(const string& filename)
{
    vertices.clear();
    faces.clear();

    ifstream objfile(filename);
    if (!objfile) throw runtime_error("unable to open the object file");

    string line, keyword;
    while (getline(objfile, line)) {
        istringstream linestream(line);
        linestream >> keyword;

        if (keyword == "v") {
            Vec3 v;
            linestream >> v.x >> v.y >> v.z;
            vertices.push_back(v);
        }

        else if (keyword == "f") {
            // get three strings
            string temp;
            for (int i = 0; i < 3; i++) {
                linestream >> temp;
                faces.push_back(stoi(temp) - 1);
            }

        }
    }

    // don't forget to close the file
    objfile.close();
    calculateNormal();
}

void Scene::print() const
{
    // print vertices and normals
    for (unsigned long i = 0; i < vertices.size(); i++)
        cout << vertices[i] << " ==> " << normals[i] << endl;
}

void Scene::calculateNormal()
{
    vector<int> count(vertices.size(), 0);
    normals = vector<Vec3>(vertices.size(), Vec3(0,0,0));

    for (unsigned long i = 0; i < faces.size(); i += 3) {
        // get 3 indices of vertices of this face
        int i1 = faces[i];
        int i2 = faces[i+1];
        int i3 = faces[i+2];

        // get the vertices
        Vec3 v1 = vertices[i1];
        Vec3 v2 = vertices[i2];
        Vec3 v3 = vertices[i3];

        // calculate normal of face
        if ((v2-v1).mag() < 0.00001) v2 = v2 * 1.000001;
        if ((v3-v2).mag() < 0.00001) v3 = v3 * 1.000001;
        Vec3 A = (v2 - v1).normalize();
        Vec3 B = (v3 - v2).normalize();
        Vec3 N = cross(A,B).normalize();

        // add this normal to all 3 vertices and increment respective counts
        normals[i1] = normals[i1] + N; count[i1]++;
        normals[i2] = normals[i2] + N; count[i2]++;
        normals[i3] = normals[i3] + N; count[i3]++;
    }

    // find mean normals of all vertices
    for (unsigned long i = 0; i < vertices.size(); i++)
        normals[i] = (normals[i]).normalize();
}
