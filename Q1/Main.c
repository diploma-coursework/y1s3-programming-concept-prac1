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

	strcpy(att.studentName, "Tan Ah Kow");
	strcpy(att.programmeCode, "DCS");
	att.yearOfStudy = 1;
	att.groupNo = 3;
	att.daysAbsent = 1;

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