#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
#include "main.h"

/**
 * init_dog - a function that initialize a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 */
void init_dog(struct dog* d, char* name, float age, char* owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
