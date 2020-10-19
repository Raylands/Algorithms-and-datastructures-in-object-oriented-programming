#pragma once

enum gender { male, female };
enum type { nil = -1, bear, fish};

class Animal
{
public:
	Animal(type type, gender gender, float strength) : type(type), gender(gender), strength(strength) {};

	const type& getType() { return type; };
	const gender& getGender() { return gender; };
	const float& getStrength() { return strength; };

private:
	type type;
	gender gender;
	float strength;
};