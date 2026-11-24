#pragma once

#include "utils/Logger.h"
#include "core/utils/IOUtils.h"
#include "cli/data/ParsedCommand.h"
#include "core/models/WeaveStructures.h"
#include <string>
#include <array>
#include <iostream>
#include <vector>
#include <variant>
#include <filesystem>

#include "core/utils/picosha2.h"
#include "core/utils/revlogUtils.h"

namespace add {

	class AddService {

	private:

		cli::ParsedCommand commandData;
		std::string fileName;  // use as global accessor instead of passing down
		std::filesystem::path filePath;
		std::filesystem::path indexFilePath;
		std::filesystem::path dataFilePath;
		std::filesystem::path stageFilePath;
		std::filesystem::path revlogPath;

		revlogUtils::DeltaRevision deltaRevision;
		models::FileIndexEntryDisk fileIndexEntry;

	private:
		bool validateAddFile();

		void createStageData();

		void resolveRevlogFiles();

		void appendRevision();

		void appendRevision2(const std::string& file);

		void updateStage();

		bool hasRevision() const;

		void tryUpdateStage();

	public:
		AddService(const cli::ParsedCommand& cmd);
		
		// Depricated //
		bool addFile(const std::string& file);

		bool addRevision(const std::string& file);
	};
}	