#include <iostream>
#include <memory>
#include <vector>
#include <Windows.h>
#include <chrono>

#include "Animal.h"

using namespace std;

#define MANUAL false

vector<Animal> fillPopulation(int size);

int main()
{
	srand(time(NULL));
	int population_size;
	cout << "Enter population size: ";
	cin >> population_size;
	vector<Animal> population;
	population.reserve(population_size);
    population = fillPopulation(population_size);

	while (true)
	{
		if (MANUAL) cin.get();
		if (GetAsyncKeyState(VK_SPACE)) break;

		//Generate random animal index
		int animal1 = rand() % population.size();
		int animal2 = rand() % population.size();

		//Check if index is invalid. I true, generate new indices
		while (animal1 == animal2 || population[animal1].getType() == nil || population[animal2].getType() == nil)
		{
			animal1 = rand() % population.size();
			animal2 = rand() % population.size();
		}

		//Check if the animals are of different type. If true, delete the fish entity.
		if (population[animal1].getType() != population[animal2].getType()) {
			if (population[animal1].getType() == fish)
				population[animal1] = Animal(nil, male, 0);
			else population[animal2] = Animal(nil, male, 0);
		}
		//If the animals are the same type, check if they are of different genders. If true, add a new entity.
		else if (population[animal1].getGender() != population[animal2].getGender())
		{
			if (rand() % 2 == 0) {
				for (auto& animal : population)
				{
					if (animal.getType() == nil) {
						population.push_back(Animal(population[animal1].getType(), male, rand() % 100));
						break;
					}
				}
			}
			else { 
				for (auto& animal : population)
				{
					if (animal.getType() == nil) {
						population.push_back(Animal(population[animal1].getType(), female, rand() % 100));
						break;
					}
				}
			}
		}
		//Deletes the weaker entity.
		else
		{
			if (population[animal1].getStrength() == population[animal2].getGender());
			else if (population[animal1].getGender() < population[animal2].getGender())
				population[animal1] = Animal(nil, male, 0);
			else population[animal2] = Animal(nil, male, 0);
		}

		int bears_count = 0;
		int fish_count = 0;

		for (auto& animal : population)
		{
			if (animal.getType() == bear) bears_count++;
			else if (animal.getType() == fish) fish_count++;
		}
		cout << "Amount of bears: " << bears_count << endl;
		cout << "Amount of fish: " << fish_count << endl << endl;
		if (bears_count < 2) {
			cout << "No more bears left!" << endl;
			break;
		}
		if (fish_count < 2) {
			cout << "No more fish left!" << endl;
			break;
		}
	}
}


vector<Animal> fillPopulation(int size) {
	vector<Animal> tmp_population;
	tmp_population.reserve(size);
	for (int i = 0; i < size; i++)
	{
		switch (rand() % 3) {
		case 0:
			if (rand() % 2 == 0) tmp_population.push_back(Animal(bear, male, rand() % 100));
			else tmp_population.push_back(Animal(bear, female, rand() % 100));
			break;
		case 1:
			if (rand() % 2 == 0) tmp_population.push_back(Animal(fish, male, rand() % 100));
			else tmp_population.push_back(Animal(fish, female, rand() % 100));
			break;
		case 2:
			tmp_population.push_back(Animal(nil, female, 0));
			break;
		}
	}
	return tmp_population;
}