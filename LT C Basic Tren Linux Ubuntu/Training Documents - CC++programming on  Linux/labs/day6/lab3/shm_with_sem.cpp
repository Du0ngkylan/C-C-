#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define SEM_FILE "sem.txt"
#define SHM_FILE "shm.txt"
#define ID 'a'

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

struct country {
    char name[30];
    char capital[30];
    char currency[30];
    int population;
};

void random_delay(){
    int random_num;
    struct timespec delay;
    
    random_num = rand() % 10;
    delay.tv_sec = 0;
    delay.tv_nsec = 10*random_num;
    nanosleep(&delay, NULL);
}

void sem_lock(int sem_set_id){
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

void sem_unlock(int sem_set_id){
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

void addcountry(int sem_set_id, int *country_num, struct country* countries, 
                const char* name, const char* capital, const char* currency, int population){
    sem_lock(sem_set_id);
    strcpy(countries[*country_num].name, name);   
    strcpy(countries[*country_num].capital, capital);
    strcpy(countries[*country_num].currency, currency);
    countries[*country_num].population = population;
    (*country_num)++;         
    sem_unlock(sem_set_id);
}
 
void do_child(int sem_set_id, int *country_num, struct country* countries){
    addcountry(sem_set_id, country_num, countries, "America", "Woashington DC", "U.S Dollar", 10000000);
    random_delay();
    addcountry(sem_set_id, country_num, countries, "Vietnam", "Hanoi", "VN Dong", 96000000);
    random_delay();
    addcountry(sem_set_id, country_num, countries, "Lao", "Phnom Penh", "Lao Dollar", 123224434);
    random_delay();
    addcountry(sem_set_id, country_num, countries, "Campuchia", "Viencham", "Cam Dollar", 34436456);
    random_delay();
}
 
void do_parent(int sem_set_id, int *country_num, struct country* countries){
    for (int k = 0; k < 5; k++){
        printf("---------------------------------------\n");
        printf("Number of countries: %d\n", *country_num);
        sem_lock(sem_set_id);
        for (int i = 0; i < *country_num; i++){
            printf("\nCountry: %s\n", countries[i].name);
            printf("\tCapital: %s\n", countries[i].capital);
            printf("\tCurrency: %s\n", countries[i].currency);
            printf("\tPopulation: %d\n", countries[i].population);
            
        } 
        printf("\n");
        sem_unlock(sem_set_id);
        random_delay();
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    int sem_set_id;
    int shm_id;
    int pid;
    semun sem_val;
    char* shmaddr;
    int* country_num;
    country* countries;
    int res;
    struct shmid_ds shm_des; 
    
    key_t SEM_KEY = ftok(SEM_FILE, ID);
    sem_set_id = semget(SEM_KEY, 1, IPC_CREAT | 0777);
    if (sem_set_id == -1){
        perror("Can't creat semapore");
        exit(1);
    }
    sem_val.val = 1;
    res = semctl(sem_set_id, 0, SETVAL, sem_val);
    if (res == -1){
        perror("Can't initilize for semapore");
        exit(1);
    }
    
    key_t SHM_KEY = ftok(SHM_FILE, ID);
    shm_id = shmget(SHM_KEY, 2048, IPC_CREAT | 0777);
    if (shm_id == -1) {
        perror("Can't creat shared memory");
        exit(1);
    }
    
    shmaddr = (char*)shmat(shm_id, NULL, 0);
    if (shmaddr == NULL){
        perror("Can't attach the shared memory to process");
        exit(1);
    }
    
    country_num = (int*)shmaddr;
    *country_num = 0;
    countries = (country*)((char*)shmaddr + sizeof(int));
    
    pid = fork();
    
    switch(pid){
        case -1: perror("Can't creat a child process"); exit(1); break;
        case 0: do_child(sem_set_id, country_num, countries); exit(0); break;
        default: do_parent(sem_set_id, country_num, countries); break;
    }
    
    {
        int status_child;
        wait(&status_child);
    }
    
    res = shmdt(shmaddr);
    if (res == -1)
        perror("Can't deattach the shared memory");
    if (shmctl(shm_id, IPC_RMID, &shm_des) == -1)
        perror("Can't destroy the shared memory");
    printf("Finish child and parent\n");
    exit(0);
}
 
