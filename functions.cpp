std::vector<std::string> explode(std::string const& s, char delim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}

std::string getFileExt(const std::string& s) {

	size_t i = s.rfind('.', s.length());
	if (i != std::string::npos) {
		return(s.substr(i + 1, s.length() - i));
	}

	return("");
}

bool find(const std::vector<std::string> arr, const std::string expansion)
{
	for (auto i : arr)
	{
		if (expansion == i)
			return true;
	}
	return false;
}

void moveFile(const std::string path, const std::string expansion, const std::string name)
{
	bool result;
	const std::vector<std::string>	archive = { "rar", "zip" }, 
								picture = { "png", "jpg", "jpeg", "gif", "tif", "bmp", "ico"},
								video = {"mpeg", "avi", "mp4"},
								document = {"doc", "xls", "txt", "ppt", "pdf"},
								music = {"mp3"},
								exe = {"exe", "lnk"},
								torrent = {"torrent"};
	
	result = find(archive, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Archives" + "\\" + name).c_str());
		return;
	}

	result = find(picture, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Pictures" + "\\" + name).c_str());
		return;
	}

	result = find(video, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Video" + "\\" + name).c_str());
		return;
	}

	result = find(document, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Documents" + "\\" + name).c_str());
		return;
	}

	result = find(music, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Music" + "\\" + name).c_str());
		return;
	}

	result = find(exe, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Programms" + "\\" + name).c_str());
		return;
	}

	result = find(torrent, expansion);
	if (result == true)
	{
		MoveFile((path + "\\" + name).c_str(), (path + "\\" + "Torrents" + "\\" + name).c_str());
		return;
	}
}