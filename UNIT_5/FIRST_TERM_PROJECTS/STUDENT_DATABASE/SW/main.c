/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MOSTAFA
 */
#include "STUDENT.h"
unsigned char x;
FIFO_T fifo;
SINFO_T m[50];
int main()
{
	FIFO_CRATE(&fifo, m ,50);
	PRINT("WELCOME TO THE STUDENT MANAGMENT SYSTEM\n")
	while(1)
	{
		PRINT("Chose the Task you want to Perform: \n")
		PRINT("1.Add Student MANUALLY \n")
		PRINT("2.Add Student FROM FILE\n")
		PRINT("3. Find Student By Roll Number\n")
		PRINT("4. Find Student By FIRST Name \n")
		PRINT("5. Find Student By Course ID \n")
		PRINT("6. Find TOTAL OF Number Students \n")
		PRINT("7. DELETE Student By Roll Number\n")
		PRINT("8. UPDATE Student By Roll Number\n")
		PRINT("9. SHOW All Information\n")
		PRINT("10. EXIT\n")
		PRINT("ENTER YOUR CHOICE: ")
		scanf("%d",&x);

		if(x==1)
		{
			add_student_manually(&fifo, m);
		}
		else if(x==2)
		{
			add_student_file(&fifo, m);
		}

		else if(x==3)
		{
			find_r1(&fifo);
		}
		else if(x==4)
		{
			find_fn(&fifo);
		}

		else if(x==5)
		{
			find_c(&fifo);
		}

		else if(x==6)
		{
			tot_s(&fifo);
		}

		else if(x==7)
		{
			del_s(&fifo);
		}

		else if (x==8)
		{
			up_s(&fifo);
		}

		else if(x==9)
		{
			show_s(&fifo);
		}
		else if(x==10)
		{
			PRINT("EXIT SYSTEM\n")
			break;
		}
		else
		{
			PRINT("FALSE CHOICE PLEASE ENTER ANOTHER CHOICE\n")
		}
	}
	return 0;
}
