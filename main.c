//Name : Md. Tahmidur Rahman
//ID : 1721370642

//Name : Shah Alvi Hossain
//ID : 1721427642


#include<stdio.h>
#include<string.h>

//Making A Structure With Necessary Things For Students Information In It.
struct student
{
    char name[30],fac[6],room[7];
    int id,st[6],mw[6],ra[6];
};

//Prototype Of Necessary Functions.
int main2();
int result();
int searchstudents();
void writeresult(char faculty[6],int stco[6],int raco[6],int mwco[6],int n);
void printresult(int n,int stco[6],int raco[6],int mwco[6]);

//Main Function Starts.
int main()
{
    int choice2=0,choice1=0;
    int i;
    char ans;

    while(choice2==0)
    {
        printf("\t\t*** Welcome To Extra Class Schedule Maker ***\n\n");
        printf("How To Use This Program : Press 'Y' To Select And Press 'N' To Cancel.\n");
        printf("You Have To Follow The Given Instructions Properly Or The Program Won't Work.\n\n");

        printf("\t\t\t    Main Menu\n");
        printf("\t\tPress 1 To Start A New Calculation.\n");
        printf("\t\tPress 2 To See The Last Calculation.\n");
        printf("\t\tPress 3 To Search A Student Schedule.\n");
        printf("\t\tPress 4 To EXIT.\n\n\t\t");
        scanf("%d",&choice1);

        system("cls");

        if(choice1==1)
        {
            choice2=main2();
        }
        else if(choice1==2)
        {
            choice2=result();
        }
        else if(choice1==3)
        {
            choice2=searchstudents();
        }
        else if(choice1==4)
        {
            choice2=1;
        }
        printf("\n\n");
    }

    printf("Thanks For Using This Program. Press Any Key To Continue......");

    fflush(stdin);
    scanf("%c",&ans);


    return 0;

    //End Of Program.
}

