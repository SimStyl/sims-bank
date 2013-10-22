#include <stdio.h>
#include <conio.h>
#include <string.h>

struct AccType
{
	int AccNum;
	int Password;
	float Balance;
};

AccType account[BUFSIZ];
int Num;
int current = 0;
int password;
float amount;

void AddNewAccount();
void CheckBalance();
void Withdraw();
void DeleteAccount();
void TransferMoney();
bool Continue();
bool AccExistence(int AccNumber);

int main()
{
	char choice;
	
	do
	{
		printf("\n\nWelcome to Sims Bank.\n\nPlease choose the action you wish to perform:\n"
			"1. Create a new account.\n"
			"2. Check balance.\n"
			"3. Transfer Money.\n"
			"4. Delete an account.\n"
			"5. Withdraw money.\n"
			"6. Cancel.\n");

		choice = getch();

		switch (choice)
		{
		case '1': 
			AddNewAccount();
			break;
		case '2':
			CheckBalance();
			break;
		case '3':
			TransferMoney();
			break;
		case '4':
			DeleteAccount();
			break;
		case '5':
			Withdraw();
			break;
		case '6':
			return 0;
		default:
			printf("Invalid choice.");
		}
	}while (Continue() == true);
}

void AddNewAccount()
{
	printf("\nPlease enter your account number:");
	scanf("%d",&Num);
	AccExistence(Num);

	if (AccExistence(Num) == false)
	{
		printf("Thank you,now please enter your password:");
		scanf("%d",&password);
		printf("Now Please enter the starting amount: TL ");
		scanf("%f",&amount);

		account[current].AccNum = Num;
		account[current].Password = password;
		account[current].Balance = amount;
		current++;
	}
	else
	{
		printf("The account already exists.");
	}
	
}

void CheckBalance()
{
	/*int NumBalance,passwordBalance;*/
	printf("\nPlease enter your account number:");
	scanf("%d",&Num);
	printf("Thank you,now please enter your password:");
	scanf("%d",&password);

	for (int i = 0;i < current;i++)
	{
		if (account[i].AccNum == Num && account[i].Password == password)
		{
			printf("\n\nAccount number: %d\n",account[i].AccNum);
			printf("Account balance: %f TL",account[i].Balance);
		}
		else
		{
			printf("Account does not exist.");
		}
	}
}

void TransferMoney()
{
	int SenderAccNum,SenderPassword;
	int RecipientAccNum,amount;
	printf("\nPlease enter your account number:");
	scanf("%d",&SenderAccNum);
	printf("Thank you,now please enter your password:");
	scanf("%d",&SenderPassword);

	for (int i = 0;i < current;i++)
	{
		if (account[i].AccNum == SenderAccNum && account[i].Password == SenderPassword)
		{
			printf("Enter the account number of the recipient:");
			scanf("%d",&RecipientAccNum);

			for(int k = 0;k < current;k++)
			{
				if ( account[k].AccNum== RecipientAccNum)
				{
					printf("Enter the amount you wish to transfer(TL):");
					scanf("%d",&amount);

					account[k].Balance+=amount;
					account[i].Balance -= amount;
					printf("Money successfully transferred.");
				}
			}
		}
	}
}

void DeleteAccount()
{
	int Num,password;
	printf("Please enter your account number:");
	scanf("%d",&Num);
	printf("Thank you,now please enter your password:");
	scanf("%d",&password);

	for (int i = 0;i < current;i++)
	{
		if (account[i].AccNum == Num && account[i].Password == password)
		{
			account[i].AccNum=0;
			account[i].Password=0;
			account[i].Balance=0;
			current--;
			printf("Account successfully deleted");
		}
	}
}

void Withdraw()
{
	int Num,password,Wamount;
	printf("Please enter your account number:");
	scanf("%d",&Num);
	printf("Thank you,now please enter your password:");
	scanf("%d",&password);

	for (int i = 0;i < current;i++)
	{
		if (account[i].AccNum == Num && account[i].Password == password)
		{
			printf("Please enter the amount you wish to withdraw:");
			scanf("%d",&Wamount);

			account[i].Balance -= Wamount;
		}
	}
}

bool Continue()
{
	char decision = true;

	printf("\n\nDo you want to do anything else?(y or n)\n");
	decision = getch();

	if (decision == 'y')
	{
		return true;
	}
	else
	{
	return 0;
	}
}

bool AccExistence(int AccNumber)
{
	for (int i = 0;i < current;i++)
	{
		if (account[i].AccNum==AccNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
