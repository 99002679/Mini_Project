#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include "doctor.h"

using namespace std;

int patients;
int beds;

//only a specified number of people in the waiting room at a time
sem_t waitroom;

//only a single person can have their hair cut at a time
sem_t mutex;

//no more than one activity should be printed to console at a time
sem_t activity;

void * patientThread(void *args){
  int *p = (int *) args;
  int patientNum = *p;
  sem_wait(&activity);
  cout << "Patient-" << patientNum << " Coming to hospital" << endl;
  sem_post(&activity);
  sem_wait(&activity);
  cout << "Patient-" << patientNum << " arrived at hospital." << endl;
  sem_post(&activity);
  sem_wait(&waitroom);
  sem_wait(&activity);
  cout << "Patient " << patientNum << " entering waiting room." << endl;
  sem_post(&activity);
  sem_wait(&mutex);
  sem_post(&waitroom);
  sem_wait(&activity);
  cout << "Patient " << patientNum << " knock up the Doctor." << endl;
  sem_post(&activity);
  sem_wait(&activity);
  cout << "The doctor is diagnosing the disease of Patient-"<<patientNum<< endl;
  sem_post(&activity);
  sem_wait(&activity);
  cout << "The doctor has finished Patient-"<<patientNum<<" diagnosis" << endl;
  sem_post(&activity);
  sem_wait(&activity);
  cout << "The doctor is taking rest for a while." << endl;
  sem_post(&activity);
  sem_post(&mutex);
  sem_wait(&activity);
  cout << "Patient-" << patientNum << " leaving the Hospital." << endl;
  sem_post(&activity);
  return 0;
}

int main(){
  cout << "MAXIMUM NUMBER OF PATIENTS ALLOWED PER DAY IN A CLINIC CAN ONLY BE 25. ";
  cout<<endl;
  cout<<endl;
  cout << "ENTER NUMBER OF PATIENTS AND BEDS." << endl;
  cin >> patients >> beds;
  while (cin.fail()){
  	cout << "Input must be two integers separated by a space" << endl;
  	cin.clear();
  	cin.ignore(256, '\n');
  	cin >> patients >> beds;
  }
  cout << "A solution to the doctor ";
  cout << "problem using semaphores." << endl;
  pthread_t thread[patients];
  sem_init(&waitroom, 0, beds);
  sem_init(&mutex, 0, 1);
  sem_init(&activity, 0, 1);
  int *patientNum;
  cout << "The doctor is at rest for a while" << endl;

  //creates a thread for each patient
  for (int n = 0; n < patients; n++){
  	patientNum  = new int(n);
  	if(pthread_create(&thread[n], NULL, patientThread, (void *) patientNum)){
  	  cout << "Error with thread creation" << endl;
  	  return -1;
  	}
  }

  for (int n = 0; n < patients; n++){
  	if(pthread_join(thread[n], NULL)){
  	  cout << "Error joining thread" << endl;
  	  return -1;
  	}
  }
  cout << "The Doctor is going home for the day." << endl;
  return 0;
}
