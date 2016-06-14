/*****************************************************************************
** Program Filename: MazeNode.cpp
** Author: Joshua McQueen
** Date: 11MAR14
** Description: Implementation file for class MazeNode
** Input: none
** Output:
*****************************************************************************/

#include "MazeNode.hpp"

namespace JAM_CS
{
	/*************************************************************************
	** Function: MazeNode::MazeNode()
	** Description: default constructor for class MazeNode
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: 
	**		data fields are set to placeholder, non-functional values
	*************************************************************************/
	MazeNode::MazeNode()
	{
		node_letter = '!';
		room_description = "default";

		for (int i = 0; i < MAX_EXITS; i++)
		{
			exits[i] = NULL;
		}

		has_been_visited = false;
	}

	/*************************************************************************
	** Function: MazeNode::MazeNode(char letter, string description)
	** Description: non-linked object constructor for class MazeNode
	** Parameters:
	**		char letter: letter to name room after
	**		string description: description of the room
	** Pre-Conditions: none
	** Post-Conditions: intializes MazeNode without links
	*************************************************************************/
	MazeNode::MazeNode(char letter, string description)
	{
		node_letter = letter;
		room_description = description;

		for (int i = 0; i < MAX_EXITS; i++)
		{
			exits[i] = NULL;
		}

		has_been_visited = false;
	}

	/*************************************************************************
	** Function: MazeNode(char letter, string description,
	**		MazeNode *connecting_rooms[], int exit_directions[])
	** Description: linked constructor for class MazeNode
	** Parameters:
	**		char letter: letter to name room after
	**		string description: description of the room
	**		MazeNode *connecting_rooms[]: array containing rooms to be
	**			connected to this object
	** Pre-Conditions: none
	** Post-Conditions: MazeNode is initialized and linked to other nodes
	*************************************************************************/
	MazeNode::MazeNode(char letter, string description,
		MazeNode *connecting_rooms[])
	{
		node_letter = letter;
		room_description = description;

		for (int i = 0; i < MAX_EXITS; i++)
		{
			set_exit(connecting_rooms[i], i);
		}
	}

	/*************************************************************************
	** Function: MazeNode* MazeNode::get_exit(int direction)
	** Description: returns pointer to next node 
	** Parameters: int direction: direction to attempt to exit
	** Pre-Conditions: none
	** Post-Conditions: 
	**		returns pointer to next node if valid direction, otherwise NULL
	*************************************************************************/
	MazeNode* MazeNode::get_exit(int direction)
	{ 
		if (direction < 0 || direction >= MAX_EXITS)
		{
			return NULL;
		}

		return exits[direction]; 
	}

	/*************************************************************************
	** Function: bool MazeNode::has_room_been_visited()
	** Description: accessor function for private bool "has_been_visited"
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns value of private bool "has_been_visited
	*************************************************************************/
	bool MazeNode::has_room_been_visited()
	{
		return has_been_visited;
	}

	/*************************************************************************
	** Function: void MazeNode::visit_room()
	** Description: mutator function for private bool "has_been_visited"
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: sets has_been_visited to true
	*************************************************************************/
	void MazeNode::visit_room()
	{
		has_been_visited = true;
	}

	/*************************************************************************
	** Function: string MazeNode::direction_to_string(int direction)
	** Description: converts a direction enum to its direction string
	** Parameters: int direction: direction to convert
	** Pre-Conditions: none
	** Post-Conditions: returns string describing direction
	*************************************************************************/
	string MazeNode::direction_to_string(int direction)
	{
		switch (direction)
		{
			case 0:
				return "north";
			case 1:
				return "east";
			case 2:
				return "south";
			case 3:
				return "west";
			default:
				return "north";
		}
	}
}