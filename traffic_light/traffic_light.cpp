// condition_variable::wait (with predicate)
#include <iostream> // std::cout
#include <thread>   // std::thread, std::this_thread::yield
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory> // Pour std::unique_ptr

using namespace std::chrono_literals;

static const sf::Color Orange(255, 165, 0);

const auto time_transit = 3s;
const auto time_waiting = 8s;

enum class Traffic_color
{
    green = 0,
    orange = 1,
    red = 2
};

Traffic_color operator++(Traffic_color& traffic_color)
{
    switch (traffic_color)
    {
    case Traffic_color::red:
        traffic_color = Traffic_color::green;
        break;

    case Traffic_color::green:
        std::this_thread::sleep_for(time_transit);
        traffic_color = Traffic_color::orange;
        std::this_thread::sleep_for(time_transit);
        traffic_color = Traffic_color::red;
    }
    return traffic_color;
}

class Traffic_light
{
private:
    Traffic_color traffic_color_;

public:
    explicit Traffic_light(const Traffic_color& traffic_color) : traffic_color_{ traffic_color } {}
    void operator++()
    {
        ++traffic_color_;
    }
    void set_traffic_color(const Traffic_color& traffic_color)
    {
        traffic_color_ = traffic_color;
    }
    const Traffic_color& get_traffic_color() const
    {
        return traffic_color_;
    }
};

const sf::Color& get_SFML_color(const Traffic_light& traffic_light)
{
    switch (traffic_light.get_traffic_color())
    {
    case Traffic_color::green:
        return sf::Color::Green;
    case Traffic_color::red:
        return sf::Color::Red;
    }
    return Orange;
}

std::ostream& operator<<(std::ostream& os, const Traffic_light& traffic_light)
{
    std::string ptr;
    switch (traffic_light.get_traffic_color())
    {
    case Traffic_color::red:
        ptr = "Red";
        break;
    case Traffic_color::green:
        ptr = "Green";
        break;
    case Traffic_color::orange:
        ptr = "Orange";
    }
    os << ptr;
    return os;
}

class Usager {
protected:
    float x, y;          // Position de l'usager
    float vitesse;       // Vitesse de déplacement
    sf::Color couleur;   // Couleur pour affichage
    std::string type;    // Type de l'usager

public:
    Usager(float x, float y, float vitesse, sf::Color couleur, std::string type)
        : x(x), y(y), vitesse(vitesse), couleur(couleur), type(type) {}

    virtual void deplacer(const Traffic_light& feu) {
        if (feu.get_traffic_color() == Traffic_color::green) {
            x += vitesse; // Avance si le feu est vert
        }
    }

    virtual void afficher(sf::RenderWindow& window) const {
        sf::CircleShape shape(8); // Taille générique pour un usager
        shape.setFillColor(couleur);
        shape.setPosition(x, y);
        window.draw(shape);
    }
};

class Voiture : public Usager {
public:
    Voiture(float x, float y) : Usager(x, y, 2.0f, sf::Color::Red, "Voiture") {}
};

class Pieton : public Usager {
public:
    Pieton(float x, float y) : Usager(x, y, 0.5f, sf::Color::Green, "Piéton") {}
};

class Cycliste : public Usager {
public:
    Cycliste(float x, float y) : Usager(x, y, 1.0f, sf::Color::Yellow, "Cycliste") {}
};

std::vector<std::unique_ptr<Usager>> usagers;

// Initialisation des usagers
void init_usagers() {
    usagers.push_back(std::make_unique<Voiture>(100, 350)); // Voiture sur la voie horizontale
    usagers.push_back(std::make_unique<Pieton>(300, 450)); // Piéton sur le trottoir
    usagers.push_back(std::make_unique<Cycliste>(200, 350)); // Cycliste sur la piste cyclable
}

void update_usagers(const Traffic_light& feu) {
    for (auto& usager : usagers) {
        usager->deplacer(feu);
    }
}

void draw_usagers(sf::RenderWindow& window) {
	for (const auto& usager : usagers) {
		usager->afficher(window);
	}
}

