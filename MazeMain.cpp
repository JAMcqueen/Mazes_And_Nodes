/*****************************************************************************
** Program Filename: MazeMain.cpp
** Author: Joshua McQueen
** Date: 11MAR14
** Description: Program file for Assignment 9, part 1
** Input: none
** Output: 
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

#include "MazeNode.hpp"
#include "MazeNodeHelper.hpp"

// from <iostream>
using std::cout;
using std::endl;

// from <string>
using std::string;

// from "MazeNode.hpp"
using JAM_CS::MazeNode;

// from "MazeNodeHelper.hpp"
using JAM_CS::MazeNodeHelper;

int main()
{
	MazeNodeHelper node_helper;
	bool keep_playing = true;
	char last_room = 'L';

	cout << "\n\tThe last thing you remember is walking through the woods";
	cout << "\n\twhen suddenly something or someone hit you on the head and";
	cout << "\n\tknocked you out...";
	cout << "\n\n\tYou wake up in a strange room alone with a dull ache";
	cout << "\n\tin your head. Realizing that you are now abandoned";
	cout << "\n\tin some strange and unfamiliar area, you pull out your";
	cout << "\n\ttrusty pen and a scrap of paper to keep track of";
	cout << "\n\tyour path through this place. " << endl;

	node_helper.hit_return_to_continue();

	while (keep_playing)
	{
		node_helper.get_current_room()->visit_room();
		node_helper.rooms_visited.push(node_helper.get_current_room());
		node_helper.print_room_description();
		node_helper.list_exits();

		if (node_helper.get_current_room()->get_node_letter() == last_room)
		{
			int choice = node_helper.end_of_maze();
			if (choice == 2)
			{
				node_helper.print_room_description();
				node_helper.list_exits();
				node_helper.choose_exit();
			}
		}
		else
		{
			node_helper.choose_exit();
		}
	}

	node_helper.clean_up(false);
	cout << "\n\tExiting program..." << endl;

	return 0;
}