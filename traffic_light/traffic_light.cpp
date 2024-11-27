#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

// Dimensions de la fen�tre
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

// Vitesse des voitures
const float CAR_SPEED = 0.3f;

// Dur�es des �tats des feux
const sf::Time GREEN_DURATION = sf::seconds(5);
const sf::Time ORANGE_DURATION = sf::seconds(2);
const sf::Time RED_DURATION = sf::seconds(7); // Inclut le temps d'orange d'un autre feu

// �num�ration pour les �tats des feux
enum LightState { GREEN, ORANGE, RED };

// Classe Feu de circulation
class TrafficLight {
public:
    sf::RectangleShape lightShape;
    LightState state;

    TrafficLight(float x, float y) {
        lightShape = sf::RectangleShape(sf::Vector2f(20, 20));
        lightShape.setPosition(x, y);
        state = RED;
        updateColor();
    }

    void setState(LightState newState) {
        state = newState;
        updateColor();
    }

    void updateColor() {
        if (state == GREEN) {
            lightShape.setFillColor(sf::Color::Green);
        }
        else if (state == ORANGE) {
            lightShape.setFillColor(sf::Color(255, 165, 0)); // Couleur orange
        }
        else {
            lightShape.setFillColor(sf::Color::Red);
        }
    }

    bool isRedOrOrange() const {
        return state == RED || state == ORANGE;
    }

    bool isGreen() const {
        return state == GREEN;
    }

    bool isOrange() const {
        return state == ORANGE;
    }
};

// Classe Voiture
class Car {
public:
    sf::RectangleShape shape;
    float speed;
    bool comingFromTop;  // Si la voiture vient du haut (ou d'une autre direction)
    bool comingFromBottom;
    bool comingFromLeft;
    bool comingFromRight;

    Car(float x, float y, float width, float height, float speed, sf::Color color, bool top, bool bottom, bool left, bool right)
        : comingFromTop(top), comingFromBottom(bottom), comingFromLeft(left), comingFromRight(right) {
        this->shape = sf::RectangleShape(sf::Vector2f(width, height));
        this->shape.setPosition(x, y);
        this->speed = speed;
        this->shape.setFillColor(color);
    }

    bool checkCollision(const Car& other) {
        // V�rifie si les voitures se touchent (collision simple sur les bords)
        return shape.getGlobalBounds().intersects(other.shape.getGlobalBounds());
    }

    void move(bool horizontal, const std::vector<TrafficLight>& lights, const std::vector<Car>& cars) {
        bool canMove = true;
        float currentSpeed = speed;

        // V�rifier uniquement le feu correspondant � la direction de la voiture
        for (const auto& light : lights) {
            // Voiture venant de la gauche (regarde le feu � gauche)
            if (comingFromLeft && horizontal) {
                if (light.lightShape.getPosition().x == 130 && light.isRedOrOrange()) { // Feu de gauche
                    if (shape.getPosition().x < 150) {
                        canMove = false;
                        if (light.isOrange()) {
                            currentSpeed = speed / 3;  // R�duit la vitesse si le feu est orange
                        }
                    }
                    break; // Une fois qu'on a trouv� le feu de gauche, on peut sortir de la boucle
                }
            }
            // Voiture venant du haut (regarde le feu du haut)
            else if (comingFromTop && !horizontal) {
                if (light.lightShape.getPosition().y == 130 && light.isRedOrOrange()) { // Feu du haut
                    if (shape.getPosition().y < 150) {
                        canMove = false;
                        if (light.isOrange()) {
                            currentSpeed = speed / 3;  // R�duit la vitesse si le feu est orange
                        }
                    }
                    break;
                }
            }
            // Voiture venant du bas (regarde le feu du bas)
            else if (comingFromBottom && !horizontal) {
                if (light.lightShape.getPosition().y == 650 && light.isRedOrOrange()) { // Feu du bas
                    if (shape.getPosition().y > 550) {
                        canMove = false;
                        if (light.isOrange()) {
                            currentSpeed = speed / 3;  // R�duit la vitesse si le feu est orange
                        }
                    }
                    break;
                }
            }
            // Voiture venant de la droite (regarde le feu de droite)
            else if (comingFromRight && horizontal) {
                if (light.lightShape.getPosition().x == 650 && light.isRedOrOrange()) { // Feu de droite
                    if (shape.getPosition().x > 550) {
                        canMove = false;
                        if (light.isOrange()) {
                            currentSpeed = speed / 3;  // R�duit la vitesse si le feu est orange
                        }
                    }
                    break;
                }
            }
        }

        // V�rifie la collision avec les autres voitures dans la m�me direction
        for (const auto& other : cars) {
            if (&other != this) { // Ne pas se comparer � soi-m�me
                if (this->comingFromLeft && horizontal && shape.getPosition().x < other.shape.getPosition().x) {
                    if (checkCollision(other)) {
                        canMove = false; // Emp�che le mouvement si il y a une collision
                        break;
                    }
                }
                else if (this->comingFromTop && !horizontal && shape.getPosition().y < other.shape.getPosition().y) {
                    if (checkCollision(other)) {
                        canMove = false; // Emp�che le mouvement si il y a une collision
                        break;
                    }
                }
                else if (this->comingFromRight && horizontal && shape.getPosition().x > other.shape.getPosition().x) {
                    if (checkCollision(other)) {
                        canMove = false; // Emp�che le mouvement si il y a une collision
                        break;
                    }
                }
                else if (this->comingFromBottom && !horizontal && shape.getPosition().y > other.shape.getPosition().y) {
                    if (checkCollision(other)) {
                        canMove = false; // Emp�che le mouvement si il y a une collision
                        break;
                    }
                }
            }
        }

        // Si le feu est vert, la voiture peut avancer
        if (canMove) {
            if (horizontal) {
                shape.move(currentSpeed, 0);
                if (shape.getPosition().x > WINDOW_WIDTH) {
                    shape.setPosition(-shape.getSize().x, shape.getPosition().y); // R�appara�t � gauche
                }
            }
            else {
                shape.move(0, currentSpeed);
                if (shape.getPosition().y > WINDOW_HEIGHT) {
                    shape.setPosition(shape.getPosition().x, -shape.getSize().y); // R�appara�t en haut
                }
            }
        }
    }
};

