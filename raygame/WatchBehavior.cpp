#include "WatchBehavior.h"

void WatchBehavior::update(Agent* agent, float deltaTime)
{
	int savedDecay = agent->getEntertainmentDecay();

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

	if (agent->getPosition() == m_target->getPosition())
	{
		int entertainmentRefill = agent->m_startEntertainment->currentStat;
		//Temporarilly set the decay to 0
		agent->setEntertainmentDecay(0);
		//While the current need is below the maximum
		while (agent->m_startEntertainment->currentStat < agent->m_startEntertainment->needStart)
		{
			entertainmentRefill++;
			agent->m_startEntertainment->currentStat = entertainmentRefill;
		}
		agent->setEntertainmentDecay(savedDecay);
	}
}
