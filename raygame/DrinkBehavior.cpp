#include "DrinkBehavior.h"
#include "raymath.h"

void DrinkBehavior::update(Agent* agent, float deltaTime)
{
	int savedDecay = agent->getThirstDecay();

	//Get this agent's position
	Vector2 pos = agent->getPosition();
	//Get the position of the target agent
	Vector2 targetPos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want the agent to move
	Vector2 force = direction * agent->getSpeed();
	//Subtract the agent's current velocity from the result to get the force we need to apply
	force = force - agent->getVelocity();

	//Return the force
	agent->addForce(force * deltaTime);

	float distance = Vector2Distance(targetPos, pos);

	if (distance <= 50)
	{
		int thirstRefill = agent->m_startThirst->currentStat;
		//Temporarilly set the decay to 0
		agent->setThirstDecay(0);
		//While the current need is below the maximum
		while (agent->m_startThirst->currentStat < agent->m_startThirst->needStart)
		{
			thirstRefill++;
			agent->m_startThirst->currentStat = thirstRefill;
		}
		agent->setThirstDecay(savedDecay);
	}

	return;
}
