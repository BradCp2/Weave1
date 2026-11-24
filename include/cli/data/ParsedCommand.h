#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <filesystem>

namespace cli {
struct ParsedCommand {	

	std::filesystem::path invocationPath;  // Path `Weave.exe` was called from.
	std::filesystem::path programPath;     // Absolute path to `Weave.exe` on disk.
	std::string command;
	std::vector<std::string> args;
	std::unordered_map<std::string, std::string> flags;
	bool valid = false;
};

}