void run_traffic_light(Traffic_light& traffic_light_master, Traffic_light& traffic_light_slave,
    Traffic_light& traffic_light_1, Traffic_light& traffic_light_2,
    std::stop_token stop_token) {
    // Initial state: Master green, Slave red
    traffic_light_master.set_traffic_color(Traffic_color::green);
    traffic_light_slave.set_traffic_color(Traffic_color::red);
    traffic_light_1.set_traffic_color(Traffic_color::red);
    traffic_light_2.set_traffic_color(Traffic_color::red);

    // Cycle through the traffic lights
    while (!stop_token.stop_requested()) {
        // Master green, Slave red, 1 red, 2 red
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed
        traffic_light_master.set_traffic_color(Traffic_color::orange); // Master goes orange
        std::this_thread::sleep_for(std::chrono::seconds(1)); // orange for 1 second
        traffic_light_master.set_traffic_color(Traffic_color::red); // Master goes red
        traffic_light_slave.set_traffic_color(Traffic_color::green); // Slave goes green

        // Master red, Slave green, 1 red, 2 red
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed
        traffic_light_slave.set_traffic_color(Traffic_color::orange); // Slave goes yellow
        std::this_thread::sleep_for(std::chrono::seconds(1)); // orange for 1 second
        traffic_light_slave.set_traffic_color(Traffic_color::red); // Slave goes red
        traffic_light_1.set_traffic_color(Traffic_color::green); // 1 goes green

        // Master red, Slave red, 1 green, 2 red
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed
        traffic_light_1.set_traffic_color(Traffic_color::orange); // 1 goes orange
        std::this_thread::sleep_for(std::chrono::seconds(1)); // orange for 1 second
        traffic_light_1.set_traffic_color(Traffic_color::red); // 1 goes red
        traffic_light_2.set_traffic_color(Traffic_color::green); // 2 goes green

        // Master red, Slave red, 1 red, 2 green
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed
        traffic_light_2.set_traffic_color(Traffic_color::orange); // 2 goes orange
        std::this_thread::sleep_for(std::chrono::seconds(1)); // orange for 1 second
        traffic_light_2.set_traffic_color(Traffic_color::red); // 2 goes red
        traffic_light_master.set_traffic_color(Traffic_color::green); // Master goes green
    }
}

// Function to print traffic light state
void print_traffic_light(Traffic_light& traffic_light_master, Traffic_light& traffic_light_slave,
    Traffic_light& traffic_light_1, Traffic_light& traffic_light_2,
    std::stop_token stop_token) {
    while (!stop_token.stop_requested()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Master: " << traffic_light_master << " Slave: " << traffic_light_slave
            << " 1: " << traffic_light_1 << " 2: " << traffic_light_2 << std::endl;
    }
}

int main() {
    std::stop_source stopping;
    Traffic_light traffic_light_master{ Traffic_color::red };
    Traffic_light traffic_light_slave{ Traffic_color::red };
    Traffic_light traffic_light_1{ Traffic_color::red };
    Traffic_light traffic_light_2{ Traffic_color::red };

    std::jthread thread_traffic_light(run_traffic_light,
        std::ref(traffic_light_master), std::ref(traffic_light_slave),
        std::ref(traffic_light_1), std::ref(traffic_light_2),
        stopping.get_token());

    std::jthread write_traffic_light(print_traffic_light,
        std::ref(traffic_light_master), std::ref(traffic_light_slave),
        std::ref(traffic_light_1), std::ref(traffic_light_2),
        stopping.get_token());

    // SFML setup (same as before)
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    float l1 = 350, l2 = 430, size = 800, radius = 10;
    sf::Vertex line1[] = { sf::Vertex(sf::Vector2f(0, l1)), sf::Vertex(sf::Vector2f(size, l1)) };
    sf::Vertex line2[] = { sf::Vertex(sf::Vector2f(0, l2)), sf::Vertex(sf::Vector2f(size, l2)) };
    sf::Vertex line3[] = { sf::Vertex(sf::Vector2f(l1, 0)), sf::Vertex(sf::Vector2f(l1, size)) };
    sf::Vertex line4[] = { sf::Vertex(sf::Vector2f(l2, 0)), sf::Vertex(sf::Vector2f(l2, size)) };

    sf::CircleShape circle1(radius);
    circle1.setFillColor(sf::Color::Blue);
    circle1.setOrigin(circle1.getRadius() / 2, circle1.getRadius() / 2);
    circle1.setPosition(l2, l2);

    sf::CircleShape circle2(radius);
    circle2.setFillColor(sf::Color::Green);
    circle2.setOrigin(circle2.getRadius() / 2, circle2.getRadius() / 2);
    circle2.setPosition(l2, l1);

    sf::CircleShape circle3(radius);
    circle3.setFillColor(sf::Color::Green);
    circle3.setOrigin(circle3.getRadius() / 2, circle3.getRadius() / 2);
    circle3.setPosition(l1, l1);

    sf::CircleShape circle4(radius);
    circle4.setFillColor(sf::Color::Green);
    circle4.setOrigin(circle4.getRadius() / 2, circle4.getRadius() / 2);
    circle4.setPosition(l1, l2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                stopping.request_stop();
                window.close();
                return 0;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4, 2, sf::Lines);

        circle1.setFillColor(get_SFML_color(traffic_light_slave));
        circle2.setFillColor(get_SFML_color(traffic_light_master));
        circle3.setFillColor(get_SFML_color(traffic_light_1));
        circle4.setFillColor(get_SFML_color(traffic_light_2));

        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.draw(circle4);

        window.display();
    }

    return 0;
}