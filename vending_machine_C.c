#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <string.h>
#include<stdlib.h>

#define DRINKS  3

#define COFFEE  0
#define TEA     1
#define HOTCOCO 2



#define INITIAL_COFFEE_DOZES  3
#define INITIAL_TEA_DOZES  3
#define INITIAL_HOTCOCO_DOZES  3



#define COFFEE_NAME "Coffee"
#define TEA_NAME     "Tea" 
#define HOTCOCO_NAME "Hot coco"

#define COFFEE_ML 30
#define TEA_ML 100
#define HOTCOCO_ML 100

#define COFFEE_PRICE  4
#define TEA_PRICE     3
#define HOTCOCO_PRICE 5

#define MAXNAME 15
typedef struct s_drink {
        char d_name[MAXNAME];
        int  d_available_quantity;
        int  d_price;
        int  d_water_ml;

 } t_drink;

t_drink drinks[DRINKS];  // array of 3 structs of type t_drink





#define INITIAL_WATER_MLs  600
int water ;



int suggar;
#define INITIAL_SUGGAR_MGs  1000
#define SL_STEP 



int canserve;


#define MAXCOINS        3
#define ONE_DH_COIN     2
#define TWO_DH_COIN     1
#define FIVE_DH_COIN    0

#define VAL_ONE_DH_COIN 1
#define VAL_TWO_DH_COIN 2
#define VAL_FIVE_DH_COIN 5

int available_coins[MAXCOINS];



#define INITIAL_ONE_DH_COINS    5
#define INITIAL_TWO_DH_COINS    5
#define INITIAL_FIVE_DH_COINS   0


int get_user_choice(void );
void serve_drink(int choice, int sl);
void print_available_quantities(void);
void init_vending_machine(void);
int get_payment(int);
void deliver_change(int,int*);
void return_coin(int );
void welcome(void);
void stop_vending_machine(void);
int get_suggar_level(void);


