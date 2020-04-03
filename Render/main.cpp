#include <SFML/Graphics.hpp>


#include <Render/Object.h>
#include <Render/Scene.h>
#include <Render/Renderer.h>
#include <armadillo>
#include <Render/Mesh.h>


using namespace arma;

int main(int argc, char ** argv) 
{
    (void)argc;
    (void)argv;
    Scene scene;
    Renderer render;
    Cube<sf::Uint8> img = Cube<sf::Uint8>(4, 800, 600);
    img.fill(0);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Image image;
    
    sf::Sprite sprite;
    sf::Texture texture;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        
        render.render(img, scene);
        image.create(800, 600, img.mem);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
