/*
    Business struct
    Domingo Gallardo Saavedra
    April 5, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Department enum
typedef enum business_dep {
    DEP_HR,
    DEP_SALES,
    DEP_RESEARCH,
    DEP_SOFTWARE,
    DEP_EXECUTIVE
} business_dep;

// Employee struct
typedef struct employee{
    business_dep department;
    int annual_salary;
    unsigned social_sec_num;
} employee;

// Salary bases constants
#define HR_DEP_SALARY_BASE          50000
#define SALES_DEP_SALARY_BASE       60000
#define RESEARCH_DEP_SALARY_BASE    70000
#define SOFTWARE_DEP_SALARY_BASE    85000
#define EX_DEP_SALARY_BASE         150000

// Salary ranges constants
#define HR_DEP_SALARY_RANGE         50000
#define SALES_DEP_SALARY_RANGE      90000
#define RESEARCH_DEP_SALARY_RANGE   50000
#define SOFTWARE_DEP_SALARY_RANGE   90000
#define EX_DEP_SALARY_RANGE        250000

// Prototypes
int salary_generator(business_dep dep);
void print_employee(const employee *emp, int index);
const char* get_department_name(business_dep dep);
void generate_social_numbers(unsigned *list, int size);
int is_duplicate(unsigned *list, int size, unsigned value);

int main() {
    const int NUM_EMPLOYEES = 10;
    employee employees[NUM_EMPLOYEES];
    unsigned social_numbers[NUM_EMPLOYEES];

    srand(time(NULL)); // random seed
    generate_social_numbers(social_numbers, NUM_EMPLOYEES);

    // Random employees
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        business_dep dept = rand() % 5;
        employees[i].department = dept;
        employees[i].annual_salary = salary_generator(dept);
        employees[i].social_sec_num = social_numbers[i];
    }

    // Prints employees
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        print_employee(&employees[i], i + 1);
    }

    return 0;
}


int salary_generator(business_dep dep) {
    int salary_base, salary_range;

    switch (dep) {
        case DEP_HR:
            salary_base = HR_DEP_SALARY_BASE;
            salary_range = HR_DEP_SALARY_RANGE;
            break;
        case DEP_SALES:
            salary_base = SALES_DEP_SALARY_BASE;
            salary_range = SALES_DEP_SALARY_RANGE;
            break;
        case DEP_RESEARCH:
            salary_base = RESEARCH_DEP_SALARY_BASE;
            salary_range = RESEARCH_DEP_SALARY_RANGE;
            break;
        case DEP_SOFTWARE:
            salary_base = SOFTWARE_DEP_SALARY_BASE;
            salary_range = SOFTWARE_DEP_SALARY_RANGE;
            break;
        case DEP_EXECUTIVE:
            salary_base = EX_DEP_SALARY_BASE;
            salary_range = EX_DEP_SALARY_RANGE;
            break;
        default:
            salary_base = 0;
            salary_range = 1;
            break;
    }

    return salary_base + rand()%salary_range;
}

void print_employee(const employee *emp, int index) {
    printf("Employee %d:\n"
           "    - Security number: %u\n"
           "    - Business department: %s\n"
           "    - Annual salary: %d\n",
           index, 
           emp->social_sec_num, 
           get_department_name(emp->department),
           emp->annual_salary);
}

const char* get_department_name(business_dep dep) {
    switch (dep) {
        case DEP_HR: return "Human Resources";
        case DEP_SALES: return "Sales";
        case DEP_RESEARCH: return "Research";
        case DEP_SOFTWARE: return "Software";
        case DEP_EXECUTIVE: return "Executive";
        default: return "Unknown";
    }
}

void generate_social_numbers(unsigned *list, int size) {
    for (int i = 0; i < size; ++i) {
        unsigned num;
        do {
            num = rand() % 900000000 + 100000000;
        } while (is_duplicate(list, i, num));
        list[i] = num;
    }
}

int is_duplicate(unsigned *list, int size, unsigned value) {
    for (int i = 0; i < size; ++i) {
        if (list[i] == value) return 1;
    }
    return 0;
}