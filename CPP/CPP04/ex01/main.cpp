#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	unsigned int	b = 4;
	Animal*			tab[b];

	for (unsigned int a = 0; a < (b / 2); a++)
		tab[a] = new Dog();
	for (unsigned int a = (b / 2); a < b; a++)
		tab[a] = new Cat();
	for (unsigned int a = 0; a < b; a++)
		delete tab[a];

	// delete j;//should not create a leak
	// delete i;

	return 0;
}
