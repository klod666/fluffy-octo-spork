#pragma once
#include <string>



using namespace std;

class Figure
{
public:
	virtual double volume() = 0;
	virtual void info() = 0;
	Figure();
	~Figure();
};

class Cylinder : public Figure
{
	double r, h;
public:
	double volume();
	void info();
	double get_radius();
	double get_height();
	void set_radius(double r);
	void set_height(double h);
	Cylinder* clone();
	Cylinder();
	Cylinder(double r, double h);
};

class Cuboid : public Figure
{
protected:
	double l, w, h;
public:
	double volume();
	void info();
	double get_lenght();
	double get_width();
	double get_height();
	void set_lenght(double l);
	void set_width(double w);
	void set_height(double h);
	void set_dimensions(double l, double w, double h);
	Cuboid* clone();
	Cuboid();
	Cuboid(double l, double w, double h);
};

class Cube : public Cuboid
{
public:
	void info();
	double get_edge();
	void set_lenght(double l);
	void set_width(double w);
	void set_height(double h);
	void set_dimensions(double l, double w, double h);
	void set_edge(double edge);
	Cube* clone();
	Cube();
	Cube(double a);
	
};

class Pyramid : public Figure
{
	int vertex_count;
	double edge, height;
public:
	double volume();
	void info();
	int get_vertex();
	double get_edge();
	double get_height();
	void set_vertex_count(int n);
	void set_edge(double e);
	void set_height(double h);
	Pyramid* clone();
	Pyramid();
	Pyramid(int n, double edge, double height);
};

