#ifndef APC523Project_CELL_H
#define APC523Project_CELL_H

#include "model.h"
#include "interface.h"

using namespace std;

class Model;
class Interface;

class Cell
{
public:
	Cell(int *interfaceid, double x, double y, double dx, double dy, int id, Model *mymodel)
	{create_(interfaceid, x, y, dx, dy, id, mymodel);};
	Cell(){create_();};

	void set_cell_interfaces();
		
	int get_id(){return id_;};
	double get_x(){return x_;};
	double get_y(){return y_;};
	double get_dx(){return dx_;};
	double get_dy(){return dy_;};
	double *get_U(){return U_;};
	double get_dt();
	
	void initialize(double*);
	void reconstruct(int, char);
	void predict(double, char);
	void update(double, char);
	
	void minbee(double*, double*, double*, double*, double*);
	void superbee(double*, double*, double*, double*, double*);

private:
	int id_;
	int interfaceid_[4];
	Interface *cell_interfaces_[4];
	Model *mymodel_;
	
	double x_, y_, dx_, dy_;
	double U_[4];

	void create_(int*, double, double, double, double, int, Model*);
	void create_();
};

#endif
