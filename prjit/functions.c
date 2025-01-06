#include <ctype.h>
#include <stdio.h>
#include "functions.h"
#include <string.h>


void menuStart(){
    printf("\n***He informs the administration of student use of good sleeping habits C***\n");
    printf("\n");
    printf("\t  CHOOSE YOUR ASH ROLE\n");
    printf("\t=====================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Student.\n");
    printf("\t[3] Teacher. \n");
    printf("\t[0] Exit.\n");
    printf("\t=====================\n");
}
void menuAdmin(){

    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t         MENU\n");
    printf("\t==========================\n");
    printf("\t[1] Student management.\n");
    printf("\t[2] Class management. \n");
    printf("\t[3] Teacher management.\n");
    printf("\t[4] User Guide.\n");
    printf("\t[0] Back.\n");
    printf("\t==========================\n");
}
void menuStudents(){
	
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    STUDENT MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add new students.\n");
    printf("\t[2] Show student list.\n");
    printf("\t[3] Delete a student.\n");
    printf("\t[4] Edit a student's information.\n");
    printf("\t[5] Looking for a student\n");
    printf("\t[6] Student arrangement.\n");
    printf("\t[0] Thoat.\n");
    printf("\t======================\n");
}
void addStudent(int *length, struct Student sv[]) {
	int isValidId(char* studentId) {
    //9 ki tu chi sô hoac chu 
    if (strlen(studentId) != 9) return 0;
    int i;
    for (i = 0; studentId[i] != '\0'; i++) {
        if (!isalnum(studentId[i])) return 0;
    }
    return 1;
}

 // Kiem tra xem id co ton tai hay khong
	int isIdExist(struct Student sv[], int length,  char* studentId) {
    if (studentId == NULL || strlen(studentId) == 0) {
        return 0;
    }
	int i;
    for (i = 0; i < length; i++) {
       
        if (strcmp(sv[i].studentId, studentId) == 0) {
            return 1;
        }
    }
    return 0; 
} 


    // Kiem tra ten hop le
    int isValidName(char* fullName) {
        if (strlen(fullName) > 30 || strlen(fullName) == 0) return 0;
        int i;
        for (i = 0; fullName[i] != '\0'; i++) {
            if (isdigit(fullName[i])) return 0;
        }
        return 1;
    }

    // Kiem tra so dien thoai hop le 
    int isValidPhoneNumber(char* phone) {
        if (phone[0] != '0' || strlen(phone) != 10) return 0;
        int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (!isdigit(phone[i])) return 0;
        }
        return 1;
    }

    // Kiem tra so dien thoai co bi trung hay khong 
    int isPhoneExist(struct Student sv[], int length, char* phone) {
    	int i;
        for (i = 0; i < length; i++) {
            if (strcmp(sv[i].phone, phone) == 0) {
                return 1; //so dien thoai da ton tai
            }
        }
        return 0; // So dien thoai khong ton tai
    }

    // Kiem tra email 
    int isValidEmail(char* email) {
        if (strstr(email, "@gmail.com") == NULL) return 0;

        int countAtGmail = 0;
        char* pos = email;

        while ((pos = strstr(pos, "@gmail.com")) != NULL) {
            countAtGmail++;
            pos++;
        }

        return countAtGmail <= 1; // Email hop le neu khong c? nhieu hon 1 lan @gmail.com
    }

    // Kiem tra email co bi trung hay khong 
    int isEmailExist(struct Student sv[], int length, char* email) {
    	int i;
        for (i = 0; i < length; i++) {
            if (strcmp(sv[i].email, email) == 0) {
                return 1; // Email da ton tai
            }
        }
        return 0; // Email khong ton tai
    }

    // Kiem tra ngay thang nam sinh hop le 
    int isValidDate(int day, int month, int year) {
        int daysInMonth[] = {31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month < 1 || month > 12) return 0;
        if (day < 1 || day > daysInMonth[month - 1]) return 0;
        return 1;
    }

    // Bat dau them sinh vien 
    printf("\n\t***Add a Student***\n");
    int newStudents;
    printf("\nEnter number of students: ");
    scanf("%d", &newStudents);
    getchar();  
	int i;
    for (i = *length; i < *length + newStudents; i++) {
        printf("\n       Student %d\n", i + 1);

        // Nhap id sinh vien hop le 
        do {
            printf("Enter student ID: ");
            fgets(sv[i].studentId, 51, stdin);
            sv[i].studentId[strcspn(sv[i].studentId, "\n")] = '\0';
            if (strlen(sv[i].studentId) == 0 || !isValidId(sv[i].studentId) || isIdExist(sv, *length, sv[i].studentId)) {
                printf("Invalid ID or already exists! Please re-enter.\n");
            }
        } while (strlen(sv[i].studentId) == 0 || !isValidId(sv[i].studentId) || isIdExist(sv, *length, sv[i].studentId));

        // Nhap ten sinh vien va kiem tra hop le 
        do {
            printf("Enter student name: ");
            fgets(sv[i].fullName, 31, stdin);
            sv[i].fullName[strcspn(sv[i].fullName, "\n")] = '\0';
            if (strlen(sv[i].fullName) == 0 || !isValidName(sv[i].fullName)) {
                printf("Invalid name or already exists! Please re-enter.\n");
            }
        } while (strlen(sv[i].fullName) == 0 || !isValidName(sv[i].fullName));

        // kiem tra ngay sinh
        do {
            printf("Enter birth date for students (dd/mm/yyyy): \n");
            printf("Day: ");
            scanf("%d", &sv[i].dateOfBrith.day);
            printf("Month: ");
            scanf("%d", &sv[i].dateOfBrith.month);
            printf("Year: ");
            scanf("%d", &sv[i].dateOfBrith.year);
            if (sv[i].dateOfBrith.day == 0 || sv[i].dateOfBrith.month == 0 || sv[i].dateOfBrith.year == 0 || !isValidDate(sv[i].dateOfBrith.day, sv[i].dateOfBrith.month, sv[i].dateOfBrith.year)) {
                printf("Invalid date or month! Please re-enter..\n");
            }
        } while (sv[i].dateOfBrith.day == 0 || sv[i].dateOfBrith.month == 0 || sv[i].dateOfBrith.year == 0 || !isValidDate(sv[i].dateOfBrith.day, sv[i].dateOfBrith.month, sv[i].dateOfBrith.year));

        // Nhap gioi tinh
        do {
            printf("Enter student gender (1 for Male, 0 for Female): ");
            scanf("%d", &sv[i].gender);
            if (sv[i].gender != 1 && sv[i].gender != 0) {
                printf("Invalid gender! Please re-enter.\n");
            }
        } while (sv[i].gender != 1 && sv[i].gender != 0);

        getchar();  

        // nhap lop hoc
        do {
            printf("Class entry for students: ");
            fgets(sv[i].classroomId, 10, stdin);
            sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
            if (strlen(sv[i].classroomId) == 0) {
                printf("Class not allowed! Please re-enter.\n");
            }
        } while (strlen(sv[i].classroomId) == 0);

      // Nhap mk va kiem tra hop le 
        do {
            printf("NPassword for students (at least 6 characters): ");
            fgets(sv[i].password, 20, stdin);
            sv[i].password[strcspn(sv[i].password, "\n")] = '\0';
            if (strlen(sv[i].password) == 0 || strlen(sv[i].password) < 6) {
                printf("Invalid password or left blank! Please re-enter.\n");
            }
        } while (strlen(sv[i].password) == 0 || strlen(sv[i].password) < 6);
    }
