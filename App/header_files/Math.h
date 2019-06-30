#ifndef MATH_H
#define MATH_H
#include <cmath>
#include <vector>
#include <iostream>
#include <math.h>
#define ROUND(x) (static_cast<int>(x + 0.5))


class Vec3
{
    public: float x,y,z;
    public: Vec3(float xx=0, float yy=0, float zz=0): x(xx) ,y(yy), z(zz) {}
            Vec3 operator + (const Vec3& vec) const {return Vec3(x+vec.x,y+vec.y,z+vec.z); }
            Vec3 operator - (const Vec3& vec) const {return Vec3(x-vec.x,y-vec.y,z-vec.z); }
            Vec3 operator / (const float& d) const {return Vec3(x/d,y/d,z/d);}
            Vec3 operator * (const float& d) const {return Vec3(x*d,y*d,z*d);}
            friend Vec3 operator*(float d, const Vec3& u) { return u*d; }

            friend std::ostream& operator<<(std::ostream&, const Vec3&);
            friend float dot(const Vec3& u, const Vec3& v) {
                return u.x*v.x + u.y*v.y + u.z*v.z; }
            friend Vec3 cross(const Vec3& u, const Vec3& v) {
                return Vec3(u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x); }
            float norm() const {return x*x + y*y + z*z ;}
            float mag() const {return sqrt(norm());}
            float& operator [] (int i){return (&x)[i];}
            Vec3 normalize() const { return (*this)/mag(); }
};

class Vec2
{
    public: float x, y,z ; //z for depth
            Vec3 c; //c for color
            float i; // i for intensity


    public:Vec2(float xx=0, float yy=0,float zz=0,float ii=10): x(xx) ,y(yy),z(zz),i(ii){}
            Vec2(const Vec2& in):x(in.x),y(in.y),z(in.z),i(in.i){}
            void operator = (const Vec2& in){
                x = in.x;
                y = in.y;
                z = in.z;
                i = in.i;
            }
            friend std::ostream& operator<<(std::ostream& o, const Vec2& v);
};


class Mat
{
    private:
        float* data;
        int row, col;
    public:
        Mat(int rows,int column) : row(rows), col(column)
        {
            data = new float[row*col];
        }

        Mat(const Mat& mat)
        {
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }
        Mat& set(const std::initializer_list<float>& _data);
        friend std::ostream& operator<<(std::ostream&, const Mat&);

        void operator=(const Mat& mat)
        {
            delete[] data;
            row = mat.row;
            col = mat.col;
            data = new float[row*col];

            for (int i =0;i<row*col;i++)
                (*this)(i) = mat(i);
        }


        float& operator() (int r, int c);   //mat(i,j)
        float& operator() (int pos) ;       //mat(pos)


        const float operator() (int r, int c) const;   //mat(i,j)
        const float operator() (int pos) const;       //mat(pos)


        Mat operator * (Mat& mat);    // M = T * M
        Mat operator + (Mat& mat);    // C = A + B
        Mat operator - (Mat& mat);    // C = A - B
        Mat operator / (float val);      // C[] = C[] / val
        float dot(Mat& mat);             // A.dot(B) == (A = A DOT B)
        float mag();                  //returns the square root of sum of squares of all element

        ~Mat(){
            delete[] data;
        }
};






//
//int main()
//{
//    Mat m(3,3);
//    Mat n(3,3);
//
//    m(0) = 1; m(1) = 2; m(2) = 3;
//    m(3) = 4; m(4) = 5; m(5) = 6;
//    m(6) = 2; m(7) = 4; m(8) = 5;
//
//    n(0) = 1; n(1) = 0; n(2) = 0;
//    n(3) = 0; n(4) = 1; n(5) = 0;
//    n(6) = 0; n(7) = 0; n(8) = 1;
//
//    n = m * n;
//
//    for (int i =0; i< 3; i++,std::cout << std::endl)
//        for (int j =0; j< 3; j++)
//            std::cout << n(i,j) << " ";
//
//}

#endif // MATRIX_H_
