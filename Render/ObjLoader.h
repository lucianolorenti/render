#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <string>
#include <armadillo>
#include <Render/Mesh.h>
#include <memory>
#include <Render/Types.h>


class ObjLoader {
public:
   std::unique_ptr<Mesh> load(const std::string & filename);
private:
    arma::vec4 readVertices(std::istringstream & iss);
    face readFace(std::istringstream & iss);

};
#endif