// cap nhat so luong sinh vien
    *length += newStudents;
    printf("\nMore successful students.\n");
} 



void printHeader(){
	
	printf("\n\t  ***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
}
void printStudent(int length, struct Student sv[]){
	
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s|\n",
            sv[i].studentId,
            sv[i].classroomId,
            sv[i].fullName,
            sv[i].dateOfBrith.day,
            sv[i].dateOfBrith.month,
            sv[i].dateOfBrith.year,
            sv[i].gender ? "Male" : "Female",
            sv[i].email,
            sv[i].phone);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|\n");
    }
}
void saveStudentToFile(int length, struct Student sv[]){
	
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(sv, sizeof(struct Student), 50, fptr);
    printf("Student data saved successfully\n");
    fclose(fptr);
}
void loadStudentFromFile(int *length, struct Student sv[]){
	
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(sv, sizeof(struct Student), 50, fptr);
    fclose(fptr);
}
void deleteStudent(int *length, struct Student sv[]) {
    system("cls");
    printf("\n\t***Delete a Student***\n");
    getchar();
    char id[10];
    printf("\nEnter student code to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex = -1;
    
  
    int i;
    for (i = 0; i < *length; i++) {
        if (strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("\nCannot find student with Id %s.\n", id);
    } else {
        printf("\nA student was found with Id: %s\n", id);
        printf("  Student information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);

        
        char confirmation;
        printf("\nAre you sure you want to delete this student? (y/n): ");
        scanf(" %c", &confirmation);  
        if (confirmation == 'y' || confirmation == 'Y') {
           
            for (i = findIndex; i < *length - 1; i++) {
                sv[i] = sv[i + 1];
            }
            (*length)--;

            printf("\nStudents have successfully completed.\n");

            printf("\n\t***Update new student information ***\n");
            printHeader();
            printStudent(*length, sv);
        } else {
            printf("\nDelete function has been canceled.\n");
            
        }
    }
}
void editStudent(int length, struct Student sv[]) {
    system("cls");
    printf("\n\t***Edit student information***\n");

    char id[10];
    printf("\nEnter the student ID you need to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; 

    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("\nCannot find student with Id %s.\n", id);
    } else {
        printf("\nThere is a student with Id: %s\n", id);
        printf("  Student information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Nam" : "Nu");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);

        
        int isValidName = 1; 
        do {
            printf("\nEnter new name (no numbers, maximum 30 characters): ");
            fgets(sv[findIndex].fullName, 30, stdin);
            sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")] = '\0';  

            // Kiem tra ten khong qua 30 ki tu
            int j;
            for (j = 0; sv[findIndex].fullName[j] != '\0'; j++) {
                if (isdigit(sv[findIndex].fullName[j])) {
                    isValidName = 0;
                    break;
                }
            }
            if (strlen(sv[findIndex].fullName) > 30) {
                isValidName = 0;
            }
            if (!isValidName) {
                printf("Invalid student name. Please re-enter.\n");
            }
        } while (strlen(sv[findIndex].fullName) == 0 || strlen(sv[findIndex].fullName) > 30 || !isValidName);

        // Chinh sua ngay sinh 
        do {
            printf("Enter new date of birth (dd/mm/yyyy):\n");
            printf("   Enter new day: ");
            scanf("%d", &sv[findIndex].dateOfBrith.day);
            if (sv[findIndex].dateOfBrith.day < 1 || sv[findIndex].dateOfBrith.day > 31) {
                printf("Date of birth is invalid. Please re-enter..\n");
            }
        } while (sv[findIndex].dateOfBrith.day < 1 || sv[findIndex].dateOfBrith.day > 31);

        do {
            printf("   Enter new month: ");
            scanf("%d", &sv[findIndex].dateOfBrith.month);
            if (sv[findIndex].dateOfBrith.month < 1 || sv[findIndex].dateOfBrith.month > 12) {
                printf("Invalid birth month. Please re-enter.\n");
            }
        } while (sv[findIndex].dateOfBrith.month < 1 || sv[findIndex].dateOfBrith.month > 12);

        do {
            printf("   Ener new year: ");
            scanf("%d", &sv[findIndex].dateOfBrith.year);
            if (sv[findIndex].dateOfBrith.year < 1 || sv[findIndex].dateOfBrith.year > 2024) {
                printf("Invalid year of birth. Please re-enter..\n");
            }
        } while (sv[findIndex].dateOfBrith.year < 1 || sv[findIndex].dateOfBrith.year > 2024);

        // Chinh sua gioi tinh
        do {
            printf("Enter new gender (1 for Male, 0 for Female): ");
            scanf("%d", &sv[findIndex].gender);
            if (sv[findIndex].gender != 1 && sv[findIndex].gender != 0) {
                printf("Invalid gender. Please re-enter.\n");
            }
        } while (sv[findIndex].gender != 1 && sv[findIndex].gender != 0);

        getchar();

        // Chinh sua lop hoc
        do {
            printf("Enter new class: ");
            fgets(sv[findIndex].classroomId, 10, stdin);
            sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")] = '\0';  
            if (strlen(sv[findIndex].classroomId) == 0) {
                printf("The class is not clear. Please re-enter.\n");
            }
        } while (strlen(sv[findIndex].classroomId) == 0);

        // Chinh sua email
        do {
            printf("Enter new email (chua @gmail.com): ");
            fgets(sv[findIndex].email, 30, stdin);
            sv[findIndex].email[strcspn(sv[findIndex].email, "\n")] = '\0'; 

            int emailValid = (strchr(sv[findIndex].email, '@') != NULL) && (strstr(sv[findIndex].email, "@gmail.com") != NULL);
            if (!emailValid || strlen(sv[findIndex].email) == 0) {
                printf("Email is invalid. Please re-enter.\n");
            }
        } while (strlen(sv[findIndex].email) == 0 || strstr(sv[findIndex].email, "@gmail.com") == NULL);

        // Chinh sua so dien thoai
        do {
            printf("Enter new phone number (must start with '0' and be 11 characters): ");
            fgets(sv[findIndex].phone, 20, stdin);
            sv[findIndex].phone[strcspn(sv[findIndex].phone, "\n")] = '\0';  

            int phoneValid = 1;
            if (sv[findIndex].phone[0] != '0' || strlen(sv[findIndex].phone) != 11) {
                phoneValid = 0;
            }
            int j;
            for (j = 0; sv[findIndex].phone[j] != '\0'; j++) {
                if (!isdigit(sv[findIndex].phone[j])) {
                    phoneValid = 0;
                    break;
                }
            }
            if (!phoneValid || strlen(sv[findIndex].phone) == 0) {
                printf("Invalid phone number. Please re-enter..\n");
            }
        } while (strlen(sv[findIndex].phone) != 11 || sv[findIndex].phone[0] != '0');

        // Chinh sua mat khau
        do {
            printf("Enter new password (minimum 6 characters): ");
            fgets(sv[findIndex].password, 20, stdin);
            sv[findIndex].password[strcspn(sv[findIndex].password, "\n")] = '\0'; 

            if (strlen(sv[findIndex].password) < 6 || strlen(sv[findIndex].password) == 0) {
                printf("Password must be at least 6 characters long. Please re-enter.\n");
            }
        } while (strlen(sv[findIndex].password) < 6 || strlen(sv[findIndex].password) == 0);

        printf("\n\t***Update new Student***\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Nam" : "Nu");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);

        printf("\nStudents have successfully corrected.\n");
    }                 
} 
void searchStudent(int length, struct Student sv[]) {
    printf("\n\t*** Search a Student***\n");
    getchar();  
    char namePart[30];
    printf("\nEnter the name of the student you want to search for : ");
    fgets(namePart, sizeof(namePart), stdin);
    namePart[strcspn(namePart, "\n")] = '\0'; 
    int found = 0;
    int i;
    for (i = 0; i < length; i++) {
        // Kiem tra xem nguoi dung nhpa co trong ten cua danh sach sinh vien hay khong 
        if (strstr(sv[i].fullName, namePart) != NULL) {
            // Neu tim thay hien thi thong bao toan bo thon gtin sinh vien 
            if (!found) {
                printf("\nList of students found:\n");
                found = 1;
            }
            printf("\nStudent looking for a name %s:\n", sv[i].fullName);
            printf("ID: %s\n", sv[i].studentId);
            printf("Name: %s\n", sv[i].fullName);
            printf("Date of birth: %02d-%02d-%04d\n", sv[i].dateOfBrith.day, sv[i].dateOfBrith.month, sv[i].dateOfBrith.year);
            printf("Class: %s\n", sv[i].classroomId);
            printf("Email: %s\n", sv[i].email);
            printf("Phone: %s\n", sv[i].phone);
            printf("Password: %s\n", sv[i].password);
        }
    }

    if (!found) {
        printf("\nThe student information you are looking for was not found. \"%s\".\n", namePart);
    } else {
        printf("\nFind complete .\n");
    }
} 
void sortStudentsByName(int length, struct Student sv[]){
	
    int choice4;
	do{
		printf("\n\t***Arrange a student***\n");
	    printf("\n");
	    printf("\t  Arrange a student.\n");
	    printf("\t=====================\n");
	    printf("\t[1] Ascending order.\n");
	    printf("\t[2] Sort Descending.\n");
	    printf("\t[0] Exit.\n");
	    printf("\t=====================\n");
		printf("\tEnter your choose: ");
	    scanf("%d", &choice4);
		switch(choice4){
			struct Student temp;
			int i,j;
			case 1:
			    printf("\n\t  Ascending order\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)>0){
			                temp = sv[i];
			                sv[i] = sv[j];
			                sv[j] = temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents are successfully placed.\n");
				break;
			case 2:
				printf("\n\t  Sort Descending\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)<0){
			                temp=sv[i];
			                sv[i]=sv[j];
			                sv[j]=temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nStudents are successfully placed.\n");
				break;
			case 0:
				break;
			default:
				printf("\tError: please re-enter.\n");
	    }
	}while(choice4!=0);
}
void menuTeacher(){
	
    printf("\n***Teacher Management in C Language***\n");
    printf("\n");
    printf("\t    TEACHER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add a new Teacher.\n");
    printf("\t[2] Show teacher list.\n");
    printf("\t[3] Delete a new Teacher.\n");
    printf("\t[4] Edit Teacher Information.\n");
    printf("\t[5] Search Teacher.\n");
    printf("\t[6] Arrange Teacher.\n");
    printf("\t[7] Add a new Teacher.\n");
    printf("\t[0] Exit.\n");
    printf("\t======================\n");
}	

void addTeacher(int *length, struct Teacher tv[]) {
	int checkEmailUnique(struct Teacher tv[], int length, char email[]) {
		int i;
    for (i = 0; i < length; i++) {
        if (strcmp(tv[i].email, email) == 0) {
            return 0; 
        }
    }
    return 1;  
}
    printf("\n\t***Add a new Teacher***\n");

    int newTeacher;
    printf("\nAdd more teachers: ");
    scanf("%d", &newTeacher);
    getchar(); 
    
    int i;
    for (i = *length; i < *length + newTeacher; i++) {
        printf("\n       Teacher %d\n", i + 1);

        
        do {
            printf("Enter ID (only numbers, maximum 50 characters): ");
            fgets(tv[i].teacherId, 51, stdin);
            tv[i].teacherId[strcspn(tv[i].teacherId, "\n")] = '\0';

            int validId = 1;
            int j;
            for (j = 0; tv[i].teacherId[j] != '\0'; j++) {
                if (!isdigit(tv[i].teacherId[j])) {
                    validId = 0;
                    break;
                }
            }
            if (strlen(tv[i].teacherId) == 0 || strlen(tv[i].teacherId) > 50 || !validId) {
                printf("Invalid ID. Please re-enter..\n");
            }
        } while (strlen(tv[i].teacherId) == 0 || strlen(tv[i].teacherId) > 50 || !isdigit(tv[i].teacherId[0]));

        int validName = 1;
        do {
            printf("Enter name: ");
            fgets(tv[i].fullName, 31, stdin);
            tv[i].fullName[strcspn(tv[i].fullName, "\n")] = '\0';

            if (strlen(tv[i].fullName) == 0 || strlen(tv[i].fullName) > 30) {
                validName = 0;
            }
			int j;
            for (j = 0; tv[i].fullName[j] != '\0'; j++) {
                if (isdigit(tv[i].fullName[j])) {
                    validName = 0;
                    break;
                }
            }

            if (!validName) {
                printf("Invalid name. Please re-enter.\n");
            }
        } while (strlen(tv[i].fullName) == 0 || strlen(tv[i].fullName) > 30 || !validName);

       
        do {
            printf("Enter date of birth (dd mm yyyy): ");
            scanf("%d %d %d", &tv[i].dateOfBrith.day, &tv[i].dateOfBrith.month, &tv[i].dateOfBrith.year);

            if (tv[i].dateOfBrith.day < 1 || tv[i].dateOfBrith.day > 31 || 
                tv[i].dateOfBrith.month < 1 || tv[i].dateOfBrith.month > 12 || 
                tv[i].dateOfBrith.year < 1900 || tv[i].dateOfBrith.year > 2024) {
                printf("Invalid date of birth. Please re-enter.\n");
            }
        } while (tv[i].dateOfBrith.day < 1 || tv[i].dateOfBrith.day > 31 || 
                 tv[i].dateOfBrith.month < 1 || tv[i].dateOfBrith.month > 12 || 
                 tv[i].dateOfBrith.year < 1900 || tv[i].dateOfBrith.year > 2024);

       
        do {
            printf("Enter gender (1 for Male, 0 for Female): ");
            scanf("%d", &tv[i].gender);
            if (tv[i].gender != 1 && tv[i].gender != 0) {
                printf("Invalid gender. Please re-enter.\n");
            }
        } while (tv[i].gender != 1 && tv[i].gender != 0);

        getchar(); 

      
        do {
            printf("Enter Class: ");
            fgets(tv[i].classroomId, 11, stdin);
            tv[i].classroomId[strcspn(tv[i].classroomId, "\n")] = '\0';
        } while (strlen(tv[i].classroomId) == 0); 

      
        do {
            printf("Enter email (@gmail.com): ");
            fgets(tv[i].email, 31, stdin);
            tv[i].email[strcspn(tv[i].email, "\n")] = '\0';

            if (strstr(tv[i].email, "@gmail.com") == NULL) {
                printf("Invalid email. Please re-enter.\n");
            } else if (!checkEmailUnique(tv, *length, tv[i].email)) {
                printf("Email is already in use. Please enter another email.\n");
            }
        } while (strstr(tv[i].email, "@gmail.com") == NULL || !checkEmailUnique(tv, *length, tv[i].email));

       
        do {
            printf("Enter phone number (starts with '0' and is 10 characters): ");
            fgets(tv[i].phone, 21, stdin);
            tv[i].phone[strcspn(tv[i].phone, "\n")] = '\0';

            if (strlen(tv[i].phone) != 10 || tv[i].phone[0] != '0' || !isdigit(tv[i].phone[0])) {
                printf("Invalid phone number. Please re-enter.\n");
            }
        } while (strlen(tv[i].phone) != 10 || tv[i].phone[0] != '0');

      
        do {
            printf("Enter password (minimum 6 characters): ");
            fgets(tv[i].password, 21, stdin);
            tv[i].password[strcspn(tv[i].password, "\n")] = '\0';

            if (strlen(tv[i].password) < 6) {
                printf("Password must be at least 6 characters long. Please re-enter.\n");
            }
        } while (strlen(tv[i].password) < 6);
    }

    *length += newTeacher;  
    printf("\nAdd teacher successfully.\n");
}
void printHeader2(){
	
	printf("\n\t  ***All Teacher***\n");
    printf("|============|=============|=========================|=======================|============|============================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               |\n");
    printf("|============|=============|=========================|=======================|============|============================|=====================|\n");
}		
void printTeacher(int length, struct Teacher tv[]){
	
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s|\n",
            tv[i].teacherId,
            tv[i].classroomId,
            tv[i].fullName,
            tv[i].dateOfBrith.day,
            tv[i].dateOfBrith.month,
            tv[i].dateOfBrith.year,
            tv[i].gender ? "Male" : "Female",
            tv[i].email,
            tv[i].phone);
            printf("|------------|-------------|-------------------------|-----------------------|------------|----------------------------|---------------------|\n");
    }
}
void saveTeacherToFile(int length, struct Teacher tv[]){
	
    FILE *fptr = fopen("teachersData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file. \n");
        return;
    }
    fwrite(tv, sizeof(struct Teacher), 50, fptr);
    printf("Teacher data saved successfully.\n");
    fclose(fptr);
}
void loadTeacherFromFile(int *length, struct Teacher tv[]){
	
    FILE *fptr = fopen("teachersData.dat", "rb");
    if (fptr == NULL) {
        printf("Can not open file.\n");
        return;
    }
    *length = fread(tv, sizeof(struct Teacher), 50, fptr);
    fclose(fptr);
}
void deleteTeacher(int *length, struct Teacher tv[]) {

    printf("\n\t***Delete a Teacher***\n");
    getchar();
	char id[10];
    printf("\nEnter the teacher ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(tv[i].teacherId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nNo teacher found with Id.\n", id);
    }else {
        printf("\nThere is a teacher with Id: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            tv[i]=tv[i+1];
        }
        (*length)--;
        printf("\n\t***Update a new Teacher ***\n");
        printHeader2();
        printTeacher(*length, tv);
        printf("\nTeacher deleted successfully.\n");
    }
}
void editTeacher(int length, struct Teacher tv[]) {
   
    int isValidEmail(char* email) {
        if (strchr(email, '@') != NULL) {
            return 1;  
        }
        return 0;
    }

    int isValidPhoneNumber(char* phone) {
    	int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (!isdigit(phone[i])) {
                return 0;  
            }
        }
        return 1;
    }

    int isValidPassword(char* password) {
        if (strlen(password) >= 6) {
            return 1; 
        }
        return 0;
    }
    printf("\n\t***Edit Teacher Information***\n");
    getchar(); 
    char id[10];
    printf("\nEnter teacher ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; 
    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(tv[i].teacherId, id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("\nThere is no teacher with Id %s.\n", id);
    } else {
        printf("\nA teacher was found with Id: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", tv[findIndex].classroomId);
        printf("FullName: %s\n", tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", tv[findIndex].dateOfBrith.day, tv[findIndex].dateOfBrith.month, tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", tv[findIndex].email);
        printf("Phone: %s\n", tv[findIndex].phone);
        printf("Password: %s\n", tv[findIndex].password);
        printf("\nEnter new Name: ");
        fgets(tv[findIndex].fullName, 30, stdin);
        tv[findIndex].fullName[strcspn(tv[findIndex].fullName, "\n")] = '\0';
        printf("Enter date, month, male student (dd / mm / yyyy):\n");
        do {
            printf("   Enter date of birth: ");
            scanf("%d", &tv[findIndex].dateOfBrith.day);
            if (tv[findIndex].dateOfBrith.day < 1 || tv[findIndex].dateOfBrith.day > 31) {
                printf("%d The date is invalid. Please re-enter.\n", tv[findIndex].dateOfBrith.day);
            }
        } while (tv[findIndex].dateOfBrith.day < 1 || tv[findIndex].dateOfBrith.day > 31);

        do {
            printf("   Enter birth month: ");
            scanf("%d", &tv[findIndex].dateOfBrith.month);
            if (tv[findIndex].dateOfBrith.month < 1 || tv[findIndex].dateOfBrith.month > 12) {
                printf("%d The month you entered is invalid. Please re-enter.\n", tv[findIndex].dateOfBrith.month);
            }
        } while (tv[findIndex].dateOfBrith.month < 1 || tv[findIndex].dateOfBrith.month > 12);

        do {
            printf("   Enter year of birth: ");
            scanf("%d", &tv[findIndex].dateOfBrith.year);
            if (tv[findIndex].dateOfBrith.year < 1 || tv[findIndex].dateOfBrith.year > 2024) {
                printf("%d The year you entered is invalid. Please re-enter.\n", tv[findIndex].dateOfBrith.year);
            }
        } while (tv[findIndex].dateOfBrith.year < 1 || tv[findIndex].dateOfBrith.year > 2024);
        
        do {
            printf("Enter gender (1 for Male, 0 for Female): ");
            scanf("%d", &tv[findIndex].gender);
            if (tv[findIndex].gender != 1 && tv[findIndex].gender != 0) {
                printf("The gender you entered is invalid. Please re-enter.\n");
            }
        } while (tv[findIndex].gender != 1 && tv[findIndex].gender != 0);
        getchar(); 
        printf("Enter new Class: ");
        fgets(tv[findIndex].classroomId, 10, stdin);
        tv[findIndex].classroomId[strcspn(tv[findIndex].classroomId, "\n")] = '\0';

        do {
            printf("Enter new Email: ");
            fgets(tv[findIndex].email, 30, stdin);
            tv[findIndex].email[strcspn(tv[findIndex].email, "\n")] = '\0';
            if (!isValidEmail(tv[findIndex].email)) {
                printf("Invalid email. Please re-enter.\n");
            }
        } while (!isValidEmail(tv[findIndex].email));

        do {
            printf("Add phone: ");
            fgets(tv[findIndex].phone, 20, stdin);
            tv[findIndex].phone[strcspn(tv[findIndex].phone, "\n")] = '\0';
            if (!isValidPhoneNumber(tv[findIndex].phone)) {
                printf("Invalid phone. Please re-enter.\n");
            }
        } while (!isValidPhoneNumber(tv[findIndex].phone));

        do {
            printf("Enter password: ");
            fgets(tv[findIndex].password, 20, stdin);
            tv[findIndex].password[strcspn(tv[findIndex].password, "\n")] = '\0';
            if (!isValidPassword(tv[findIndex].password)) {
                printf("Invalid password (missing 6 characters). Please re-enter.\n");
            }
        } while (!isValidPassword(tv[findIndex].password));

        printf("\n\t***Update Teacher Information***\n");
        
        printHeader2();
        printTeacher(length, tv);
        printf("\nTeacher successfully edited.\n");
    }
}
void searchTeacher(int length, struct Teacher tv[]){
    printf("\n\t***Search a Teacher***\n");
    getchar();
	char name[30];
    printf("\nEnter teacher name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(tv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nNo teachers found with that name %s.\n",name);
    }else{
        printf("\nThe teacher was found with the name %s.\n",name);
        printf("The teacher was successfully found..\n\n");
	}
}
void sortTeachersByName(int length, struct Teacher tv[]){
	
    int choice6;
	do{
		printf("\n\t***Arrange a teacher***\n");
	    printf("\n");
	    printf("\t Arrange a teacher\n");
	    printf("\t=====================\n");
	    printf("\t[1] Ascending.\n");
	    printf("\t[2] Descending.\n");
	    printf("\t[0] Exit.\n");
	    printf("\t=====================\n");
		printf("\tEnter your choose: ");
	    scanf("%d", &choice6);
		switch(choice6){
			struct Teacher temp;
			int i,j;
			case 1:
			    printf("\n\t  Sort in ascending order\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)>0){
			                temp = tv[i];
			                tv[i] = tv[j];
			                tv[j] = temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nTeachers are successfully placed.\n");
				break;
			case 2:
				printf("\n\t  Sort in desscending order\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)<0){
			                temp=tv[i];
			                tv[i]=tv[j];
			                tv[j]=temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nTeachers are successfully placed.\n");
				break;
			case 0:
				break;
			default:
				printf("\tLoi: Please re-enter\n");
	    }
	}while(choice6!=0);
} 
void backandexit() {
	int choice9;
    do {
        printf("Go back(b)? or Exit(0)? : ");
        scanf(" %c", &choice9);
        if (choice9 == 'b') {
            return;
        } else if (choice9 == '0') {
            printf("End Program.\n");
            break;
        } else {
            printf("\tError: Please re-enter.\n");
        }
    } while (1);
} 
