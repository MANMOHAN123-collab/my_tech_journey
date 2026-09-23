# include<stdio.h>
# include<math.h>
# include<stdlib.h>
# include<time.h>
int main() {
   int choice,pin,no,ch,old,newpin,new;
   long long number,account,Reciever;
   float amount,Rs,withdrawl,RAmount;
   char Name[50];
   long long Accno=(rand()%9+1);
   srand(time(NULL));
   printf("========================================\n======Canara Banking Online System======\n========================================\n");
   printf("1.Create new Account\n");
   printf("2.Login\n");
   printf("3.Exit\n");
   printf("****Please select your choice*****\n");
   printf("Enter your choice no.: ");
   scanf("%d",&choice);
   switch (choice){
      case 1:
      printf("-----Create your Account-----\n");
      printf("Enter your name: ");
      getchar();
      fgets(Name, sizeof(Name),stdin);
      while(1){
         printf("Enter your mobile no.: ");
         scanf("%lld",&number);
         if(number>=1000000000 && number<=9999999999){
         printf("valid mobile no.>>> \n");
          break;}
          else{
            printf("Invalid mobile no.!! Try again.\n");
          }
      }
      while(1){
         printf("Create 4 digit pin: ");
         scanf("%d",&pin);
         if(pin>=1000 && pin<=9999){
            printf("Valid pin>>>>\n");
            break;
         }else{
            printf("Please enter only 4 digits \n");
         }
      }
      
      printf("Enter Initial Deposit: ");
      scanf("%f",&amount);
      printf("******************************\n Account Created Succesfully\n******************************\n");
      printf("Name: %s\n",Name);
      printf("Mobile no.: %lld\n",number);
      for (int i=0;i<9;i++){
         Accno=Accno*10+rand()%10;
      }
      printf("Account no.: %lld",Accno);
        printf("\n");
      printf("Press Enter for login........");
      getchar();
      getchar();
      while(1){
      printf("******************************\nLogin\n******************************\n");
      printf("Enter only last 4 digit of your account no.: ");
      scanf("%lld",&account);
      printf("Enter your pin: ");
      scanf("%d",&no);
      if(account==Accno%10000 && no==pin){
         printf("------------------------------------------------------------\n");
         printf("****WELCOME****\nLogin Succesfull\n");
         printf("%s\n",Name);
         break;

      }else{
         printf("!! Invalid Account no. or pin !!\n ");
      }}
      printf("------------------------------------------------------------\n");
      printf("1.Check Balance\n");
      printf("2.Deposit Money\n");
      printf("3.Withdraw Money\n");
      printf("4.Transfer money\n");
      printf("5.Change pin\n");
      printf("6.Logout\n");
      printf("------------------------------------------------------------\n");
      printf("Enter your choice: ");
      scanf("%d",&ch);
      switch (ch){
         case 1:
         printf("Current balance: Rs.%.2f\n",amount);
         break;
         case 2:
         printf("Enter Deposit money: ");
         scanf("%f",&Rs);
         printf("Deposit Succesfull !\n");
         printf("Current balance: Rs.%.2f\n",amount+Rs);
         break;
         case 3:
         
         while(1){
         printf("Enter Withdrawl money: ");
         scanf("%f",&withdrawl);
         if(withdrawl<=amount){
         printf("Withdrawl Succesfull\n");
         printf("Current balance: Rs.%.2f\n",amount-withdrawl);
          break;
          }
         else{
            printf("Please enter sufficient balance !!\n");
            
         }}break;
         case 4:
         
         while(1){
         printf("Enter Reciever Account no.: ");
         scanf("%lld",&Reciever);
         printf("Enter Amount: ");
         scanf("%f",&RAmount);
         if(RAmount<=amount){
         printf("Transfer Succesfull !!\n");
         printf("Current balance: Rs.%.2f\n",amount-RAmount);
         break;}
         else{
            printf("Please enter sufficient balance !!\n");
         }}break;
         case 5:
         
            while(1){
              printf("Enter old pin: ");
              scanf("%d",&old);
              if(old==pin){
               while(1){
               printf("Enter new pin: ");
               scanf("%d",&new);
               printf("confirm New pin: ");
               scanf("%d",&newpin);
                if(new==newpin){
           
              printf("****PIN changed Succesfully****\n");
              break;} 
                else{
              printf("Both new pin are not same!!!\n");
         }}
             break; } 
              else{
               printf("Please Enter correct old pin!!\n");
              }
            }
         
         
         break;
         case 6:
         printf("Logged out Succesfully......\nThank for your Banking with us.");
         break;



      } break;
      case 2:
      printf("No Account found...!\n Please create a new account first,,,,\n");
      break;
      case 3:
      printf("Thank you!! for using canara banking system !!\nHave a nice day..\n");
      break;
      
   
   
   
   
   }

printf("^^Thank you for using canara banking online system^^\n");   
printf("Designed by \n****MANMOHAN SINGH***");
     
   return 0;
}