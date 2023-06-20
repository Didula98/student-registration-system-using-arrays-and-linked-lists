#include <stdio.h>

//creating a structure to store student records
typedef struct _{
    int batch;
    int regNo;
    char firstName[20];
    char lastName[20];
    float cGPA;
} student_t;

//declaring functions
void UI();
void option();

void print_list(int, student_t[]);
void print_student(int, student_t[]);

student_t Add();
student_t* Delete(student_t[], int);


int main(){

    UI();

    return 0;
}


//this function creates UI and call other functions in the particular inputs of the user
void UI(){
    //printing user mannuel
    for(int i = 1; i <= 42; i++){
        printf("-");
    }

    printf("\nA VOLATILE STUDENT RECORD MAINTENCE SYSTEM\n");

    for(int i = 1; i <= 42; i++){
        printf("-");
    }
    printf("\n0. Quit\n1. Insert a Student Record\n2. Print a Student Records\n3. Print all Student Records\n4. Delete a Student Record\n");

    //making static variables to use them in here and as well as other functions
    static int i=0;
    static student_t arr[100];

    int n=10;

    //while the input is zero it gets inputs form user
    while(n != 0){

        option();
        scanf("%i", &n);//read the input from user

        //consider each particular input and call particular function
        if(n == 1){
            arr[i] = Add();
            i++;
        }else if(n == 2){
            print_student(i, arr);
        }else if(n == 3){
            print_list(i, arr);
        }else if(n == 4){
            Delete(arr, i);
        }
    }

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
student_t Add(){

    student_t x;

    printf("Enter the batch (14/15/16/17): ");
    scanf("%i", x.batch);
    printf("Enter the registration number: ");
    scanf("%i", x.regNo);
    printf("%-29s%s","Enter the first name",": ");
    scanf("%s", &x.firstName);
    printf("%-29s%s","Enter the last name",": ");
    scanf("%s", &x.lastName);
    printf("%-29s%s","Enter the cumulative GPA",": ");
    scanf("%f", x.cGPA);
    printf("\n");
    return x;
}

//this function is used to print given student information
void print_student(int i, student_t arr[]){

    char c1,c2,c3;
    int regNum, j, batch, flag = 0;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%i%c%i", &c1,&c2,&batch,&c3,&regNum); //read input(format is E/XX/YYY where XX is batch and YYY is reg no) from the user


    for(j = 0; j < i; j++){
        if(arr[j].batch == batch && arr[j].regNo == regNum && c1 == 'E' && c2 == '/' && c3 == '/'){
            flag = 1;
            break;

        }
    }

    if(flag == 1){
        printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", arr[j].firstName, arr[j].lastName, arr[j].batch, arr[j].regNo, arr[j].cGPA);
    }else{
        printf("No student with the given Registration Number!\n");
    }
    printf("\n");
}


//this function is used to print entered student list
void print_list(int i, student_t arr[]){

    //printing each value in the array of student data
    for(int j =0; j<i; j++){
        if(arr[j].batch != 0 && arr[j].regNo != 0){
            printf("The student %s %s (E/%d/%d) has a cumulative GPA of %.2f\n", arr[j].firstName, arr[j].lastName, arr[j].batch, arr[j].regNo, arr[j].cGPA);
        }
    }
    printf("\n");

}

//this function is used to delete a given student information form array
student_t* Delete(student_t arr[], int i){

    char c1,c2,c3;
    int regNum, batch, flag = 0;

    printf("Enter the Registration Number: ");
    scanf(" %c%c%i%c%i", &c1,&c2,&batch,&c3,&regNum); //read input(format is E/XX/YYY where XX is batch and YYY is reg no) from the user

    //checking whether array is contain input student data
    for(int j = 0; j < i; j++){
        if(arr[j].batch == batch && arr[j].regNo == regNum && c1 == 'E' && c2 == '/' && c3 == '/'){
            flag = 1;
            for(int k = j; k < i; k++){
                arr[k] = arr[k+1]; //in here if student found in the array, it will remove
            }
            break;
        }
    }

    if(flag == 1){
        printf("Delete Successful!\n");
    }else{
        printf("No student with the given Registration Number!\n");
    }
    printf("\n");
    return arr;

}

