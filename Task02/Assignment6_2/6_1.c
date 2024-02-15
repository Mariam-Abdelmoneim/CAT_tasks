#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student
{
    long id;
    int progMark;
    int dsMark;
    int discreteMark;
    int algoMark;
}Student;



int main()
{
    long idTest;
    Student students[10];
    //student 1
    students[0].id = 123456;
    students[0].progMark = 25;
    students[0].algoMark = 30;
    students[0].discreteMark = 35;
    students[0].dsMark = 40;

    //student 2
    students[1].id = 789101;
    students[1].progMark = 30;
    students[1].algoMark = 37;
    students[1].discreteMark = 42;
    students[1].dsMark = 40;

    //student 3
    students[2].id = 102002;
    students[2].progMark = 13;
    students[2].algoMark = 38;
    students[2].discreteMark = 17;
    students[2].dsMark = 42;

    //student 4
    students[3].id = 112006;
    students[3].progMark = 42;
    students[3].algoMark = 41;
    students[3].discreteMark = 36;
    students[3].dsMark = 29;

    //student 5
    students[4].id = 61972;
    students[4].progMark = 39;
    students[4].algoMark = 49;
    students[4].discreteMark = 50;
    students[4].dsMark = 47;

    //student 6
    students[5].id = 92004;
    students[5].progMark = 26;
    students[5].algoMark = 29;
    students[5].discreteMark = 30;
    students[5].dsMark = 37;

    //student 7
    students[6].id = 82011;
    students[6].progMark = 25;
    students[6].algoMark = 30;
    students[6].discreteMark = 35;
    students[6].dsMark = 40;

    //student 8
    students[7].id = 14475;
    students[7].progMark = 25;
    students[7].algoMark = 30;
    students[7].discreteMark = 35;
    students[7].dsMark = 40;

    //student 9
    students[8].id = 12203;
    students[8].progMark = 15;
    students[8].algoMark = 34;
    students[8].discreteMark = 20;
    students[8].dsMark = 45;

    //student 10
    students[9].id = 10502;
    students[9].progMark = 47;
    students[9].algoMark = 49;
    students[9].discreteMark = 50;
    students[9].dsMark = 50;

    do
    {
        printf(">>> Student's ID? ");
        scanf("%ld", &idTest);
        for(int i = 0; i < 10; i++)
        {
            if (students[i].id == idTest) {
                printf("\n\t-> Programming Marks: %d/50\n", students[i].progMark);
                printf("\t-> Algorithms Marks: %d/50\n", students[i].algoMark);
                printf("\t-> Discrete Maths Marks: %d/50\n", students[i].discreteMark);
                printf("\t-> Data Structure Marks: %d/50\n", students[i].dsMark);
                return 0;
            }
        }
        printf("!! INVALID ID !! try again!\n");

    }while(true);

}