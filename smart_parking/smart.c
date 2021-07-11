#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

struct vehicle
{
    int type;
    char no[20];
    char vname[20];
    char cname[30];
    char ph[15];
    int hr,min;
};
struct vehiclefile
{
    char vno[15];
};
struct owner
{
    char name[30];
    int m,n;
};

void  slotdisplay()
{
    FILE *f,*f2;
    f = fopen("vehicleno","r");
    f2 = fopen("authority","r");
    int i,j;
    char no[20],no1[25];
    int m , n;
    fscanf(f2,"%s%d%d",no1,&m,&n);
    printf("\n\n");
    for(i = 0 ; i < m ; i++)
    {
        for(j = 0 ; j < n && fscanf(f,"%s",no)!=EOF ; j++ )
        {
            if(strcmp(no,"EMPTY")==0)
                printf("%s\t\t",no);
            else
                printf("%s\t",no);
        }
        printf("\n");
    }
    fclose(f);
    fclose(f2);
    printf("\n\n");
}

void authority()
{
    struct owner o;
    FILE *fp1,*fp2,*fp3;
    fp3 = fopen("password","w");
    fprintf(fp3,"%s","12345678");
    fclose(fp3);
    int i,j;char ch , pass[20],password[20];
    fp1 = fopen("authority","w");
    fp2 = fopen("vehicleno","w");
    fp3 = fopen("password","r");
    printf("\nPLEASE ENTER THE NAME OF THE PLACE \n");
    scanf("%s",o.name);
    fscanf(fp3,"%s",password);
    printf("\nplease enter the password (8digit): \n");
    printf("hint : 1to8\n");
   a : for(j=0;j<8;j++)
    {

        ch = getch();
        pass[j]=ch;
        ch='*';
        printf("%c",ch);
    }
    pass[j]='\0';
    //a : scanf("%s",pass);
    if(strcmp(pass,password)!=0)
    {
        printf("\npassword mismatch\n");
        printf("please enter the correct password \n");
       goto a;
    }
    printf("\nPLEASE ENTER NUMBER OF ROWS AND COLUMNS AVAILABLE\n");
    scanf("%d%d",&o.m,&o.n);
    fprintf(fp1,"%s\t%d\t%d",o.name,o.m,o.n);
    for( i = 1 ; i <= o.m*o.n ; i++)
        fprintf(fp2,"%s\n","EMPTY");
    fclose(fp1);
    fclose(fp2);
    fp1=fopen("vehicle","w");
    fp1=fopen("vehicleexit","w");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    FILE *f;
    float a = 5;
    f=fopen("feedbackplace","w");
    fprintf(f,"%f",a);
    fclose(f);
    f=fopen("feedbackslot","w");
    fprintf(f,"%f",a);
    fclose(f);
    system("cls");
}

