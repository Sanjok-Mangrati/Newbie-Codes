#include<stdio.h>
#include<stdlib.h>

//Sum of marks depending upon gender, if boy then sum of all marks in even postion/if girl sum of marks in odd position.

//Sum Function Logic 1:

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    for (int i = (gender == 'b' ? 0 : 1); i < number_of_students; i = i + 2) 
        sum += *(marks + i);
    
    return sum;
}

//Sum Function Logic 2:

/** 
    int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    for (int i = (gender == 'g'); i < number_of_students; i += 2) {   //i is assigned 0 or 1 depending upon if gender==g is true or false
        sum += marks[i];
    }
    return sum;
} 
**/

//Sum Function Logic 3:

/** 

    int marks_summation(int* marks, int number_of_students, char gender) {
        int size=number_of_students;
        int sum=0;
        switch(gender)
        {
            case 'b':
                
                for(int i=0;i<size;i+=2)
                    sum+=marks[i];
                break;
                
            case 'g':
                
                for(int i=1;i<size;i+=2)
                    sum+=marks[i];
                break;          
         }
    return sum;
}

**/

int main() {
    int number_of_students;
    char gender;
    int sum;
    
    printf("Enter number of students: ");
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        printf("Enter marks: ");
        scanf("%d", (marks + student));
    }
    
    printf("Enter gender (g or b): ");
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("The sum is %d", sum);
    free(marks);
 
    return 0;
}