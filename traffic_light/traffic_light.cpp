#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test de chargement d'image");
    sf::Texture texture;

    if (!texture.loadFromFile("photo_prog.png")) {
        std::cerr << "Erreur : Impossible de charger l'image photo_prog.png" << std::endl;
        return -1;
    }

    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
