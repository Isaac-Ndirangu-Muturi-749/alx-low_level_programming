#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "dog.h"

dog_t* new_dog(char* name, float age, char* owner)
{
	dog_t* new_dog = (dog_t*)malloc(sizeof(dog_t));

	if (new_dog == NULL)
		return (NULL); /* Return NULL if memory allocation fails */

	/* Allocate memory for name and owner strings */
	new_dog->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	new_dog->owner = (char*)malloc((strlen(owner) + 1) * sizeof(char));

	/* If memory allocation for strings fails,*/
	/*free previously allocated memory and return NULL */
	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog->owner);
		free(new_dog);
		return (NULL);
	}

	/* Copy name and owner strings */
	strcpy(new_dog->name, name);
	strcpy(new_dog->owner, owner);

	new_dog->age = age;

	return (new_dog);
}
