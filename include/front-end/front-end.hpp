#pragma once

#include "../back-end/token.hpp"

#include <fstream>
#include <string>
#include <vector>

// entry point - calls on the back end as well
void FrontEnd(
	const int argc,
	char* argv[]
);

/*
void EvaluateCommands(
	char* argv[]
);
*/

std::vector<Token> OpenFile(
	const std::string& file
);