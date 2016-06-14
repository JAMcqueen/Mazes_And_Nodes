/*****************************************************************************
** Program Filename: MazeNodeHelper.hpp
** Author: Joshua McQueen
** Date: 11MAR14
** Description: Header/Interface file for class MazeNodeHelper
** Input: none
** Output: none
*****************************************************************************/

#ifndef MAZE_NODE_HELPER_H_JAM_CS
#define MAZE_NODE_HELPER_H_JAM_CS

#define NUM_ROOMS 12

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include "MazeNode.hpp"

// from <iostream>
using std::cout;
using std::cin;
using std::endl;

// from <vector>
using std::vector;

// from <stack>
using std::stack;

// from <queue>
using std::queue;

namespace JAM_CS
{
	class MazeNodeHelper
	{
	public:
		MazeNodeHelper();
		
		stack<MazeNode*> path_back;
		queue<MazeNode*> rooms_visited;

		MazeNode* get_current_room(){ return current_room; }

		int get_direction_of_origin()
			{ return direction_of_origin; }

		void set_direction_of_origin(int direction);
		int reverse_direction(int direction);

		void print_room_description();
		void list_exits();
		void choose_exit();

		void list_rooms_visited();
		void toggle_bread_crumbs();

		void hit_return_to_continue();

		int end_of_maze();

		void clean_up(bool found_exit);
	private:
		MazeNode *current_room;

		vector<char> name_list;
		vector<string> description_list;
		vector<MazeNode*> maze_node_list;
		
		bool bread_crumbs_activated;
		int direction_of_origin;

		void fill_name_list();
		void fill_description_list();
		void make_maze_nodes();
		void connect_rooms();

		int direction_char_to_direction(char direct_char);
		int check_exits();

		void show_bread_crumbs();
		void end_of_maze_dialogue();
	};
}
#endif