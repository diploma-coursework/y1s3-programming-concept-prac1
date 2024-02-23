#include <stdio.h>
#include <string.h>

struct Attendance {
	char studentName[40];
	char programmeCode[4];
	int yearOfStudy;
	int groupNo;
	int daysAbsent;
};

int main() {
	struct Attendance att;
	char actionMsg[30];

	printf("Enter your name > ");
	scanf("%[^\n]%*c", att.studentName);
	printf("Enter your programme code > ");
	scanf("%s", att.programmeCode);
	printf("Enter your year of study > ");
	scanf("%d", &att.yearOfStudy);
	printf("Enter your group number > ");
	scanf("%d", &att.groupNo);
	printf("Enter your days of absent > ");
	scanf("%d", &att.daysAbsent);

	// evaluate action
	if (att.daysAbsent < 3) strcpy(actionMsg, "warning to student");
	else if (att.daysAbsent < 5) strcpy(actionMsg, "inform parents");
	else strcpy(actionMsg, "bar from exam");

	printf(
		"Name         Programme    Group    Days Absent    Action\n"
		"--------------------------------------------------------------------\n"
		"%-12s %-12s %-8d %-14d %s\n",
		att.studentName, att.programmeCode, att.groupNo, att.daysAbsent, actionMsg
	);
}