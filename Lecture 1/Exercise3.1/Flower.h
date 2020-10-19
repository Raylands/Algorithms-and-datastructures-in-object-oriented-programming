#pragma once

#include <iostream>

using namespace std;

class Flower
{
private:
	string name;
	int pedals;
	float price;

public:
	Flower(string name, int pedals, float price) : name(name), pedals(pedals), price(price) {};

	void SetName(string name) { this->name = name; };
	const string& GetName() const { return name; };

	void SetPedals(int pedals) { this->pedals = pedals; };
	const int& GetPedals() const { return pedals; };

	void SetPrice(float price) { this->price = price; };
	const float& GetPrice() const { return price; };
};