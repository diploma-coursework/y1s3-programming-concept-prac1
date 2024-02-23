#include <stdio.h>
#include <string.h>

struct Time {
	int hours;
	int minutes;
} current, nextMin;

int main() {
	while (1) {
		printf("Enter the current time for hours > ");
		scanf("%d", &current.hours);
		if (current.hours > 12) {
			printf("Invalid hour, maximum is 12.\n");
			continue;
		}
		break;
	}

	while (1) {
		printf("Enter the current time for minutes > ");
		scanf("%d", &current.minutes);
		if (current.minutes > 59) {
			printf("Invalid minute, maximum is 59.\n");
			continue;
		}
		break;
	}

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