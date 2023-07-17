#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<windows.h> //  header file for gotoxy     //header file for standard input output

COORD coord={0,0}; // this is global variable
                                   //center of axis is set to the top left cornor of the screen
int A1[10],sequenceg[10],totg,sequence[10],mindist=10000000000,pcsize;
void gotoxy(int x,int y)
{
  	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
FILE *fp;
struct DATE
{
  int dd;
  int mm;
  int yy;
};
char strst[60] = "C:\\Users\\admin\\Desktop\\project\\accounts\\" ,userg[20]="Chinmay",pincodeg[10]="560097",lastline[100];int p=100;
struct cart
{
    int code,price,qty;
    float rating;
    char name[100];
}; struct cart C1[50];
int cartsize = 0,min_dist=100000;char txt[4]=".txt",pc[100][100];
struct orders
{   int total;
    struct cart CC[100];
    struct DATE dd_placed,dd_delivered;
    char status[20];
    char review_status;
    long pincode;
};

void myitao(int num, char str[])
{
    int i = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    int temp=num;
    if (num < 0 )
    {
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }

    // If number is negative, append '-'
    if (temp<0)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    strrev(str);
}

void password_enter(char password[])
{   char ch1;int i;
    for( i=0; i<30; i++)
                {
                       ch1=getch();
                       password[i]=ch1;

                       if(ch1!=13)      //13 is ASCII of Enter key
                          printf("*");
                       if(ch1 == 13)
                          break;
                  }password[i]='\0';
}

void login_user()
{   char str[100],pass[20],password[20],user[20],ch1;int size,i,a,j;cartsize=0;
    goto A;
    A:
        getch();system("cls");
    printf("enter the username\n");
                   scanf("%^\n",userg);
           //        password_enter(password);
        fp = fopen("C:\\Users\\admin\\Desktop\\project\\custinfo.txt", "r");
         size=atoi(fgets(str,100,fp));
//         printf("%d       ",size);
          for( i=0;i<size;i++)
    {
        fgets(str,100,fp);
        for(j=0;;j++)
        {   ch1=str[j];
            if(ch1=='#')
                break;
            user[j]=ch1;
        }user[j]='\0';
        if(strcmpi(user,userg)==0)
        {   printf("correct username\n");
            K:
            system("cls");
            printf("enter password\n");
            password_enter(password);int j,k;
            for( j=0,k=30;;j++,k++)
            {   ch1=str[k];
            if(ch1=='#')
                break;
            pass[j]=ch1;
            }pass[j]='\0';
          //  puts(pass);
            if(strcmp(pass,password)==0)
            {
                printf("login successful\n");getch();
                strcpy(user,userg);
                for( j=75,a=0;;j++,a++)
                {
                    if(str[j]=='#')
                    {
                        break;
                    }
                    pincodeg[a]=str[j];
                }
                pincodeg[a]='\0';
               fclose(fp);
                p=3;return;
            }
            else
             {

                printf("invalid password");getch();
                goto K;
                fclose(fp);
                p=3;return;

             }
        }
        }
        printf("username invalid\n");
        fclose(fp);
        goto A;

}
void prev_orders()
{   char str[100],clone1[30],clone2[60];int size,i,insize;
    system("cls");strcpy(clone1,userg);strcpy(clone2,strst);
    strcat(clone1,txt);
    strcat(clone2,clone1);
    fp =  fopen(clone2,"r");
    fgets(str,100,fp);
    size = atoi(str);int y=0;
    for(i=0;i<size;i++)
    {  int j;
    fgets(str,100,fp);y++;y++;
    insize = atoi(str);
    printf("order no %d\nproduct",i+1);gotoxy(20,y);printf("qty");gotoxy(25,y);printf("price\n");
        for(j=0;j<insize;j++)
        {y++;y++;
            fgets(str,100,fp);str[strlen(str)]='\0';
            for(int lll=0;lll<strlen(str);lll++)
            if(str[lll]=='#')
                str[lll]=' ';
            puts(str);
        }
    }
    fclose(fp);
    printf("press any key to go back");getch();
    p=3;return;
}
void admin_orders()
{
    char str[100];
    int size,i=0,insize,name[20],pincode[6];pcsize=0;
    fp=fopen("C:\\Users\\admin\\Desktop\\project\\orders.txt","r");
    fgets(str,100,fp);
    size = atoi(str);//printf("%d\n",size);
    if(size>8)
        size = 8;
    while(i<size)
    {  int j;
    fgets(str,100,fp);
    str[strlen(str)]='\0';
       insize=atoi(str);

        for(j=0;j<insize-1;j++)
        {
            fgets(str,100,fp);str[strlen(str)]='\0';//getch();
            printf("%s\n",str);
        }

        int m=0,n=35;
        fgets(str,100,fp);str[strlen(str)]='\0';pincode[0]='\0';//puts(str);
  //      printf("%d\n",insize);
  pcsize++;
        for(;m<6;m++)
        {
            pc[i][m]=str[n];
            pincode[m]=str[n];

            n++;
      //      printf("%c\n",pincode[m]);
        }//printf("%d",pcsize);
     //   for(int pk=0;pk<6;pk++)
      //  printf("%c",pc[i][pk]);
        pincode[6]='\0';
        pc[i][m]='\0';name[0]='\0';
        for(m=0,n=16;;m++,n++)
        {
            if(str[n]==' ')
                break;
            name[m]=str[n];
        }

        str[m]='\0';//puts(name);puts(pincode);
         printf("total:");
        for(int i=43;str[i]!=' ';i++)
        printf("%c",str[i]);printf("\n");
        printf("ordered by:");int k=strlen(name);
        for(int i=0;i<m;i++)
        printf("%c",name[i]);
        printf("\npincode:");
        for(int i=0;i<6;i++)
        printf("%c",pincode[i]);printf("\n\n\n");
       // printf("Date ordered:");
      //  for(int k=0;str[k]!=' ';k++)
            // printf("%c",str[k]);printf("\n\n\n");
       // printf("      pincode:%s\n",pincode);
       //getch();
       str[0]='\0';i++;
    }
    fclose(fp);
   /* for(int i=0;i<pcsize;i++)
          {
              for(int j=0;j<6;j++)
              {
                  printf("%c",pc[0][j]);
              }
              printf("\n");
          }*/
}
void shortest_path_for_delivery()
{
    int i,pr=2,pppp=pcsize;int size=8,mm[8];char in[4];
    if(pcsize>7)
        pppp=7;
    for(i=0;i<pppp;i++)
    {
        in[0]=pc[i][4];
        in[1]=pc[i][5];in[3]='\0';
        mm[i] = atoi(in);
    }
    for(i=pcsize;i<7;i++)
            mm[i]=0;
            generate_seq(mm);
}
void generate_seq(int U1[])
{
    int i=7,m=7,U2[9],U3[9],U4[9],U5[9],U6[9],U7[9];int j=i,totdist,k,l;
    for(i=0;i<7;i++)
    {
        sequence[0]=U1[i];
         for(k=0,l=0;k<7;k++)
         {  // printf("executed\n");
             if(k==i)
                continue;
             U2[l]=U1[k];
             l++;
         }
        for(int i1=0;i1<6;i1++)
        {  sequence[1]=U2[i1];
            for( k=0,l=0;k<6;k++)
         {
             if(k==i1)
                continue;
             U3[l]=U2[k];
             l++;
         }
         for(int i2=0;i2<5;i2++)
        {  sequence[2]=U3[i2];
            for( k=0,l=0;k<5;k++)
         {
             if(k==i2)
                continue;
             U4[l]=U3[k];
             l++;
         }
          for(int i3=0;i3<4;i3++)
        {  sequence[3]=U4[i3];
            for(k=0,l=0;k<4;k++)
         {
             if(k==i3)
                continue;
             U5[l]=U4[k];
             l++;
         }
        for(int i4=0;i4<3;i4++)
        {  sequence[4]=U5[i4];
            for(k=0,l=0;k<3;k++)
         {
             if(k==i4)
                continue;
             U6[l]=U5[k];
             l++;
         }
          for(int i5=0;i5<2;i5++)
        {  sequence[5]=U6[i5];

          sequence[6]=U6[1-i5];
          calc_dist(&totdist);
             if(totdist<min_dist)
             {
                 mindist=totdist;
                 for(int j=0;j<7;j++)
                 {
                     sequenceg[j]=sequence[j];

                 }
             }

        }
    }
        }
        }
        }
        }
}

void calc_dist(int *totdist)
{   *totdist=0;
    int x1,x2,y1,y2,x,y;
    x1=sequence[0]%50;y1=sequence[0]/50;
    *totdist+=pow(x1,2);*totdist+=pow(y1,2);
    *totdist=pow(*totdist,.5);
    for(int i=0;i<7;i++)
    {
        x1=sequence[i]%50;y1=sequence[i]/50;
        x2=sequence[i+1]%50;y2=sequence[i+1]/50;
        x=x1-x2;y=y1-y2;
         x1= pow(x,2);
         y1= pow(y,2);
         x2=x1+y1;
         y2=pow(x2,.5);
         *totdist+=y2;
    }
    x1=sequence[6]%50;y1=sequence[6]/50;
    *totdist+=pow(x1,2);*totdist+=pow(y1,2);
    *totdist=pow(*totdist,.5);
}
void write_review()
{

         printf("give a rating to the product that you have purchased\n");

}
void update_products()
{

}
void sign_up()
{
    FILE *fileptr1, *fileptr2;
    char str[100],username[20],user[20],password1[20],password2[20],replace[20],pincode[20],phno[20],ch1,str1[100],clone1[30],clone2[60];
    int i,j,size=0;FILE *fp1;username[0]='\0';
    fp = fopen("C:\\Users\\admin\\Desktop\\project\\custinfo.txt","r");
//    fp1= fopen("C:\\Users\\admin\\Desktop\\project\\replica.txt", "r");
    B:
    printf("enter username\n");
    scanf("%^\n",username);

         size=atoi(fgets(str,100,fp));
    //     printf("%d       ",size);
          for( i=0;i<size;i++)
    {
        fgets(str,100,fp);
        for( j=0;;j++)
        {   ch1=str[j];
            if(ch1=='#')
                {    user[j]='\0';
                    break;
                }
            user[j]=ch1;
        }
        if(strcmpi(username,user)==0)
        {
            printf("username already exixts\n re-");
            goto B;
        }
    }
    C:
    printf("enter password\n");
    password_enter(password1);
    printf("re-enter password\n");
    password_enter(password2);
    if(strcmp(password1,password2)!=0)
    {
        printf("passwords dont match, reenter\n");
        goto C;
    }
   // getch();
   // printf("enter your phone no\n");
   //phno[0]='\0'
    gets(phno);
    printf("enter your 6 digit pincode\n");
    gets(pincode);
    for(i=0,j=0;i<strlen(username);i++,j++)
    {
        str1[i]=username[j];
    }
    str1[i]='#';i++;
    for(;i<30;i++)
        str1[i]=' ';
    for(j=0;j<strlen(password1);j++,i++)
        str1[i]=password1[j];
    str1[i]='#';i++;
    for(;i<60;i++)
        str1[i]=' ';
    for(j=0;j<strlen(phno);j++,i++)
        str1[i]=phno[j];
    str1[i]='#';i++;
    for(;i<75;i++)
        str1[i]=' ';
    for(j=0;j<strlen(pincode);j++,i++)
        str1[i]=pincode[j];
    str1[i]='#';i++;str1[i]='\0';i++;
    size++;
    fclose(fp);
    fileptr1 = fopen("C:\\Users\\admin\\Desktop\\project\\custinfo.txt", "r");
    fileptr2 = fopen("C:\\Users\\admin\\Desktop\\project\\replica.txt","w");
    str[0]='\0';
    myitao(size,replace);
    fputs(replace,fileptr2);
    fputs("\n",fileptr2);
    fgets(str,100,fileptr1);
    str[(strlen(str)-1)]='\0';
    //puts(str);
    for(int i=0;i<size-1;i++)
    {   fgets(str,100,fileptr1);
       str[(strlen(str)-1)]='\0';
     //  puts(str);
    //    printf("%d  %d  %d\n",strlen(str),strlen(contents),strcmpi(str,"Chinmay Chinmay"));
    //  puts(str);
    //  puts(contents);
        fputs(str,fileptr2);
        fputs("\n",fileptr2);
    }
    fputs(str1,fileptr2);
    fputs("\n",fileptr2);
    fclose(fileptr1);
    fclose(fileptr2);
    remove("C:\\Users\\admin\\Desktop\\project\\custinfo.txt");
    //rename the file replica.c to original name
    rename("C:\\Users\\admin\\Desktop\\project\\replica.txt", "C:\\Users\\admin\\Desktop\\project\\custinfo.txt");
    p=100;
    strcpy(clone1,username);strcpy(clone2,strst);
    strcat(clone1,txt);
    strcat(clone2,clone1);
    fp1=fopen(clone2,"w");
    str[0]='0';str[1]='\0';
    fputs(str,fp1);
    fclose(fp);
    return;
}

void display_products_sub1(char name[])
{
    char str[100],loc[50]="C:\\Users\\admin\\Desktop\\project\\products\\",namein[20]="";
    int size;
    strcpy(namein,name);
    strcat(namein,txt);
    strcat(loc,namein);
    //open file in read mode
    fp = fopen(loc, "r");
    fgets(str,100,fp);
    size = atoi(str);
    printf("Code \t\t\tName\t\price\trating\n");
 //   y
    for(int i=0;i<size;i++)
    {
        fgets(str,100,fp);
       str[(strlen(str)-1)]='\0';
       puts(str);
    }
    fclose(fp);
}
int calc_total()
{   int total=0;
    for(int i=0;i<cartsize;i++)
    {
        total+=C1[i].price;
    }
    return(total);
}

void display_products()
{   char ch,name[30];int choice,qty,pr,code;char ele[20]="electronics",spo[20]="sports",sta[20]="stationary",chh[20];float rating;chh[0]='\o';
    system("cls");
    printf("enter product category\n");
    P:
        chh[0]='\0';
    printf("1.electronics\n2.sports\n3.stationary\n4.back\n");
        printf("enter you choice\n");
         scanf("%d",&choice);
            switch(choice)
            {
                case 1: ch=1;strcpy(chh,ele);break;
                case 2: ch=2;strcpy(chh,spo);break;
                case 3: ch=3;strcpy(chh,sta);break;
                case 4: p=3;return;
                default:printf("invalid choice\n");
                goto P;
            }

    for(;;)
    {  system("cls");
        display_products_sub1(chh);
    printf("1.add a product\n2.back\n");
        printf("enter you choice\n");
         scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("enter the product code\n");
                        scanf("%d",&code);
                        printf("enter the quantity\n");
                        scanf("%d",&C1[cartsize].qty);
                        updatecart(code,&pr,name,&rating,chh);
                        strcpy(C1[cartsize].name,name);
                       // puts(C1[cartsize].name);
                        getch();
                        C1[cartsize].price=pr;
                        C1[cartsize].rating=rating;
                        C1[cartsize].code=code;cartsize++;
                        break;
                case 2:goto P;
                default:printf("invalid choice reenter\n");
            }
    }

}

