

//220113

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	while (성적을 읽을 수 있음)
		성적의 첫 번째 문자에 따라 score(평점)에 0, 1, ..., 4의 점수 부여
		성적의 두 번째 문자에 따라 0.3만큼 증감
		이름/성적/평점을 출력
*/


main()
{
    char name[20], grade[10];	/* 이름, 성적 */
    double score;  			/* 평점 */
    //이후 작성 switch 문 사용
    do(
        printf("이름 성적 형식으로 입력(프로그램을 종료하려면 CTRL+Z 입력)\n");

    scanf_s("%c %c", &name, &grade);



    score = 0;

    switch (grade[0]) {

    case 'A':
        switch (grade[1]) {
        case '+':
            score = 4.3;
            break;
            return 0;
        case '0':
            score = 4.0;
            break;
            return 0;
        case '-':
            score = 3.7;
            break;
            return 0;
        }
        break;
    case 'B':
        switch (grade[1])
        {
        case '+':
            score = 3.3;
            break;
            return 0;
        case '0':
            score = 3.0;
            break;
            return 0;
        case '-':
            score = 2.7;
            break;
            return 0;
        }
        break;
    case 'C':
        switch (grade[1])
        {
        case '+':
            score = 2.3;
            break;
            return 0;
        case '0':
            score = 2.0;
            break;
            return 0;
        case '-':
            score = 1.7;
            break;
            return 0;
        }
        break;
    case 'D':
        switch (grade[1])
        {
        case '+':
            score = 1.3;
            break;
            return 0;
        case '0':
            score = 1.0;
            break;
            return 0;
        case '-':
            score = 0.7;
            break;
            return 0;
        }
        break;
    default:
        score = 0.0;
        break;
        return 0;
    
}
        printf_s("이름: %s 성적: %s 평점: %f\n", name, grade, score);
)while (int i > 20);

