#include "GlobTools.h"

// C++ STL
#include <algorithm>
#include <string>

// Functions

// check whether a file or directory exist
bool GlobTools::is_filedir_existA(const std::string& path)
{
    return std::filesystem::exists(path);
}
// check whether a file or directory exist
bool GlobTools::is_filedir_existW(const std::wstring& path)
{
    return std::filesystem::exists(path);
}
// check whether input string is file
bool GlobTools::is_file(const std::string& str)
{
    return std::filesystem::is_regular_file(str);
}
// check whether input string is file
bool GlobTools::is_file(const std::wstring& str)
{
    return std::filesystem::is_regular_file(str);
}
// check whether input string is directory
bool GlobTools::is_directory(const std::string& str)
{
    return std::filesystem::is_directory(str);
}
// check whether input string is directory
bool GlobTools::is_directory(const std::wstring& str)
{
    return std::filesystem::is_directory(str);
}

// check whether input str is like a file name (has file extension)
bool GlobTools::like_file(const std::string& str)
{
    std::string buff(str);
    // reverse string
    std::reverse(buff.begin(), buff.end());
    // get reversed file name from string
    size_t pos = buff.find('\\');
    if (pos == std::string::npos) // did not get a windows dir splitter, try linux
        pos = buff.find('/');
    if (pos == std::string::npos) // canont find any dir splitter
        return false;
    else { // get reversed file name, try to find file extension
        buff.assign(buff.begin(), buff.begin()+pos);
        if (buff.find('.') != std::string::npos)
            return true;
        else
            return false;
    }
    return false;
}
// check whether input str is like a file name (has file extension)
bool GlobTools::like_file(const std::wstring& str)
{
    std::wstring buff(str);
    // reverse string
    std::reverse(buff.begin(), buff.end());
    // get reversed file name from string
    size_t pos = buff.find(L'\\');
    if (pos == std::wstring::npos) // did not get a windows dir splitter, try linux
        pos = buff.find(L'/');
    if (pos == std::wstring::npos) // canont find any dir splitter
        return false;
    else { // get reversed file name, try to find file extension
        buff.assign(buff.begin(), buff.begin()+pos);
        if (buff.find(L'.') != std::wstring::npos)
            return true;
        else
            return false;
    }
    return false;
}

// change all char in string to upper
std::string GlobTools::all2upperA(const std::string& src)
{
    std::string output;
    for (auto it : src)
        output += std::toupper(it);
    return output;
}
// change all wchar_t in wstring to upper
std::wstring GlobTools::all2upperW(const std::wstring& src)
{
    std::wstring output;
    for (auto it : src)
        output += std::toupper(it);
    return output;
}

// change all char in string to lower
std::string GlobTools::all2lowerA(const std::string& src)
{
    std::string output;
    for (auto it : src)
        output += std::tolower(it);
    return output;
}
// change all wchar_t in wstring to lower
std::wstring GlobTools::all2lowerW(const std::wstring& src)
{
    std::wstring output;
    for (auto it : src)
        output += std::tolower(it);
    return output;
}

// get current .exe path, return string, end with '\\'
std::string GlobTools::getCurrExePathA()
{
#ifdef WIN32
    return (std::filesystem::current_path().string()+"\\");
#else
    return (std::filesystem::current_path().string()+"/");
#endif
}
// get current .exe path, return wstring, end with L'\\'
std::wstring GlobTools::getCurrExePathW()
{
#ifdef WIN32
    return (std::filesystem::current_path().wstring()+L"\\");
#else
    return (std::filesystem::current_path().wstring()+L"/");
#endif
}

// get file list of input directory
bool GlobTools::getFilesUnderDirA(const std::string& dir, std::vector<std::string>& buff)
{
    if (GlobTools::is_filedir_existA(dir)) {
        for (auto file : std::filesystem::directory_iterator(dir))
            buff.push_back(file.path().filename().string());
    } else return false;
    // sort buff filenames
    std::sort(
        buff.begin(), buff.end(),
        [](const std::string& left, const std::string& right) {
            int l = std::stoi(left.substr(left.find_last_of('_') + 1, left.find_last_of('.')));
            int r = std::stoi(right.substr(right.find_last_of('_') + 1, right.find_last_of('.')));
            return (l < r);
        }
    );
    return true;
}
// get file list of input directory
bool GlobTools::getFilesUnderDirW(const std::wstring& dir, std::vector<std::wstring>& buff)
{
    if (GlobTools::is_filedir_existW(dir)) {
        for (auto file : std::filesystem::directory_iterator(dir))
            buff.push_back(file.path().filename().wstring());
    } else return false;
    // sort buff filenames
    std::sort(
        buff.begin(), buff.end(),
        [](const std::wstring& left, const std::wstring& right) {
            int l = std::stoi(left.substr(left.find_last_of('_') + 1, left.find_last_of('.')));
            int r = std::stoi(right.substr(right.find_last_of('_') + 1, right.find_last_of('.')));
            return (l < r);
        }
    );
    return true;
}


// ifstream w/ utf8 locale set
GlobTools::utf8_ifstream::utf8_ifstream()
{
	imbue(utf8_locale);
}
GlobTools::utf8_ifstream::utf8_ifstream(
    const std::string& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::ifstream::open(p, mode);
}
GlobTools::utf8_ifstream::utf8_ifstream(
    const std::wstring& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::ifstream::open(p, mode);
}
void GlobTools::utf8_ifstream::open(
    const std::string& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::ifstream::open(p, mode);
}
void GlobTools::utf8_ifstream::open(
    const std::wstring& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::ifstream::open(p, mode);
}

// wifstream w/ utf8 locale set
GlobTools::utf8_wifstream::utf8_wifstream()
{
	imbue(utf8_locale);
}
GlobTools::utf8_wifstream::utf8_wifstream(
    const std::string& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::wifstream::open(p, mode);
}
GlobTools::utf8_wifstream::utf8_wifstream(
    const std::wstring& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::wifstream::open(p, mode);
}
void GlobTools::utf8_wifstream::open(
    const std::string& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::wifstream::open(p, mode);
}
void GlobTools::utf8_wifstream::open(
    const std::wstring& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::wifstream::open(p, mode);
}

// ofstream w/ utf8 locale set
GlobTools::utf8_ofstream::utf8_ofstream()
{
	imbue(utf8_locale);
}
GlobTools::utf8_ofstream::utf8_ofstream(
    const std::string& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::ofstream::open(p, mode);
}
GlobTools::utf8_ofstream::utf8_ofstream(
    const std::wstring& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::ofstream::open(p, mode);
}
void GlobTools::utf8_ofstream::open(
    const std::string& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::ofstream::open(p, mode);
}
void GlobTools::utf8_ofstream::open(
    const std::wstring& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::ofstream::open(p, mode);
}

// wofstream w/ utf8 locale set
GlobTools::utf8_wofstream::utf8_wofstream()
{
	imbue(utf8_locale);
}
GlobTools::utf8_wofstream::utf8_wofstream(
    const std::string& path, std::ios_base::openmode mode)
{
	imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::wofstream::open(p, mode);
}
GlobTools::utf8_wofstream::utf8_wofstream(
    const std::wstring& path, std::ios_base::openmode mode)
{
    imbue(utf8_locale);
    std::filesystem::path p(path);
    this->std::wofstream::open(p, mode);
}
void GlobTools::utf8_wofstream::open(
    const std::string& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::wofstream::open(p, mode);
}
void GlobTools::utf8_wofstream::open(
    const std::wstring& path, std::ios_base::openmode mode)
{
    std::filesystem::path p(path);
    this->std::wofstream::open(p, mode);
}
