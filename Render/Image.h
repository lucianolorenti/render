#include <string>
#include <SFML/System.hpp>
#include <vector>
class Image {
public:
    Image(uint h, uint w);
    void save(const std::string & filename);

    sf::Uint8 & operator()(int r, int c);
    

private:
    std::vector<sf::Uint8> m_pixels;
};