#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>


using namespace std;

class File
{
    public:
      string path;
      vector<float> vertices;
      vector<unsigned int> indices;

      void import_obj(string Path_var);

      explicit File(string x){
            path = x;
            import_obj(path);
      }


};

void File::import_obj(string path)
{
    ifstream my_file;
    my_file.open(path);

    if (!my_file) {
		cout << "Fuck !! cannot open file" << endl;
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
            vertices.push_back(x/4);
            vertices.push_back(y/4);
            vertices.push_back(z/4);
            
           
            continue;
        }
        else if (type=="f")
        {   
            int a,b,c;
            char d;
            for (int i=0;i<3;i++)
            {
              in >> a >>d>>d>>c;
              indices.push_back(--a);
	      

            }
            continue;
        }
        
    }  

}
