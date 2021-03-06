// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//

//Helper function to add one new car to the list
#include "traincar.h"
#include <vector>

void PushBack(TrainCar*& simple, TrainCar* newCar);

//Destroy thr list from beginning to avoid memory leak
void DeleteAllCars(TrainCar* simple);
//Optimization problem
std::vector<TrainCar*>  ShipFreight(TrainCar*& all_engines, TrainCar*& all_freight, int min_speed, int max_cars_per_train);
//Sort the freight list from heavy to light
void sortFreights(TrainCar*& all_freight);
//Swap to adjacent Node, Note that std::sort doesn't work well here
void swap(TrainCar*& a);
int engineLeft(TrainCar * all_engines);
int freightLeft(TrainCar * all_freight);
TrainCar* pop_front(TrainCar*& all_engines);
bool checkOK(TrainCar* curTrain, TrainCar* curFreight, int min_speed, int max_cars_per_train);
int getCarNum(TrainCar* head);
float getSpeed(TrainCar* curTrain, TrainCar* curFreight, int min_speed);
int getTotalWeight(TrainCar* curTrain);
int getCount(TrainCar* head);
void addToTrain(TrainCar*& head, TrainCar* newCar);
void MergeTrains(std::vector<TrainCar*>& trains, int max_cars_per_train);
bool compTrain(TrainCar* t1, TrainCar* t2);
void linkCars(TrainCar*& t1, TrainCar*& t2);
void TotalWeightAndCountCars(TrainCar* train, int &total_weight, int &num_engines, 
	int &num_freight_cars, int &num_passenger_cars, int &num_dining_cars, int &num_sleeping_cars);
float CalculateSpeed(TrainCar* train);

void Separate(TrainCar*& train1, TrainCar*& train2, TrainCar*& train3);
int engineCnt(TrainCar* t);
void moveBackEngine(TrainCar*& itr1, TrainCar*& itr2);
void moveFrontEngine(TrainCar*& itr1, TrainCar*& itr2);

float  AverageDistanceToDiningCar(TrainCar *train);
int  ClosestEngineToSleeperCar(TrainCar* train);