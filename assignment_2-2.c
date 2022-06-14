#include <stdio.h>
#include <math.h>

void numWord(int a)
{
    int rev = 0, digit, i = 0;
    int len = (int)(log10(a) + 1);
    int arr[len];
    while (a != 0)
    {
        arr[i] = a % 10;
        a = a / 10;
        i++;
    }
    while (i != 0)
    {
        switch (arr[i - 1])
        {
        case 0:
            printf("zero ");
            break;
        case 1:
            printf("one ");
            break;
        case 2:
            printf("two ");
            break;
        case 3:
            printf("three ");
            break;
        case 4:
            printf("four ");
            break;
        case 5:
            printf("five ");
            break;
        case 6:
            printf("six ");
            break;
        case 7:
            printf("seven ");
            break;
        case 8:
            printf("eight ");
            break;
        case 9:
            printf("nine ");
            break;
        }
        i--;
    }
    printf("\n");
}

char grade(int a)
{
    if (a >= 90)
        return 'E';
    else if (a >= 80)
        return 'A';
    else if (a >= 70)
        return 'B';
    else if (a >= 60)
        return 'C';
    else if (a >= 50)
        return 'D';
    else if (a >= 40)
        return 'P';
    else
        return 'F';
}
char gradeBacklog(int a)
{
    if (a >= 90)
        return 'A';
    else if (a >= 80)
        return 'B';
    else if (a >= 70)
        return 'C';
    else if (a >= 60)
        return 'D';
    else if (a >= 40)
        return 'P';
    else
        return 'F';
}

char gradeRelative(int a, int b[])
{
    int i = 0;
    char gradeArr[6] = {'E', 'A', 'B', 'C', 'D', 'P'};
    for (i = 0; i < 6; i++)
    {
        if (a >= b[i])
        {
            return gradeArr[i];
            break;
        }
    }
}

int main()
{
    int roll, marks, backlog, relative, i, j, error = 0, check = 0, temp1, temp2;
    float atten;
    int cutoff[6];
    char gradeArr[6] = {'E', 'A', 'B', 'C', 'D', 'P'}, grd;

    printf("** Enter Student Roll Number : ");
    scanf("%d", &roll);

    printf("** Enter the Attendance Percentage : ");
    scanf("%f", &atten);

    if (atten >= 80)
    {
        printf("** Enter Subject Marks (out of 100) : ");
        scanf("%d", &marks);
        if (marks <= 100)
        {
            printf("** Is this marks for Supplementary/Backlog Examination? (Type '0' if NOT): ");
            scanf("%d", &backlog);

            if (backlog != 0)
            {
                printf("** Do you want Relative Grading? (Type '0' if NOT): ");
                scanf("%d", &relative);

                if (relative != 0)
                {
                    for (i = 0; i < 6; i++)
                    {
                        printf("** Cutoff for %c = ", gradeArr[i]);
                        scanf("%d", &cutoff[i]);
                    }
                    for (i = 0; i < 6; i++)
                    {
                        for (j = 0; j < 6; j++)
                        {
                            if (i != j && cutoff[i] == cutoff[j])
                            {
                                error = 1;
                                temp1 = i;
                                temp2 = j;
                                break;
                            }
                        }
                    }
                    if (error == 1)
                        printf("-- Error : Cutoff for '%c' is not less than Cutoff for '%c'!", gradeArr[temp1], gradeArr[temp2]);

                    else
                    {
                        grd = gradeRelative(marks, cutoff);
                        printf("-- The Subject Marks of %d is : ", roll);
                        numWord(marks);
                        printf("-- The Relative Grade of %d is : %c\n", roll, grd);
                    }
                }
                else
                {
                    printf("-- The Subject Marks of %d is : ", roll);
                    numWord(marks);
                    printf("-- The Absolute Grade of %d is : %c\n", roll, gradeBacklog(marks));
                }
            }
            else
            {
                printf("** Do you want Relative Grading? (Type '0' if NOT): ");
                scanf("%d", &relative);

                if (relative != 0)
                {
                    for (i = 0; i < 6; i++)
                    {
                        printf("** Cutoff for %c = ", gradeArr[i]);
                        scanf("%d", &cutoff[i]);
                    }
                    for (i = 0; i < 6; i++)
                    {
                        for (j = 0; j < 6; j++)
                        {
                            if (i != j && cutoff[i] == cutoff[j])
                            {
                                error = 1;
                                temp1 = i;
                                temp2 = j;
                                break;
                            }
                        }
                    }
                    if (error == 1)
                        printf("-- Error : Cutoff for '%c' is not less than Cutoff for '%c'!", gradeArr[temp1], gradeArr[temp2]);

                    else
                    {
                        grd = gradeRelative(marks, cutoff);
                        printf("-- The Subject Marks of %d is : ", roll);
                        numWord(marks);
                        printf("-- The Relative Grade of %d is : %c\n", roll, grd);
                    }
                }
                else
                {
                    printf("-- The Subject Marks of %d is : ", roll);
                    numWord(marks);
                    printf("-- The Absolute Grade of %d is : %c\n", roll, grade(marks));
                }
            }
        }

        else
            printf("-- Error: Mistake in Marks Record!");
    }

    else if (atten > 100)
        printf("-- Error : Mistake in Attendance Record!");

    else
        printf("-- The Grade of %d is : F (Shortage in Attendance!)", roll);

    return 0;
}
