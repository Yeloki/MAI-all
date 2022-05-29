//
// Created by Yeloki on 29.05.2022.
//

#ifndef KP_6_CORE_H
#define KP_6_CORE_H
#define str_len 256


typedef struct Computer { char surname[str_len]; int processors;
    char proc_type[str_len]; int memory_size;
    char video_controller_type[str_len]; int vid_mem_size;
    char HMDD_type[str_len]; int HMDD_number;
    int HMDD_size;
    int controllers_number; int devices_number; char OS[str_len];
} comp;
void add();
void delite();
void help();
void print();
        void create_new();
void func();



#endif //KP_6_CORE_H
