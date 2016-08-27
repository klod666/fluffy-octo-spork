#include "Figure.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

enum CMD { ADD, DELETE, INFO, INFO_ALL, HELP, EXIT, INVALID_COMMAND };
enum SHAPE {CYLINDER, CUBOID, CUBE, PYRAMID, INVALID_SHAPE };

vector<Figure*> *fig_list = new vector<Figure*>();

CMD stringToCMD(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	if (s.compare("add") == 0) return ADD;
	else if (s.compare("delete") == 0) return DELETE;
	else if (s.compare("info") == 0) return INFO;
	else if (s.compare("info_all") == 0) return INFO_ALL;
	else if (s.compare("help") == 0) return HELP;
	else if (s.compare("exit") == 0) return EXIT;
	else return INVALID_COMMAND;
}

SHAPE stringToSHAPE(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	if (s.compare("cylinder") == 0) return CYLINDER;
	else if (s.compare("cuboid") == 0) return CUBOID;
	else if (s.compare("cube") == 0) return CUBE;
	else if (s.compare("pyramid") == 0) return PYRAMID;
	else return INVALID_SHAPE;
}

void Add()
{
	cout << "Enter the type of figure:\ncylinder cuboid cube pyramid\n";

	string t;
	cin >> t;
	SHAPE sh = stringToSHAPE(t);
	switch (sh)
	{
	case CYLINDER:
		double r, h;
		cout << "Radius: ";
		cin >> r;
		cout << "Height: ";
		cin >> h;
		fig_list->push_back(new Cylinder(r, h));
		break;
	case CUBOID:
		double l, w;
		cout << "Enter 3 dimentions: ";
		cin >> l >> w >> h;
		fig_list->push_back(new Cuboid(l, w, h));
		break;
	case CUBE:
		double edge;
		cout << "Edge: ";
		cin >> edge;
		fig_list->push_back(new Cube(edge));
		break;
	case PYRAMID:
		int n;
		double e;
		cout << "The amount of base vertices: ";
		cin >> n;
		cout << "Base edge lenght: ";
		cin >> e;
		cout << "Height: ";
		cin >> h;
		fig_list->push_back(new Pyramid(n, e, h));
		break;
	case INVALID_SHAPE:
		break;
	default:
		break;
	}
	cout << "Object added\n";
}

void Delete()
{
	if (fig_list->size() < 0)
	{
		cout << "No objects\n";
		return;
	}
	cout << "Enter a number from 0 to " << fig_list->size() - 1 << ": ";
	int num;
	cin >> num;
	if (0 <= num && num < fig_list->size())
		fig_list->erase(fig_list->begin() + num);
	else cout << "Invalid number\n";
}

void Info()
{
	if (fig_list->size() < 0)
	{
		cout << "No objects\n";
		return;
	}
	cout << "Enter a number from 0 to " << fig_list->size() - 1 << ": ";
	int  num;
	cin >> num;
	if (0<=num && num<fig_list->size())
		(*fig_list)[num]->info();
	else cout << "Invalid number\n";
	
}

void Info_all()
{
	for (int i = 0; i < fig_list->size(); i++)
	{
		cout << "#" << i << "\n";
		(*fig_list)[i]->info();
	}
}

void Help()
{
	cout << "Command list:\n\
Add\n\
Delete\n\
Exit\n\
Help\n\
Info\n\
Info_all\n";
}

int main()
{
	string s;
	CMD cmd;

	cout << "Enter command.\n";

	while (1)
	{
		cin >> s;
		cmd = stringToCMD(s);
		switch (cmd)
		{
		case ADD:
			Add();
			break;
		case DELETE:
			Delete();
			break;
		case INFO:
			Info();
			break;
		case INFO_ALL:
			Info_all();
			break;
		case HELP:
			Help();
			break;
		case EXIT:
			return 0;
		case INVALID_COMMAND:
			cout << "Unknown command. Use HELP for command list.\n";
			break;
		default:
			break;
		}
	}

	return 0;
}