int main(int argc, char *argv[])
{
  int c,change,s;
 
    init_vending_machine();
    do {

    print_available_quantities();  
    c=get_user_choice ();
    s=get_suggar_level();
    if(suggar<s) {
        printf("Not enough suggar\n");
        continue;
    }
    change=get_payment(c);
    if(change)
        deliver_change(change,&c);
    serve_drink(c,s);
   
  }while(canserve==1);
  stop_vending_machine();
 
 
  return 0;
}
void init_vending_machine()
{
      strcpy(drinks[0].d_name,"Coffee");
      drinks[0].d_available_quantity=3;
      drinks[0].d_price=4;
      drinks[0].d_water_ml=COFFEE_ML;
      strcpy(drinks[1].d_name,"Tea");
      drinks[1].d_available_quantity=INITIAL_TEA_DOZES;
       drinks[1].d_price=TEA_PRICE;
      drinks[1].d_water_ml=TEA_ML;
      strcpy(drinks[2].d_name,"Hot coco");
      drinks[2].d_available_quantity=INITIAL_HOTCOCO_DOZES;
      drinks[2].d_price=HOTCOCO_PRICE;
      drinks[2].d_water_ml=HOTCOCO_ML;
      available_coins[0]=5;
      available_coins[1]=5;
      available_coins[2]=0;
      water=INITIAL_WATER_MLs;
      suggar=INITIAL_SUGGAR_MGs;
      canserve=1;
   

   

}
void start_vending_machine()
{
printf("welcome to aui vending machine\n");
PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\welcome.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);

}
void print_available_quantities(){
    printf("We will display our available quantities knowing that drink 0 refers to coffee and drink 1 refers to tea and drink 2 refers to  HOTCOCO\n\n");
//printf("%d\n",available_quantities[0]);
for (int i=0;i<DRINKS;i++)

{if(drinks[i].d_available_quantity>0)

       printf("drink %d: %d\t\t\t\t",i, drinks[i].d_available_quantity);}
if (water>=0)
        printf("\nquantity available of water is %d ml\t\t\t\t",water);
//else if (water<=30)
      //{  printf("\n ---------------------------------------------------\nsince our machine is out of order we will turn off the vending machine until it is recharged again \n-------------------------- ");
        //exit();
       
      //0  canserve=0;}

if(suggar>=0)
    printf(" quantity avalable of sugar is %d", suggar);
    printf("\n------------------------------------------\n");
     printf (" 1dhs coins avaible  : %d coins\t\t",  available_coins[0]);
    printf (" 2dhs coins avaible  : %d coins\t\t",  available_coins[1]);
      printf (" 5dhs coins avaible  : %d coins\t\t",  available_coins[2]);


}
int get_user_choice(void )
{      
      printf("Please would you choose?\n");
     
        if (drinks[0].d_available_quantity>0)
            printf("For coffe choose 0\n");
            if (drinks[1].d_available_quantity>0)
            printf("for tea choose 1\n");
            if (drinks[2].d_available_quantity>0)
            printf("for hot coco choose 2\n");
      int choice;
      scanf("%d", &choice);
      PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
      if(choice==0 || choice==1 || choice==2)
      return (choice);
      else
        return (-1);
   
}
int get_suggar_level(void)
{ int level=5;
while(level!=0 && level!=1 && level !=2)
      {  printf("please enter the level of sugar\nwe do have 3 levels\n level0=0mg \t\t\tlevel1=20mg\t\t\tlevel2=50mg\n ");
        printf("enter either 0 or 1  or 2\n");
        scanf("%d",&level);
        PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
      }
     
        return(level);


}
int get_payment(int choice)
{
int coins,moneypay,moremoney,moneytopay,change;

  if (choice==0)
       
 { moneytopay=COFFEE_PRICE;
 label0:
        printf("Would u pls pay %d MAD\n",moneytopay);
        scanf("%d", &coins);
        PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
    available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
     

while(moneytopay>0 && (coins==1 || coins==2 || coins==5) )
       
 { printf("pay pls %d mad\n",moneytopay);
        scanf("%d", &coins);
        PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
   available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
      }}}

 
if (moneytopay!=0)
 {if (coins!=1 && coins!=2 && coins!=5)
 {
    printf("pls insert accepted coins only which are 1 MAD 2 MAD and 5 MAD\n");
    goto label0;
 }}
 if (moneytopay<=0)
 {   printf("paiement succesful\n");
   moneytopay=moneytopay*(-1);
 



 }
}
if (choice==1)
       
 { moneytopay=TEA_PRICE;
 label1:
        printf("would u pls pay %d MAD\n",moneytopay);
        scanf("%d", &coins);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
   available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
     

while(moneytopay>0 && (coins==1 || coins==2 || coins==5) )
       
 { printf("pay pls %d mad\n",moneytopay);
        scanf("%d", &coins);
       PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
   available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
      }}}

 
if (moneytopay!=0)
 {if (coins!=1 && coins!=2 && coins!=5)
 {
    printf("pls insert accepted coins only which are 1 MAD 2 MAD and 5 MAD\n");
    goto label1;
 }}
 if (moneytopay<=0)
 {   printf("paiement succesful\n");
   moneytopay=moneytopay*(-1);
 



 }
}
if (choice==2)
       
 { moneytopay=HOTCOCO_PRICE;
 label2:
        printf("would u pls pay %d MAD\n",moneytopay);
        scanf("%d", &coins);
       PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
   available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
     

while(moneytopay>0 && (coins==1 || coins==2 || coins==5) )
       
 { printf("pay pls %d mad\n",moneytopay);
        scanf("%d", &coins);
        PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\ok.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
    if (coins==1 || coins==2 || coins==5)
      {  
       if (coins==1)
    {  
    moneytopay=moneytopay-1;
   available_coins[0]=available_coins[0]+1;


    }
    else  if (coins==2)
    {  
    moneytopay=moneytopay-2;
   available_coins[1]=available_coins[1]+1;


    }  
    else if (coins==5)
    {  
    moneytopay=moneytopay-5;
   available_coins[2]=available_coins[2]+1;}
      }}}

 
