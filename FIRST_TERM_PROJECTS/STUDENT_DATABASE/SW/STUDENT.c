/*
 * STUDENT.c
 *
 *  Created on: Oct 14, 2022
 *      Author: MOSTAFA
 */
#include "STUDENT.h"

char info[20];char temp[20];char temp2[20];
FIFO_T* FIFO_TEMP;
int j, i=0;
DATABASE_STATUS FIFO_CRATE(FIFO_T* FIFO_BUF, SINFO_T* buf,int length)
{
	if (buf == NULL)
		return BUFFER_NULL;
	else
	{
		FIFO_BUF->length=length;
		FIFO_BUF->count=0;
		FIFO_BUF->base=buf;
		FIFO_BUF->head=buf;
		FIFO_BUF->tail=buf;
		PRINT("=======FIFO CREATED SUCCESFULLY=======\n");
		return FIFO_NO_ERROR;
	}
}

DATABASE_STATUS FIFO_IS_FULL(FIFO_T* FIFO_BUF)
{
	if (FIFO_IS_NULL(FIFO_BUF)==FIFO_NO_ERROR)
	{
		if (FIFO_BUF->count!=FIFO_BUF->length)
			return FIFO_NO_ERROR;
		else
			return FIFO_FULL;
	}
	else
		return FIFO_NULL;
}

DATABASE_STATUS FIFO_IS_NULL(FIFO_T* FIFO_BUF)
{
	if(FIFO_BUF->base==NULL && FIFO_BUF->head==NULL && FIFO_BUF->tail==NULL)
		return FIFO_NULL;
	else
		return FIFO_NO_ERROR;
}

