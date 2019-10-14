#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

struct data{
	int month;
	int day;
	int year;
};

struct human_being{
	char name[10];
	int age;
	float salary;
	struct data dob;
};

typedef struct{
	int sex;
	union{
		int children;
		int beard;
	}u;
}sex_type;

int HumanEqual(struct human_being person1,struct human_being person2);

void main(void)
{
	struct human_being person1,person2;

	strcpy(person1.name,"James");
	person1.age = 18;
	person1.salary = 30000;
	person1.dob.month = 2;
	person1.dob.day = 11;
	person1.dob.year = 2001;

	strcpy(person2.name,"Jos");
	person1.age = 18;
	person1.salary = 30000;
	person1.dob.month = 3;
	person1.dob.day = 18;
	person1.dob.year = 1999;

	if(HumanEqual(person1,person2))
		printf("The same!\n");
	else
		printf("Not the same!\n");

	sex_type person3;
	person3.sex = 1;
	person3.u.beard = 0;
	person3.u.children = 1;

	printf("Setting of beard : %d\n",person3.u.beard);
	if(person3.sex == 0)
	{
		printf("Female\n");
		if(person3.u.children == 1)
			printf("Girl\n");
		else
			printf("Woman\n");
	}
	else
	{
		printf("Male\n");
		if(person3.u.children == 1)
			printf("Boy\n");
		else
			printf("Man\n");
	}
}

int HumanEqual(struct human_being person1,struct human_being person2)
{
	if(strcmp(person1.name,person2.name))
		return FALSE;
	if(person1.age != person2.age)
		return FALSE;
	if(person1.salary != person2.salary)
		return FALSE;
	return TRUE;
}
