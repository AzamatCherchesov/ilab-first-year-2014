const int MAX_COMMAND_SIZE = 64;
const int NUM_OF_COMMAND = 8;
const char COMMANDS[][MAX_COMMAND_SIZE] = {
		"push"
		"pop"
		"pushr"
		"popr"
		"mul"
		"div"
		"add"
		"sub"
};
void replace (FILE *input, FILE *output);