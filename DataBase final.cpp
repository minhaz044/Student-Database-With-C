//Student DataBase//


#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>



int menu();
void enter();
void search_id();
void display_all();
void del();
void exit();
void modify();




struct data
{
	char name[10];
	int id;
	char email[30];
	long int contuct_number;
};


int main()
{



	int choice,c;
		//while(1)
		{

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
break;
case 5:modify();
break;
case 6:exit();
break;
defualt:
break;



}
}
}


int menu()//function//

{


int i;
int menu_ans;



    printf("-------GIVE CHOICE--------\n\n");

            printf("   1 TO ENTER STUDENT INFO.\n");

            printf("   2 To SEARCH \n");

            printf("   3 To DISPLAY \n");

            printf("   4 To REMOVE \n");

            printf("   5 TO MODIFY DATA\n");

            printf("   6 To EXIT \n");



scanf("%d",&menu_ans);

return menu_ans;

}




void enter(void)//function//

{



int i;
int c;
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

  
         menu();
    

}





void search_id(void)
{




    int i,id;
    struct data output;
    FILE *save;
    save=fopen("save.txt","r");
    printf("enter your id");
    scanf("%d",&id);




        while(!feof(save))
            {

            fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,&output.contuct_number);

                if(id==output.id)
                    {
                        printf(" %d\n ",output.id);
                        printf(" %s \n",output.name);
                        printf(" %s \n",output.email);
                        printf(" %d \n",output.contuct_number);
                        }

            }

}





void display_all()

{



int i,id,again;
struct data output;
FILE *save;
save=fopen("save.txt","r");


printf("Display All Data\n**********************************************************\n");

while (!feof(save)){

fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,&output.contuct_number);


    {



printf("ID= %d\n\n ",output.id);
printf("NAME= %s \n\n",output.name);
printf("EMAIL= %s \n\n",output.email);
printf("CONTUCT NUMBER= %d \n\n\n",output.contuct_number);


}


}
    menu();

}








void del()

{




int id,again;
int c;
char b;
int d;
struct data del;
FILE *save,*file; 
save=fopen("save.txt","r");


file=fopen("file.txt","w");


printf("\nEnter your id-");


scanf("%d",&id);





      

while (!feof(save))

        

{

 fscanf(save,"%d\t%s\t%s\t%d\n",&del.id,del.name,del.email,&del.contuct_number);


   


  

  if(del.id!=id)
  {




fprintf(file,"%d\t%s\t%s\t%d\n",del.id,del.name,del.email,del.contuct_number);// printing in  "file.txt"    but \n is not printing




 }




      }
      fclose(file);

      fclose(save);


   remove("save.txt");




   rename("file.txt","save.txt");


          printf("\nfile deleted\n\n");
      menu();
}





























void modify()


{




int id,again;
int c;
char b;
int d;
struct data modify;
FILE *save,*file; // here your previous file is save and new file name is file
save=fopen("save.txt","r");


file=fopen("file.txt","w");


printf("\nEnter your id-");


scanf("%d",&id);


      
while (!feof(save))

       

{

 fscanf(save,"%d\t%s\t%s\t%d\n",&modify.id,modify.name,modify.email,&modify.contuct_number);



  if(modify.id==id)



  {


  	printf("Enter The Name-\n");
      scanf("%s",modify.name);


        printf("enter student id-");

                scanf("%d",&modify.id);



   printf("Enter The Email-\n");
      scanf("%s",&modify.email);


        printf("enter student Contuct_Number");

                scanf("%d",&modify.contuct_number);


fprintf(file,"%d\t%s\t%s\t%d\n",modify.id,modify.name,modify.email,modify.contuct_number);


  }

  else
  {




fprintf(file,"%d\t%s\t%s\t%d\n",modify.id,modify.name,modify.email,modify.contuct_number);// printing in  "file.txt"    but \n is not printing




 }


      }
      fclose(file);

      fclose(save);


   remove("save.txt");

   rename("file.txt","save.txt");


          printf("\nFile MOdified");

menu();
}


































void exit()
{
	
	          printf("----------press ENTER to exit------------- ");

   exit(0);
}


