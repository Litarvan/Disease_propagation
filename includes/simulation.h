#ifndef SIMULATION_H
#define SIMULATION_H
#include "menu.h"
#include "person.h"
#include <vector>
#include <cmath>


// Classe d�finissant la simulation

class Simulation
{

public:

	int									pixels_size;			// Taille des pixels
	double								vaccinated_percentage;	// Pourcentages de personnes vaccin�es
	int									nb_sick;				// Nombre de gens malades
	double								death_rate;				// Pourcentage de chance de mourir de la maladie
	double								contagious_level;		// Contagiosit� de la maladie
	int									time_before_death;		// Temps avant la mort
	int									time_before_cure;		// Temps avant de gu�rir
	sf::RectangleShape					person;					// Un pixel � afficher
	std::vector<std::vector<Person> >	population;				// La population
	sf::RenderTexture					texture;				// La texture sur laquelle sont dessin�s les pixels
	sf::Sprite							sprite;					// Le sprite servant � afficher la texture

	Simulation();
	Simulation(const Simulation& simulation);
	Simulation(const Menu& menu);

	void operator=(const Simulation& simulation);

	void restart(const Menu& menu);
	void draw_person(int x, int y);
	void draw_population();
	void refresh_population();
	bool anti_segfault(int x, int y);
	void update_healthy(int x, int y);
	void update_sick(int x, int y);
	void update();
	void draw(sf::RenderWindow& window);
};

#endif
