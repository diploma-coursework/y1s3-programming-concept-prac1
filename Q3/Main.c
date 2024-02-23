#include <stdio.h>
#include <string.h>

struct Time {
	int hours;
	int minutes;
} current, nextMin;

int main() {
	printf("Enter the current time for hours > ");
	scanf("%d", &current.hours);
	printf("Enter the current time for minutes > ");
	scanf("%d", &current.minutes);

	nextMin = current;
	if (nextMin.minutes == 59) {
		nextMin.minutes = 0;
		nextMin.hours++;
	}
	else {
		nextMin.minutes++;
	}

	if (nextMin.hours == 13) {
		nextMin.hours = 1;
	}

	printf("It is now %02d:%02d. Next minute it will be %02d:%02d\n",
		current.hours, current.minutes,
		nextMin.hours, nextMin.minutes
	);
}