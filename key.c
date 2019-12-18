#include<stdio.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int getch (void)
{
	int ch;
	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;
}
void main()
{
 char pasword[10],usrname[10], ch;
 int i;
 while ( getch() != 0x0A ) 
 {
  
  printf("*");
 }
printf("\n");
 /*If you want to know what you have entered as password, you can print it*/
 printf("\nYour password is :");

 for(i=0;i<8;i++)
 {
  printf("%c",pasword[i]);
 }
 printf("\n");
}
