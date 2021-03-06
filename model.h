#ifndef APC523Project_MODEL_H
#define APC523Project_MODEL_H

#include <vector>
#include "cell.h"
#include "interface.h"

#define GAMMA 1.4

using namespace std;

class Cell;
class Interface;
void grid(double, int, const char*);

class Model
{
public:
	Model(const char* filename){create_(filename);};


	Cell *get_cell(int i){return &cells_[i];};
	Interface *get_interface(int i){return &interfaces_[i];};
	
	void Grid(double, int, const char*);
	void Initialize(double);
	
	void Reconstructx(int);
	void Predictx(double);
	void Riemannx(int);
	void Updatex(double);
	
	void Reconstructy(int);
	void Predicty(double);
	void Riemanny(int);
	void Updatey(double);
	double Timestep(double);
	
	void Output(const char*);
	
private:
	vector<Cell> cells_;
	vector<Interface> interfaces_;
	int Nx_, Ny_, Nvertical_;
	void create_(const char*);
	void create_();
};

#endif
