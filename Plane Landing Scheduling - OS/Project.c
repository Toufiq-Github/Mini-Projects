#include <stdio.h>
#include <string.h>

typedef struct {
    char flight_number[10];
    int fuel_level;            // Fuel level (lower is more critical)
    int distance;              // Distance from airport (closer is more critical)
    int emergency_status;      // 1 if emergency, 0 otherwise
    int landing_duration;      // Time taken to land (in minutes)
    int arrival_time;          // Time when the plane requests landing (in minutes)
    int priority;              // Priority value (calculated based on factors)
} Plane;

// Function to convert time from HH.MM format and AM/PM to minutes from start of day
int convertTimeToMinutes(int hour, int minute, char period[]) {
    if (strcmp(period, "PM") == 0 && hour != 12) {
        hour +=12; // Convert PM hour to 24-hour format
    }
    else if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0; // Handle 12 AM as midnight
    }
    return hour * 60 + minute;
}

// Function to convert minutes back to HH:MM AM/PM format for display
void convertMinutesToTime(int minutes, char *timeStr) {
    int hour = (minutes / 60) % 24;
    int minute = minutes % 60;
    char period[3] = "AM";

    if (hour >= 12) {
        if (hour > 12) {
            hour -= 12;
        }
        strcpy(period, "PM");
    }
    else if (hour == 0) {
        hour = 12;  // Midnight case
    }
    sprintf(timeStr, "%02d:%02d %s", hour, minute, period);
}

// Function to input details of a plane
void inputPlane(Plane *p) {
    printf("Enter flight number: ");
    scanf(" %[^\n]", p->flight_number);
    printf("Enter fuel level: ");
    scanf("%d", &p->fuel_level);
    printf("Enter distance from airport (in miles): ");
    scanf("%d", &p->distance);
    printf("Is this an emergency flight? (1 for yes, 0 for no): ");
    scanf("%d", &p->emergency_status);
    printf("Enter landing duration (in minutes): ");
    scanf("%d", &p->landing_duration);
    getchar(); // Consume the newline character

    char timeStr[12]; // Buffer to hold the input time string
    printf("Enter request arrival time (in HH:MM format, e.g., 01:30 AM or 12:45 PM): ");
    fgets(timeStr, sizeof(timeStr), stdin);


    int hour, minute;
    char period[3];
    sscanf(timeStr, "%d:%d %s", &hour, &minute, period); // parser

    // Convert the input time to minutes from start of the day
    p->arrival_time = convertTimeToMinutes(hour, minute, period);

     // Calculate priority: higher priority for emergency, lower fuel, and closer distance
    int emergencyPriority = 0;
    if (p->emergency_status == 1) {
        emergencyPriority = 100;
    }
    p->priority = emergencyPriority + (100 - p->fuel_level) + (100 - p->distance);
}


// Sort planes based on priority first, then by arrival time if priority is the same
void priorityScheduling(Plane planes[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Compare by priority first
            if (planes[j].priority < planes[j+1].priority) {
                Plane temp = planes[j];
                planes[j] = planes[j+1];
                planes[j+1] = temp;
            }
            // If priorities are the same, compare by arrival time
            else if (planes[j].priority == planes[j+1].priority && planes[j].arrival_time > planes[j+1].arrival_time) {
                Plane temp = planes[j];
                planes[j] = planes[j+1];
                planes[j+1] = temp;
            }
            // If both priority and arrival time are the same, compare by landing duration
            else if (planes[j].priority == planes[j+1].priority && planes[j].arrival_time == planes[j+1].arrival_time) {
                if (planes[j].landing_duration > planes[j+1].landing_duration) {
                    Plane temp = planes[j];
                    planes[j] = planes[j+1];
                    planes[j+1] = temp;
            }
        }
    }
    }
}

// Function to print the Plane Landing Schedule in a table format
void printLandingSchedule(Plane planes[], int n) {
    printf("\n\n---------------------------AIR TRAFFIC CONTROL SIMULATION-------------------------\n\n");
    printf("\nPlane Landing Schedule :\n");
    printf(" -------------------------------------------------------------------------------------\n");
    printf("| Flight  | Fuel | Distance | Emergency | Priority | Landing Duration | Arrival Time  |\n");
    printf("|---------|------|----------|-----------|----------|------------------|---------------|\n");
    char timeStr[10];
    for (int i = 0; i < n; i++) {
        convertMinutesToTime(planes[i].arrival_time, timeStr);
        printf("| %-7s | %4d | %8d | %9s | %8d | %16d | %13s |\n",
            planes[i].flight_number, planes[i].fuel_level, planes[i].distance,
            (planes[i].emergency_status ? "Yes" : "No"),
            planes[i].priority, planes[i].landing_duration, timeStr);
    }
    printf("|---------|------|----------|-----------|----------|------------------|---------------|\n");
}

// Function to print Gantt chart for plane landings in a table format
void printGanttChart(Plane planes[], int n) {
    int currentTime = 0;
    printf("\nGantt Chart (Landing Schedule)\n");
    printf(" ---------------------------------------------\n");
    printf("| Flight Number | Landing Time   | Duration   |\n");
    printf("|---------------|----------------|------------|\n");
    char timeStr[10];
    for (int i = 0; i < n; i++) {
        if (currentTime < planes[i].arrival_time) {
            currentTime = planes[i].arrival_time;
        }
        convertMinutesToTime(currentTime, timeStr);
        printf("| %-13s | %-14s | %10d |\n", planes[i].flight_number, timeStr, planes[i].landing_duration);
        currentTime += planes[i].landing_duration;
    }
    printf("|---------------|----------------|------------|\n");
}

int main() {
    int n;
    printf("Enter the number of planes: ");
    scanf("%d", &n);
    Plane planes[n];

    for (int i = 0; i < n; i++) {
        printf("\nEntering details for plane %d\n", i + 1);
        inputPlane(&planes[i]);
    }

    priorityScheduling(planes, n);

    printLandingSchedule(planes, n);
    printGanttChart(planes, n);

    return 0;
}