void updatecart(int code, int *price,char name[],float *rating,char names[])
{           name[0]='\0';
            char str[100],codearr[100],ch,namein[20];
            long int j,pr,flag=0;
            float real;
      char loc[50]="C:\\Users\\admin\\Desktop\\project\\products\\";
    int size;
    strcpy(namein,names);
    strcat(namein,txt);
    strcat(loc,namein);
    fp=fopen(loc,"r");
      fgets(str,100,fp);
    size = atoi(str);
       for(int i=0;i<size;i++)
    {
        fgets(str,100,fp);
               //
       str[(strlen(str)-1)]='\0';

       for( j=0;j<4;j++)       //CHECK IF THE CODE MATCHES WITH ANY PRODUCT CODE
            {codearr[j]=str[j];

            }codearr[j]='\0';
  //      printf("%d\n",atoi(codearr));
       if(code==atoi(codearr))
       {   flag++;
           printf("item %d updated to cart",atoi(codearr));
               //printf("%d\n",C1[0].code);
           int m=13,f=0;
           ch=str[m];
           while(ch!=' ')
           {
               name[f]=ch;

               f++;
               m++;
               ch=str[m];
           }
           name[f]='\0';//puts(name);
           m=37;f=0;
           codearr[0]='\0';
           ch=str[m];
           while(ch!=' ')
           {
               codearr[f]=ch;

               f++;m++;
               ch=str[m];
           }
           codearr[f]='\0';
           pr=atoi(codearr);//printf("%d",pr);
           *price=pr;
           m = strlen(str)-5;
          //
           real=str[m]-48;
           m+=2;
           codearr[0]='\0';
           f=0;

           for(int i=0;i<3;i++,f++,m++)
               codearr[f]=str[m];

           codearr[f]='\0';
           real=real + (float)atoi(codearr)/1000;
       // printf("%f\n",real);
        *rating=real;
        return;
       }
       str[0]='\0';
       codearr[0]='\0';
       }

   fclose(fp);
   if(flag==0)
    printf("invalid code");

}

