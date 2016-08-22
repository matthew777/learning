#include <stdio.h>
#include <string.h>

#define NUM 2
#define NAMESIZE 13

typedef struct nodetype_t NODETYPE;
struct nodetype_t
{
    int id;
    char name[NAMESIZE];
}student[NUM];

int main(int argc, char *argv[])
{
    NODETYPE *student_0;

    student_0 = &student[0];
    student_0->id = 101;
    strcpy (student_0->name, "Kitty");
    printf ("student_0 id: %d\t name: %s\n", student_0->id, student_0->name);

    student[1].id = 102;
    strcpy (student[1].name, "Do Ra A Mon");
    printf ("student[1] id: %d\t name: %s\n", student[1].id, student[1].name);
	
    printf ("student_0->id size: %d\n", sizeof(student_0->id));
    printf ("student_0->name size: %d\n", sizeof(student_0->name));

    printf ("student_0 size: %d\n", sizeof(student_0));
    printf ("*student_0 size: %d\n", sizeof(*student_0));
    printf ("student[0] size: %d\n", sizeof(student[0]));

    return 0;
}

