#ifndef APC523Project_INTERFACE_H
#define APC523Project_INTERFACE_H

#include "cell.h"
#include "model.h"

using namespace std;

class Model;
class Cell;

class Interface
{
public:
	Interface(int *cellid, int id, Model *mymodel){create_(cellid, id, mymodel);};
	Interface(){create_();};

	void set_interface_cells();
	
	
	int get_id(){return id_;};
	Cell *get_cell(int i){return interface_cells_[i];};
	int get_cellid(int i){return cellid_[i];}
	double *get_F(){return F_;};
	double *get_U1(){return U1_;};
	double *get_U2(){return U2_;};
	
	void initialize(char);
	void set_U1(double *);
	void set_U2(double *);
	void roe(char);
	void hlle(char);
	void hllc(char);

private:
	int id_;
	int cellid_[2];
	Cell *interface_cells_[2];
	Model *mymodel_;

	double U1_[4];
	double U2_[4];
	double F_[4];

	void create_(int*, int, Model*);
	void create_();
};


#endif
