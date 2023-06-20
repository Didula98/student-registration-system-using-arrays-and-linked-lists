#include <stdio.h>
#include <stdlib.h>




//creating a structure to store student records
typedef struct _{
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
    struct _* next;
} student_t;





//declaring functions
void option();
void print_list(student_t *);
void print_student(student_t *);
void Add(student_t *);
void Delete(student_t *);







int main(){
    //printing user mannuel
    for(int i = 1; i <= 44; i++){
        printf("-");
    }

    printf("\nA VOLATILE STUDENT RECORD MAINTENANCE SYSTEM\n");

    for(int i = 1; i <= 44; i++){
        printf("-");
    }
    printf("\n0. Quit\n1. Insert a Student Record\n2. Print a Student Record\n3. Print all Student Records\n4. Delete a Student Record\n");

    student_t *head = (student_t*)malloc(sizeof(student_t));
    head ->next = NULL;

    int n=10;

    //while the input is zero it gets inputs form user
    while(n != 0){

        option();
        scanf("%i", &n);//read the input from user

        //consider each particular input and call particular function
        if(n == 1){
          Add(head);

        }else if(n == 2){
          print_student(head);

        }else if(n == 3){
          print_list(head);

        }else if(n == 4){
          Delete(head);
        }
    }

    return 0;
}









//this function print the input range. after any operation this will print on the screen
void option(){
    for(int i = 1; i <= 18; i++){
        printf("-");
    }

    printf("\nENTER OPTION [0-4]\n");

    for(int i = 1; i <= 18; i++){
        printf("-");
    }
    printf("\n");
}









//this function is used to add student information when user input 1
void Add(student_t *head){

    student_t *ptr, *temp;
    ptr = head;
    temp = (student_t*)malloc(sizeof(student_t));

    printf("Enter the batch (14/15/16/17): ");
    scanf("%i", &(temp ->batch));
    printf("Enter the registration number: ");
    scanf("%i", &(temp ->regNo));
    printf("%-29s%s","Enter the first name",": ");
    scanf("%s", temp ->firstName);
    printf("%-29s%s","Enter the last name",": ");
    scanf("%s", temp ->lastName);
    printf("%-29s%s","Enter the cumulative GPA",": ");
    scanf("%f", &(temp ->cGPA));
    temp ->next = NULL;
    printf("\n");

    while(ptr ->next != NULL){
      ptr = ptr->next;
    }
    ptr ->next = temp;

}










//this function is used to print given student information
void print_student(student_t *head){
    student_t *current;
    char c1,c2,c3;
    int regNum,batch, flag = 0;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%i%c%i", &c1,&c2,&batch,&c3,&regNum); //read input(format is E/XX/YYY where XX is batch and YYY is reg no) from the user


    for(current = head ->next; current != NULL; current = current ->next){
        if(current ->batch == batch && current ->regNo == regNum && c1 == 'E' && c2 == '/' && c3 == '/'){
            flag = 1;
            break;

        }
    }

    if(flag == 1){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", current ->firstName, current ->lastName, current ->batch, current ->regNo, current ->cGPA);
    }else if(flag == 0){
        printf("No student with the given Registration Number!\n");
    }
    printf("\n");
}









//this function is used to print entered student list
void print_list(student_t *head){
    student_t *current;
    //printing each value OF student data
    for(current = head ->next; current != NULL; current = current ->next){

      printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", current ->firstName, current ->lastName, current ->batch, current ->regNo, current ->cGPA);

    }
    printf("\n");

}









//this function is used to delete a given student information
void Delete(student_t *head){

    student_t *current, *previous;
    char c1,c2,c3;
    int regNum, batch, flag = 0;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%i%c%i", &c1,&c2,&batch,&c3,&regNum); //read input(format is E/XX/YYY where XX is batch and YYY is reg no) from the user

    //checking each nodes which are next to each other by using for loop. If current node contains data which wants to delete, it updates previous node next address to current node next address and free memory allocated for current node
    for(previous = head; previous ->next != NULL; previous = previous ->next){
        current = previous ->next;
        if(current ->batch == batch && current ->regNo == regNum && c1 == 'E' && c2 == '/' && c3 == '/'){
            printf("%p\n", current);
            flag = 1;
            previous ->next = current ->next;
            free(current);
            printf("%p\n", current);
            break;
        }
    }


    if(flag == 1){
        printf("Delete Successful!\n");
    }else if(flag == 0){
        printf("No student with the given Registration Number!\n");
    }
    printf("\n");

}
