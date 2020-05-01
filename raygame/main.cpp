/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Graph.h"
#include "DecisionTreeBehavior.h"
#include "BehaviorDecision.h"
#include "WanderBehavior.h"
#include "Object.h"
#include "EatBehavior.h"
#include "IsNeedyCondition.h"
#include "DrinkBehavior.h"
#include "BooleanDecision.h"
#include "SleepBehavior.h"
#include "WatchBehavior.h"
#include "ScreenEdgeBehavior.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920;
	int screenHeight = 1080;
	
	InitWindow(screenWidth, screenHeight, "The Persons");

	////to use a graph first create one
	//Graph graph;
	////Then call the creatGraph function and add the number of nodes you want in the list
	//graph.createGraph(25);
	////Next, to test a star, call the AStarSearch function and add the coordinates of the starting and then the ending node
	////If the coordinates aren't in the list this will error so be careful here
	//graph.AStarSearch({ 0,0 }, { 4,4 });
	////to draw the graph call the draw function in the while loop below

	//Creates all the "persons"
	Agent* nick = new Agent(100, 100, 100, 100, 100);
	nick->setPosition(Vector2{ 960, 540 });
	nick->setSpeed(350.0f);
	nick->setColor(DARKBLUE);

	Agent* carlos = new Agent(120, 90, 80, 125, 100);
	carlos->setPosition(Vector2{ 900, 250 });
	carlos->setSpeed(400.0f);
	carlos->setColor(GREEN);

	Agent* marie = new Agent(90, 110, 100, 80, 95);
	marie->setPosition(Vector2{ 834, 725 });
	marie->setSpeed(400.0f);
	marie->setColor(PINK);

	Agent* sera = new Agent(100, 80, 110, 95, 130);
	sera->setPosition(Vector2{ 560, 500 });
	sera->setSpeed(350.0f);
	sera->setColor(RED);

	//Creates all of the objects
	Object* stove = new Object();
	stove->setPosition(Vector2{ 350, 200 });
	stove->setColor(LIGHTGRAY);

	Object* sink = new Object();
	sink->setPosition(Vector2{ 1200, 824 });
	sink->setColor(SKYBLUE);

	Object* bed = new Object();
	bed->setPosition(Vector2{ 1400, 150 });
	bed->setColor(WHITE);

	Object* tv = new Object();
	tv->setPosition(Vector2{ 200, 932 });
	tv->setColor(BROWN);

	//Creates and sets the ScreenEdgeBehavior to each "person" before creating the decision tree
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	nick->addBehavior(screenEdgeBehavior);
	carlos->addBehavior(screenEdgeBehavior);
	marie->addBehavior(screenEdgeBehavior);
	sera->addBehavior(screenEdgeBehavior);

	//Creation of the leaves
	WanderBehavior* wanderBehavior = new WanderBehavior();
	BehaviorDecision* wanderDecision = new BehaviorDecision(wanderBehavior);
	EatBehavior* eatBehavior = new EatBehavior();
	eatBehavior->setTarget(stove);
	BehaviorDecision* eatDecision = new BehaviorDecision(eatBehavior);
	DrinkBehavior* drinkBehavior = new DrinkBehavior();
	drinkBehavior->setTarget(sink);
	BehaviorDecision* drinkDecision = new BehaviorDecision(drinkBehavior);
	SleepBehavior* sleepBehavior = new SleepBehavior();
	sleepBehavior->setTarget(bed);
	BehaviorDecision* sleepDecision = new BehaviorDecision(sleepBehavior);
	WatchBehavior* watchBehavior = new WatchBehavior();
	watchBehavior->setTarget(tv);
	BehaviorDecision* watchDecision = new BehaviorDecision(watchBehavior);
	

	
	//Nick's Decision Tree
	IsNeedyCondition* nickIsBoredCondition = new IsNeedyCondition(nick, 1000, nick->m_startEntertainment);
	BooleanDecision* nickIsBoredDecision = new BooleanDecision(watchDecision, wanderDecision, nickIsBoredCondition);
	IsNeedyCondition* nickIsSleepyCondition = new IsNeedyCondition(nick, 1000, nick->m_startSleep);
	BooleanDecision* nickIsSleepyDecision = new BooleanDecision(sleepDecision, nickIsBoredDecision, nickIsSleepyCondition);
	IsNeedyCondition* nickIsThirstyCondition = new IsNeedyCondition(nick, 1000, nick->m_startThirst);
	BooleanDecision* nickIsThirstyDecision = new BooleanDecision(drinkDecision, nickIsSleepyDecision, nickIsThirstyCondition);
	IsNeedyCondition* nickIsHungryCondition = new IsNeedyCondition(nick, 1000, nick->m_startHunger);
	BooleanDecision* nickIsHungryDecision = new BooleanDecision(eatDecision, nickIsThirstyDecision, nickIsHungryCondition);

	DecisionTreeBehavior* nickDecisionTree = new DecisionTreeBehavior(nickIsHungryDecision);
	nick->addBehavior(nickDecisionTree);

	//Carlos' Decision Tree
	IsNeedyCondition* carlosIsSleepyCondition = new IsNeedyCondition(carlos, 1000, carlos->m_startSleep);
	BooleanDecision* carlosIsSleepyDecision = new BooleanDecision(sleepDecision, wanderDecision, carlosIsSleepyCondition);
	IsNeedyCondition* carlosIsThirstyCondition = new IsNeedyCondition(carlos, 1000, carlos->m_startThirst);
	BooleanDecision* carlosIsThirstyDecision = new BooleanDecision(drinkDecision, carlosIsSleepyDecision, carlosIsThirstyCondition);
	IsNeedyCondition* carlosIsHungryCondition = new IsNeedyCondition(carlos, 1000, carlos->m_startHunger);
	BooleanDecision* carlosIsHungryDecision = new BooleanDecision(eatDecision, carlosIsThirstyDecision, carlosIsHungryCondition);
	IsNeedyCondition* carlosIsBoredCondition = new IsNeedyCondition(carlos, 1000, carlos->m_startEntertainment);
	BooleanDecision* carlosIsBoredDecision = new BooleanDecision(watchDecision, carlosIsHungryDecision, carlosIsBoredCondition);

	DecisionTreeBehavior* carlosDecisionTree = new DecisionTreeBehavior(carlosIsBoredDecision);
	carlos->addBehavior(carlosDecisionTree);

	//Marie's Decision Tree
	IsNeedyCondition* marieIsHungryCondition = new IsNeedyCondition(marie, 1000, marie->m_startHunger);
	BooleanDecision* marieIsHungryDecision = new BooleanDecision(eatDecision, wanderDecision, marieIsHungryCondition);
	IsNeedyCondition* marieIsBoredCondition = new IsNeedyCondition(marie, 1000, marie->m_startEntertainment);
	BooleanDecision* marieIsBoredDecision = new BooleanDecision(watchDecision, marieIsHungryDecision, marieIsBoredCondition);
	IsNeedyCondition* marieIsThirstyCondition = new IsNeedyCondition(marie, 1000, marie->m_startThirst);
	BooleanDecision* marieIsThirstyDecision = new BooleanDecision(drinkDecision, marieIsBoredDecision, marieIsThirstyCondition);
	IsNeedyCondition* marieIsSleepyCondition = new IsNeedyCondition(marie, 1000, marie->m_startSleep);
	BooleanDecision* marieIsSleepyDecision = new BooleanDecision(sleepDecision, marieIsThirstyDecision, marieIsSleepyCondition);

	DecisionTreeBehavior* marieDecisionTree = new DecisionTreeBehavior(marieIsSleepyDecision);
	marie->addBehavior(marieDecisionTree);

	//Sera's Decision Tree
	IsNeedyCondition* seraIsBoredCondition = new IsNeedyCondition(sera, 1000, sera->m_startEntertainment);
	BooleanDecision* seraIsBoredDecision = new BooleanDecision(watchDecision, wanderDecision, seraIsBoredCondition);
	IsNeedyCondition* seraIsSleepyCondition = new IsNeedyCondition(sera, 1000, sera->m_startSleep);
	BooleanDecision* seraIsSleepyDecision = new BooleanDecision(sleepDecision, seraIsBoredDecision, seraIsSleepyCondition);
	IsNeedyCondition* seraIsHungryCondition = new IsNeedyCondition(sera, 1000, sera->m_startHunger);
	BooleanDecision* seraIsHungryDecision = new BooleanDecision(eatDecision, seraIsSleepyDecision, seraIsHungryCondition);
	IsNeedyCondition* seraIsThirstyCondition = new IsNeedyCondition(sera, 1000, sera->m_startThirst);
	BooleanDecision* seraIsThirstyDecision = new BooleanDecision(drinkDecision, seraIsHungryDecision, seraIsThirstyCondition);

	DecisionTreeBehavior* seraDecisionTree = new DecisionTreeBehavior(seraIsThirstyDecision);
	sera->addBehavior(seraDecisionTree);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	float deltaTime;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		deltaTime = GetFrameTime();
		// Update
		//----------------------------------------------------------------------------------
		nick->update(deltaTime);
		carlos->update(deltaTime);
		marie->update(deltaTime);
		sera->update(deltaTime);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		//Add how far apart the nodes should be here
		//graph.draw(150);

		nick->draw();
		carlos->draw();
		marie->draw();
		sera->draw();

		stove->draw();
		sink->draw();
		bed->draw();
		tv->draw();

		ClearBackground(BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
