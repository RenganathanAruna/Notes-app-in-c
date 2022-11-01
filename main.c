#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>


void createnote();
void viewnote();
void listnote();
void deletenote();
void search_by_name();
void search_by_content();
void editnote();
void addnotes();
void login();
void regist();
int notes();
void sharing();
void sharelogin();
int sharelistnote();


int i,j,c,k,loc,check,checking,shareuid;
char str1[100],str2[100],str3[100],str4[100],locationarr[100][100],userfilenamesarr[100][100][100],
sharedlocationarr[100][100],usersharedfilenamesarr[100][100][100];


 void createnote()
{
    //puts(locationarr[1]);
    //puts(userfilenamesarr[1]);
    char ch,fname[100];
    int n;
    FILE *fp;
    printf("Enter the name of the file: ");
    getchar();
    gets(fname);

    char *num;
    asprintf(&num,"%d",loc);
    strcpy(str2,num);

    strcpy(str1,"userfilename");
    strcat(str1,str2);
    strcpy(str3,".txt");
    strcat(str1,str3);

    fp=fopen(str1,"a");
    fputs(fname,fp);
    ch='\n';
    fputc(ch,fp);
    fclose(fp);


    strcpy(str1,locationarr[loc]);
    strcpy(str2,"//");
    strcat(str1,str2);
    strcpy(str3,fname);
    strcat(str1,str3);
    //printf(str1);
    fp=fopen(str1,"a");
    //while ((getchar())!='\n');
    ch=getchar();
    while(ch!='`')
    {
        fputc(ch,fp);
       // printf("%d ",ch);
        ch=getchar();
    }
 fclose(fp);
}


void viewnote()
{
    char ch,fname[100],f;
    listnote();

    FILE *fp;
    printf("\n\nEnter the file name: ");
    getchar();
    gets(fname);



    for(c=0,i=1;i<=check;i++)
    {
       // puts(userfilenamesarr[loc][i]);
        if(strcmp(fname,userfilenamesarr[loc][i])==0)
        {
            c=1;
            break;
        }
    }



   /* for(k=0,j=1;j<=checking;j++)
    {
        printf("hi");
        printf("%d",checking);
        puts(usersharedfilenamesarr[loc][j]);
        if(strcmp(fname,usersharedfilenamesarr[loc][j])==0)
        {
            k=1;
            break;
        }
    }
*/

    if(c==1)
    {
    strcpy(str1,locationarr[loc]);
    strcpy(str2,"//");
    strcat(str1,str2);
    strcpy(str3,fname);
    strcat(str1,str3);
   // printf(str1);
    fp=fopen(str1,"r");
    if(NULL==fp)
    {
        printf("\nThere is no notes to show");
    }
    else
    {
       ch=fgetc(fp);
       printf("\n\n");
       while(ch!=EOF)
       {
            printf("%c",ch);
            ch=fgetc(fp);
       }
    fclose(fp);
    }
    }

    else
    {
    strcpy(str1,sharedlocationarr[loc]);
    strcpy(str2,"//");
    strcat(str1,str2);
    strcpy(str3,fname);
    strcat(str1,str3);
    //printf(str1);
    fp=fopen(str1,"r");
    if(NULL==fp)
    {
        printf("\nThere is no such note to view");
    }
    else
    {
       ch=fgetc(fp);
       printf("\n\n");
       while(ch!=EOF)
       {
            printf("%c",ch);
            ch=fgetc(fp);
       }
    fclose(fp);
    }
    }

 /*   else
      printf("\nThere is no such note");*/
}


void listnote()
{
    strcpy(str1,locationarr[loc]);
	struct dirent *de;
	DIR *dr = opendir(str1);

	if (dr == NULL)
	{
		printf("\n\nThere is no notes to show" );
	}
	else
	{
	while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }
	}

	closedir(dr);

    strcpy(str1,sharedlocationarr[loc]);

	 dr = opendir(str1);

	if (dr == NULL)
	{
		printf(" \n\nThere is no notes to show in shared notes");
	}
	else
	{
	while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }
	}

	closedir(dr);


}


void deletenote()
{
    char dnote[50];
    listnote();
    int f=1,pos=0;

        printf("\nEnter the file name that is to be deleted: ");
        getchar();
        gets(dnote);


            strcpy(str1,locationarr[loc]);
            strcpy(str2,"//");
            strcat(str1,str2);
            strcpy(str3,dnote);
            strcat(str1,str3);
            //printf(str1);


          if(remove(str1)==0)
          {
            printf("\n\nnote is deleted\n");
            listnote();
          }
          else
            printf("\n\nThere is no such note to delete");

}


