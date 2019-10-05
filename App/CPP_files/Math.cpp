#include "../header_files/Math.h"
#include <stdexcept>
using namespace std;

ostream& operator<<(ostream& o, const Vec3& v)
{
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


ostream& operator<<(ostream& o, const Vec2& v)
{
    return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
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


float Mat::mag(){
    float res = 0;
    int pos;
    for (int i =0;i < this->row; i++)
    {
        for (int j=0;j<this->col;j++)
        {
            pos = (this->col)*i + j;
            //pos gives the value of this(i,j)

            res += data[pos] * data[pos];

        }
    }
    return sqrt(res);
}
Mat& Mat::set(const std::initializer_list<float>& args) {
//    if (_data.size() != data.size())
//        throw std::length_error("invalid size of initializer_list to assign matrix");
//    data = _data;
    std::initializer_list<float>::iterator it;
    int i=0;
    for ( it=args.begin(); it!=args.end(); ++it) {
        (*this)(i) = *it;
        i++;
    }


    return *this;
}

float Mat::dot(Mat& mat){
    if ((this->row != mat.row) || (this->col != mat.col))
    throw "ERROR";
    int pos;
    float res = 0;
    for (int i =0;i < this->row; i++)
    {
        for (int j=0;j<this->col;j++)
        {
            pos = (this->col)*i + j;
            //pos gives the value of this(i,j)

            res += data[pos] * mat(i,j);
        }
    }
    return res;

}

Mat Mat::operator*(Mat& mat)
{
    if (this->col != mat.row) throw "ERROR";
    int pos;
    Mat res(row,mat.col);

    for(int i = 0; i< this->row; i++ )
    {
        for (int j= 0; j< mat.col; j++)
        {
            res(i,j) = 0;
            for(int k=0; k< this->col; k++)
            {
                pos = (this->col)*i + k ; // ith row kth column
                res(i,j) += data[pos] * mat(k,j);
            }
        }
    }
    return res;
}

float& Mat::operator() (int r, int c)
{
    int pos = col* r + c ;
    return data[pos];
}

const float Mat::operator() (int r, int c) const
{
    int pos = col* r + c ;
    return data[pos];
}

float& Mat::operator() (int pos)
{
    return data[pos];
}

const float Mat::operator() (int pos) const
{
    return data[pos];
}

Mat Mat::operator+(Mat& mat)
{
    if ((this->row != mat.row) || (this->col != mat.col))
        throw "ERROR";
    Mat res(this->row,this->col);
    int pos;
    for (int i =0;i < this->row; i++)
    {
        for (int j=0;j<this->col;j++)
        {
            pos = (this->col)*i + j;
            res(i,j) = data[pos] + mat(i,j);
        }
    }
    return res;
}

Mat Mat::operator - (Mat& mat)
{
    if ((this->row != mat.row) || (this->col != mat.col))
        throw "ERROR";
    Mat res(this->row,this->col);
    int pos;
    for (int i =0;i < this->row; i++)
    {
        for (int j=0;j<this->col;j++)
        {
            pos = (this->col)*i + j;
            res(i,j) = data[pos] - mat(i,j);
        }
    }
    return res;
}

Mat Mat::operator / (float val)
{
    Mat res(this->row,this->col);
    int pos;

    for (int i =0;i < this->row; i++)
    {
        for (int j=0;j<this->col;j++)
        {
            pos = (this->col)*i + j;
            res(i,j) = data[pos] / val ;
        }
    }

    return res;
}
