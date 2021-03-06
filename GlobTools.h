// disable C4996, CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#pragma warning(disable: 4996)

#pragma once

// C++ STL
#include <string>
#include <sstream>
#include <vector>
#include <codecvt>
#include <locale>
#include <filesystem>
#include <fstream>
#include <mutex>


namespace GlobTools 
{
    // global variables 
    
    // convert wstring & string
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> cvter;
    
    // utf8 locale for global use
    static std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>);
    
    // mutex for multithreading
    static std::mutex glob_mtx;
    
    
    // global functions
    
    // check whether a file or directory exist
    bool is_filedir_existA(const std::string& dir);
    // check whether a file or directory exist
    bool is_filedir_existW(const std::wstring& dir);
    // check whether input string is file
    bool is_file(const std::string& str);
    // check whether input string is file
    bool is_file(const std::wstring& str);
    // check whether input string is directory
    bool is_directory(const std::string& str);
    // check whether input string is directory
    bool is_directory(const std::wstring& str);
    
    // check whether input str is like a file name (has file extension)
    bool like_file(const std::string& str);
    // check whether input str is like a file name (has file extension)
    bool like_file(const std::wstring& str);
    
    // change all char in string to upper
    std::string all2upperA(const std::string& src);
    // change all wchar_t in wstring to upper
    std::wstring all2upperW(const std::wstring& src);
    
    // change all char in string to lower
    std::string all2lowerA(const std::string& src);
    // change all wchar_t in wstring to lower
    std::wstring all2lowerW(const std::wstring& src);
    
    // get current .exe path, return string, end with '\\'
    std::string getCurrExePathA();
    // get current .exe path, return wstring, end with L'\\'
    std::wstring getCurrExePathW();
    
    // get file list of input directory
    // return true if success, false if fail
    bool getFilesUnderDirA(const std::string& dir, std::vector<std::string>& buff);
    // get file list of input directory
    // return true if success, false if fail
    bool getFilesUnderDirW(const std::wstring& dir, std::vector<std::wstring>& buff);
    
    
    // LC_CTYPE => locale will only handle characters
    
    // ifstream w/ utf8 locale set
    class utf8_ifstream : public std::ifstream
    {
    public:
        utf8_ifstream();
        utf8_ifstream(const std::string& path, std::ios_base::openmode mode = ios_base::in);
        utf8_ifstream(const std::wstring& path, std::ios_base::openmode mode = ios_base::in);
        virtual void open(const std::string& path, std::ios_base::openmode mode = ios_base::in);
        virtual void open(const std::wstring& path, std::ios_base::openmode mode = ios_base::in);
    };
    // wifstream w/ utf8 locale set
    class utf8_wifstream : public std::wifstream
    {
    public:
        utf8_wifstream();
        utf8_wifstream(const std::string& path, std::ios_base::openmode mode = ios_base::in);
        utf8_wifstream(const std::wstring& path, std::ios_base::openmode mode = ios_base::in);
        virtual void open(const std::string& path, std::ios_base::openmode mode = ios_base::in);
        virtual void open(const std::wstring& path, std::ios_base::openmode mode = ios_base::in);
    };
    // ofstream w/ utf8 locale set
    class utf8_ofstream : public std::ofstream
    {
    public:
        utf8_ofstream();
        utf8_ofstream(const std::string& path, std::ios_base::openmode mode = ios_base::out);
        utf8_ofstream(const std::wstring& path, std::ios_base::openmode mode = ios_base::out);
        virtual void open(const std::string& path, std::ios_base::openmode mode = ios_base::out);
        virtual void open(const std::wstring& path, std::ios_base::openmode mode = ios_base::out);
    };
    // wofstream w/ utf8 locale set
    class utf8_wofstream : public std::wofstream
    {
    public:
        utf8_wofstream();
        utf8_wofstream(const std::string& path, std::ios_base::openmode mode = ios_base::out);
        utf8_wofstream(const std::wstring& path, std::ios_base::openmode mode = ios_base::out);
        virtual void open(const std::string& path, std::ios_base::openmode mode = ios_base::out);
        virtual void open(const std::wstring& path, std::ios_base::openmode mode = ios_base::out);
    };
};