int main2()
{
    int i,j,k,n,temp,ask2=2;                     //Necessary INT For Loops.
    int stco[6],raco[6],mwco[6];          //Necessary INT To Count Free Time Of ST,MW & RA ( CO Is Short Form Of Count ).
    char faculty[6],ans,nametemp[30],txt[]={'.','t','x','t','\0'};         //Char Named TXT Is To Add txt Extension To Name Char.
    FILE *fp;



    //Gets The Name Of The Faculty.
    fflush(stdin);
    printf("Under Which Faculty The Search Is Done? : ");
    gets(faculty);
    printf("\n");



    printf("How many students present Today? ");


    //Scanning The Number Of Students.
    scanf("%d",&n);
    struct student stu[n];


    //This Is To Fill All ST RA and MW With A Number Which Is Not Between 0 to 5
    //Marking All st[] Value 8
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            stu[i].st[j]=8;
        }
    }


    //Marking All mw[] Value 8
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            stu[i].mw[j]=8;
        }
    }


    //Marking All ra[] Value 8
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            stu[i].ra[j]=8;
        }
    }



    //Making The Value Of STCO RACO And MWCO Zero.
    for(i=0;i<6;i++)
    {
        stco[i]=0;
    }
    for(i=0;i<6;i++)
    {
        raco[i]=0;
    }
    for(i=0;i<6;i++)
    {
        mwco[i]=0;
    }

    system("cls");

    //Every Student Input Starts.
    for(i=0;i<n;i++)
    {


        fflush(stdin);
        printf("\nGive The information of student #%d\n",i+1);
        printf("\n");


        //Gets Name Of The Student
        printf("Name : ");
        gets(stu[i].name);


        //Add's .txt Extension To The Name
        strcpy(nametemp,stu[i].name);
        strcat(nametemp,txt);


        //Gets ID Of Student
        printf("\nID : ");
        scanf("%d",&stu[i].id);
        printf("\n");


        //Opens A TXT File Named (Student Name.txt)
        fp=fopen(nametemp,"w");


        //Writes Name And ID On File.
        fprintf(fp,"NAME:%s ID:%d\n",stu[i].name,stu[i].id);

        system("cls");

        //Gets ST Class Confirmation
        printf("Do You Have Classes On Sunday/Tuesday? ");
        fflush(stdin);
        scanf("%c",&ans);
        printf("\n");


        //If Y Than Loop Starts
        if(ans=='y' || ans =='Y')
        {


            //Writs 'Sunday/Tuesday' On TXT File
            fprintf(fp,"Sunday/Tuesday\n");


            //This Is To Tell The User How To Operate The Program.
            printf("Press 0 If You Have Classes On 8.00-9.30 AM \n");
            printf("Press 1 If You Have Classes On 9.40-11.10 AM \n");
            printf("Press 2 If You Have Classes On 11.20-12.50 PM \n");
            printf("Press 3 If You Have Classes On 1.00-2.30 PM \n");
            printf("Press 4 If You Have Classes On 2.40-4.10 PM \n");
            printf("Press 5 If You Have Classes On 4.20-5.50 PM\n\n");


            //ST Input Starts
            for(j=0;j<6;j++)
            {


                printf("\nWhen Is Your Class On Sunday/Tuesday? ");


                //Gets Class Time.
                scanf("%d",&stu[i].st[j]);


                //Gets Faculty Name.
                printf("\nFaculty Name : ");
                fflush(stdin);
                gets(stu[i].fac);


                //Gets Room Number
                printf("\nRoom Number : ");
                fflush(stdin);
                gets(stu[i].room);


                //Writs Class Time And Faculty Name On TXT File
                if(stu[i].st[j]==0)
                {
                    fprintf(fp,"8.00-9.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].st[j]==1)
                {
                    fprintf(fp,"9.40-11.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].st[j]==2)
                {
                    fprintf(fp,"11.20-12.50 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].st[j]==3)
                {
                    fprintf(fp,"1.00-2.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].st[j]==4)
                {
                    fprintf(fp,"2.40-4.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].st[j]==5)
                {
                    fprintf(fp,"4.20-5.50 %s %s\n",stu[i].fac,stu[i].room);
                }


                //Confirms If Any Classes On ST Is Left Or Not.
                printf("\nDo You Have More Classes On Sunday/Tuesday? ");
                scanf("%c",&ans);


                //If Not ST Input Loop Breaks.
                if(ans=='n' || ans=='N')
                {
                    break;
                }


            }
        }
        //ST Input Ends.

        system("cls");

        //Gets MW Class Confirmation
        printf("\nDo You Have Classes On Monday/Wednesday? ");
        fflush(stdin);
        scanf("%c",&ans);
        printf("\n");


        //If 'Y' Then The Loop Starts
        if(ans=='y' || ans=='Y')
        {


            //Writs 'Monday/Wednesday' On TXT File
            fprintf(fp,"Monday/Wednesday\n");



            //This Is To Tell The User How To Operate The Program.
            printf("Press 0 If You Have Classes On 8.00-9.30 AM \n");
            printf("Press 1 If You Have Classes On 9.40-11.10 AM \n");
            printf("Press 2 If You Have Classes On 11.20-12.50 PM \n");
            printf("Press 3 If You Have Classes On 1.00-2.30 PM \n");
            printf("Press 4 If You Have Classes On 2.40-4.10 PM \n");
            printf("Press 5 If You Have Classes On 4.20-5.50 PM\n\n");


            //MW Input Starts.
            for(j=0;j<6;j++)
            {



                printf("\nWhen Is Your Class On Monday/Wednesday? ");


                //Gets Class Time.
                scanf("%d",&stu[i].mw[j]);



                //Gets Faculty Name.
                printf("\nFaculty Name : ");
                fflush(stdin);
                gets(stu[i].fac);



                //Gets Room Number
                printf("\nRoom Number : ");
                fflush(stdin);
                gets(stu[i].room);



                //Writs Class Time And Faculty Name On TXT File
                if(stu[i].mw[j]==0)
                {
                    fprintf(fp,"8.00-9.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].mw[j]==1)
                {
                    fprintf(fp,"9.40-11.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].mw[j]==2)
                {
                    fprintf(fp,"11.20-12.50 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].mw[j]==3)
                {
                    fprintf(fp,"1.00-2.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].mw[j]==4)
                {
                    fprintf(fp,"2.40-4.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].mw[j]==5)
                {
                    fprintf(fp,"4.20-5.50 %s %s\n",stu[i].fac,stu[i].room);
                }



                //Confirms If Any Classes On MW Is Left Or Not.
                printf("\nDo You Have More Classes On Monday/Wednesday? ");
                scanf("%c",&ans);



                //If 'N' than MW Input Loop Breaks.
                if(ans=='n' || ans=='N')
                {
                    break;
                }



            }
        }
        //MW Input Ends.

        system("cls");

        //Gets MW Class Confirmation.
        printf("\nDo You Have Classes On Saturday/Thursday? ");
        fflush(stdin);
        scanf("%c",&ans);
        printf("\n");



        //If 'Y' Then The Loop Starts.
        if(ans=='y' || ans=='Y')
        {


            //Writs 'Saturday/Thursday' On TXT File
            fprintf(fp,"Saturday/Thursday\n");



            //This Is To Tell The User How To Operate The Program.
            printf("Press 0 If You Have Classes On 8.00-9.30 AM \n");
            printf("Press 1 If You Have Classes On 9.40-11.10 AM \n");
            printf("Press 2 If You Have Classes On 11.20-12.50 PM \n");
            printf("Press 3 If You Have Classes On 1.00-2.30 PM \n");
            printf("Press 4 If You Have Classes On 2.40-4.10 PM \n");
            printf("Press 5 If You Have Classes On 4.20-5.50 PM\n\n");


            //RA Input Starts.
            for(j=0;j<6;j++)
            {



                printf("\nWhen Is Your Class On Saturday/Thursday? ");



                //Gets Class Time.
                scanf("%d",&stu[i].ra[j]);



                //Gets Faculty Name.
                printf("\nFaculty Name : ");
                fflush(stdin);
                gets(stu[i].fac);



                //Gets Room Number
                printf("\nRoom Number : ");
                fflush(stdin);
                gets(stu[i].room);



                //Writs Class Time And Faculty Name On TXT File
                if(stu[i].ra[j]==0)
                {
                    fprintf(fp,"8.00-9.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].ra[j]==1)
                {
                    fprintf(fp,"9.40-11.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].ra[j]==2)
                {
                    fprintf(fp,"11.20-12.50 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].ra[j]==3)
                {
                    fprintf(fp,"1.00-2.30 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].ra[j]==4)
                {
                    fprintf(fp,"2.40-4.10 %s %s\n",stu[i].fac,stu[i].room);
                }
                else if(stu[i].ra[j]==5)
                {
                    fprintf(fp,"4.20-5.50 %s %s\n",stu[i].fac,stu[i].room);
                }



                //Confirms If Any Classes On RA Is Left Or Not.
                printf("\nDo You Have More Classes On Saturday/Thursday? ");
                scanf("%c",&ans);



                //If 'N' than MW Input Loop Breaks.
                if(ans=='n' || ans=='N')
                {
                    break;
                }


            }
        }
        //RA Input Ends.

        fprintf(fp,"\n");       //This Is Done For Debugging purposes.

        //File Close.
        fclose(fp);

        system("cls");

    }
    //Every Student Input Ends.



    //Calculation Starts.



    //STCO Gets Filled With The Value Of Students Busy On ST At Different Times Of The Day.
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                if(stu[i].st[j]==k)
                {
                    stco[k]++;
                }
            }
        }
    }



    //MWCO Gets Filled With The Value Of Students Busy On MW At Different Times Of The Day.
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                if(stu[i].mw[j]==k)
                {
                    mwco[k]++;
                }
            }
        }
    }



    //RACO Gets Filled With The Value Of Students Busy On RA At Different Times Of The Day.
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                if(stu[i].ra[j]==k)
                {
                    raco[k]++;
                }
            }
        }
    }



    //Replacing Busy Students With Free Students.
    for(i=0;i<6;i++)
    {
        stco[i]=n-stco[i];
        mwco[i]=n-mwco[i];
        raco[i]=n-raco[i];
    }


    //Calculation Ends.


    //This IS To Write The Results On A File Called result.txt
    writeresult(faculty,stco,raco,mwco,n);



    printresult(n,stco,raco,mwco);


    printf("\n\nPress 0 To Return To Main Menu.\n");
    printf("Press 1 To Return To Exit\n");
    scanf("%d",&ask2);

    system("cls");

    if(ask2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void writeresult(char faculty[6],int stco[6],int raco[6],int mwco[6],int n)
{

    //Necessary INT For Loop And Pointer To Open Files.
    int i;
    FILE *fp;


    //Opening A TXT File Called result.txt To Save The Results Of The Calculation.
    fp=fopen("result.txt","w");


    //Writing All The Results On result.txt
    fprintf(fp,"Search Done By : %s\n\n",faculty);
    fprintf(fp,"Students Free On Sunday/Tuesday\n\n");
    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            fprintf(fp,"At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==1)
        {
            fprintf(fp,"At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==2)
        {
            fprintf(fp,"At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==3)
        {
            fprintf(fp,"At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==4)
        {
            fprintf(fp,"At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==5)
        {
            fprintf(fp,"At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }

    }
    fprintf(fp,"\n\n");

    fprintf(fp,"Students Free On Monday/Wednesday\n");
    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            fprintf(fp,"At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==1)
        {
            fprintf(fp,"At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==2)
        {
            fprintf(fp,"At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==3)
        {
            fprintf(fp,"At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==4)
        {
            fprintf(fp,"At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==5)
        {
            fprintf(fp,"At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }

    }
    fprintf(fp,"\n\n");

    fprintf(fp,"Students Free On Saturday/Thursday\n");
    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            fprintf(fp,"At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==1)
        {
            fprintf(fp,"At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==2)
        {
            fprintf(fp,"At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==3)
        {
            fprintf(fp,"At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==4)
        {
            fprintf(fp,"At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==5)
        {
            fprintf(fp,"At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }

    }
    fprintf(fp,"\n\n");


    fclose(fp);
    //Writing Ends.
}


void printresult(int n,int stco[6],int raco[6],int mwco[6])
{


    int i;

    //Printing The Results.
    printf("Students Free On Sunday/Tuesday\n");



    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            printf("At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==1)
        {
            printf("At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==2)
        {
            printf("At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==3)
        {
            printf("At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==4)
        {
            printf("At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }
        else if(i==5)
        {
            printf("At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",stco[i],n);
        }

    }
    printf("\n\n");



    printf("Students Free On Monday/Wednesday\n");



    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            printf("At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==1)
        {
            printf("At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==2)
        {
            printf("At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==3)
        {
            printf("At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==4)
        {
            printf("At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }
        else if(i==5)
        {
            printf("At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",mwco[i],n);
        }

    }
    printf("\n\n");



    printf("Students Free On Saturday/Thursday\n");



    for(i=0;i<6;i++)
    {

        if(i==0)
        {
            printf("At 8.00-9.30 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==1)
        {
            printf("At 9.40-11.10 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==2)
        {
            printf("At 11.20-12.50 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==3)
        {
            printf("At 1.00-2.30 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==4)
        {
            printf("At 2.40-4.10 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }
        else if(i==5)
        {
            printf("At 4.20-5.50 %d Students Are Free Out Of %d Students.\n",raco[i],n);
        }

    }
    printf("\n\n");

}


//Result Function To See Last result.
int result()
{

    int ask2=2;
    //A Pointer To point At result.txt FILE.
    FILE *fp;
    char read[150];

    //Opening result.txt.
    fp=fopen("result.txt","r");


    //To Print The Last Result Inside The Console.
    if (fp!= NULL)
    {

        while(!feof(fp))
        {
            fgets(read,150,fp);
            puts(read);
        }

        fclose(fp);
    }


    //If There Is No Search Done Before.
    else
    {
        printf("Error In Opening File.\n\n");
    }

    printf("\n\nPress 0 To Return To Main Menu.\n");
    printf("Press 1 To Return To Exit\n");
    scanf("%d",&ask2);

    system("cls");

    if(ask2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



//Search Function To Search A Students Schedule.
int searchstudents()
{

    char ans,name[40],read[150],txt[]={'.','t','x','t','\0'};    //Necessary Char To Read and To Open File.
    int ans2=2;
    FILE *fp;                                                    //Pointer To Open Students Record.



    printf("Give The Name Of The Student You Want To Search : ");
    fflush(stdin);
    gets(name);


    //Adding .txt At The End Of Searched Name String.
    strcat(name,txt);
    fp=fopen(name,"r");



    if(fp != NULL)
    {
        printf("\nIn The Following Time The Student Has Classes.\n\n\n");

        while(!feof(fp))
        {
            fgets(read,150,fp);
            puts(read);
        }

        fclose(fp);
    }


    //If There Is No Record Found Under Searched Name.
    else
    {
        printf("\nNo Records Were Found Under This Name.");
    }


    printf("\n\nPress 0 To Return To Main Menu.\n");
    printf("Press 1 To Return To Exit\n");
    scanf("%d",&ans2);

    system("cls");

    if(ans2==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
