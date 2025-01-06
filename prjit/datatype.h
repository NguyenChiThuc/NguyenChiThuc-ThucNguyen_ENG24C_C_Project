#include<stdbool.h>
struct Date{
	int day,month,year;
};
struct Student{
	char studentId[10];
	char classroomId[10];
	char fullName[30];
	struct Date dateOfBrith;
	bool gender;
	char email[30];
	char phone[20];
	char password[20];
};

struct Classroom{
	char classroomId[10];
	char teacherID[10];
	char classroomName[20];
	struct Student *students;
	int numStudents;
};

struct Teacher{
	char teacherId[10];
	char classroomId[10];
	char fullName[30];
	struct Date dateOfBrith;
	bool gender;
	char email[30];
	char phone[20];
	char password[20];
    struct Classroom *classrooms;    	
};

//dinh nghia du lieu cho nguoi dung nhap vao tai khoan 
/*typedef struct {
    char username[30];
    char password[30];
} Admin; */	
