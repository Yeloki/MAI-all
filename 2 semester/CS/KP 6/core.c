//
// Created by Yeloki on 29.05.2022.
//

#include <bits/types/FILE.h>
#include <stdio.h>
#include <string.h>
#include "core.h"


void create_new() {
    char name[str_len];
    FILE *thisfile;
    printf("Please, enter a name of the file you want to create or renew:\n");
    scanf("%s", name);
    thisfile = fopen(name, "rb");
    if (thisfile == NULL) {
        thisfile = fopen(name, "wb");
        printf("File %s was successfully created\n", name);
        fclose(thisfile);
    } else {
        thisfile = fopen(name, "wb");
        printf("File %s has become empty\n", name);
        fclose(thisfile);
    }
}


void add() {
    FILE *thisfile;
    char name[str_len];
    int num;
    comp pc;
    printf("Enter a name of the file where you want add tuple:\n");
    scanf("%s", name);
    printf("How many tuples you want to add?\n");
    scanf("%d", &num);
    thisfile = fopen(name, "ab");
    for (int i = 0; i < num; i++) {
        printf("Enter the surname of pc's owner, press underlines instead of whitespaces:\n");
        scanf("%s", pc.surname);

        printf("Enter the number of processors:\n");
        scanf("%d", &pc.processors);

        printf("Enter type of processors, press underlines instead of whitespaces\n");
        scanf("%s", pc.proc_type);

        printf("Enter size of memory\n");
        scanf("%d", &pc.memory_size);

        printf("Enter type of video controller, press underlines instead of whitespaces\n");
        scanf("%s", pc.video_controller_type);

        printf("Enter size of video memory\n");
        scanf("%d", &pc.vid_mem_size);

        printf("Enter type of hard disks, press underlines instead of whitespaces\n");
        scanf("%s", pc.HMDD_type);

        printf("Enter number of hard disks\n");
        scanf("%d", &pc.HMDD_number);

        printf("Enter size of hard disks\n");
        scanf("%d", &pc.HMDD_size);

        printf("Enter number of controllers\n");

        scanf("%d", &pc.controllers_number);

        printf("Enter number of devices\n");
        scanf("%d", &pc.devices_number);

        printf("Enter OS, press underlines instead of whitespaces:\n");
        scanf("%s", pc.OS);
        fwrite(&pc, sizeof(comp), 1, thisfile);
        printf("Tuple was added\n");
    }
    fclose(thisfile);
}


void delite() {
    FILE *thisfile;
    char name[str_len];
    printf("Enter a name of the removing file\n");
    scanf("%s", name);
    thisfile = fopen(name, "rb");
    if (!thisfile) {
        printf("This file doesn't exist in the directory\n");
    } else {
        remove(name);
        fclose(thisfile);
        printf("File %s was delited\n", name);
    }
}


void help() {
    printf("Enter '-c' to create new file\nEnter '-a' to add tuple to new or existing file\n");
    printf("Enter '-h' for help\nEnter '-r' to remove file\nEnter '-p' to print file\nEnter '-f' to use function\n");
}


void print() {
    comp pc;
    FILE *thisfile;
    char name[str_len];
    printf("Enter a name of the file you want to print\n");
    scanf("%s", name);
    thisfile = fopen(name, "rb");
    if (thisfile == NULL) {
        printf("This file doesn't exist in the directory\n");
        return;

    } else {

        printf("\n");
        printf("|	Surname	|Number of CPUs|   CPUs' type   |Memory|VideoControllerType|Video memory| HDD's type |HDD's Number|HDD's size|Contr. numb.|Devices|      OS      |\n");
        while (fread(&pc, sizeof(comp), 1, thisfile) && feof(thisfile) == 0) {
            fprintf(stdout, "|%-15s|%-14d|%-16s|%-6d|%-19s|%-12d|%-12s|%-12d|%-10d|%-12d|%- 7d|%-14s|\n",
                    pc.surname, pc.processors, pc.proc_type, pc.memory_size, pc.video_controller_type, pc.vid_mem_size,
                    pc.HMDD_type, pc.HMDD_number, pc.HMDD_size, pc.controllers_number, pc.devices_number, pc.OS);
        }
        fclose(thisfile);
        printf("\n");
    }
}

void func() {
    comp pc;
    FILE *thisfile;
    char name[str_len];
    char type1[] = "AMD_Opteron";
    char type2[] = "Intel_Xeon";
    char type3[] = "Intel_Atom";
    char type4[] = "Intel_Itanium";
    char os1[] = "Free_BSD";
    char os2[] = "Windows_Server";
    char os3[] = "CentOS";
    char os4[] = "Ubuntu_Server";
    char os5[] = "Gentoo";
    char os6[] = "Fedora";
    char os7[] = "OS_X_Server";
    char os8[] = "OpenBSD";
    char os9[] = "Solaris";
    char os10[] = "HO-UX";
    char os11[] = "AIX";
    printf("Enter a name of the file where you want to use function:\n");
    scanf("%s", name);
    thisfile = fopen(name, "rb");
    if (thisfile == NULL)
        printf("This file doesn't exist in the directory\n");
    else {

        printf("\n");
        printf("|	Surname	|Number of CPUs|   CPUs' type   |Memory|VideoControllerType|Video memory| HDD's type |HDD's Number|HDD's size|Contr. numb.|Devices|      OS      |\n");
        while (fread(&pc, sizeof(comp), 1, thisfile) && feof(thisfile) == 0) {
            if
                    ((((strcmp(pc.proc_type, type1) == 0) || (strcmp(pc.proc_type, type2) == 0) ||
                       (strcmp(pc.proc_type, type3) == 0) || (strcmp(pc.proc_type, type4) == 0)) &&
                      ((strcmp(pc.OS, os1) == 0) || (strcmp(pc.OS, os2) == 0) || (strcmp(pc.OS, os3) == 0) ||
                       (strcmp(pc.OS, os4) == 0) ||
                       (strcmp(pc.OS, os5) == 0) || (strcmp(pc.OS, os6) == 0) || (strcmp(pc.OS, os7) == 0) ||
                       (strcmp(pc.OS, os8) == 0) || (strcmp(pc.OS, os9) == 0) || (strcmp(pc.OS, os10) == 0) ||
                       (strcmp(pc.OS, os11) == 0))) &&
                     ((pc.processors > 1) || (pc.memory_size >= 16) || (pc.HMDD_number > 1) || (pc.HMDD_size >= 1024) ||
                      (pc.devices_number > 15))) {
                fprintf(stdout, "|%-15s|%-14d|%-16s|%-6d|%-19s|%-12d|%-12s|%-12d|%-10d|%- 12d|%-7d|%-14s|\n",
                        pc.surname, pc.processors, pc.proc_type, pc.memory_size, pc.video_controller_type,
                        pc.vid_mem_size, pc.HMDD_type, pc.HMDD_number, pc.HMDD_size, pc.controllers_number,
                        pc.devices_number, pc.OS);
            }
        }
        fclose(thisfile);
        printf("\n");
    }
}
