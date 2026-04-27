// EXPENSE TRACKER
#include<stdio.h>

enum Categeories{
SHOPPING,
ENTERTAINMENT,
GENERAL,
BILLS, 
HEALTH 
};

typedef struct Expense{
int amount;
enum Categeories category;
}Expense;

typedef struct Budget{
int Shopping;
int Entertainment;
int General;
int Bills;
int Health;
}Budget;



int main(){
    printf("EXPENSE TRACKER!!!\n");

    char decision;
    Budget B;
    Expense E;
    int Salary;
    int totalBudget;
    int choice;
    FILE *fptr;

    printf("Enter the Your Salary:");
    scanf("%d",&Salary);

printf("\n");
while(1){
      do{
        printf("Enter budget for Shopping: ");
        scanf("%d", &B.Shopping);
        if (B.Shopping < 0)
            printf("Invalid!\n");
    }while(B.Shopping < 0);

    do {
        printf("Enter budget for Entertainment: ");
        scanf("%d", &B.Entertainment);
        if (B.Entertainment < 0)
            printf("Invalid!\n");
    }while(B.Entertainment < 0);

    do {
        printf("Enter budget for General: ");
        scanf("%d", &B.General);
        if (B.General < 0)
            printf("Invalid!\n");
    }while(B.General < 0);

    do {
        printf("Enter budget for Bills: ");
        scanf("%d", &B.Bills);
        if (B.Bills < 0)
            printf("Invalid!\n");
    }while(B.Bills < 0);

    do {
        printf("Enter budget for Health: ");
        scanf("%d", &B.Health);
        if (B.Health < 0)
            printf("Invalid!\n");
    }while(B.Health < 0);

    totalBudget=B.Shopping+B.Entertainment+B.General+B.Bills+B.Health;

    if(totalBudget>Salary){
        printf("Budget is   Inavalid\n");
    }
    else{
        printf("Budget is Fine\n");
        break;
    }
}
  
while(1){
    printf("\n");
    printf("1,Add Expense\n");
    printf("2,Show Expense\n");
    printf("3,Exit\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
        switch(choice){
        case 1:
        decision='Y';
        while(decision=='Y'){
        printf("\n");
        printf("Select the Categeorie\n");
        printf("0-Shopping\n 1-Entertainment\n 2-General\n 3-Bills\n 4-Health\n");
        printf("Select:");
        scanf("%d",&E.category);
          if(E.category<0 || E.category>4){
            printf("Invalid\n");
            break;
        }
        printf("Enter the amount to spend:");
        scanf("%d",&E.amount);

         if(E.amount<=0){
            printf("Invalid\n");
            break;
        }

        switch(E.category){
            case SHOPPING:
            B.Shopping -= E.amount;
            if(B.Shopping<0){
                printf("Insufficent Funds\n");
            }
            break;
            case ENTERTAINMENT:
            B.Entertainment -= E.amount;
            if(B.Entertainment<0){
                printf("Insufficent Funds\n");
            }
            break;
            case GENERAL:
            B.General -= E.amount;
            if(B.General<0){
                printf("Insufficent Funds\n");
            }
            break;
            case BILLS:
            B.Bills -= E.amount;
            if(B.Bills<0){
                printf("Insufficent Funds\n");
            }
            break;
            case HEALTH:
            B.Health -= E.amount;
            if(B.Health<0){
                printf("Insufficent Funds\n");
            }
            break;
        }

        fptr=fopen("expense.txt","a");
        if(fptr!=NULL){ 
        printf("Remaining Budget\n");
        printf("Amount left in Shopping:%d\n",B.Shopping);
        printf("Amount left in Entertainment:%d\n",B.Entertainment);
        printf("Amount left in General:%d\n",B.General);
        printf("Amount left in Bills:%d\n",B.Bills);
        printf("Amount left in Health:%d\n",B.Health);
        printf("Total Amount Left:%d\n",B.Shopping+B.Entertainment+B.General+B.Bills+B.Health);
        fprintf(fptr,"Category:%d\n Amount:%d\n",E.category,E.amount);
        fclose(fptr);
        }

        do{
            printf("Do you wnat to continue YES(Y/y) OR NO(N/n):");
            scanf(" %c",&decision);

            if(decision=='Y' || decision=='y'){
                printf("CONTINUING...");
            }else if(decision=='N' || decision=='n'){
                printf("EXITING...");
            }else{
                printf("INVALID");
            }
        } while(decision!='Y' && decision!='y' && decision!='N' && decision!='n');
    }
        break;
        
        case 2:
        printf("Remaining Budget\n");
        printf("Amount left in Shopping:%d\n",B.Shopping);
        printf("Amount left in Entertainment:%d\n",B.Entertainment);
        printf("Amount left in General:%d\n",B.General);
        printf("Amount left in Bills:%d\n",B.Bills);
        printf("Amount left in Health:%d\n",B.Health);
        printf("Total Amount Left:%d\n",B.Shopping+B.Entertainment+B.General+B.Bills+B.Health);
        break;

        case 3:
        printf("EXIT");
        return 0;

        default:
        printf("Invalid Choice\n");
    }
}
  return 0;
}
