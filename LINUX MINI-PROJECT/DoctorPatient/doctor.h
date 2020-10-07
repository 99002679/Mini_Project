
#include <iostream>
#include <pthread.h>
#include <semaphore.h>

class Doctor{

public:
    int patients;
    int beds;

    void * patientThread(void *args);





};