void editnote()
{
    char fname[100],ch;
    listnote();
  printf("\n\nEnter the filename that you want to edit: ");
  getchar();
  gets(fname);


    strcpy(str1,locationarr[loc]);
    strcpy(str2,"//");
    strcat(str1,str2);
    strcpy(str3,fname);
    strcat(str1,str3);

    FILE *fp;

    fp=fopen(str1,"r");
    if(NULL==fp)
    {
        printf("\nThere is no such note");
    }
    else
    {
       printf("\n\nThe content in the note are: ");
       ch=fgetc(fp);
       printf("\n\n");
       while(ch!=EOF)
       {
            printf("%c",ch);
            ch=fgetc(fp);
       }
    fclose(fp);

    fp=fopen(str1,"w");
    printf("\n\nEnter the content that you want to edit: \n");
    ch=getchar();
    while(ch!='`')
    {
        fputc(ch,fp);
       // printf("%d ",ch);
        ch=getchar();
    }
 fclose(fp);
    }


}


void addnotes()
{
    listnote();
    char fname[100],ch;
    printf("\n\nEnter the filename you want to add content: ");
    getchar();
    gets(fname);

    strcpy(str1,locationarr[loc]);
    strcpy(str2,"//");
    strcat(str1,str2);
    strcpy(str3,fname);
    strcat(str1,str3);

    FILE *fp;

    fp=fopen(str1,"r");
    if(NULL==fp)
    {
        printf("\nThere is no such note");
    }
    else
    {
       printf("\n\nThe content in the note are:");
       ch=fgetc(fp);
       printf("\n\n");
       while(ch!=EOF)
       {
            printf("%c",ch);
            ch=fgetc(fp);
       }
    fclose(fp);

    fp=fopen(str1,"a");
    ch=' ';
    fputc(ch,fp);
    fclose(fp);


    fp=fopen(str1,"a");
    printf("\n\nEnter the content that you want to edit: \n");
    ch=getchar();
    while(ch!='`')
    {
        fputc(ch,fp);
       // printf("%d ",ch);
        ch=getchar();
    }
 fclose(fp);
    }

}


void search_by_name()
{

   int d,e,q=0,co=0;
   char search[100],check1[100][100],check2[100][100];
   printf("\n\nEnter the file name to search: ");
   getchar();
   gets(search);

   //putchar(userfilenamesarr[loc][1][0]);
  // printf("%d",check);
   for(i=1;i<=check;i++)
     for(k=0;userfilenamesarr[loc][i][k];k++)
       check1[i][k]=userfilenamesarr[loc][i][k];
   // putchar(check1[1][0]);

    for(i=0;i<=search[i];i++)
        check2[1][i]=search[i];
   // putchar(check2[1][i-4]);

    for(i=1;i<=check;i++)
    {
      for(q=0,d=0;check2[1][d];d++)
      {
        for(k=0;userfilenamesarr[loc][i][k];k++)
        {
           if(check1[i][k]==check2[1][d])
          {
              e=strlen(search);
              //printf("%d",e);
              if(e==1)
                puts(userfilenamesarr[loc][i]);
            else
            {

             for(c=1;c<=check2[1][c];c++)
             {
                // putchar(check1[i][k+c]);
                 //putchar(check2[1][d+c]);
                // printf("\n");
                if(check1[i][k+c]==check2[1][d+c] && check1[i][k+c]!=0 && check2[1][d+c] !=0)
                   q=1;
                else
                  q=0;
             }
            }
              break;
          }
        }
        if(q==1 && e!=1)
        {
            if(co==0)
            {
                printf("\n\nThe results of search are: \n");
                co=co+1;
            }
           puts(userfilenamesarr[loc][i]);
           break;
        }
      }
    }
}


void search_by_content()
{
   char check3[100][100][100],check4[100][100],ch;
   int d=1,e=1;
   printf("\n\nEnter the content that you want to search: ");


    ch=getchar();
    while(ch!='`')
    {
        if(ch==' ')
        {
            //check4[e][d]='\0';
            e=e+1;
            d=1;
        }
        else
        {
            check4[e][d++]=ch;
        }

    ch=getchar();

    if(ch==EOF)
        d=1;
    }
    puts(check4[2]);
    putchar(check4[2][1]);

   FILE *fp;
   for(i=1;i<=check;i++)
   {
       strcpy(str1,locationarr[loc]);
       strcpy(str2,"//");
       strcat(str1,str2);
       strcpy(str3,userfilenamesarr[loc][i]);
       strcat(str1,str3);
       //puts(str1);

       fp=fopen(str1,"r");
       ch=fgetc(fp);

       while(ch!=EOF)
       {
          if(ch==' ')
          {
              d=d+1;
              e=1;
          }
          else
          {
              // putchar(ch);
               check3[i][d][e]=ch;
               e=e+1;
              // printf("%d ",i);
              // printf(" %d ",d);
          }
       ch=fgetc(fp);
       if(ch==EOF)
          d=1;
       }
       fclose(fp);
   }
   printf(check3[1][2]);



}


