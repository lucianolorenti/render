#include <Render/ObjLoader.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector> 
#include <armadillo> 
template <class Container>
void split(const std::string& str, Container& cont,
              char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(std::stoi(str.substr(previous, current - previous)));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(std::stoi(str.substr(previous, current - previous)));
}

arma::vec4 ObjLoader::readVertices(std::istringstream & iss)
{
    float v1, v2, v3;
    iss >> v1 >> v2 >> v3;
    return arma::vec4{v1, v2, v3, 1};
}

face ObjLoader::readFace(std::istringstream &iss)
{
    std::string f1, f2, f3;
    iss >> f1 >> f2 >> f3;
    std::vector<uint64_t> faces_data;
    split(f1, faces_data, '/');
    split(f2, faces_data, '/');
    split(f3, faces_data, '/');
    return face{faces_data[0], faces_data[0], faces_data[0]};
}



std::unique_ptr<Mesh> ObjLoader::load(const std::string & filename)
{
    std::ifstream infile(filename);
    std::string line;
    std::string type;
    
    std::vector<arma::vec4> vertices;
    std::vector<face> faces;
    while (std::getline(infile, line))  {
        std::istringstream iss(line);
        iss >> type;
        if (type == "v") {            
            vertices.push_back(this->readVertices(iss));
        } else if (type == "f") {
            faces.push_back(this->readFace(iss));
        }
        
        
    }
    return std::make_unique<Mesh>(vertices, faces);
}

