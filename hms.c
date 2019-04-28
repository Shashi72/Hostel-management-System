#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j,main_exit;
void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void closer();

struct date{
 int month,day,year;
};

struct{
    char name[60];
    int age;
    char city[60];
    char mail_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    char hostel_name[6];
    int roll_no;
    struct date dob;
}add,upd,rem,sort,qwe[100],temp;
int check;    
int main()
{
	pass();
	menu();
	return 0;
}

int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	
    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0; 
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		system("PAUSE");
		a++;
		
		getch();
		
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		
		getch();
		
		}
		system("cls");	
}

void menu()
{  
system("CLS");
    int choice;
    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> Removing existing account\n\t\t5>> View all students list\n\t\t6>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:view_list();
        break;
        case 6:closer();
        break;
        default:menu();
    }
}

void new_entry()
{system("CLS");
    int choice;
    FILE *ptr,*hostel;
    ptr=fopen("record.dat","a+");
    roll_no:
    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%d",&check);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, &add.mail_id, &add.father_name, &add.father_phone, &add.room_no, &add.hostel_name)!=EOF)
    {
        if (check==add.roll_no)
            {printf("Students roll no. already in use!");
             goto roll_no;
        }
    }
    add.roll_no=check;
    printf("\nEnter the name:");
    scanf("%s",&add.name);
	int z=1;
	while(z!=0){
	int mm,dd,y;  
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d/%d/%d",&mm,&dd,&y);
    if(y>=1900 && y<=9999)
	{
	if(mm>=1 && mm<=12)
	{
  	if(((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)) || ((dd>=1 && dd<=30)&&(mm==4 || mm==6 || mm==9 || mm==11)) || ((dd>=1 && dd<=28) && (mm==2)) || (dd==29 && mm==2 && (y%400==0 || (y%4==0 && y%100!=0))))
  	{
	add.dob.month=mm;
	add.dob.year=y;
	add.dob.day=dd;
   	}
  	else
  	{printf("Day is invalid.\n");
	continue;
	}
  	}
  	else
	{printf("Month is not valid.\n");
	continue;}
	}
	else
    {
        printf("Year is not valid.\n");
		continue;
    }        
	z=0;
	}
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the city:");
    scanf("%s",&add.city);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n Enter your email id :");
    scanf("%s",&add.mail_id);
    printf("\n Enter your Father's name:");
    scanf("%s",&add.father_name);
    printf("\n Enter your Father's phone no.:");
    scanf("%d",&add.father_phone);
    printf("\n Enter your room no.:");
    scanf("%s",&add.room_no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",&add.hostel_name);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            closer();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void edit()
{
	system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",upd.roll_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail_id, &add.father_name, &add.father_phone, &add.room_no, &add.hostel_name)!=EOF)

    {
        if (add.roll_no==upd.roll_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);
            
            if(choice==1)
                {
				printf("Enter the new room no.:");
                scanf("%s",&upd.room_no);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, upd.room_no, add.hostel_name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

	if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    
    edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);  
        if (main_exit==1)
			menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;
        }
}

void see()
{int i,j,k=0;
	system("CLS");
    FILE *ptr;
    int test=0;
    ptr=fopen("record.dat","r");
    printf("\n\nEnter the roll number:");
    scanf("%d",&check);
	while (fscanf(ptr,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail_id, &add.father_name, &add.father_phone, &add.room_no, &add.hostel_name)!=EOF)
    {
    	
    	qwe[k]=add;
    	k++;
        
    }
    for (i=k-1;i>=0;--i){
    		for(j=0;j<i;++j){
				if(qwe[j].roll_no>qwe[j+1].roll_no){
					temp=qwe[j];
					qwe[j]=qwe[j+1];
					qwe[j+1]=temp;
				}
    	    }		
		}
		printf("shortest %d  largest %d",qwe[0].roll_no,qwe[k-1].roll_no);
		
	int first=0,last=k-1,mid=(first+last)/2;
	while(first<=last){
		if(qwe[mid].roll_no < check){
			first = mid+1;
		} 
		else if(qwe[mid].roll_no == check){
			test=1;
            printf("\nROLL NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            break;
		}
		else 
			last = mid-1;
			
		mid = (first+last)/2;
		
	}	
    	
    fclose(ptr);
	if(test!=1)
     	printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {	
        	printf("\nInvalid!\a");
            goto see_invalid;
		}
}

void erase()
{
	system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll no. of student whose data you want to delete:");
    scanf("%d",&rem.roll_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail_id, &add.father_name, &add.father_phone, &add.room_no, &add.hostel_name)!=EOF)
   {
        if(add.roll_no!=rem.roll_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
	    printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {	
        	printf("\nInvalid!\a");
            goto erase_invalid;
		}
}

void view_list()
{
	system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    printf("\nROLL NO.\t\tNAME\tDOB\t\tAGE\t\tCITY\t\tPHONE NO.\tEmail ID\t\tFATHER NAME\t\tFATHER PHONE NO.\t\tROOM NO.\tHOSTEL\n");
    while(fscanf(view,"%d %s %d/%d/%d %d %s %d %s %s %d %s %s\n",&add.roll_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, &add.city, &add.phone, &add.mail_id, &add.father_name, &add.father_phone, &add.room_no, &add.hostel_name)!=EOF)
       {
           printf("\n%d\t%10s\t%d/%d/%d\t%d\t %10s\t%d\t%15s\t%10s\t%d\t%5s\t%5s\n",add.roll_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.city,add.phone,add.mail_id,add.father_name,add.father_phone,add.room_no,add.hostel_name);
           test++;
       }
    fclose(view);
    if (test==0)
        {   
            printf("\nNO RECORDS!!\n");
		}
    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void closer()
{
	system("CLS");
    printf("\n\nTHANK YOU!");
}