void entry()
{
    FILE *fp1,*fp2,*fp3;
    struct vehicle n;
    struct vehiclefile f;
    int count = 0;
    int flag = 0;
    fp1=fopen("vehicle","a");
    fp2=fopen("vehicleno","r");
    fp3=fopen("temp","w");

    while(fscanf(fp2,"%s",f.vno)!=EOF)
    {
        count++;

        if(strcmp(f.vno,"EMPTY")==0)
        {
            printf("\n\nCONGRATS..!!\nSLOTS ARE AVAILABLE\n");
            slotdisplay();
            printf("\nPLEASE ENTER THE FOLLOWING DETAILS : \n");
            printf("vehicle type : ");scanf("%d",&n.type);
            printf("VEHICLE NAME : ");scanf("%s",n.vname);
            printf("VEHICLE NUMBER : ");scanf("%s",n.no);
            printf("CUSTOMER NAME : ");scanf("%s",n.cname);
            printf("CUSTOMER CONTACT NUMBER : ");scanf("%s",n.ph);
            printf("ENTRY TIME IN HH MM FORMAT : ");scanf("%d%d",&n.hr,&n.min);

            fprintf(fp1,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",n.hr,n.min,n.type,n.vname,n.no,n.cname,n.ph);
            strcpy(f.vno,n.no);
            fprintf(fp3,"%s\n",f.vno);
            printf("\n\nPLEASE PARK THE VEHICLE AT POSITION %d\n\n",count);
            flag = 1;
            break;
        }
        else
        {
            fprintf(fp3,"%s\n",f.vno);
        }
    }
    while(fscanf(fp2,"%s",f.vno)!=EOF)
    {
        fprintf(fp3,"%s\n",f.vno);
    }

    fclose(fp2);
    fclose(fp3);
    fclose(fp1);
    fp2=fopen("vehicleno","w");
    fp3=fopen("temp","r");
    while(fscanf(fp3,"%s",f.vno)!=EOF)
    {
        fprintf(fp2,"%s\n",f.vno);
    }

    fclose(fp2);
    fclose(fp3);
    if(flag==0)
    {
        printf("\n\nSORRY NO SLOTS ARE AVAIALABLE\nPLEASE WAIT UNTIL A SLOT GETS EMPTY\n\n");
    }
}

void entrycustomerdisplay()
{
    printf("\n\n");
    FILE *fp;
    int flag = 0 ;
    struct vehicle n;
    fp = fopen("vehicle","r");
    printf("DETAILS OF VEHICLE AND OWNER AT TIME OF ENTRY: \n ");
    printf("HOUR\tMINUTE\tTYPE\tVNAME\tNUMBER\t\tNAME\t\tPHONE\n");
    while(fscanf(fp,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
    {
        flag=1;
        printf("%d\t%d\t%d\t%s\t%s\t%s\t\t%s\n",n.hr,n.min,n.type,n.vname,n.no,n.cname,n.ph);
    }
    if(flag==0)
        printf("\nNO RECORDS FOUND\n");
    fclose(fp);
    printf("\n\n");
}

void vehicleexit()
{
    printf("\n\n");
    struct vehicle n;
    struct vehiclefile f;
    int h,m;
    FILE *fp1,*fp2,*fp3,*fp4;
    char no[20];
    int flag = 0;
    fp1 = fopen("vehicleexit","a");
    fp2 = fopen("vehicleno","r");
    fp3 = fopen("temp","w");
    fp4 = fopen("vehicle","r");
    slotdisplay();
    printf("\nPLEASE ENTER THE VEHICLE NUMBER TO EXIT : ");
    scanf("%s",no);
    while(fscanf(fp2,"%s",f.vno)!=EOF)
    {
        if(strcmp(f.vno,no)==0)
        {
            fprintf(fp3,"%s\n","EMPTY");
            flag=1;
            break;
        }
        else
        {
            fprintf(fp3,"%s\n",f.vno);
        }
    }
    while(fscanf(fp2,"%s",f.vno)!=EOF)
    {
        fprintf(fp3,"%s\n",f.vno);
    }
    if(flag == 1)
    {
        printf("\nplease eneter time in hh mm format : \n");
        scanf("%d%d",&h,&m);
        while(fscanf(fp4,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
        {
            if(strcmp(n.no,no)==0)
            {
                fprintf(fp1,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",h,m,n.type,n.vname,n.no,n.cname,n.ph);
                break;
            }
        }
    }
    else
    {
        printf("NO VEHICLES WITH VEHICLE NUMBER %s IF FOUND",no);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fp2 = fopen("vehicleno","w");
    fp3 = fopen("temp","r");
    while(fscanf(fp3,"%s",f.vno)!=EOF)
    {
        fprintf(fp2,"%s\n",f.vno);
    }
    fclose(fp2);
    fclose(fp3);
    if(flag==1)
    {
        fp1 = fopen("vehicleexit","r");
        fp4 = fopen("vehicle","r");
        while(fscanf(fp1,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
        {
            if(strcmp(n.no,no)==0)
            {
                fscanf(fp1,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&h,&m,&n.type,n.vname,n.no,n.cname,n.ph);
                break;
            }
        }
        while(fscanf(fp4,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
        {
            if(strcmp(n.no,no)==0)
            {
                fscanf(fp1,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph);
                break;
            }
        }
        int fare,time;
        if(n.hr==h)
        {
            time = 1 ;
        }
        else
        {
            time = h-n.hr;
        }
        if(time <= 6)
        {
            if ( n.type == 2 )
            {
                fare = time*10;
            }
            else
            {
                fare = time*25;
            }
        }
        else if ( time > 6)
        {
            if ( n.type == 2 )
            {
                fare = 60;

            }
            else
            {
                fare = 150;
            }
        }
        else
        {
            fare = 200;
        }
        FILE *fp;
        struct owner o;
        fp = fopen("authority","r");
        while(fscanf(fp,"%s\t%d\t%d",o.name,&o.m,&o.n)!=EOF);
        printf("Generating bill.");
        Sleep(1000);printf(".");Sleep(1000);printf(".");Sleep(1000);printf(".");
        Sleep(1000);printf("\n\n");
        int i;
        for(i=0;i<30;i++)
            printf("~~");
        printf("\n");
        for(i=0;i<30;i++)
            printf("__");
            printf("\n");
        printf("%s",o.name);
        printf("\nSMART PARKING LOT\n");
        for(i=0;i<30;i++)
            printf("--");
        printf("\n");
        printf("Online Generated INVOICE\n");
        for(i=0;i<30;i++)
            printf("..");
        printf("\n");
        printf("Customer name : %s \n",n.cname);
        printf("Customer phone number : %s\n",n.ph);
        printf("Vehicle number : %s\n",n.vname);
        printf("VEHICLE TYPE : %d wheeler\n",n.type);
        printf("TOTAL PARKING TIME : %d hours\n",time);
        printf("PARKING fare : %dRs\n",fare);
        printf("GST :%fRs\n",0.18*fare);
        printf("TOTAL PRICE(inclusive GST) : %fRs\n",fare+(0.18*fare));
        for(i=0;i<30;i++)
            printf("~~");
        printf("\n\n");
        printf("CUSTOMER FEEDBACK\n");
        float a,b,c;
        printf("\nplease rate the %s out of 5\n",o.name);
        b : scanf("%f",&a);
        if(a>5)
        {
            goto b;
        }
        printf("\nplease rate the SMART PARKING MANAGEMENT   out of 5\n");
        c : scanf("%f",&b);
        if(b>5)
        {
            goto c;
        }
        FILE *a1;
        a1=fopen("feedbackplace","r");
        fscanf(a1,"%f",&c);
        a=(a+c)/2;
        fclose(a1);
        a1=fopen("feedbackplace","w");
        fprintf(a1,"%f",a);
        fclose(a1);
        a1=fopen("feedbackslot","r");
        fscanf(a1,"%f",&c);
        b=(b+c)/2;
        fclose(a1);
        a1=fopen("feedbackslot","w");
        fprintf(a1,"%f",b);
        fclose(a1);
        fclose(fp);
        fclose(fp4);
        fclose(fp1);
    }
    printf("\n\n");
}

void exitcustomerdisplay()
{
    printf("\n\n");
    FILE *fp;
    int flag = 0 ;
    struct vehicle n;
    fp = fopen("vehicleexit","r");
    printf("DETAILS OF VEHICLE AND OWNER AT TIME OF EXIT : \n ");
    printf("HOUR\tMINUTE\tTYPE\tVNAME\tNUMBER\t\tNAME\t\tPHONE\n");
    while(fscanf(fp,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
    {
        flag=1;
        printf("%d\t%d\t%d\t%s\t%s\t%s\t\t%s\n",n.hr,n.min,n.type,n.vname,n.no,n.cname,n.ph);

    }
    if(flag==0)
        printf("\nNO RECORDS FOUND\n");
    fclose(fp);
    printf("\n\n");
}

void feedback()
{
    FILE *f1,*f2;float a;char name[20];int m,n;
    f2 = fopen("authority","r");
    fscanf(f2,"%s%d%d",name,&m,&n);
    f1 = fopen("feedbackplace","r");
    fscanf(f1,"%f",&a);
    printf("RATING OF %s IS %0.f\n",name,a);
    fclose(f1);
    f1 = fopen("feedbackslot","r");
    fscanf(f1,"%f",&a);
    printf("RATING OF SMART PARKING SYSTEM IS %0.f\n",a);
    fclose(f1);
    fclose(f2);
}

void search()
{
    FILE *f1,*f2,*f3;
    f1=fopen("vehicleno","r");
    f2=fopen("vehicle","r");
    f3=fopen("vehicleexit","r");
    struct vehicle n;
    struct vehiclefile f;

    int flag = 0,count = 0;
    char name[20];
    printf("\n\nPlease enter the number of vehicle to search:");
    scanf("%s",name);
    while(fscanf(f1,"%s",f.vno)!=EOF)
    {
        count++;
        if(strcmp(name,f.vno)==0)
        {
            flag = 1 ;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nVEHICLE %s is parked at %d\n",name,count);
    }
    fclose(f1);
    if(flag==1)
    {
        printf("VEHICLE DETAILS IN ENTRY FILE :\n");
        while(fscanf(f2,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
        {
            if(strcmp(name,n.no)==0)
            {
                flag=1;
                printf("HOUR\tMINUTE\tTYPE\tVNAME\tNUMBER\t\tNAME\t\tPHONE\n");
                printf("%d\t%d\t%d\t%s\t%s\t%s\t\t%s\n",n.hr,n.min,n.type,n.vname,n.no,n.cname,n.ph);
            }
        }
    }
    fclose(f2);
        while(fscanf(f3,"%d\t%d\t%d\t%s\t%s\t%s\t%s\n",&n.hr,&n.min,&n.type,n.vname,n.no,n.cname,n.ph)!=EOF)
        {
            if(strcmp(name,n.no)==0)
            {
                flag = 1;
                printf("VEHICLE DETAILS IN EXIT FILE :\n");
                printf("HOUR\tMINUTE\tTYPE\tVNAME\tNUMBER\t\tNAME\t\tPHONE\n");
                printf("%d\t%d\t%d\t%s\t%s\t%s\t\t%s\n",n.hr,n.min,n.type,n.vname,n.no,n.cname,n.ph);
                break;
            }
        }
    fclose(f3);
    if(flag==0)
    {
        printf("\nSORRY VEHICLE WITH NUMBER %s NOT FOUND \n",name);
    }

}


int main()
{
    int choice;
    while(1)
    {
        FILE *f1;
        f1 = fopen("authority","r");
        if(f1!=NULL)
        {
            int i;
            for(i=0;i<120;i++)
                printf("_");
            printf("\n\t\t\t\t\t\tSMART PARKING LOT\n");
            for(i=0;i<120;i++)
                printf("-");
            printf("\n");
            rewind(f1);
         //FILE *f2;
         //   f2 = fopen("authority","r");
            char no1[25];
            int m , n;
            for(i=0;i<120;i++)
                printf("_");
            printf("\n");
            fscanf(f1,"%s%d%d",no1,&m,&n);
            printf("\t\t\t\t\t\t%s\n",no1);
            fclose(f1);
            for(i=0;i<120;i++)
                printf("-");
            printf("\n");
        }

        printf("\n 1 : AUTHORITY LOGIN \n 2 : VEHICLE ENTRY \n 3 : DISPLAY OF SLOTS \n 4 : DISPLAY OF ENTRY FILE \n");
        printf(" 5 : DISPLAY OF EXITFILE \n 6 : VEHICLE EXIT \n 7 : CLEAR SCREEN \n 8 : DISPLAY RATING  \n");
        printf(" 9 : SEARCH FOR A VEHICLE \n 10 : EXIT \n ");
        printf("PLEASE ENTER YOUR CHOICE : ");scanf("%d",&choice);
        switch(choice)
        {
            case 1 : authority();
                    break;

            case 2 : entry();
                    break;

            case 3 : slotdisplay();
                    break;

            case 4 : entrycustomerdisplay();
                    break;

            case 5 : exitcustomerdisplay();
                    break;

            case 6 : vehicleexit();
                    break;

            case 7 : system("cls");
                    break;
            case 8 : feedback();
                    break;
            case 9 : search();
                    break;
            case 10 : exit(0);

            default : printf("\nPLEASE ENTER A VALID CHOICE \n");
        }
    }
    return 0;
}
