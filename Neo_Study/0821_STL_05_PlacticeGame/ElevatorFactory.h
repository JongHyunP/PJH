#pragma once
#include "Elevator.h"
#include "PublicIncludeHeader.h"

class ElevatorFactory1 : public Elevator
{
	void dContainer();
	void dDoor();
	void dButton();
public:
	ElevatorFactory1(int max, int floor);
};

class ElevatorFactory2 : public Elevator
{
	void dContainer();
	void dDoor();
	void dButton();
public:
	ElevatorFactory2(int max, int floor);
};


class ElevatorFactory3 : public Elevator
{
	void dContainer();
	void dDoor();
	void dButton();
public:
	ElevatorFactory3(int max, int floor);
};

class ElevatorFactory4 : public Elevator
{
	void dContainer();
	void dDoor();
	void dButton();
public:
	ElevatorFactory4(int max, int floor);
};