int main() {
    // Initialisation al�atoire
    std::srand(static_cast<unsigned>(std::time(0)));

    // Cr�ation de la fen�tre
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simulation Circulation avec Feux");

    // Chargement de l'image de fond
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:\\Users\\corentin.bondeau\\source\\repos\\CIR2\\traffic_light\\photo_prog.png")) {
        std::cerr << "Erreur : Impossible de charger l'image photo_prog.png" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Cr�ation des feux de circulation
    std::vector<TrafficLight> trafficLights;
    trafficLights.emplace_back(260, 130); // Feu pour les voitures venant du haut
    trafficLights.emplace_back(520, 650); // Feu pour les voitures venant du bas
    trafficLights.emplace_back(130, 520); // Feu pour les voitures venant de la gauche
    trafficLights.emplace_back(650, 260); // Feu pour les voitures venant de la droite

    // Timer global pour les feux
    sf::Clock lightClock;
    int lightPhase = 0; // 0 = haut/bas verts, 1 = gauche/droite verts

    // Vecteur pour stocker les voitures
    std::vector<Car> cars;

    // Ajout de voitures initiales sur la partie droite des routes
    cars.emplace_back(300, 440, 80, 50, CAR_SPEED, sf::Color::Blue, false, false, true, false);  // Voiture bleue venant de la gauche
    cars.emplace_back(300, 100, 50, 80, CAR_SPEED, sf::Color::Green, true, false, false, false); // Voiture verte venant du haut
    cars.emplace_back(800, 300, 80, 50, -CAR_SPEED, sf::Color::Yellow, false, false, false, true);  // Voiture jaune venant de la droite
    cars.emplace_back(440, 800, 50, 80, -CAR_SPEED, sf::Color::Red, false, true, false, false); // Voiture rouge venant du bas

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Ajout de voitures avec la touche A
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                int road = std::rand() % 4;
                if (road == 0) { // Route horizontale haut
                    cars.emplace_back(800, 300, 80, 50, -CAR_SPEED, sf::Color::Yellow, false, false, false, true);
                }
                else if (road == 1) { // Route horizontale bas
                    cars.emplace_back(300, 440, 80, 50, CAR_SPEED, sf::Color::Cyan, false, false, false, true);
                }
                else if (road == 2) { // Route verticale gauche
                    cars.emplace_back(300, 100, 50, 80, CAR_SPEED, sf::Color::Magenta, true, false, false, false);
                }
                else { // Route verticale droite
                    cars.emplace_back(440, 800, 50, 80, -CAR_SPEED, sf::Color::Red, false, true, false, false);
                }
            }

            // Suppression de voitures avec la touche S
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                if (!cars.empty()) {
                    cars.pop_back(); // Supprime la derni�re voiture
                }
            }
        }

        // Mise � jour des feux de circulation
        if (lightClock.getElapsedTime() > GREEN_DURATION + ORANGE_DURATION + RED_DURATION) {
            lightClock.restart();
        }

        // D�terminer la phase en fonction du temps �coul�
        sf::Time elapsed = lightClock.getElapsedTime();
        if (elapsed < GREEN_DURATION) {
            lightPhase = 0; // Haut/bas verts
            trafficLights[0].setState(GREEN);
            trafficLights[1].setState(GREEN);
            trafficLights[2].setState(RED);
            trafficLights[3].setState(RED);
        }
        else if (elapsed < GREEN_DURATION + ORANGE_DURATION) {
            trafficLights[0].setState(ORANGE);
            trafficLights[1].setState(ORANGE);
        }
        else {
            lightPhase = 1; // Gauche/droite verts
            trafficLights[0].setState(RED);
            trafficLights[1].setState(RED);
            trafficLights[2].setState(GREEN);
            trafficLights[3].setState(GREEN);
        }

        // D�placement des voitures
        for (auto& car : cars) {
            if (car.shape.getSize().x > car.shape.getSize().y) {
                car.move(true, trafficLights, cars); // D�placement horizontal
            }
            else {
                car.move(false, trafficLights, cars); // D�placement vertical
            }
        }

        // Dessin dans la fen�tre
        window.clear();
        window.draw(backgroundSprite); // Dessine le fond

        for (const auto& light : trafficLights) {
            window.draw(light.lightShape); // Dessine chaque feu
        }

        for (const auto& car : cars) {
            window.draw(car.shape); // Dessine chaque voiture
        }

        window.display();
    }

    return 0;
}