if (moneytopay!=0)
 {if (coins!=1 && coins!=2 && coins!=5)
 {
    printf("pls insert accepted coins only which are 1 MAD 2 MAD and 5 MAD\n");
    goto label2;
 }}
 if (moneytopay<=0)
 {   printf("paiement succesful\n");
   moneytopay=moneytopay*(-1);
 }
}
return (moneytopay);}

void deliver_change(int change,int* uchoice)
{     if (change==0) printf("there is no change\n");
      while (change!=0)
      {if (available_coins[2]>0)
      { while (change>=5)
      { if (available_coins[2]>0)
         { change=change-5;
          available_coins[2]=available_coins[2]-1;
          printf("\n pick up your 5 dhs\n");}
      }
      }
      if (available_coins[1]>0)
{      while (change>=2)
      { if (available_coins[1]>0)
      {
          change=change-2;
          available_coins[1]=available_coins[1]-1;
          printf("\n pick up your 2 dhs\n");}
PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\change.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
      }}
      if (available_coins[0]>0)
    {  while (change>=1)
      { if (available_coins[0]>0)
      {
          change=change-1;
          available_coins[0]=available_coins[0]-1;
          printf("\n pick up your 1 dh\n");
          PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\change.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);


      }}}

       if(change>0) {
        PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\glitch.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
        printf("there is no available coins no more, we are sorry for not delivring your change\n");
        canserve=0;
        printf("if you want to still order without taking the change left press 1 otherwise if you want to cancel the whole order press any other key\n ");
       
        int cancel;
        scanf("%d",&cancel);
                if (cancel==1)
                {
                  *uchoice=-(*uchoice+1);
                  break;


                }
                else 
                {
                  printf("thank you, we will try to recharge ourvending machine with coins ;), try to reach our staff \n");
                  exit(0);
                }
       
      }
      }
   
      }
     
 void serve_drink(int choice, int suggarmg)
      {         if(choice==-1)
                  {printf("we will recharge our vending machine with change, thank you\n");
                 
                 PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\glitch.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
                 printf("pick up your cofee \n");
                  canserve=0;

                  exit(0);
                  }
                    if(choice==-2)
                  {printf("we will recharge our vending machine with change, thank you\n");
                 
                  PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\glitch.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
                 printf("pick up your tea \n");
                  canserve=0;

                  exit(0);
                  }
                    if(choice==-3)
                  {printf("we will recharge our vending machine with change, thank you\n");
                 
                 PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\glitch.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
                 printf("pick up your hot coco \n");
                  canserve=0;

                  exit(0);
                  }
              if (choice==0)
              {
                  drinks[0].d_available_quantity= drinks[0].d_available_quantity-1;
                  water=water-30;
                  printf("pick up your coffee\n");
              PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\preparation.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);


              }
               if (choice==1)
              {
                   drinks[1].d_available_quantity= drinks[1].d_available_quantity-1;
                  water=water-50;
                   printf("pick up your tea");
                   PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\preparation.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);

              }
               if (choice==2)
              {
                   drinks[2].d_available_quantity= drinks[2].d_available_quantity-1;
                  water=water-50;
                 PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\preparation.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
                   printf("pick up your hot coco");



              }
              if (suggarmg==0)
                {suggar=suggar-0;}
              else if (suggarmg==1)
                {suggar=suggar-30;}
                else  if (suggarmg==2)
               { suggar=suggar-50;}


            if (suggarmg==0 || water<=30
            )
            canserve=0;}
void stop_vending_machine(void) {
 
        printf("Machine out of order since we run out either from water or sugar");
PlaySound("C:\\Users\\user\\Downloads\\sound files (1)\\sound files\\glitch.wav",NULL,SND_SYNC | SND_LOOP | SND_FILENAME);
}