#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>

// Définition des couleurs de feu de signalisation
enum class Traffic_color { red, orange, green };

// Classe pour le feu de signalisation
class Traffic_light {
public:
    Traffic_light(Traffic_color initial_color)
        : color(initial_color) {}

    void set_traffic_color(Traffic_color new_color) {
        color = new_color;
    }

    sf::Color get_SFML_color() const {
        switch (color) {
        case Traffic_color::red: return sf::Color::Red;
        case Traffic_color::orange: return sf::Color(255, 165, 0); // Orange spécifique
        case Traffic_color::green: return sf::Color::Green;
        default: return sf::Color::Black;
        }
    }

private:
    Traffic_color color;
};

// Définition de la voiture
class Car {
public:
    enum class Direction { Up, Left, Down, Right };

    Car(float x, float y, Direction dir, float speed)
        : position(x, y), direction(dir), speed(speed), can_move(true) {}

    void move(float delta_time) {
        if (can_move) {
            switch (direction) {
            case Direction::Up:    position.y -= speed * delta_time; break;
            case Direction::Left:  position.x -= speed * delta_time; break;
            case Direction::Down:  position.y += speed * delta_time; break;
            case Direction::Right: position.x += speed * delta_time; break;
            }
        }
    }

    void set_can_move(bool can_move) {
        this->can_move = can_move;
    }

    sf::RectangleShape get_shape() const {
        sf::RectangleShape car_shape(sf::Vector2f(40, 20)); // Largeur et hauteur de la voiture
        car_shape.setPosition(position);
        car_shape.setFillColor(sf::Color::Blue);
        return car_shape;
    }

    sf::Vector2f get_position() const {
        return position;
    }

    Direction get_direction() const {
        return direction;
    }

private:
    sf::Vector2f position;
    Direction direction;
    float speed;
    bool can_move; // Indique si la voiture peut se déplacer (basé sur les feux)
};

// Déclaration des feux de signalisation
Traffic_light traffic_haut_droite(Traffic_color::red);
Traffic_light traffic_bas_droite(Traffic_color::red);
Traffic_light traffic_haut_gauche(Traffic_color::red);
Traffic_light traffic_bas_gauche(Traffic_color::red);

// Dimensions de la fenêtre
const int window_width = 800;
const int window_height = 800;

// Rayon des cercles (feux de signalisation)
const int radius = 40;

// Positions des feux de signalisation
const int l1 = window_width / 4; // Position x pour les coins
const int l2 = window_width * 3 / 4; // Position x opposé
const int l3 = window_height / 4; // Position y pour les coins
const int l4 = window_height * 3 / 4; // Position y opposé

// Liste des voitures
std::vector<Car> cars = {
    Car(100, window_height / 4, Car::Direction::Down, 100.f),  // Voiture venant du haut
    Car(window_width / 4, window_height - 100, Car::Direction::Up, 100.f), // Voiture venant du bas
    Car(window_width - 100, window_height / 4, Car::Direction::Left, 100.f), // Voiture venant de la droite
    Car(window_width / 4, 100, Car::Direction::Right, 100.f)  // Voiture venant de la gauche
};

