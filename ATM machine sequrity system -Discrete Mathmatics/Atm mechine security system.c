#include <stdio.h>

unsigned long cash=3000, dep, wit;
int choice, pin, k;
char transaction ='y';

void main()
{
	while (pin != 1212)
	{
		printf("ENTER YOUR SECRET PIN NUMBER:");
		scanf("%d", &pin);
		if (pin != 1212)
		printf("PLEASE ENTER VALID PASSWORD\n");
	}
	do
	{
		printf("\nWelcome to ATM Service\n");
		printf("1. Check Balance\n");
		printf("2. Withdraw Cash\n");
		printf("3. Deposit Cash\n");
		printf("4. Quit\n");
		printf("\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n YOUR BALANCE IN Taka : %lu ", cash);
			break;
		case 2:
			printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%lu", &wit);
			if (wit % 100 != 0)
			{
				printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
			}
			else if (wit >(cash - 500))
			{
				printf("\n INSUFFICENT BALANCE");
			}
			else
			{
				cash = cash - wit;
				printf("\n\n PLEASE COLLECT CASH");
				printf("\n YOUR CURRENT BALANCE IS: %lu", cash);
			}
			break;
		case 3:
			printf("\n ENTER THE AMOUNT TO DEPOSIT:");
			scanf("%lu", &dep);
                        cash = cash + dep;
			printf("YOUR BALANCE IS: %lu", cash);
			break;
		case 4:
			printf("\n THANK U FOR USING OUR ATM SERVICE");
			break;
		default:
			printf("\n INVALID CHOICE");
		}
		printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
		fflush(stdin);
		scanf("%c", &transaction);
		if (transaction == 'n'|| transaction == 'N')
                    k = 1;
	} while (!k);
	printf("\n\n THANKS FOR USING OUT ATM SERVICE");

}
