#pragma once
#include "raylib.h"
#include <vector>

class Behavior;

class Agent
{
public:
	Agent(int startHunger) { m_startHunger = startHunger; }
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

	//Need functions
	int setHunger(int hunger) { m_hunger = hunger; }
	int getHunger() { return m_hunger; }
	int setThirst(int thirst) { m_thirst = thirst; }
	int getThirst() { return m_thirst; }
	int setSleep(int sleep) { m_sleep = sleep; }
	int getSleep() { return m_sleep; }
	int setSocial(int social) { m_social = social; }
	int getSocial() { return m_social; }
	int setEntertainment(int entertainment) { m_entertainment = entertainment; }
	int getEntertainment() { return m_entertainment; }

	//Need Decay functions
	int setHungerDecay(int hungerDecay) { m_hungerDecay = hungerDecay; }
	int getHungerDecay() { return m_hungerDecay; }
	int setThirstDecay(int thirstDecay) { m_thirstDecay = thirstDecay; }
	int getThirstDecay() { return m_thirstDecay; }
	int setSleepDecay(int sleepDecay) { m_sleepDecay = sleepDecay; }
	int getSleepDecay() { return m_sleepDecay; }
	int setSocialDecay(int socialDecay) { m_socialDecay = socialDecay; }
	int getSocialDecay() { return m_socialDecay; }
	int setEntertainmentDecay(int entertainmentDecay) { m_entertainmentDecay = entertainmentDecay; }
	int getEntertainmentDecay() { return m_entertainmentDecay; }

	//Intializes public variables
	int m_startHunger = 100;
	int m_startThirst = 100;
	int m_startSleep = 100;
	int m_startSocial = 100;
	int m_startEntertainment = 100;

protected:
	std::vector<Behavior*> m_behaviorList;

	Vector2 m_position = { 0.0f, 0.0f };
	Vector2 m_velocity = { 0.0f, 0.0f };

	float m_speed = 500.0f;
	Color m_color = MAROON;

	//Intializes all the needs and decay rates for the agent
	int m_hunger = m_startHunger;
	int m_thirst = m_startThirst;
	int m_sleep = m_startSleep;
	int m_social = m_startSocial;
	int m_entertainment = m_startEntertianment;
	int m_hungerDecay = 5;
	int m_thirstDecay = 5;
	int m_sleepDecay = 5;
	int m_socialDecay = 5;
	int m_entertainmentDecay = 5;
};