void display_cart_sub1()
{   int i=0;
    printf("\tcode\tname\t\t\tprice");
    for(i=0;i<cartsize;i++)
    {
        gotoxy(8,i+2);printf("%d",C1[i].code);
        gotoxy(16,i+2);printf("%s",C1[i].name);
        gotoxy(40,i+2);printf("%d",C1[i].price);
    }
    printf("\n\ttotal:");gotoxy(40,i+2);printf("%d\n",calc_total());
}
void display_cart()
{         char name[100],sure;
int price=0,qty,code,choice;
float rating=0;
          while(1)
    {   system("cls");
        if(cartsize==0)
        {
            printf("cart is empty press any key\n");
            getch();p=3;
            return;
        }

        display_cart_sub1();
        printf("1.delete item\n2.check out\n3.back");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1 :
          printf("enter the product code and quantity\n");
          scanf("%d%d",&code,&qty);
          deletecart(code,qty);
          cartsize--;
          break;
          case 2:
           printf("are you sure y\n");
           yesorno(&sure);
           if(sure=='y')
               place_order();
           break;
          case 3:
              p=3;
            return;
        }
    }
}
void adminlogin()
{  char admin_pass[20]="believe",password[20],ch;int choice;
   system("cls");printf("enter the admin password\n");
   password_enter(password);
   if(strcmp(admin_pass,password)==0)
   {  system("cls");
       printf("\n    login successful  \n");
    }
   else
   {
       printf("invalid password\n");
       p=100;
       return;
   }
    system("cls");
       printf("\n    orders list: \n");

    for(;;)
        {   system("cls");
            admin_orders();
       /*   for(int i=0;i<pcsize;i++)
          {
              for(int j=0;j<6;j++)
              {
                  printf("%c",pc[i][j]);
              }
              printf("\n");
          }*/
            shortest_path_for_delivery();
            pcsize=0;
            printf("\n\nthe shortest path for delivery is :\n");
            for(int i=0;i<7;i++)
                printf("%d\t",sequenceg[i]);
           // if(pcsize<7)
             //   printf("dispach not required, too less orders\n");
            printf("\n1.dispach\n2.back\nenter your choice\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    dispach();
                    printf("\nare you sure you want to dispach\n");
                    yesorno(&ch);
                    if(ch=='y')
                        dispach();
                    break;
                case 2:
                    p=10000;
                    return;
                default:printf("invalid choice reenter\n");
            }
        }
}
void dispach()
{
     char str[100],loc[50]="C:\\Users\\admin\\Desktop\\project\\products\\";
    int size,insize;FILE *fp1;
    //open file in read mode
    fp = fopen("C:\\Users\\admin\\Desktop\\project\\orders.txt", "r");
    fp1 = fopen("C:\\Users\\admin\\Desktop\\project\\replica.txt","w");
    fgets(str,100,fp);
    size = atoi(str);int k=size;
    if(k>8)
        k=8;
    for(int i=0;i<size;i++)
    {
        fgets(str,100,fp);insize=atoi(str);//insize--;
        for(int j=0;j<insize;j++)
        {
            fgets(str,100,fp);
        }
    }
    size=size-k;str[0]=(size)/10+'0';str[1]=size%10+'0';str[2]='\0';
    fputs(str,fp1);
    for(int i=0;i<size-k;i++)
    {
        fgets(str,100,fp);insize=atoi(str);//insize--;
        for(int j=0;j<insize;j++)
        {
            fgets(str,100,fp);
            fputs(str,fp1);
        }
    }
    fclose(fp);fclose(fp1);
    remove("C:\\Users\\admin\\Desktop\\project\\orders.txt");
    //rename the file replica.c to original name
    rename("C:\\Users\\admin\\Desktop\\project\\replica.txt", "C:\\Users\\admin\\Desktop\\project\\orders.txt");
}
/*void write_feedback()
{   struct DATE dateo;char clone1[30],clone2[30];FILE *fp1;
    strcpy(clone1,userg);strcpy(clone2,strst);
    strcat(clone1,txt);
    strcat(clone2,clone1);
    printf(" enter todays date in dd mm yy format\n");
    scanf("%d %d %d",&dateo.dd,&dateo.mm,&dateo.yy);
    fp=fopen("C:\\Users\\admin\\Desktop\\project\\accounts\\replica.txt","w");
    fp1 =  fopen(clone2,"r");
    fgets(str,100,fp1);int insize;
    size = atoi(str);
    str[0]=size+49;
    str[1]='\0';
    fputs(str,fp);
    fputs("\n",fp);
    for(i=0;i<size;i++)
    {  int j;
    fgets(str,100,fp1);
    str[strlen(str)]='\0';
     insize=atoi(str);
     fputs(str,fp);
 //    fputs("\n",fp);
  //   printf("%d\t%d\n",insize,size);
        for(j=0;j<insize;j++)
        {
            fgets(str,100,fp1);
            str[strlen(str)]='\0';
            fputs(str,fp);
}*/
void main_page()
{   system("cls");
        for(int j=0;j<20;j++)
    {system("cls");printf("\n");
    printf("  _____                _______        ______      _______         ______   ______   _____  _______         ______\n");
    printf(" |     | |\\   | |         |    |\\   ||            |       |    | |      | |      | |     |    |    |\\   | |      \n");
    printf(" |     | | \\  | |         |    | \\  ||_____       |______ |____| |      | |______| |_____|    |    | \\  | |   __ \n");
    printf(" |     | |  \\ | |         |    |  \\ ||                  | |    | |      | |        |          |    |  \\ | |  |  | \n");
    printf(" |_____| |   \\| |_____ ___|___ |   \\||_____       ______| |    | |______| |        |       ___|___ |   \\| |_____| \n");
    printf("                          _______        ______  _________  _____\n");
    printf("                          |        \\  / |            |     |       |\\  /|\n");
    printf("                          |______   \\/  |_____       |     |_____  | \\/ |\n");
    printf("                                |   /         |      |     |       |    |\n");
    printf("                          ______|  /     _____|      |     |_____  |    |");
    gotoxy(0,13);
    printf("done by\n");
    printf(" _____        _____                 \\  /    ____  \n");
    printf("|       |__|    |    |\\ | |\\/|  /\\   \\/    |____   \n");
    printf("|_____  |  |  __|__  | \\| |  | /  \\  /      ____| \n");
    //printf("          Chinmay S,");
   // printf("Abhishek Gupta,Deekshith Pruthviraj and Chethan Patel");
    gotoxy(0,0);printf("-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    gotoxy(0,12);printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    for(int p=0;p<100000;p++)
    for(int i=0;i<100;i++);
    gotoxy(0,0);printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    gotoxy(0,12);printf("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    for(int p=0;p<100000;p++)
    for(int i=0;i<100;i++);
    gotoxy(0,0);printf("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -   -");
    gotoxy(0,12);printf("-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    for(int p=0;p<100000;p++)
    for(int i=0;i<100;i++);
    gotoxy(0,0);printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    gotoxy(0,12);printf(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    }
}
void deletecart(int code,int qty)
{   int count=0;
    for(int i=0;i<cartsize;i++)
    {
        if(C1[i].code==code)
        {   if(C1[i].qty>qty)
                {C1[i].qty-=qty;return;}
            for(int j=i;j<cartsize-1;j++)
            {
                C1[j]=C1[j+1];
                count++;
            }
        }
    }
    if(count==0)
        printf("item not fount\n");
}
void convert(int pr, char price[])
{ char ch[3];
    for(;;)
        {   if(pr/10==0)
        {
            ch[0]=pr%10+48;
            ch[1]='\0';
            strcat(price,ch);
            strrev(price);
    //        price[strlen(price)-1]='\0';
            return;
        }
            ch[0] = pr%10+48;
            ch[1]='\0';
            strcat(price,ch);
            pr/=10;
        }

}
void place_order()
{   struct DATE dateo;char str[100],clone1[30],clone2[60];int size,p,k;char ch[2],price[20];
    printf("enter todays date\n");
    scanf("%d %d %d",&dateo.dd,&dateo.mm,&dateo.yy);
    int i;FILE *fp1;
    strcpy(clone1,userg);strcpy(clone2,strst);
    strcat(clone1,txt);
    strcat(clone2,clone1);puts(clone2);
    fp=fopen("C:\\Users\\admin\\Desktop\\project\\accounts\\replica.txt","w");
    fp1 =  fopen(clone2,"r");
    fgets(str,100,fp1);int insize;
    size = atoi(str);
    size++;
    str[0]='\0';
    myitao(size,str);
    size--;
    fputs(str,fp);
    fputs("\n",fp);
    for(i=0;i<size;i++)
    {  int j;
    fgets(str,100,fp1);
    str[strlen(str)]='\0';
     insize=atoi(str);
     fputs(str,fp);
 //    fputs("\n",fp);
  //   printf("%d\t%d\n",insize,size);
        for(j=0;j<insize;j++)
        {
            fgets(str,100,fp1);
            str[strlen(str)]='\0';
            fputs(str,fp);
      //      fputs("\n",fp);
        }
    }
    str[0]=cartsize+49;
    str[1]='\0';
    fputs(str,fp);
    fputs("\n",fp);
    int j=0,pr;
    for(i=0;i<cartsize;i++)
    {   for( j =0;C1[i].name[j]!='\0';j++)
        {
          str[j] = C1[i].name[j];
        }
        str[j]='#';
        j++;
        for(;j<30;j++)
            str[j]=' ';
        str[j]=C1[i].qty+48;
        j++;
        str[j]='#';
        j++;
        for(;j<35;j++)
            str[j]=' ';
        pr=C1[i].price;
        convert(pr,price);//printf("%d",strlen(price));
        for( p=0;p<strlen(price);p++,j++)
        {
            str[j]=price[p];
        }j++;
      //   str[j]='#';
    //    j++;
        str[j]='\0';
        fputs(str,fp);
   //     if(size == 0||size == 1)
         fputs("\n",fp);
     //   puts(str);
        str[0]='\0';
        price[0]='\0';
    }//printf("%d\n",i);
   str[0]='\0';
   convertdate(dateo,str);
    for( p=9;p<15;p++)
       str[p]=' ';
    str[p]='\0';
    strcat(str,pincodeg);
    for(p=21;p<23;p++)
        str[p]=' ';//fputs("\n",fp);
        str[p]='\0';
    price[0]='\0';k=calc_total();
    myitao(k,price);
    strcat(str,price);price[0]='\0';
    k=strlen(str);str[k]=' ';k++;str[k]='\0';
    fputs(str,fp);
    fputs("\n",fp);//puts(clone2);getch();
     fclose(fp);
    fclose(fp1);
    remove(clone2);
    //rename the file replica.c to original name
    rename("C:\\Users\\admin\\Desktop\\project\\accounts\\replica.txt", clone2);
    update_ordersfile(dateo);
    for(int pk=0;pk<cartsize;pk++)
       C1[pk].name[0]='\0';
    cartsize =0;
}
void convertdate(struct DATE dateo,char str[])
{
    char sss[5]="";int k;
    if(dateo.dd/10!=0)
    {
        str[0]='0';
        str[1]=dateo.dd+'0';
    }
    str[0]=dateo.dd/10+'0';
    str[1]=dateo.dd%10+'0';
    str[2]='-';
    if(dateo.dd/10!=0)
    {
        str[3]='0';
        str[4]=dateo.mm+'0';
    }
    str[3]=dateo.yy/10+'0';
    str[4]=dateo.yy%10+'0';
    str[5]='-';
    if(dateo.dd/10!=0)
    {
        str[6]='0';
        str[7]=dateo.yy+'0';
    }
 //   strrev(sss);
    str[6]=dateo.yy/10+'0';
    str[7]=dateo.yy%10+'0';
    str[8]=' ';
//  str[strlen(str)]='-';
 //   strrev(str);
}
void update_ordersfile(struct DATE dateo)
{   char str[50];int size,p,k,i,j,pr;char ch[2],price[20],sss[20];
    FILE *fp1;
    fp=fopen("C:\\Users\\admin\\Desktop\\project\\replica.txt","w");
    fp1 =  fopen("C:\\Users\\admin\\Desktop\\project\\orders.txt","r");
    fgets(str,100,fp1);
    int insize;
    size = atoi(str);
    size++;
    str[0]='\0';
    myitao(size,str);
    size--;
    fputs(str,fp);
    fputs("\n",fp);
    for(i=0;i<size;i++)
    {  int j;
    fgets(str,100,fp1);
    str[strlen(str)]='\0';
     insize=atoi(str);
     fputs(str,fp);
 //    fputs("\n",fp);
  //   printf("%d\t%d\n",insize,size);
        for(j=0;j<insize;j++)
        {
            fgets(str,100,fp1);
            str[strlen(str)]='\0';
            fputs(str,fp);
      //      fputs("\n",fp);
        }
    }
    str[0]=cartsize+49;
    str[1]='\0';
    fputs(str,fp);
    fputs("\n",fp);
    for(i=0;i<cartsize;i++)
    {   for( j =0;j<strlen(C1[i].name);j++)
        {
          str[j] = C1[i].name[j];
        }
        str[j]=' ';
        j++;
        for(;j<30;j++)
            str[j]=' ';
        str[j]=C1[i].qty+48;
        j++;
        str[j]=' ';
        j++;
        for(;j<35;j++)
            str[j]=' ';
        pr=C1[i].price;
        convert(pr,price);//printf("%s",price);
        for( p=0;p<strlen(price);p++,j++)
        {
            str[j]=price[p];
        }//j++;
      //   str[j]='#';
    //    j++;
        str[j]='\0';
        fputs(str,fp);
      //  if(size == 0||size == 1)
         fputs("\n",fp);
     //   puts(str);
        str[0]='\0';
        price[0]='\0';
    }//printf("%d\n",i);
   str[0]='\0';
   convertdate(dateo,str);
    for( p=9;p<15;p++)
       str[p]=' ';
   // str[p]='\0';
    for(p=16,j=0;j<strlen(userg);j++,p++)
    {
        str[p]=userg[j];
    }
    for( p;p<35;p++)
       str[p]=' ';
    for(j=0,p;j<strlen(pincodeg);p++,j++)
       str[p]=pincodeg[j];
    str[p]='\0';
    for(p=41;p<43;p++)
        str[p]=' ';//fputs("\n",fp);
        str[p]='\0';
    price[0]='\0';k=calc_total();
    myitao(k,price);
    strcat(str,price);price[0]='\0';
   // strcat(str,pincodeg);
    //puts(str);
    //fputs("\n",fp);
    strcat(str,price);price[0]='\0';
    k=strlen(str);str[k]=' ';k++;str[k]='\0';
    fputs(str,fp);
    fputs("\n",fp);//puts(clone2);getch();
     fclose(fp);
    fclose(fp1);
    remove("C:\\Users\\admin\\Desktop\\project\\orders.txt");
    //rename the file replica.c to original name
    rename("C:\\Users\\admin\\Desktop\\project\\replica.txt", "C:\\Users\\admin\\Desktop\\project\\orders.txt");
}//void place_order()
void yesorno(char *ch)
{
     printf("say y/n");
     scanf("%c",ch);
     if(*ch=='y'||*ch=='Y')
        return;
     else if(*ch=='n'||*ch=='N')
        return;
     printf("invalid choice/n");
     yesorno(ch);
}
void login_page()
{   system("cls");
    char m;int choice;
    printf("are you an admin say y/n");
    yesorno(&m);
    if(m=='y')
       {
           p=0;return;
       }
    if(m=='n');
    {
        for(;;)
        {
            printf("1.login\n2.signup\n3.back\nenter your choice\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:p=1;return;
                case 2:p=-1;return;
                case 3:p=0;return;
                default:
                    printf("invalid choice re-enter\n");
            }
        }
    }
}
void login_menu()
{int choice;
    for(;;)
    {   system("cls");
        printf("1.display products\n2.display cart\n3.display previous orders\n4.back\n");
        printf("enter you choice\n");
         scanf("%d",&choice);
            switch(choice)
            {
                case 1: p=4;return;
                case 2: p=5;return;
                case 3: p=6;return;
                case 4: p=100;return;
                default:printf("invalid choice reenter\n");getch();
        }
    }
}

int main()
{

  //       gets(str1);

    int l=2000,funno=100,u[8]={10,20,30,55,4,60,37};
  //  dateo.dd=11;dateo.dd=12;dateo.dd=20;
   // generate_seq(u);
    //for(int i=0;i<7;i++)
    //   printf("%d\t%d\n",sequence[i],sequenceg[i]);
    main_page();
 //  for(int i=0;i<5;i++)
//   sign_up();
   //  place_order();
  // convert(l,str);
   //puts(str);
 //  login_user();
   //strrev(str);
   //puts(str);
  // struct DATE dt={4,12,20};
  // convertdate(dt,str);
  // puts(str);
 // display_products();
//update_ordersfile(dateo);
//adminlogin();
//admin_orders();
//prev_orders();while(1)
///*
while(1)
{
  // printf("yako hing aadtya\n");
     if(funno==1)
       {
           login_user();
                funno=p;
      }
      else if(funno==-1)
          {sign_up();funno=p;}

      else if(funno==0)
          {adminlogin();funno=p;}

      else if(funno==3)
      {login_menu();funno=p;}

     else if(funno==4)
         {display_products();funno=p;}

     else if(funno==5)
         {display_cart();funno=p;}

     else if(funno==6)
         {
             prev_orders();funno=p;}

     else
         {login_page();funno=p;}

}printf("yako hing aadtya\n");
//*/

}
