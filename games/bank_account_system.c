#include <stdio.h>
#include <stdlib.h>

void account();
void transfermoney();
void checkbalance();
void login();

// Creating a structure to store
// data of the user
struct pass
{
    char username[50];
    int date, month, year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};

// Structure to keep track
// of amount transfer
struct money
{
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

struct userpass
{
    char password[50];
};

int main()
{
    int selection;
    int selection2;
    printf("Please select one of the following:");
    printf("\nIf you wish to create a new account press 1");
    printf("\nIf you wish to login to your account press 2");
    scanf("%d", &selection);

    switch (selection)
    {
    case 1:
        account();
        break;

    case 2:
        login();

        printf("\nIf you wish to transfer money to the account press 3");
        printf("\nIf you wish to check the balance of your account press 4");
        scanf("%d", &selection2);

        switch (selection2)
        {
        case 3:
            transfermoney();
            break;

        case 4:
            checkbalance();
            break;

        default:
            break;
        }

        break;

    default:
        printf("\nInvalid choice.");
    }
}

void account()
{
    char password[20];
    int passwordlength, i, seek = 0;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass p1;

    struct userpass u2;

    // opening file to
    //  write data of a user
    fp = fopen("username.txt", "ab");

    // inputs
    system('clear');
    printf("\n\n!!!!!CREATE ACCOUNT!!!!");

    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname);

    printf("\n\nLAST NAME..");
    scanf("%s", &u1.lname);

    printf("\n\n FATHER's NAME..");
    scanf("%s", &u1.fathname);

    printf("\n\n MOTHER's NAME..");
    scanf("%s", &u1.mothname);

    printf("\n\n ADDRESS..");
    scanf("%s", &u1.address);

    printf("\n\n  ACCOUNT TYPE..");
    scanf("%s", &u1.typeaccount);

    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);

    printf("\n\nADHAR NUMBER");
    scanf("%s", u1.adharnum);

    printf("\n\nPHONE NUMBER");
    scanf("%s", u1.pnumber);

    printf("\n\nUSERNAME.. ");
    scanf("%s", &u1.username);

    printf("\n\nPASSWORD..");

    // Taking password in the
    // form of stars

    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }

    // Writing to the file
    fwrite(&u1, sizeof(u1), 1, fp);

    // closing file
    fclose(fp);

    // calling another function
    //  after succesful creation
    //  of account
    accountcreated();
}

// Successful account creation
void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf(
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++)
    {
        i++;
        i--;
    }

    gotoxy(30, 10);

    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);

    printf("Press enter to login");

    getch();
    login();
}

// Function to transfer
// money from one user to
// another

void transfermoney()
{
    int i, j;
    FILE *fm, *fp;
    struct pass u1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("clear");

    // Opening file in read mode to
    // read user's username
    fp = fopen("username.txt", "rb");

    // Creating a another file
    // to write amount along with
    // username to which amount
    // is going to be transferred
    fm = fopen("mon.txt", "ab");

    gotoxy(33, 4);
    printf("----TRANSFER MONEY ----");
    gotoxy(33, 5);
    printf("=============");

    gotoxy(33, 11);
    printf("FROM (your username)...");
    scanf("%s", &usernamet);

    // Checking for username if it
    // is present in file or not
    while (fread(&u1, sizeof(u1), 1, fp))

    {
        if (strcmp(usernamep,
                   u1.username) == 0)
        {
            strcpy(m1.usernameto,
                   u1.username);
            strcpy(m1.userpersonfrom,
                   usernamet);
        }
    }
    gotoxy(33, 16);

    // Taking amount input
    printf("ENTER THE AMOUNT TO BE TRANSFERED..");
    scanf("%d", &m1.money1);

    // writing to the file
    fwrite(&m1, sizeof(m1), 1, fm);

    gotoxy(0, 26);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    gotoxy(0, 28);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    gotoxy(0, 29);
    printf("transferring amount, Please wait..");

    gotoxy(10, 27);
    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    gotoxy(33, 40);
    printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
    getch();

    // Close the files
    fclose(fp);
    fclose(fm);

    // Function to return
    // to the home screen
    display(usernamet);
}

// Function to check balance
// in users account

void checkbalance(char username2[])
{
    system("clear");
    FILE *fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;

    // Opening amount file record
    fm = fopen("mon.txt", "rb");

    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;

    gotoxy(30, 2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(k, l);
    printf("S no.");
    gotoxy(m, n);
    printf("TRANSACTION ID");
    gotoxy(u, v);
    printf("AMOUNT");

    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1), 1, fm))
    {
        if (strcmp(username2,
                   m1.usernameto) == 0)
        {
            gotoxy(k, ++l);
            printf("%d", i);
            i++;
            gotoxy(m, ++n);
            printf("%s", m1.userpersonfrom);

            gotoxy(u, ++v);
            printf("%d", m1.money1);
            // adding and finding total money
            summoney = summoney + m1.money1;
        }
    }
    gotoxy(80, 10);
    printf("TOTAL AMOUNT");

    gotoxy(80, 12);
    printf("%d", summoney);

    getch();

    // Closing file after
    // reading it
    fclose(fm);
    display(username2);
}

// Login function to check
// the username of the user
void login()
{
    system("clear");

    char username[50];
    char password[50];

    int i, k, j;
    char ch;
    FILE *fp, *fu;
    struct pass u1;
    struct userpass u2;

    // Opening file of
    // user data

    fp = ("username.txt", "rb");

    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE");
    }

    gotoxy(34, 2);
    printf("ACCOUNT LOGIN");
    gotoxy(7, 5);

    printf("**************************");

    gotoxy(35, 10);
    printf("==== LOG IN ====");

    // Take input
    gotoxy(35, 12);
    printf("USERNAME.. ");
    scanf("%s", &username);

    gotoxy(35, 14);
    printf("PASSWORD..");
    // Input the password
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }

        else
            break;
    }

    // Checking if username
    // exists in the file or not
    while (fread(&u1,
                 sizeof(u1), 1, fp))
    {
        if (strcmp(username,
                   u1.username) == 0)
        {
            loginsu();
            display(username);
        }
    }

    // Closing the file
    fclose(fp);
}

// Screen is shown after
// successful login
void loginsu(void)
{
    int i;
    FILE *fp;
    struct pass u1;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }
    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");

    getch();
}