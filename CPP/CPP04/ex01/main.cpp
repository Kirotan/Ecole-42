#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal* tab[10];

	for (int a = 0; a < 5; a++)
		tab[a] = new Dog();
	for (int a = 5; a < 10; a++)
		tab[a] = new Cat();
	for (int a = 0; a < 10; a++)
		delete tab[a];

	delete j;//should not create a leak
	delete i;

	return 0;
}
