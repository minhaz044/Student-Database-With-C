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
void password();
void modify_student();
void change_password();




struct data
{
     char name[10];
     int id;
     char email[30];
     long int contuct_number;
     long int password;
};


int main()//Main Function//

{

    int choice,c;
    

	    {
	 			 	
            choice=menu();//call function//
		 	 
                switch(choice)
    
                    {  
        	
                        case 1:enter();//call function//
                        break;
                        case 2:search_id();//call function//
                        break;
                        case 3:display_all();//call function//
                        break;
                        case 4:modify();//call function//
                        break;
                        case 5:exit();//call function//
                        break;     
                        defualt:
                        break;
   
                    }
		}
}


//**********************************************************************************************************************************************************//

int menu()//function//

{


    int i;
    int menu_ans;



    printf("-------GIVE CHOICE--------\n\n");

            printf("   1 TO ENTER STUDENT INFO.\n");
            printf("   2 To SEARCH \n");
            printf("   3 To DISPLAY \n");
            printf("   4 TO MODIFY DATA\n");
            printf("   5 To EXIT \n");


    scanf("%d",&menu_ans);

    return menu_ans;

}


//********************************************************************************************************************************************************//

void enter(void)//function//

{

    int i;
    int c;
    char again;

    struct data input[30];



        FILE *save;

        save=fopen("save.txt","a");//open file//


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
                     
             
			          
                    fprintf(save,"%d\t",input[i].id);//print data in file//
                    fprintf(save,"%s\t",input[i].name);//print data in file//
                    fprintf(save,"%s\t",input[i].email);//print data in file//
                    fprintf(save,"%d\n",input[i].contuct_number);//print data in file//


                }
        fclose(save);//close file//


}


//***********************************************************Function For Search*******************************************************************************//

void search_id(void)
{
 
    int i,id;
    struct data output;
	   
    
        FILE *save;//file pointer//
         
        save=fopen("save.txt","r");//open file//
     
        printf("ENTER YOUR ID");
        scanf("%d",&id);





        while(!feof(save))
            {


                fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,&output.contuct_number);//data import from file//


                    if(id==output.id)           
                        {
                            printf("\n  ID= %d\n\n ",output.id);
                            printf(" NAME=%s\n\n",output.name);
                            printf("  EMAIL=%s\n\n",output.email);
                            printf("  CONTUCT NUMBER=%d \n\n",output.contuct_number);
                            break;
                        }
                   


            }  



}



//***********************************************Function For Display All Data*****************************************************************//

void display_all()

{



    int id;
    struct data output;
    
        FILE *save;
        
        save=fopen("save.txt","r");

        printf("  Display All Data\n\n**********************************************************\n");

            while(!feof(save))
			    {

                    fscanf(save,"%d\t%s\t%s\t%d\n",&output.id,output.name,output.email,&output.contuct_number);


                    printf("  ID= %d\n\n ",output.id);
                    printf(" NAME= %s\n\n",output.name);
                    printf("  EMAIL= %s\n\n",output.email);
                    printf("  CONTUCT NUMBER= %d\n\n\n",output.contuct_number);


                


                }


}



//***********************************************Function For Delete Data************************************************************************************************//



void del()

{


    int id;

    struct data del; 
    
        FILE *save,*file; // here previous file is save and new file name is file//
        
    save=fopen("save.txt","r");
    file=fopen("file.txt","w");
    printf("\nEnter your id-");
    scanf("%d",&id);

        while (!feof(save))
  
            {

                fscanf(save,"%d\t%s\t%s\t%d\n",&del.id,del.name,del.email,&del.contuct_number);

                    if(del.id!=id)
                {

                    fprintf(file,"%d\t%s\t%s\t%d\n",del.id,del.name,del.email,del.contuct_number);
                }
                
            }
            
        fclose(file);
        fclose(save);


        remove("save.txt");
        rename("file.txt","save.txt");


        printf("\nfile deleted\n\n");

}

//**********************************************Function For Modify Data*************************************************************************//

void modify()


{


    int student_teacher,new_password,choice1,password;
    
        struct data modify;
       
        
        printf("  1  STUDENT(s)\n  2  TEACHER(T)\n");
        scanf("%d",&student_teacher);
        
        
      if(student_teacher==2)
	  {
	     
	             printf("Enter the password");
	                 scanf("%d",&new_password);

	         
	         
	         modify.password=12345;
	           
	            if(modify.password==new_password)
	                {
	                	
	                		printf("  1 TO MODIFY STUDENT DATA ");
	        
	                        printf("   2 To REMOVE DATA \n");
	                        
	                        scanf("%d",&choice1);
	                        
	                        switch(choice1)
	                             
								{
								 	
								 	case 1:modify_student();
								 	break;
								 	case 2:del();
								 	break;
								 	default:
								 	break;
								 	
				            	}	
					}   	
				
	            
	            
	    } 
	            
	            
     if(student_teacher==1)	            
	    {
	    	printf("SEARCH WITHOUT MODIFY OPTION (restricted )\n");
			 }     
	            

}	       	
	 //**************************************************************************************************************    
void modify_student()
	     
	        {
	        	    int id;
			
			        struct data modify;
							  
		            FILE *save, *file; 
		            save=fopen("save.txt","r+");
		            
                    file=fopen("file.txt","w+");
             

                    printf("\nENTER THE ID WHICH YOU WANT TO MODIFY-");
                    scanf("%d",&id);
                    
                   
     
                        while(!feof(save))

                            {
                           
                                fscanf(save,"%d\t%s\t%s\t%d\n",&modify.id,modify.name,modify.email,&modify.contuct_number);
                
                                    if(modify.id==id)

                                        {
                
                                            printf("Enter The Name-\n");
                                            scanf("%s",modify.name);

                                            printf("Enter student id-\n");
                                            scanf("%d",&modify.id);

                                            printf("Enter The Email-\n");
                                            scanf("%s",&modify.email);

                                            printf("Enter student Contuct_Number-\n");
                                            scanf("%d",&modify.contuct_number);

                                            fprintf(file,"%d\t%s\t%s\t%d\n",modify.id,modify.name,modify.email,modify.contuct_number);

                                        }
                                        
                                    else
                                    
                                        {

                                            fprintf(file,"%d\t%s\t%s\t%d\n",modify.id,modify.name,modify.email,modify.contuct_number);

                                        }

                            }
            
            
                fclose(file);
                
                fclose(save);

                remove("save.txt");
                
                rename("file.txt","save.txt");

                printf("\nDATA  MOdified\n");
      
}
	

void exit()
{
	


}


