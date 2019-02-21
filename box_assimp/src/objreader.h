#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>


using namespace std;

class File
{
    string path;

    public:
        vector<float> vertices;
        vector<float> textures;
        vector<unsigned int> indices;
        
        
        File(string x);
        void import_obj();
        void filter();

};


//defining class methods

File::File(string x)
{
    path=x;
    File::import_obj();
    File::filter();

}

void File::filter()
{
    int length=textures.size()/2;
    
    for (int i=0;i<length;i++)
    {
            vertices[(5*i)+3] = textures[2*i];
			vertices[(5*i)+4] = textures[2*i + 1];
    }

}

void File::import_obj()
{
    ifstream my_file;
    my_file.open(path);

    if (!my_file) {
		cout << "cannot open file" << endl;
		exit(1);
	}

    string line;
    while(getline(my_file,line))
    {
        string type;
        istringstream in(line);
        in >>type;

        if (type=="v")
        {   
            float x, y, z;
			in >> x >> y >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            vertices.push_back(0);
            vertices.push_back(0);


            
            continue;
        }
        else if(type=="vt")
        {   
            float x,y;
            in >> x >>y;
            textures.push_back(x);
            textures.push_back(y);

            continue;
        }
        else if (type=="f")
        {   
            int a,b,c;
            char d;
            for (int i=0;i<3;i++)
            {
              in >> a >>d>>b>>d>>c;
              indices.push_back(a);

            }
            continue;
        }
    }  

}