// Fonction pour gérer le cycle des feux de signalisation
void run_traffic_light(std::atomic<bool>& stop_signal) {
    while (!stop_signal.load()) {
        // Séquence de changements de feux
        traffic_haut_droite.set_traffic_color(Traffic_color::green);
        traffic_bas_droite.set_traffic_color(Traffic_color::red);
        traffic_haut_gauche.set_traffic_color(Traffic_color::red);
        traffic_bas_gauche.set_traffic_color(Traffic_color::red);

        std::this_thread::sleep_for(std::chrono::seconds(3));

        traffic_haut_droite.set_traffic_color(Traffic_color::orange);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        traffic_haut_droite.set_traffic_color(Traffic_color::red);
        traffic_bas_droite.set_traffic_color(Traffic_color::green);

        std::this_thread::sleep_for(std::chrono::seconds(3));

        traffic_bas_droite.set_traffic_color(Traffic_color::orange);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        traffic_bas_droite.set_traffic_color(Traffic_color::red);
        traffic_haut_gauche.set_traffic_color(Traffic_color::green);

        std::this_thread::sleep_for(std::chrono::seconds(3));

        traffic_haut_gauche.set_traffic_color(Traffic_color::orange);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        traffic_haut_gauche.set_traffic_color(Traffic_color::red);
        traffic_bas_gauche.set_traffic_color(Traffic_color::green);

        std::this_thread::sleep_for(std::chrono::seconds(3));

        traffic_bas_gauche.set_traffic_color(Traffic_color::orange);
        std::this_thread::sleep_for(std::chrono::seconds(1));

        traffic_bas_gauche.set_traffic_color(Traffic_color::red);
    }
}

// Fonction pour dessiner les feux de signalisation
void draw_traffic_lights(sf::RenderWindow& window) {
    sf::CircleShape circle_haut_droite(radius);
    circle_haut_droite.setFillColor(traffic_haut_droite.get_SFML_color());
    circle_haut_droite.setOrigin(radius / 2, radius / 2);
    circle_haut_droite.setPosition(l2, l3);

    sf::CircleShape circle_bas_droite(radius);
    circle_bas_droite.setFillColor(traffic_bas_droite.get_SFML_color());
    circle_bas_droite.setOrigin(radius / 2, radius / 2);
    circle_bas_droite.setPosition(l2, l4);

    sf::CircleShape circle_haut_gauche(radius);
    circle_haut_gauche.setFillColor(traffic_haut_gauche.get_SFML_color());
    circle_haut_gauche.setOrigin(radius / 2, radius / 2);
    circle_haut_gauche.setPosition(l1, l3);

    sf::CircleShape circle_bas_gauche(radius);
    circle_bas_gauche.setFillColor(traffic_bas_gauche.get_SFML_color());
    circle_bas_gauche.setOrigin(radius / 2, radius / 2);
    circle_bas_gauche.setPosition(l1, l4);

    window.draw(circle_haut_droite);
    window.draw(circle_bas_droite);
    window.draw(circle_haut_gauche);
    window.draw(circle_bas_gauche);
}

// Fonction pour mettre à jour les voitures
void update_cars(float delta_time) {
    for (auto& car : cars) {
        bool can_move = true;

        // Vérification des feux pour chaque direction
        switch (car.get_direction()) {
        case Car::Direction::Up:
            if (traffic_haut_gauche.get_SFML_color() == sf::Color::Red) {
                can_move = false;
            }
            break;
        case Car::Direction::Left:
            if (traffic_bas_gauche.get_SFML_color() == sf::Color::Red) {
                can_move = false;
            }
            break;
        case Car::Direction::Down:
            if (traffic_bas_droite.get_SFML_color() == sf::Color::Red) {
                can_move = false;
            }
            break;
        case Car::Direction::Right:
            if (traffic_haut_droite.get_SFML_color() == sf::Color::Red) {
                can_move = false;
            }
            break;
        }

        car.set_can_move(can_move);
        car.move(delta_time);
    }
}

// Fonction principale
int main() {
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Simulation Feux de Circulation");

    // Démarrage du thread pour les feux de circulation
    std::atomic<bool> stop_thread(false);
    std::thread traffic_thread(run_traffic_light, std::ref(stop_thread));

    sf::Clock clock;

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                stop_thread.store(true); // Arrêter le thread des feux
            }
        }

        float delta_time = clock.restart().asSeconds();
        update_cars(delta_time);
        draw_traffic_lights(window);

        // Dessiner les voitures
        for (const auto& car : cars) {
            window.draw(car.get_shape());
        }

        window.display();
    }

    // Attendre que le thread des feux se termine
    if (traffic_thread.joinable()) {
        traffic_thread.join();
    }

    return 0;
}
