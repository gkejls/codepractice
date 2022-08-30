#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*count digits, white space, nothers */
#define MAXLINE 1000 /*maximum input line size*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line*/
int main(int argc, char* argv[]) {
	#0830
		int len; 				/* current line length */
	int max;				/* maximum length so far */
	char line[MAXLINE]; 	/* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) //??
		if (len > max) {
			mam = len;
			copy(longest, line);
		}
	return 0;
}

//c언언데 설정하는 거 너무 귀찮아서 그동안 안 만짐..