DATABASE_STATUS FIFO_IS_EMPTY(FIFO_T* FIFO_BUF)
{
	if (FIFO_IS_NULL(FIFO_BUF)==FIFO_NO_ERROR)
	{
		if (FIFO_BUF->count)
			return FIFO_NO_ERROR;
		else
			return FIFO_EMPTY;
	}
	else
		return FIFO_NULL;
}
void add_student_manually(FIFO_T* FIFO_BUF, SINFO_T* buf)
{
	if(FIFO_IS_FULL(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER STUDENT INFORMATION: \n");
		PRINT("ENTER STUDENT ID: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<=FIFO_BUF->length;i++)
		{
			if(atoi(temp)==buf[i].roll)
				break;
		}
		if(i<=FIFO_BUF->length)
		{
			PRINT("THIS STUDENT IS ALREAEDY SIGNED \n");
		}
		else
		{
			FIFO_BUF->count ++;
			(FIFO_BUF->head->roll)=atoi(temp);
			PRINT("ENTER FIRST NAME: ");
			gets(info);
			strcat((FIFO_BUF->head->fname),info);
			PRINT("ENTER LAST NAME: ");
			gets(info);
			strcat((FIFO_BUF->head->lname),info);
			PRINT("ENTER GPA: ");
			gets(info);
			strcpy(temp,info);
			(FIFO_BUF->head->GPA)=atof(temp);
			PRINT("ENTER NUMBER OF COURSES: ");
			gets(info);
			strcpy(temp,info);
			for(i=0;i<atoi(temp);i++)
			{
				PRINT("ENTER COURSE %d ID: ",i+1);
				scanf("%d",&(FIFO_BUF->head->cid[i]));
			}
			if(FIFO_BUF->head == FIFO_BUF->base + (FIFO_BUF->length) * (sizeof(buf)))
			{
				FIFO_BUF->head=FIFO_BUF->base;
			}
			else FIFO_BUF->head ++;
		}
	}
	else if(FIFO_IS_FULL(FIFO_BUF)==FIFO_FULL)
	{
		PRINT("=======SCHOOL DATA BASE IS FULL=======\n");
	}
	else
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
}


void add_student_file(FIFO_T* FIFO_BUF, SINFO_T* buf)
{
	char x;
	if(FIFO_IS_FULL(FIFO_BUF)==FIFO_NO_ERROR)
	{

		FILE *FILEPTR=fopen("read.txt","r");
		for(;fscanf(FILEPTR,"%c",&x)!=EOF;)
		{
			PRINT("READ STUDENT INFORMATIONS FROM FILE: \n");
			PRINT("READ STUDENT ROLL: ");

			fscanf(FILEPTR,"%s ",info);
			PRINT("%s",info);
			strcpy(temp,info);
			for(i=0;i<=FIFO_BUF->length;i++)
			{
				if(atoi(temp)==buf[i].roll)
				{
					fscanf(FILEPTR,"%[^\n]",info);
					break;
				}
			}
			if(i<=FIFO_BUF->length)
			{
				PRINT("\nTHIS STUDENT IS ALREAEDY SIGNED \n");
			}
			else
			{
				FIFO_BUF->count ++;
				(FIFO_BUF->head->roll)=atoi(temp);
				PRINT("\nREAD FIRST NAME: ");
				fscanf(FILEPTR,"%s ",info);
				PRINT("%s",info);
				strcat((FIFO_BUF->head->fname),info);
				PRINT("\nREAD LAST NAME: ");
				fscanf(FILEPTR,"%s ",info);
				PRINT("%s",info);
				strcat((FIFO_BUF->head->lname),info);
				PRINT("\nREAD GPA: ");
				fscanf(FILEPTR,"%s ",info);
				PRINT("%s",info);
				strcpy(temp,info);
				(FIFO_BUF->head->GPA)=atof(temp);
				PRINT("\nREAD COURSES: \n");
				fscanf(FILEPTR,"%[^\n]",info);
				for(j=0,i=0;i<strlen(info);i++,j++)
				{
					(FIFO_BUF->head->cid[i])=atoi(&info[j]);
					j++;
				}
				if(FIFO_BUF->head == FIFO_BUF->base + (FIFO_BUF->length) * (sizeof(buf)))
				{
					FIFO_BUF->head=FIFO_BUF->base;
				}
				else FIFO_BUF->head ++;
			}
		}
	}
	else if(FIFO_IS_FULL(FIFO_BUF)==FIFO_FULL)
	{
		PRINT("=======SCHOOL DATA BASE IS FULL=======\n");
	}
	else
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
}









void find_r1(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER ROLL NUMBER: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<=FIFO_BUF->count;i++)
		{
			if(atoi(temp)==(FIFO_BUF->base)[i].roll)
				break;
		}
		if(i<=FIFO_BUF->count)
		{
			PRINT("STUDENT ROLL IS: %d \n",(FIFO_BUF->base)[i].roll);
			PRINT("STUDENT FIRST NAME IS: %s \n",(FIFO_BUF->base)[i].fname);
			PRINT("STUDENT LAST NAME IS: %s \n",(FIFO_BUF->base)[i].lname);
			PRINT("STUDENT GPA IS: %f \n",(FIFO_BUF->base)[i].GPA);
			for(j=0;j<10;j++)
			{
				if((FIFO_BUF->base)[i].cid[j]==0)
					break;
				PRINT("STUDENT COURSES IS: %d \t",(FIFO_BUF->base)[i].cid[j]);
				PRINT("\n");
			}
		}
		else
		{
			PRINT("=======THIS STUDENT IS NOT EXIST=======\n");
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}

void find_fn(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER STUDENT FIRST NAME: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<=FIFO_BUF->count;i++)
		{
			if( !(stricmp(temp, (FIFO_BUF->base)[i].fname)) )
				break;
		}
		if(i<FIFO_BUF->count)
		{
			PRINT("STUDENT ROLL IS: %d \n",(FIFO_BUF->base)[i].roll);
			PRINT("STUDENT FIRST NAME IS: %s \n",(FIFO_BUF->base)[i].fname);
			PRINT("STUDENT LAST NAME IS: %s \n",(FIFO_BUF->base)[i].lname);
			PRINT("STUDENT GPA IS: %f \n",(FIFO_BUF->base)[i].GPA);
			for(j=0;j<10;j++)
			{
				if((FIFO_BUF->base)[i].cid[j]==0)
					break;
				PRINT("STUDENT COURSES IS: %d \t",(FIFO_BUF->base)[i].cid[j]);
				PRINT("\n");
			}

		}
		else
		{
			PRINT("=======THIS STUDENT IS NOT EXIST=======\n");
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}

void find_c(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER COURSE ID: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<FIFO_BUF->count;i++)
		{
			for(j=0;j<10;j++)
			{
				if( (FIFO_BUF->base[i]).cid[j]==atoi(info) )
				{
					PRINT("\nSTUDENT NUMBER %d SIGNED IN THIS COURSE\n",i+1);
					PRINT("STUDENT ROLL IS: %d \n",(FIFO_BUF->base)[i].roll);
					PRINT("STUDENT FIRST NAME IS: %s \n",(FIFO_BUF->base)[i].fname);
					PRINT("STUDENT LAST NAME IS: %s \n",(FIFO_BUF->base)[i].lname);
					PRINT("STUDENT GPA IS: %f \n",(FIFO_BUF->base)[i].GPA);
				}
			}
		}
		if (i>=FIFO_BUF->count)
		{
			PRINT("=======NO STUDENT HAVE SIGNED IN THIS COURSE YET=======\n");
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}

void tot_s(FIFO_T* FIFO_BUF)
{
	PRINT("NUMBER OF STUDENTS IS: %d\n",FIFO_BUF->count);
}

void del_s(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER ROLL NUMBER: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<=FIFO_BUF->count;i++)
		{
			if(atoi(temp)==(FIFO_BUF->base)[i].roll)
				break;
		}
		if(i<FIFO_BUF->count)
		{
			PRINT("STUDENT ROLL IS: %d DELETED FROM DATA BASE\n",(FIFO_BUF->base)[i].roll);
			for(j=0;j<FIFO_BUF->count;j++,i++)
			{
				(FIFO_BUF->base)[i]=(FIFO_BUF->base)[i+1];
			}
			FIFO_BUF->count --;
			FIFO_BUF->head --;
		}
		else
		{
			PRINT("=======THIS STUDENT IS NOT EXIST=======\n");
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}

void up_s(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		PRINT("ENTER ROLL NUMBER: ");
		gets(info);
		strcpy(temp,info);
		for(i=0;i<=FIFO_BUF->count;i++)
		{
			if(atoi(temp)==(FIFO_BUF->base)[i].roll)
				break;
		}
		if(i<FIFO_BUF->count)
		{
			char choice;
			PRINT("CHANGE FIRST NAME-->ENTER F\n");
			PRINT("CHANGE LAST NAME-->ENTER L\n");
			PRINT("CHANGE ROLL-->ENTER R\n");
			PRINT("CHANGE GPA-->ENTER G\n");
			PRINT("CHANGE COURSES-->ENTER C\n");
			PRINT("ENTER YOUR CHOICE: ");
			choice=getchar();
			switch(choice)
			{
			case 'f':
			case 'F':
				PRINT("ENTER FIRST NAME: ")
				gets(info);
				strcpy((FIFO_BUF->base)[i].fname,info);
				break;
			case 'l':
			case 'L':
				PRINT("ENTER LAST NAME: ")
				gets(info);
				strcpy((FIFO_BUF->base)[i].lname,info);
				break;
			case 'r':
			case 'R':
				PRINT("ENTER NEW ROLL: ")
				gets(info);
				(FIFO_BUF->base)[i].roll=atoi(info);
				break;
			case 'g':
			case 'G':
				PRINT("ENTER NEW GPA: ")
				gets(info);
				(FIFO_BUF->base)[i].GPA=atof(info);
				break;
			case 'c':
			case 'C':
				PRINT("ENTER NUMBER OF COURSES: ");
				gets(info);
				strcpy(temp,info);
				for(i=0;i<atoi(temp);i++)
				{
					PRINT("ENTER COURSE %d ID: ",i+1);
					scanf("%d",&(FIFO_BUF->base->cid[i]));
				}
				break;
			default:
				break;
			}
		}
		else
		{
			PRINT("=======THIS STUDENT IS NOT EXIST=======\n");
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}

void show_s(FIFO_T* FIFO_BUF)
{
	if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_NO_ERROR)
	{
		for(i=0;i<FIFO_BUF->count;i++)
		{
			PRINT("STUDENT ROLL IS: %d \n",(FIFO_BUF->base)[i].roll);
			PRINT("STUDENT FIRST NAME IS: %s \n",(FIFO_BUF->base)[i].fname);
			PRINT("STUDENT LAST NAME IS: %s \n",(FIFO_BUF->base)[i].lname);
			PRINT("STUDENT GPA IS: %f \n",(FIFO_BUF->base)[i].GPA);
			for(j=0;j<10;j++)
			{
				if((FIFO_BUF->base)[i].cid[j]==0)
					break;
				PRINT("STUDENT COURSES IS: %d \t",(FIFO_BUF->base)[i].cid[j]);
				PRINT("\n");
			}
		}
	}
	else if(FIFO_IS_EMPTY(FIFO_BUF)==FIFO_EMPTY)
	{
		PRINT("=======FIFO IS EMPTY=======\n");
	}
	else
	{
		PRINT("=======SCHOOL DATA BASE IS NOT CREATED========\n");
	}
}
