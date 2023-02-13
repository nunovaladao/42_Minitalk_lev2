#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* void print_bits(char octec)
{
    int i = 256;

    while (i >>= 1)
        (octec & i) ? printf("1") : printf("0");
    puts("");
}

char print_str(char *str)
{
    int i = 0;

    while (str[i])
    {
        print_bits(str[i]);
        i++;
    }
    return *str;
}

int main(int ac, char **av)
{
    (void)ac;
    char *str = "01000001";

    printf("%c", print_str(str)); 

    int octec = atoi(av[1]);
    print_bits(octec);
} */

int main()
{
	int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	int converted = 0;
    int i = 0;
    int binary[9];

	while (i < 8)
	{
        int mask = 1 << i;
		if ((binary[i] & mask) == mask)
			converted += binary_table[i];
		i++;
	}
	write(1, &converted, 1);
	write(1, "\n", 1);
}

/* #include <unistd.h>
#include <stdio.h>

int main()
{
    int binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    char binary[9];
    int converted = 0;
    int i = 0;

    printf("Enter a binary number (8 bits): ");
    scanf("%s", binary);

    while (i < 8)
    {
        if (binary[i] == '1')
        {
            converted += binary_table[i];
        }
        i++;
    }

    printf("Converted ASCII character: %c\n", converted);

    return 0;
} */

