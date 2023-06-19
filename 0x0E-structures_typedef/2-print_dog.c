#include <stdio.h>

struct dog {
	char* name;
	float age;
	char* owner;
};

void print_dog(struct dog* d)
{
	if (d == NULL)
		return;

	printf("%s\n", d->name != NULL ? d->name : "(nil)");
	printf("%.1f\n", d->age);
	printf("%s\n", d->owner != NULL ? d->owner : "(nil)");
}
