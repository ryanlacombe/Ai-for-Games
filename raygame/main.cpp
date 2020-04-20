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

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920;
	int screenHeight = 1080;
	
	InitWindow(screenWidth, screenHeight, "The Persons");

	//to use a graph first create one
	Graph graph;
	//Then call the creatGraph function and add the number of nodes you want in the list
	graph.createGraph(25);
	//Next, to test a star, call the AStarSearch function and add the coordinates of the starting and then the ending node
	//If the coordinates aren't in the list this will error so be careful here
	graph.AStarSearch({ 0,0 }, { 4,4 });
	//to draw the graph call the draw function in the while loop below

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	float deltaTime;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		deltaTime = GetFrameTime();
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		//Add how far apart the nodes should be here
		//graph.draw(150);
		ClearBackground(RAYWHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}