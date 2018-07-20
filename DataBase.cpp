//Student DataBase//


#include<stdio.h>
#include<string.h>
#include<conio.h>



int menu();

void enter();

void search_id();

void display_all();

void del();




struct data
{
char name[10];
int id;
char email[30];
long int contuct_number;
};


int main()
{
int choice;

choice=menu();//call function//
switch(choice)
{
case 1:enter();//call function//
break;
case 2:search_id();
break;
case 3:display_all();
break;
case 4:del();



}
}


int menu()//function//

{
int i;
int menu_ans;



    printf("GIVE CHOICE--\n");
             printf("   1 TO ENTER STUDENT INFO.\n");

             printf("   2 To SEARCH \n");
              printf("   3 To DISPLAY \n");

printf("   4 To DELETE \n");

scanf("%d",&menu_ans);
return menu_ans;
}




void enter(void)//function//

{

int i,id1=0;
char again;

struct data input[30];





        FILE *save;

save=fopen("save.txt","a");


for(i=0;i<1;i++)
{

printf("Enter The Name-\n");
      scanf("%s",&input[i].name);


        printf("enter student id-");

                scanf("%d",&input[i].id);



   printf("Enter The Email-\n");
      scanf("%s",&input[i].email);


        printf("enter student Contuct_Number");

                scanf("%d",&input[i].contuct_number);



            fprintf(save,"%d\t",input[i].id);

            fprintf(save,"%s\t",input[i].name);

            fprintf(save,"%s\t",input[i].email);

            fprintf(save,"%d\n",input[i].contuct_number);



}
fclose(save);
}





void search_id(void)
{
	
	
	
	
int i,id;
struct data output;
FILE *save;
save=fopen("save.txt","r");
printf("enter your id");
scanf("%d",&id);
while (!feof(save))
{

    

fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,output.contuct_number);




if(id==output.id)
    {
printf(" %d\n ",output.id);
printf(" %s \n",output.name);
printf(" %s \n",output.email);
printf(" %s \n",output.contuct_number);
}
break;
printf("not found");


}



}





void display_all()

{


int i,id;
struct data output;
FILE *save;
save=fopen("save.txt","r");
printf("Display All Data\n");


fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,output.contuct_number);


    {
    	
    	
    	
printf(" %d\n ",output.id);
printf(" %s \n",output.name);
printf(" %s \n",output.email);
printf(" %s \n",output.contuct_number);
}



}




void del()



{
	
		
	
int i,id;
struct data del;
FILE *save;
save=fopen("save.txt","r+");
printf("enter your id");
scanf("%d",&id);
int ab=00;
int bd; 
 i=0;
while (!feof(save))
{

   

fscanf(save,"%d\t%s\t%s\t%d\n",&del.id,del.name,del.email,del.contuct_number);

//	fprintf(save,strset(del.id,ab));


if(id==del.id)
    {
    	
    	
    	del.id=00;
    //	bd=strset(del.id,ab);
    
     
        
        
fprintf(save,"%d",del.id);
	break;
	

}
fclose(save);

      }
}