int notes(int userid)
{
    int n,d=1,e=1,f=1,g=1,nolif=0,nolifn=0,nolifsl=0,nolisfn=0;
    loc=userid;
    char ch;

    //printf(" %d ",loc);
    FILE *fp;
    fp=fopen("userdirlocation.txt","r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolif=nolif+1;
   // printf("%d",nolif);
     fclose(fp);

    fp=fopen("userdirlocation.txt","r");
    while(nolif)
    {
        fgets(locationarr[d],100,fp);
        char *ptr=strchr(locationarr[d],'\n');
        if(ptr)
            *ptr='\0';
        nolif=nolif-1;
        d=d+1;
    }
    fclose(fp);




    fp=fopen("usershareddirlocation.txt","r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolifsl=nolifsl+1;
   // printf("%d",nolif);
     fclose(fp);

    fp=fopen("usershareddirlocation.txt","r");
    while(nolifsl)
    {
        fgets(sharedlocationarr[f],100,fp);
        char *ptr=strchr(sharedlocationarr[f],'\n');
        if(ptr)
            *ptr='\0';
        nolifsl=nolifsl-1;
        f=f+1;
    }
    fclose(fp);



    char *num;
    asprintf(&num,"%d",loc);
    strcpy(str2,num);

    strcpy(str1,"userfilename");
    strcat(str1,str2);
    strcpy(str3,".txt");
    strcat(str1,str3);
   // printf(str1);
    fp=fopen(str1,"r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolifn=nolifn+1;
    //printf("%d",nolifn);
     fclose(fp);
     check=nolifn;


    fp=fopen(str1,"r");
    while(nolifn)
    {
        fgets(userfilenamesarr[loc][e],100,fp);
        char *ptr=strchr(userfilenamesarr[loc][e],'\n');
        if(ptr)
            *ptr='\0';
        nolifn=nolifn-1;
        e=e+1;
    }
    //puts(userfilenamesarr[loc][1]);
    fclose(fp);





    asprintf(&num,"%d",loc);
    strcpy(str2,num);

    strcpy(str1,"shareduserfilename");
    strcat(str1,str2);
    strcpy(str3,".txt");
    strcat(str1,str3);
   // printf(str1);
    fp=fopen(str1,"r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolisfn=nolisfn+1;
  // printf("%d",nolifn);
     fclose(fp);
     checking=nolisfn;
    // printf("%d",checking);


    fp=fopen(str1,"r");
    while(nolisfn)
    {
        fgets(usersharedfilenamesarr[loc][g],100,fp);
        char *ptr=strchr(usersharedfilenamesarr[loc][g],'\n');
        if(ptr)
            *ptr='\0';
        nolisfn=nolisfn-1;
        g=g+1;

    }
    //puts(userfilenamesarr[loc][1]);
    fclose(fp);



    printf("\n\n1.Create note\n2.List note\n3.Delete note\n4.View note\n5.edit note\n6.add to note\n7.search by name\n8.search by content\n9.sharing\n10.back\n");
    printf("\nchoose any one option: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: createnote();
              notes(userid);
        case 2: listnote();
              notes(userid);
        case 3: deletenote();
              notes(userid);
        case 4: viewnote();
              notes(userid);
        case 5: editnote();
              notes(userid);
        case 6: addnotes();
              notes(userid);
        case 7: search_by_name();
              notes(userid);
        case 8: search_by_content();
              notes(userid);
        case 9: sharing(userid);
              notes(userid);
        case 10: main();
        default: printf("\nPlease enter a valid option :");
              notes(userid);
    }
}


void login()
{

    int userno=0,nolif=0,userid,j=0;
    char name[100],fname[100],ch;

    FILE *fp;


    printf("\n\n**LOGIN**");
    printf("\n\nEnter Your name: ");
    getchar();
    gets(name);

    fp=fopen("username.txt","r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolif=nolif+1;
   // printf("%d",nolif);
     fclose(fp);

    fp=fopen("username.txt","r");
    while(nolif)
    {
    userno=userno+1;
    fgets(fname,100,fp);
    if(strncmp(name,fname,strlen(name))==0)
    {
        j=1;
        userid=userno;
     printf("%d",userid);
        printf("\n\nLogin successful\n");
        notes(userid);
    }
    nolif=nolif-1;
    }
    if(j==0)
    {
        printf("\n\n you have not registered please register");
        main();
    }
    //system("pause");
    fclose(fp);
}


void regist()
{
   int j=0,nolif=0,out=0;
   char ch,name[100],fname[100];


    FILE *fp;


   printf("\n\n**Register**");
   printf("\n\nEnter your name for registeration: ");
   getchar();
   gets(name);


    fp=fopen("username.txt","r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          nolif=nolif+1;
   // printf("%d",nolif);
     fclose(fp);

    fp=fopen("username.txt","r");
    while(nolif)
    {
    fgets(fname,100,fp);
    if(strncmp(name,fname,strlen(name))==0)
          j=1;
    nolif=nolif-1;
    }
     fclose(fp);

    if(j==1)
    {
        printf("\n\nAlready registered user");
        main();
    }
    else
    {
        fp=fopen("username.txt","a");
        fputs(name,fp);
        ch='\n';
        fputc(ch,fp);
        fclose(fp);


        strcpy(str1,"C://Users//ELCOT//Documents//c program//notes application//");
        strcpy(str2,name);
        strcat(str1,str2);
        mkdir(str1);


        fp=fopen("userdirlocation.txt","a");
        fputs(str1,fp);
        ch='\n';
        fputc(ch,fp);
        fclose(fp);

        strcat(str1,"//shared notes");
        mkdir(str1);


        fp=fopen("usershareddirlocation.txt","a");
        fputs(str1,fp);
        ch='\n';
        fputc(ch,fp);
        fclose(fp);



        printf("\n\nRegisteration done successfully");
        main();
    }


}




void sharing()
{
    int noliun,id=0;
    char ch,uname[100],fname[100];
    printf("\n\nEnter the user name you need to send the note: ");
    getchar();
    gets(uname);

    FILE *fp;
    fp=fopen("username.txt","r");
    for(ch=getc(fp);ch!=EOF;ch=getc(fp))
        if(ch=='\n')
          noliun=noliun+1;
     //printf("%d\n",noliun);
     fclose(fp);

    fp=fopen("username.txt","r");
    while(noliun)
    {
    id=id+1;
    fgets(fname,100,fp);
    if(strncmp(uname,fname,strlen(uname))==0)
    {
        j=1;
        shareuid=id;
        //printf(" %d ",shareuid);
        break;
    }
    noliun=noliun-1;
    }
    fclose(fp);


    if(j==1)
    {
        listnote();
        printf("\n\nchoose the note that you want to send: ");
        gets(fname);



        char *num;
        asprintf(&num,"%d",loc);
        strcpy(str2,num);

        strcpy(str1,"shareduserfilename");
        strcat(str1,str2);
        strcpy(str3,".txt");
        strcat(str1,str3);

        fp=fopen(str1,"a");
        fputs(fname,fp);
        ch='\n';
        fputc(ch,fp);
        fclose(fp);




        strcpy(str1,sharedlocationarr[shareuid]);
        strcpy(str2,"//");
        strcat(str1,str2);
        strcpy(str3,fname);
        strcat(str1,str3);


        FILE *fp1,*fp2;
        fp1=fopen(str1,"w+");

        strcpy(str1,locationarr[loc]);
        strcpy(str2,"//");
        strcat(str1,str2);
        strcpy(str3,fname);
        strcat(str1,str3);
        printf(str1);

        fp2=fopen(str1,"r");
        ch=fgetc(fp2);
        while(ch!=EOF)
        {
            fputc(ch,fp1);
            ch=fgetc(fp2);
        }
    fclose(fp1);
    fclose(fp2);

     printf("\n\nNote sharing is done sucessfully");

    }
    else
        printf("\n\nThere is no such registered user");

}


int main()
{
    char ch;
    printf("\n\n**Notes**\n");
    printf("\nA.login\nB.register\nc.closeapp\n");
    printf("\nchoose any one option: ");
    scanf("\n%c",&ch);
    switch(ch)
    {
        case 'A': login();
        case 'B': regist();
        case 'C': exit(0);
        default: printf("\nPlease enter a valid option: ");
                  main();
    }
return 0;
}







































