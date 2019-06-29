#ifndef BOT_FIELD_HPP
#define BOT_FIELD_HPP

#include <list>
#include <random>

#include <clever/HexagonField.hpp>





struct Cell;
struct Plant;
struct Bot;



struct MapUnit
{
	double
		grounden = 0.0,
		airen = 0.0,
		planten = 0.0,
		boten = 0.0,
		bodyen = 0.0, 
		mineralen = 0.0;
	int density = 0;
};



struct BotField: public clever::HexagonField<Cell>
{
	static constexpr int const MAPPING_KOFF = 5;

	// members
	int age = 0;

	double
		summen = 0.0,
		grounden = 0.0,
		airen = 0.0,
		planten = 0.0,
		boten = 0.0,
		bodyen = 0.0, 
		mineralen = 0.0;

	HexagonField<MapUnit> mapping;



	// create, destroy
	BotField();
	~BotField();



	// functions
	BotField &free();

	void init_botfield(int wedth, int height);
	void reset();
	void update();

	bool push(int x, int y, Bot *bot, bool calc = true);
	bool push(int x, int y, Plant *plant);
	void push(int x, int y, bool calc = true);

	void random_fill(int cellcount);
	void ravage_ground(double k);
	void random_bots(int count);



private:
	inline bool valid(clever::PointI const &p);
	inline bool valid(clever::PointI const &p, int dir);

	void update_environment_();
	void update_entities_();

	void calculate_energy_();

	void set_cells_();
	
	clever::HexagonField<double> smoothf_ = {0, 0, nullptr};



};





#endif
