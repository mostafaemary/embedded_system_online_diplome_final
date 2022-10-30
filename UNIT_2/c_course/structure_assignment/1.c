/*
 *      Author: Mostafa Emary
 */
#include "stdio.h"
#include "stdlib.h"
struct student_data {

	char name[100];
	int roll;
	float marks;

};
struct student_data read_data(struct student_data x)
{
	struct student_data y;
	printf("enter student name: ");
	fflush (stdout);
	scanf("%s",x.name);
	printf("enter student roll: ");
	fflush (stdout);
	scanf("%d",&x.roll);
	printf("enter student marks: ");
	fflush (stdout);
	scanf("%f",&x.marks);
	y=x;
	return y;
}
void display_data(struct student_data x)
{
	printf("student name is: %s \r\n",x.name);
	printf("student roll is: %d \r\n",x.roll);
	printf("student marks is: %f \r\n",x.marks);
}
int main()
{
	struct student_data x;

//without founction
/*	printf("enter student name: ");
	fflush (stdout);
	scanf("%s",x.name);
	printf("enter student roll: ");
	fflush (stdout);
	scanf("%d",&x.roll);
	printf("enter student marks: ");
	fflush (stdout);
	scanf("%f",&x.marks);
	printf("student name is: %s \r\n",x.name);
	printf("student roll is: %d \r\n",x.roll);
	printf("student marks is: %f \r\n",x.marks);
*/
	//with functions
	struct student_data y;
	y=read_data(x);
	display_data(y);
	return 0;
}


