#pragma once
#include "raylib.h"
#include <vector>
#include "Stat.h"

class Behavior;

class Agent
{
public:
	Agent(int startHunger, int startThirst, int startSleep, int startSocial, int startEntertainment) 
	{
		m_startHunger = new Stat(startHunger), m_startThirst = new Stat(startThirst), m_startSleep = new Stat(startSleep),
			m_startSocial = new Stat(startSocial), m_startEntertainment = new Stat(startEntertainment);
	}
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Draw the agent
	virtual void draw();

	//Add a behavior to the agent
	void addBehavior(Behavior* behavior);

	//Add a force to the agent's velocity
	void addForce(Vector2 force);

	//Movement functions
	void setPosition(Vector2 position) { m_position = position; }
	Vector2 getPosition() { return m_position; }
	void setVelocity(Vector2 velocity) { m_velocity = velocity; }
	Vector2 getVelocity() { return m_velocity; }

	//Speed functions
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() { return m_speed; }

	//Color functions
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

	//Need Decay functions
	void setHungerDecay(int hungerDecay) { m_hungerDecay = hungerDecay; }
	int getHungerDecay() { return m_hungerDecay; }
	void setThirstDecay(int thirstDecay) { m_thirstDecay = thirstDecay; }
	int getThirstDecay() { return m_thirstDecay; }
	void setSleepDecay(int sleepDecay) { m_sleepDecay = sleepDecay; }
	int getSleepDecay() { return m_sleepDecay; }
	void setSocialDecay(int socialDecay) { m_socialDecay = socialDecay; }
	int getSocialDecay() { return m_socialDecay; }
	void setEntertainmentDecay(int entertainmentDecay) { m_entertainmentDecay = entertainmentDecay; }
	int getEntertainmentDecay() { return m_entertainmentDecay; }

	//Intializes public variables
	Stat* m_startHunger;
	Stat* m_startThirst;
	Stat* m_startSleep;
	Stat* m_startSocial;
	Stat* m_startEntertainment;

protected:
	std::vector<Behavior*> m_behaviorList;

	Vector2 m_position = { 0.0f, 0.0f };
	Vector2 m_velocity = { 0.0f, 0.0f };

	float m_speed = 500.0f;
	Color m_color = MAROON;

	//Intializes all the needs and decay rates for the agent
	int m_hungerDecay = 1;
	int m_thirstDecay = 1;
	int m_sleepDecay = 1;
	int m_socialDecay = 1;
	int m_entertainmentDecay = 1;
};