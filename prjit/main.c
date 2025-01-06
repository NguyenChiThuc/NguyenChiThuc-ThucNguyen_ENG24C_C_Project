#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
    int choice, choiceMenuStudent, choiceMenuTeacher, choiceMenuAdmin;
    int studentCount = 0;
    int length = 0;
    int teacherCount= 0;
    struct Student students[50];
    struct Teacher teachers[50];

    loadStudentsFromFile(&studentCount, students);
    loadTeachersFromFile(&teacherCount, teachers);
    do {
        menuStart();
        printf("\tEnter your choose: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            	system("cls");
                do{
                    menuAdmin();
                    printf("\tEnter your choose: ");
                    scanf("%d", &choiceMenuAdmin); 
                    switch(choiceMenuAdmin){
                        case 1:
                        	system("cls");
                            do {
                                menuStudents();
                                printf("\tEnter your selection: ");
                                scanf("%d", &choiceMenuStudent);
                                switch(choiceMenuStudent){
                                    case 1:
                                    	system("cls");
                                        addStudent(&studentCount, students);
                                        backandexit();
                                        saveStudentToFile(studentCount, students);
                                        break;
                                    case 2:
                                    	system("cls");
                                        printHeader();
                                        printStudent(studentCount, students);
                                        backandexit();
                                        break;
                                    case 3:
                                    	system("cls");
                                    	deleteStudent(&studentCount, students);
                                    	backandexit();
                                    	saveStudentToFile(studentCount, students);
                                    	break;
                                    case 4:
                                    	system("cls");
                                    	editStudent(studentCount, students);
                                    	backandexit();
                                    	saveStudentToFile(studentCount, students);
                                    	break;
                                    case 5:
                                    	system("cls");
                                    	searchStudent(studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 6:
                                    	system("cls");
                                    	sortStudentsByName(studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 0:
                                        break;
                                    default:
                                        printf("\tLoi: Please enter again.\n");
                                }
                            }while(choiceMenuStudent!=0);
                            break;
                        case 2: 
                        	break;
                        case 3:
                        	system("cls");
                        	do{
                        		menuTeacher();
                        		printf("\tEnter your selection: ");
                                scanf("%d", &choiceMenuTeacher);
                                switch(choiceMenuTeacher){
                                	case 1:
                                		system("cls");
                                		addTeacher(&teacherCount, teachers);
                                		saveTeacherToFile(teacherCount, teachers);
                                		backandexit();
                                		break;
                                	case 2:
                                		system("cls");
                                		printHeader2();
                                        printTeacher(teacherCount, teachers);
                                        backandexit();
                                		break;
                                	case 3:
                                		system("cls");
                                    	deleteTeacher(&teacherCount, teachers);
                                    	saveTeacherToFile(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 4:
                                    	system("cls");
                                    	editTeacher(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 5:
                                    	system("cls");
                                    	searchTeacher(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 6:
                                    	system("cls");
                                    	sortTeachersByName(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                	case 7:
                                		system("cls");
                                		backandexit();
                                		break;
                                	case 0:
                                		printf("You exit the program\n");
                                		break;
                                	default:
                                		printf("\tLoi:Please enter again.\n");	
                                }
							}while(choiceMenuTeacher!=0);
                        	break; 
                        case 4:
                        	system("cls");
              				printf("You are using the system to separate students from the dormitory state ");
              				backandexit();
            				break;
                        case 0:
                        	printf("You choose to exit the program");
                            break;
                        default:
                            printf("\tLoi: Please enter again.\n");
                    }
                }while(choiceMenuAdmin!=0);
                break;
            case 2:
            	system("cls");
                break;
            case 3:
           		system("cls");
                break;
            case 0:
                printf("\tExiting the program...\n");
                break;
            default:
                printf("\n");
				printf("\tLoi: Please enter again\n");
        }
    }while(choice!=0);  
    return 0;
}
