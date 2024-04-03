#include <stdio.h>

int decrypt(char *);
int encrypt(char *);

int encrypt(char *s)
{
	int i = 0;
	int num;

	while (s[i] != '\0')
	{
		if (s[i] < 33 && s[i] > 126)
			return (-1);
		num = s[i] + i;
		if (num > 126)
			num = 33 + (num - 126);
		printf("%c", num);
		i++;
	}
	printf("\n");
	return (-1);
}

int decrypt(char *s)
{
	int i = 0;
	int num;

	while (s[i] != '\0')
	{
		if (s[i] < 33 && s[i] > 126)
			return (-1);
		num = s[i] - i;
		if (num < 33)
			num = 126 - (33 - num);
		printf("%c", num);
		i++;
	}
	printf("\n");
	return (1);
}

int main(int argc, char *argv[])
{
	char *str = argv[2];

	if (argv[1] != NULL && argv[1][0] == 'd')
	{
		printf("\n")
		printf("Decrypted message\n");
		printf("---------------------------------\n");
		decrypt(str);
	}
	else if (argv[1] != NULL && argv[1][0] == 'e')
	{
		printf("\n");
		printf("Encrypted Message\n");
		printf("---------------------------------\n");
		encrypt(str);
	}
	else
	{
		printf("You should specify to encrypt or dcrypt the message\n");
		printf("Usage: ./a.out e 'message to encrypt'\n");
		printf("Usage: ./a.out d 'message to decrypt'\n");
	}
	return(0);
}
