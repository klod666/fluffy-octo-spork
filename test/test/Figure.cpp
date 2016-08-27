#include "Figure.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.1415926535897932384626433832795



Figure::Figure()
{
}


Figure::~Figure()
{
}

double Cylinder::volume()
{
	double r = get_radius(), h = get_height();
	return PI*r*r*h;
}

void Cylinder::info()
{
	printf("Cylinder\n");
	printf("Radius: %lf\n", get_radius());
	printf("Height: %lf\n", get_height());
	printf("Volume: %lf\n", volume());
}

double Cylinder::get_radius()
{
	return r;
}

double Cylinder::get_height()
{
	return h;
}

void Cylinder::set_radius(double r)
{
	this->r = r;
}

void Cylinder::set_height(double h)
{
	this->h = h;
}

Cylinder * Cylinder::clone()
{
	Cylinder* cpy = new Cylinder();
	cpy->set_radius(this->r);
	cpy->set_height(this->h);
	return cpy;
}

Cylinder::Cylinder()
{
	set_radius(0);
	set_height(0);
}

Cylinder::Cylinder(double r, double h)
{
	set_radius(r);
	set_height(h);
}

double Cuboid::volume()
{
	return get_lenght()*get_width()*get_height();
}

void Cuboid::info()
{
	printf("Cuboid\n");
	printf("Dimentions: %lf x %lf x %lf\n", get_lenght(), get_width(), get_height());
	printf("Volume: %lf\n", volume());
}

double Cuboid::get_lenght()
{
	return l;
}

double Cuboid::get_width()
{
	return w;
}

double Cuboid::get_height()
{
	return h;
}

void Cuboid::set_lenght(double l)
{
	this->l = l;
}

void Cuboid::set_width(double w)
{
	this->w = w;
}

void Cuboid::set_height(double h)
{
	this->h = h;
}

void Cuboid::set_dimensions(double l, double w, double h)
{
	this->l = l;
	this->w = w;
	this->h = h;
}

Cuboid * Cuboid::clone()
{
	Cuboid* cpy = new Cuboid();
	cpy->set_dimensions(this->get_lenght(), this->get_width(), this->get_height());
	return cpy;
}

Cuboid::Cuboid()
{
	set_dimensions(0, 0, 0);
}

Cuboid::Cuboid(double l, double w, double h)
{
	set_dimensions(l, w, h);
}

void Cube::info()
{
	printf("Cube\n");
	printf("Dimentions: %lf x %lf x %lf\n", get_edge(), get_edge(), get_edge());
	printf("Volume: %lf\n", volume());
}

double Cube::get_edge()
{
	return get_lenght();
}

void Cube::set_lenght(double l)
{
	this->set_edge(l);
}

void Cube::set_width(double w)
{
	this->set_edge(w);
}

void Cube::set_height(double h)
{
	this->set_edge(h);
}

void Cube::set_dimensions(double l, double w, double h)
{
	set_edge(l);
}

void Cube::set_edge(double edge)
{
	l = w = h = edge;
}

Cube * Cube::clone()
{
	Cube* cpy = new Cube();
	cpy->set_edge(this->get_edge());
	return cpy;
}

Cube::Cube()
{
	set_edge(0);
}

Cube::Cube(double edge)
{
	set_edge(edge);
}

double Pyramid::volume()
{
	int vertex_count = get_vertex();
	double edge = get_edge(), height = get_height();
	if (vertex_count < 3) return 0;
	double alfa = PI/vertex_count;
	return vertex_count*edge*edge*height / (12 * tan(alfa));
}

void Pyramid::info()
{
	printf("%d-gon Pyramid\n", get_vertex());
	printf("Edge: %lf\n", get_edge());
	printf("Height: %lf\n", get_height());
	printf("Volume: %lf\n", volume());
}

int Pyramid::get_vertex()
{
	return vertex_count;
}

double Pyramid::get_edge()
{
	return edge;
}

double Pyramid::get_height()
{
	return height;
}

void Pyramid::set_vertex_count(int n)
{
	if (n > 0) vertex_count = n;
}

void Pyramid::set_edge(double e)
{
	edge = e;
}

void Pyramid::set_height(double h)
{
	height = h;
}

Pyramid * Pyramid::clone()
{
	Pyramid* cpy = new Pyramid();
	cpy->set_vertex_count(this->get_vertex());
	cpy->set_edge(this->get_edge());
	cpy->set_height(this->get_height());
	return nullptr;
}

Pyramid::Pyramid()
{
	set_vertex_count(1);
	set_edge(0);
	set_height(0);
}

Pyramid::Pyramid(int n, double edge, double height)
{
	set_vertex_count(n);
	set_edge(edge);
	set_height(height);
}
