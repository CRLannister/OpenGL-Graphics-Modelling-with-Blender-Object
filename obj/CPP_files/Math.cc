#include "../header_files/Math.h"
#include <stdexcept>
using namespace std;

ostream& operator<<(ostream& o, const Vec3& v)
{
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

Vec3 operator/(const Vec3& u, float d)
{
    //This is to prevent causing NaN when normalizing zero vectors
    if (d == 0) d = 0.00001;
    return Vec3(u.x/d, u.y/d, u.z/d);
}

float& Vec3::operator[](int i)
{
    if (i == 0) return x;
    else if (i == 1) return y;
    else if (i == 2) return z;
    else throw range_error("index out of range in Vec3::operator[]");
}

ostream& operator<<(ostream& o, const Vec2& v)
{
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

Mat& Mat::set(const std::initializer_list<float>& _data)
{
    if (_data.size() != data.size())
        throw std::length_error("invalid size of initializer_list to assign matrix");
    data = _data;
    return *this;
}

ostream& operator<<(ostream& o, const Mat& A)
{
    o << "[";
    for (int i = 0; i < A.row; i++) {
        if (i != 0) o << "; ";
        for (int j = 0; j < A.col; j++) {
            if (j != 0) o << ", ";
            o << A(i,j);
        }
    }
    return o << "]";
}

Mat operator+(const Mat& A, const Mat& B)
{
    Mat R = A;
    for (unsigned long i = 0; i < R.data.size(); i++)
        R.data[i] += B.data[i];
    return R;
}

Mat operator-(const Mat& A, const Mat& B)
{
    Mat R = A;
    for (unsigned long i = 0; i < R.data.size(); i++)
        R.data[i] -= B.data[i];
    return R;
}

Mat operator*(const Mat& A, const Mat& B)
{
    if (A.col != B.row)
        throw std::invalid_argument("invalid sized matrices to multiply");

    Mat R(A.row, B.col, 0);
    for (int i = 0; i < R.row; i++)
        for (int j = 0; j < R.col; j++) {
            R(i,j) = 0;
            for (int k = 0; k < A.col; k++)
                R(i,j) += A(i,k)*B(k,j);
        }
    return R;
}

Mat operator*(const Mat& A, float d)
{
    Mat R = A;
    for (unsigned long i = 0; i < R.data.size(); i++)
        R.data[i] *= d;
    return R;
}

Vec3 operator*(const Mat& A, Vec3 B)
{
    Vec3 R = B;
    for (int i = 0; i < A.row; i++){
        for(int j =0; j<3; j++){
            R[i] += R[i] + A(i,j)*B[j];
        }
    }

    return R;
}


Mat operator/(const Mat& A, float d)
{
    if (d == 0) throw runtime_error("division of matrix by zero");

    Mat R = A;
    for (unsigned long i = 0; i < R.data.size(); i++)
        R.data[i] /= d;
    return R;
}

float Mat::mag() const
{
    float sum = 0;
    for (float f : data)
        sum += f*f;
    return sqrt(sum);
}


//Matrix dot product

//float dot(const Mat& A, const Mat& B)
//{
//    if (A.row != B.row or A.col != B.col)
//        throw invalid_argument("invalid sized matrices to dot product");
//
//    float sum = 0;
//    for (unsigned long i = 0; i < A.data.size(); i++)
//        sum += A(i)*B(i);
//    return sum;
//}
