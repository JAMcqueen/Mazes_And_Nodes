/*****************************************************************************
** Program Filename: MazeNode.hpp
** Author: Joshua McQueen
** Date: 11MAR14
** Description: Header/Interface file for class MazeNode
** Input: none
** Output: none
*****************************************************************************/

#ifndef MAZE_NODE_H_JAM_CS
#define MAZE_NODE_H_JAM_CS

#define MAX_EXITS 4

#define NORTH "north"
#define EAST "east"
#define SOUTH "south"
#define WEST "west"

enum directions {north = 0, east = 1, south = 2, west = 3};


#include <string>
#include <cstdlib>
#include <cstdio>

// from <string>
using std::string;

// from <cstdlib>
using std::exit;

namespace JAM_CS
{
	class MazeNode
	{
	public:
		MazeNode();
		MazeNode(char letter, string description);
		MazeNode(char letter, string description, 
			MazeNode *connecting_rooms[]);


		char get_node_letter(){ return node_letter; }
		string get_room_description(){ return room_description; }
		MazeNode* get_exit(int direction);
		bool has_room_been_visited();
		
		void visit_room();
		void set_node_letter(char letter){ node_letter = letter; }
		void set_room_description(string description)
			{room_description = description;}
		void set_exit(MazeNode *exit, int direction)
			{ exits[direction] = exit; }

		string direction_to_string(int direction);
	private:
		bool has_been_visited;
		char node_letter;
		string room_description;

		MazeNode *exits[MAX_EXITS];
	};
	typedef MazeNode* MazeNodePntr;
}
#endif