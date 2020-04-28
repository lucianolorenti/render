#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <armadillo>
#include <Render/Scene.h>
#include <memory>
#include <Render/VertexShader.h>

class Renderer {
public:
    Renderer();
    void render(arma::Cube<sf::Uint8> & texure, Scene & scene);
private:
    arma::mat44 m_projection_matrix;
    arma::mat44 m_transformation_matrix;
    std::unique_ptr<VertexShader> m_vertex_shader;
    float angle = 0;
};
#endif
