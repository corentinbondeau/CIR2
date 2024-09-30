#include "shape.hpp"

int main()
{
    Rectangle_pure_virtual rectangle_pv(5.f, 10.f, Color::green);
    rectangle_pv.print_data();

    auto p_rectangle_pv = &rectangle_pv;
    p_rectangle_pv->print_data();

    Shape_pure_virtual *p_shape_pv = &rectangle_pv;
    p_shape_pv->print_data();
    
    Shape *p_shape_0 = &rectangle_pv;
    p_shape_0->print_data();

    Rectangle_virtual rectangle_v(5.f, 10.f, Color::orange);
    rectangle_v.print_data();

    auto p_rectangle_v = &rectangle_v;
    p_rectangle_v->print_data();

    Shape_virtual *p_shape_v = &rectangle_v;
    p_shape_v->print_data();

    Shape *p_shape_1 = &rectangle_v;
    p_shape_1->print_data();

    Rectangle rectangle(5.f, 10.f, Color::brown);
    rectangle.print_data();

    auto p_rectangle = &rectangle;
    p_rectangle->print_data();

    Shape *p_shape = &rectangle;
    p_shape->print_data();

    Shape shape;
    shape.print_data();

    constexpr size_t nb_quadrupede = 4;
    Quadrupede* tableau_de_quadrupede[nb_quadrupede];

    // On cree alternativement des chiens et des chats.
    Quadrupede* matouPremier = new Chat("Felix");
    Quadrupede* cabotPremier = new Chien("Albert");
    Quadrupede* matouLeSecond = new Chat("Simba");
    Quadrupede* cabotLeSecond = new Chien("Stein");

    // On les ajoute au tableau
    tableau_de_quadrupede[0] = matouPremier;
    tableau_de_quadrupede[1] = cabotPremier;
    tableau_de_quadrupede[2] = matouLeSecond;
    tableau_de_quadrupede[3] = cabotLeSecond;

    // On lance la methode de la classe fille
    for (size_t iquad = 0; iquad < nb_quadrupede; ++iquad) {
        tableau_de_quadrupede[iquad]->speak();
    }

    // On lance la methode de la classe fille si elle est de type pointeur sur une classe Chat
    for (size_t iquad = 0; iquad < nb_quadrupede; ++iquad) {
        auto tmp = dynamic_cast<Chat*> (tableau_de_quadrupede[iquad]);
        if (tmp) {
            tmp->speak();
        }
    }


    return 0;
}