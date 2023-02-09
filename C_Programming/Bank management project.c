#include <stdio.h>
void menu();

typedef struct account {
    char name[50];
    char date_of_birth[11];
    unsigned int citizenship;
    char address[100];
    unsigned int phone_number;
    int age;
    int type_of_account;
    char date_of_deposit[11];
    float amount_of_interest;
    float money;
    unsigned int acc_num;
    /*1- saving 2-current 3-investment*/
} acc;
void viewlist(acc v);
void new_account(acc l);
void see(acc l);
void transact(acc z);

int clear_input_buffer() {
    int ch;
    while (((ch = getchar()) != EOF) && (ch != '\n'));
    return ch;
}

int main() {


    menu();
    return 0;


}

void menu() {
  unsigned int option;
  printf("Welcome to our system\n");
  printf("please enter mode you want\n");
  printf("1- create new account\n\n2-Edit\n3-transact\n4-erase\n5-see\n");
  scanf("%u", &option);
    acc l, z;
    switch (option) {

        case 1:
            new_account(l);
            break;
            /*case 2:
            edit();
             break;*/
        case 3:
            transact(z);
            break; /*
case 4:
erase();
 break;*/
        case 5:
            see(l);
            break;
            /*default:
                printf("please enter a number from 1 to 6 ");
                break;*/
    }
}

void new_account(acc l) {
    FILE *accptr;
    int n;
    accptr = fopen("clients.txt", "ab");
    fseek(accptr, 0, SEEK_END);
    n = ftell(accptr);
    l.acc_num = (n / sizeof (acc)) + 1;
    printf("Please enter some of personal information to create a new account!\n");
    printf("your name!: ");
    clear_input_buffer();
    gets(l.name);
    printf("date of birth!: ");
    scanf("%s", l.date_of_birth);
    printf("Your citizenship number!: ");
    scanf("%u", &l.citizenship);
    printf("Your address!: ");
    clear_input_buffer();
    gets(l.address);
    printf("Your phone number!:+20");
    scanf("%u", &l.phone_number);
    printf("How much money you want to deposit? ");
    scanf("%f", &l.money);
    printf("What is the type of account you want?\n1-save account.\n2-current account.\n3-investment account.\n choose 1 or 2 or 3: ");
    scanf("%d", &l.type_of_account);
    fwrite(&l, sizeof (acc), 1, accptr);
    printf("You're successfully created an account!\n");
    fclose(accptr);
    viewlist(l);
}

void viewlist(acc v) {
    printf("account number is :%u", v.acc_num);
    printf("account phone number is :%u", v.phone_number);
    printf("account address is :%s", v.address);
    printf("account name is :%s", v.name);
}

void see(acc l) {
    FILE *accptr;
    accptr = fopen("clients.txt", "rb");
    int x, n, offset;
    x = (sizeof (acc));
    printf("enter your acc num\n");
    scanf("%d", &n);
    offset = x * (n - 1);
    fseek(accptr, offset, SEEK_SET);
    fread(&l, sizeof (acc), 1, accptr);
    printf("your account num is : %u , \nyour account name is : %s , \nyour account date of birth is : %s , \nyour account citizenship is : %u , \nyour account address is : %s , \nyour account phone number is : +20-%u , \nyour account balance is : %f , \nyour account type is : %d.\n", l.acc_num, l.name, l.date_of_birth, l.citizenship, l.address, l.phone_number, l.money, l.type_of_account);
    fclose(accptr);
}

void transact(acc z) {
    FILE *accptr;
    accptr = fopen("clients.txt", "rb+");
    int x, n, offset;
    x = (sizeof (acc));
    printf("enter your acc num\n");
    scanf("%d", &n);
    offset = x * (n - 1);
    fseek(accptr, offset, SEEK_SET);
    fread(&z, sizeof (z), 1, accptr);
    int i;
    float wit;
    float dep;
    do {
        printf("if you want to deposit money press '1' and to withdraw press '2'\n");
        scanf("%d", &i);
        if (i == 1) {
            //fseek(accptr, offset, SEEK_SET);
            printf("please enter your deposit value\n");
            scanf("%f", &dep);
            z.money = z.money + dep;
        }
        if (i == 2) {
            printf("please enter your deposit value\n");
            scanf("%f", &wit);
            if (wit > z.money) {

                printf("your balance less than this value%f", wit);
            } else {
                z.money = z.money - wit;
            }
        }
    } while (i != 1 && i != 2);
    fseek(accptr, offset, SEEK_SET);
    fwrite(&z, sizeof (z), 1, accptr);
    printf("your balance now is :%f\n", z.money);
    fclose(accptr);
}
