#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define char_size 100

typedef struct{
    char name[char_size];
    char dealer[char_size];
    int weight,cost;
    //int phone[10];
    int year,month,date;

}element;

typedef struct stack *stackPointer;
typedef struct stack{
    element data;
    stackPointer link;
    };
stackPointer top=NULL;

void push(element item);
void printSchedule(stackPointer top);
element pop();
int countPurchase(stackPointer top);
void push(element item);
void printMenu();

int main(){

    char user[10];
    char pw[10];
    int action;
    char delete_choice;
    int PurchaseAmount;
    time_t current_t,start_t;
    element item;
    printf("Username:");
    scanf("%s",&user);
    printf("Password:");
    scanf("%s",&pw);
    printf("\n");
    if(!strcmp(user,"admin")&&!strcmp(pw,"admin")){
        printf("Login successfully!\n"
               "==============================================================\n");
        printMenu();
        scanf("%d",&action);
        while(action!=5){
                switch(action){
                case 1:
                    printf("Product name:");
                    scanf("%s",&item.name);
                    printf("Dealer:");
                    scanf("%s",&item.dealer);
                    printf("Price(NT$):");
                    scanf("%d",&item.cost);
                    printf("Weight(KG):");
                    scanf("%d",&item.weight);
                    printf("Date:");
                    scanf("%d-%d-%d",&item.year,&item.month,&item.date);
                    //printf("AGE,TIME:%d,%d-%d",item.age,item.start_time,item.end_time);//confirm輸入//重新排列Schedule//如果預約重複會告知
                    //for(int i=0;item.name[i]!='\0';i++)
                        //printf("%c",item.name[i]);
                    //printf("\n");
                    push(item);//驗證過top有值但沒接上
                    printf("New Purchase Added!");
                    //second->link=top;//***這裡更新top有點怪
                    break;
                case 2:
                    item=pop();
                    printf("Cancellation Completed:%s\n",item.name);
                    PurchaseAmount=countPurchase(top);
                    printf("Purchase left:%d\n",PurchaseAmount);//***ghj->ching->null(沒接上了)
                    //printf("Confirm Cancellation:%s\n",item.name);
                    //delete_choice=getchar();
                    //if(delete_choice=='Y'){
                        //item=pop();
                        //printf("Cancellation Completed!");
                        //printf("Purchase left:%d\n",PurchaseAmount-1);//***ghj->ching->null(沒接上了)
                    //}
                    //else printf("HAHA");
                    break;
                case 3:
                    modifier(top);
                    break;
                case 4:
                    printSchedule(top);
                    break;
                }
        printf("\n");
        Sleep(500);
        system("CLS");
        printMenu();
        printf("Next Action:");
        scanf("%d",&action);
        printf("==============================================================\n");
        }
    }
    else printf("Login Failure!");
    return 0;
}
ddddddd
void push(element item){
    stackPointer temp;
    temp=(stackPointer *)malloc(sizeof(stackPointer));
    strcpy(temp->data.name,item.name);
    strcpy(temp->data.dealer,item.dealer);
    temp->data.cost=item.cost;
    temp->data.weight=item.weight;
    temp->data.year=item.year;
    temp->data.month=item.month;
    temp->data.date=item.date;
    temp->link=top;
    top=temp;
}

void printSchedule(stackPointer top){
    printf("Aggregrated Purchase ViewList:\n\n");
    int count=0;
    for(;top;top=top->link){//
        count=count+1;
        //printf("[%d]\n",count);
        printf("[%d]Product name:%s\n",count,top->data.name);
        printf("   Product name:%s\n",top->data.dealer);
        printf("   Price:NT$%d\n",top->data.cost);
        printf("   Weight:%d KG\n",top->data.weight);
        printf("   Date:%d-%d-%d\n\n",top->data.year,top->data.month,top->data.date);
    }
}

element pop(){
    element item;
    stackPointer temp=top;
    item=temp->data;
    top=temp->link;
    free(temp);
    return item;
}

int countPurchase(stackPointer top){
    int count=0;
    for(;top;top=top->link)
        count=count+1;
    return count;
}

void modifier(stackPointer top){
    int mod_choice;
    int inp1;
    if(top!=NULL){
        printf("Modifier:(1)Price (2)Weight          #");
        scanf("%d",&mod_choice);
        switch(mod_choice){
        case 1:
            printf("New Price(NT$):");
            scanf("%d",&inp1);
            top->data.cost=inp1;
            break;
        case 2:
            printf("New Weight(KG):");
            scanf("%d",&inp1);
            top->data.weight=inp1;
        }
        printf("\n");
        printf("Update Successfully!\n");
        printf("   Product name:%s\n",top->data.name);
        printf("   Product name:%s\n",top->data.dealer);
        printf("   Price:NT$%d\n",top->data.cost);
        printf("   Weight:%d KG\n",top->data.weight);
        printf("   Date:%d-%d-%d\n\n",top->data.year,top->data.month,top->data.date);
    }
    else printf("No Data Inside!");
}

void printMenu(){
    printf("Actions:(1)New Purchase\n"
               "        (2)Remove Previous Purchase\n"
               "        (3)Modify Previous Purchase\n"
               "        (4)View Aggregated Purchase \n"
               "        (5)Exit             # ");

}

//改成float:cost-weight
//更改刪除指定筆數(不一定要是最新的)
//出貨系統
