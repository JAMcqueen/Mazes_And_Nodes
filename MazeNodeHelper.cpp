/*****************************************************************************
** Program Filename: MazeNodeHelper.cpp
** Author: Joshua McQueen
** Date: 11MAR14
** Description: Implementation file for class MazeNodeHelper
** Input: none
** Output:
*****************************************************************************/

#include "MazeNode.hpp"
#include "MazeNodeHelper.hpp"

namespace JAM_CS
{
	/*************************************************************************
	** Function: MazeNodeHelper::MazeNodeHelper()
	** Description: default constructor for class MazeNode
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: makes rooms and initializes MazeNodeHelper correctly
	*************************************************************************/
	MazeNodeHelper::MazeNodeHelper()
	{
		fill_name_list();
		fill_description_list();
		make_maze_nodes();
		connect_rooms();

		bread_crumbs_activated = false;
		direction_of_origin = 0;
		current_room = maze_node_list[0];
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::fill_name_list()
	** Description: makes list of names used for room creation
	** Parameters: none
	** Pre-Conditions: # of names added matches # of rooms to make
	** Post-Conditions: populates name_list with room names
	*************************************************************************/
	void MazeNodeHelper::fill_name_list()
	{
		name_list.push_back('A');
		name_list.push_back('B');
		name_list.push_back('C');
		name_list.push_back('D');
		name_list.push_back('E');
		name_list.push_back('F');
		name_list.push_back('G');
		name_list.push_back('H');
		name_list.push_back('I');
		name_list.push_back('J');
		name_list.push_back('K');
		name_list.push_back('L');
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::fill_description_list()
	** Description: makes list of room descriptions used for room creation
	** Parameters: none
	** Pre-Conditions: # of descriptions added matches # of rooms to make
	** Post-Conditions: populates description_list with room descriptions
	*************************************************************************/
	void MazeNodeHelper::fill_description_list()
	{
		description_list.push_back(
			"The room is a tiny jail cell with a narrow, barred window.\n\t");
		description_list[0] += 
			"There is matted, damp straw covering the floor.";

		description_list.push_back(
			"This hallway is composed of old grey stones. A flickering\n\t");
		description_list[1] += "torch provides a minute amount of light.";

		description_list.push_back(
			"The stench of decay overpowers your senses as you enter\n\t");
		description_list[2] += "this dark and cramped room.";

		description_list.push_back(
			"Shackled to the wall is a leering skeleton, one of the\n\t");
		description_list[3] += "unfortunate souls who didn't escape.";

		description_list.push_back(
			"Slime coats the walls of this tunnel. It appears to pulsate\n\t");
		description_list[4] += 
			"hungrily at your approach. I wouldn't linger if I were you!";

		description_list.push_back(
			"Piles of ash and soot clog this room. Even the air is\n\t");
		description_list[5] += "thickened, making it hard to breathe.";

		description_list.push_back(
			"Ugh! Rotted flesh is splattered on every surface here!\n\t");
		description_list[6] += 
			"You feel dizzy and attempt to stop yourself from retching.";

		description_list.push_back(
			"\"TURN BACK OR SUFFER THE SAME FATE AS ALL THE OTHERS\",\n\t");
		description_list[7] += "a loud voice booms from all around you.";

		description_list.push_back(
			"Ack! Your entrance has disturbed a colony of bats, who are\n\t");
		description_list[8] += 
			"now flying around and chittering angrily at you.";

		description_list.push_back(
			"Wow, this room is completely normal. You feel somewhat\n\t");
		description_list[9] += 
			"relieved as you eye your surroundings suspiciously...";

		description_list.push_back(
			"Bones litter the floor of this ghastly chamber. They\n\t");
		description_list[10]
			+= "seem to rattle almost sorrowfully as the walk through them.";

		description_list.push_back(
			"You see long tunnel with daylight at the end...");
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::make_maze_nodes()
	** Description: makes all the rooms for a maze
	** Parameters: none
	** Pre-Conditions: size of name_list and description list is the same
	** Post-Conditions: creates rooms with names and descriptions but no exits
	*************************************************************************/
	void MazeNodeHelper::make_maze_nodes()
	{
		for (int i = 0; i < NUM_ROOMS; i++)
		{
			maze_node_list.push_back(
				new MazeNode(name_list[i], description_list[i]));
		}
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::connect_rooms()
	** Description: sets links between rooms
	** Parameters: none
	** Pre-Conditions: must link nodes to existing and initailized nodes
	** Post-Conditions: all the rooms/nodes are connected 
	*************************************************************************/
	void MazeNodeHelper::connect_rooms()
	{
		maze_node_list[0]->set_exit(maze_node_list[1], east); // A

		maze_node_list[1]->set_exit(maze_node_list[2], east); // B
		maze_node_list[1]->set_exit(maze_node_list[5], south);
		maze_node_list[1]->set_exit(maze_node_list[0], west);

		maze_node_list[2]->set_exit(maze_node_list[3], east); // C
		maze_node_list[2]->set_exit(maze_node_list[6], south);
		maze_node_list[2]->set_exit(maze_node_list[1], west);

		maze_node_list[3]->set_exit(maze_node_list[7], south); // D
		maze_node_list[3]->set_exit(maze_node_list[2], west);

		maze_node_list[4]->set_exit(maze_node_list[5], east); // E
		maze_node_list[4]->set_exit(maze_node_list[9], south);
		maze_node_list[4]->set_exit(maze_node_list[8], west);

		maze_node_list[5]->set_exit(maze_node_list[1], north); // F
		maze_node_list[5]->set_exit(maze_node_list[10], south); 
		maze_node_list[5]->set_exit(maze_node_list[4], west);

		maze_node_list[6]->set_exit(maze_node_list[2], north); // G
		maze_node_list[6]->set_exit(maze_node_list[7], east);
		maze_node_list[6]->set_exit(maze_node_list[10], south);

		maze_node_list[7]->set_exit(maze_node_list[3], north); // H
		maze_node_list[7]->set_exit(maze_node_list[11], south);
		maze_node_list[7]->set_exit(maze_node_list[6], west);

		maze_node_list[8]->set_exit(maze_node_list[9], east); // I
		maze_node_list[8]->set_exit(maze_node_list[4], west);

		maze_node_list[9]->set_exit(maze_node_list[4], north); // J
		maze_node_list[9]->set_exit(maze_node_list[8], west);

		maze_node_list[10]->set_exit(maze_node_list[6], north); // K
		maze_node_list[10]->set_exit(maze_node_list[5], west);

		maze_node_list[11]->set_exit(maze_node_list[7], north); // L
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::print_room_description()
	** Description: informs user of current room and it's description
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: 
	**		outputs to console the name of the node/room and its description
	*************************************************************************/
	void MazeNodeHelper::print_room_description()
	{ 
		cout << "\n\t>>>> You are in room " << current_room->get_node_letter()
			<< " of the Castle of Confusion. <<<<" << endl;
		cout << "\n\t" << current_room->get_room_description() << endl; 
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::list_exits()
	** Description: 
	**		informs user of all available exits to the current room,
	**		the direction the user just came from, and (if enabled) the
	**		direction to that backtracks the user's path from the starting
	**		room to the current position
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: outputs information listed above in "Description"
	*************************************************************************/
	void MazeNodeHelper::list_exits()
	{
		// used to determine if the exit listed is the first one
		// to be listed
		bool first_exit = true;

		// lists available exits
		cout << "\n\tAvailable exit(s) are to the ";
		for (int i = 0; i < MAX_EXITS; i++)
		{
			if (current_room->get_exit(i) != NULL)
			{
				// if this is the first exit listed, we don't want to print
				// "and to the" after the exit direction because
				// there may not be another exit
				if (first_exit)
				{
					cout << current_room->direction_to_string(i);
					first_exit = false;
				}
				else
				{
					cout << " and to the " 
						<< current_room->direction_to_string(i);
				}
			}
		}
		cout << "." << endl;

		// outputs from which direction you just came
		// if you haven't left the first room, then skip this
		if (rooms_visited.size() > 1)
		{
			cout << "\t(You entered the room from the "
				<< current_room->direction_to_string(direction_of_origin)
				<< ")" << endl;
		}

		// if bread crumb mode is activated, outputs the direction to 
		// the previous room from the path from the starting room to
		// your current room
		if (bread_crumbs_activated)
		{
			// if you're in the starting room, skip this
			if (path_back.size() > 0)
			{
				show_bread_crumbs();
			}
		}
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::choose_exit()
	** Description: 
	**		Function used to move user from room to room. Also serves to take
	**		user input for other options. Has a helper role in tracking
	**		where the user has been
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions:
	**		User will move to a different room if there is an exit to it
	*************************************************************************/
	void MazeNodeHelper::choose_exit()
	{
		// for getting user input
		char exit = 'x';
		// user's chosen direction is store here
		int direction = 0;
		// for keeping user in loop until appropriate response is given
		bool loop = true;

		while (loop)
		{
			cout << "\n\t> Please type a letter indicating which exit you "
				<< " would like to use.";
			cout << "\n\t\t(\'n' for north, \'e' for east, \'s' for south, " 
				<< "\'w' for west)";
			cout << "\n\t> Type \'m' if you want to trace your way back to "
				<< "the start";
			cout << "\n\t\t(Type \'m' again if you want to stop tracing)";
			cout << "\n\t> Type \'q' to quit if you're too scared to finish..."
				<< endl;
		
			// get user response
			exit = getchar();
			cin.ignore(1000, '\n');

			// convert response to direction or other option
			direction = direction_char_to_direction(exit);

			// did the direction lead to a room?
			if (current_room->get_exit(direction) != NULL)
			{
				// are we in the first room? if not...
				if (path_back.size() > 0)
				{
					// does the direction point to the room we just came from? 
					// if so, remove that room from the path_back stack,
					// otherwise add it to the stack
					if (current_room->get_exit(direction)->get_node_letter()
						!= path_back.top()->get_node_letter())
					{
						path_back.push(current_room);
					}
					else
					{
						path_back.pop();
					}
				}
				else 
				{
					// if we're leaving the first room, at it to the
					// path_back stack
					path_back.push(current_room);
				}
			
				// set the room that the direction points to as 
				// current room and store the direction you just
				// came from
				current_room = current_room->get_exit(direction);
				set_direction_of_origin(direction);
				loop = false;
			}
			else if (direction == -2) // did the user enable bread_crumbs?
			{
				if (bread_crumbs_activated)
				{
					cout << 
						"\tYou're now tracing a route back to the start\n";
				}
				else
				{
					cout << "\tYou stop tracing a route back to the start\n";
				}
				list_exits();
			}
			else // bad input
			{
				cout << "\n\tInvalid choice. Please try again." << endl;
				list_exits();
			}
		}
	}

	/*************************************************************************
	** Function: 
	**		int MazeNodeHelper::direction_char_to_direction(char direct_char)
	** Description: 
	**		converts user single char input into a direction, or enables
	**		bread_crumb, or quits program
	** Parameters: char direct_char: char that the user entered
	** Pre-Conditions: none
	** Post-Conditions: performs actions listed above in "Description"
	*************************************************************************/
	int MazeNodeHelper::direction_char_to_direction(char direct_char)
	{
		switch (direct_char)
		{
		case 'n':
			return 0;
		case 'e':
			return 1;
		case 's':
			return 2;
		case 'w':
			return 3;
		case 'm':
			if (!bread_crumbs_activated)
			{
				bread_crumbs_activated = true;
			}
			else
			{
				bread_crumbs_activated = false;
			}
			return -2;
		case 'q':
			clean_up(false);
			break;
		default:
			return -1;
		}

		return -1;
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::set_direction_of_origin(int direction)
	** Description: 
	**		sets direction_of_origin to the opposite direction a user is
	**		exiting from
	** Parameters: int direction: direction the user is exiting
	** Pre-Conditions: none
	** Post-Conditions:
	**		direction_of_origin is set to the opposite value of direction
	*************************************************************************/
	void MazeNodeHelper::set_direction_of_origin(int direction)
	{ 
		direction_of_origin = reverse_direction(direction);
	}

	/*************************************************************************
	** Function: int MazeNodeHelper::reverse_direction(int direction)
	** Description: reverses direction
	** Parameters: int direction: direction to reverse
	** Pre-Conditions: none
	** Post-Conditions: returns integer reflecting reversed direction
	*************************************************************************/
	int MazeNodeHelper::reverse_direction(int direction)
	{
		switch (direction)
		{
		case 0: // north to south
			return 2;
		case 1: // east to west
			return 3;
		case 2: // south to north
			return 0;
		case 3: // west to east
			return 1;
		}

		return 0;
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::list_rooms_visited()
	** Description: lists all the rooms the user has been through in order
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: 
	*************************************************************************/
	void MazeNodeHelper::list_rooms_visited()
	{
		// used to track how many rooms user has been through
		int counter = 0;

		// makes copy of the rooms_visited queue to move through
		// since we may want to still use the queue later 
		queue<MazeNode*> rooms_visited_copy = rooms_visited;
		
		cout << "\n\tHere are the rooms you have been through,";
		cout << "\n\tfrom first to last visited.";

		// outputs name of each room visited to console window,
		// stopping every 10 rooms to get a keypress
		while (rooms_visited_copy.size() > 0)
		{
			counter++;
			cout << "\n\tRoom " << counter << ": "
				<< rooms_visited_copy.front()->get_node_letter();
			if (counter % 10 == 0)
			{
				cout << "\n\t------------MORE------------";
				hit_return_to_continue();
			}
			rooms_visited_copy.pop();
		}

		// stop at every 10th room to get keypress so the screen isn't
		// immediately flooded with room names
		if ((counter % 10) != 0)
		{
			hit_return_to_continue();
		}
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::show_bread_crumbs()
	** Description:
	**		outputs the direction to room to backtrack path from current
	**		position to beginning
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: outputs direction to previous room in path
	*************************************************************************/
	void MazeNodeHelper::show_bread_crumbs()
	{
		string go_north = 
			"\n\tBACKTRACK: Go north to return to starting room\n";
		string go_east = "\n\tBACKTRACK: Go east to return to starting room\n";
		string go_south = 
			"\n\tBACKTRACK: Go south to return to starting room\n";
		string go_west = "\n\tBACKTRACK: Go west to return to starting room\n";
		string current_direction = "";

		int backtrack = check_exits();
		switch (backtrack)
		{
		case 0:
			current_direction = go_north;
			break;
		case 1:
			current_direction = go_east;
			break;
		case 2:
			current_direction = go_south;
			break;
		case 3:
			current_direction = go_west;
			break;
		case -1:
		default:
			cout << "\n\tERROR!!!" << endl;
			clean_up(false);
			break;
		}	
		cout << current_direction;	
	}

	/*************************************************************************
	** Function: int MazeNodeHelper::check_exits()
	** Description:
	**		checks exits for the one that will lead user to previous room
	**		in path back to the beginning room
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns integer indicating direction to go
	*************************************************************************/
	int MazeNodeHelper::check_exits()
	{
		for (int i = 0; i < MAX_EXITS; i++)
		{
			if (current_room->get_exit(i) != NULL)
			{
				if (current_room->get_exit(i)->get_node_letter() ==
					path_back.top()->get_node_letter())
				{
					return i;
				}
			}
		}
		// shouldn't get here
		return -1;
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::hit_return_to_continue()
	** Description: prompts and waits for user to hit enter
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: none
	*************************************************************************/
	void MazeNodeHelper::hit_return_to_continue()
	{
		cout << "\n\tPlease press enter to continue.";
		cin.ignore(1, '\n');
	}

	/*************************************************************************
	** Function: int MazeNodeHelper::end_of_maze()
	** Description:
	**		prints out the last room message and gets user input concerning
	**		what to do next
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: 
	**		user will leave maze, return to maze, or list out all the rooms
	**		they have visited
	*************************************************************************/
	int MazeNodeHelper::end_of_maze()
	{
		// prints out message and menu
		end_of_maze_dialogue();
		// user to get user input
		char choice = 'x';
		// used to keep user in loop until appropriate response is given
		bool loop = true;

		while (loop)
		{
			choice = getchar();
			cin.ignore(1000, '\n');

			switch (choice)
			{
			case '1': // lists all the rooms the user has been through
				list_rooms_visited();
				loop = false;
				return 0;
			case '2': // lets user return to maze
				loop = false;
				return 2;
			case '3': // quits program
				clean_up(true);
				return 0;
			default: // bad entry
				cout << "\n\tInvalid choice. Please try again." << endl;
				break;
			}
		}
		// shouldn't get here
		return 0;
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::end_of_maze_dialogue()
	** Description: prints out end of maze message and option menu
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: outputs message to console
	*************************************************************************/
	void MazeNodeHelper::end_of_maze_dialogue()
	{
		cout << "\n\tIt's the exit! You did it!";
		cout << "\n\tWhat would you like to do now?";
		cout << "\n\n\t1: Look at your notes to see where you've been";
		cout << "\n\t2: Return to the labyrinth";
		cout << "\n\t3: Get out of here!";
		cout << "\n\n\tEnter 1, 2, or 3 and press enter: ";
	}

	/*************************************************************************
	** Function: void MazeNodeHelper::clean_up(bool found_exit)
	** Description: frees up dynamically allocated memory
	** Parameters: 
	**		bool found_exit: used to determine whether the user quit before
	**		reaching the end
	** Pre-Conditions: none
	** Post-Conditions: frees dynamic memory and prints closing message
	*************************************************************************/
	void MazeNodeHelper::clean_up(bool found_exit)
	{
		for (int i = (NUM_ROOMS - 1); i >= 0; i--)
		{
			delete maze_node_list[i];
		}

		if (found_exit)
		{
			cout << "\n\tYou walk out into the sunlight, glad to be free of";
			cout << "\n\tthe maddening maze...";
			cout << "\n\tYOU WIN!";
			cout << "\n\n\tIt took you " << (rooms_visited.size() - 2)
				<< " moves to find the exit.\n" << endl;
		}
		else
		{
			cout << "\n\tYou are doomed to spend the rest of your life LOST\n\t";
			cout << "in the Castle of Confusion...\n" << endl;
		}
		exit(0);
	}
}