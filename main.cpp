#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include <cstring>
#include <vector>

#include "ArgumentHandler.h"
#include "GlobTools.h"

#ifdef WIN32
#define FWSlash L'\\' 
#define STRING std::wstring
#define T(x) L ## x
#else
#define FWSlash '/'
#define STRING std::string
#define T(x) x
#endif

// public functions

// input str is like a file, but without a proper extension (has '.' but no more)
bool like_file_without_extension(const STRING& str)
{
    if (GlobTools::like_file(str) && *(str.end()-1) == T('.'))
        return true;
    return false;
}


#ifdef WIN32
int wmain(int argc, wchar_t *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    ArgumentHandler arg(argc, argv);
    
    // help mode
    if (arg.hasHelp()) {
        arg.printHelp();
        return 0;
    }
    // split mode
    else if (arg.isSplitMode()) {
#ifdef WIN32
        std::wcout << L"Split File:\n" << arg.getInput() << std::endl;
#else
        std::cout << "Split File:\n" << arg.getInput() << std::endl;
#endif
        // setup fstream
        GlobTools::utf8_ifstream file_in;
        file_in.imbue(std::locale());
        GlobTools::utf8_ofstream file_out;
        file_out.imbue(std::locale());
        
        // make sure input is file
        STRING input;
        if (GlobTools::is_file(arg.getInput()))
            input = arg.getInput();
        else {
            std::wcout << L"Please input a single file for splitting.\n";
            return -1;
        }
        
        // get input file length
        file_in.open(input, std::ios::binary);
        file_in.seekg (0, file_in.end);
        int total_len = file_in.tellg();
        file_in.seekg (0, file_in.beg);
        file_in.close();
        int counter = 1;
        int curr_len = 0;
        STRING output;
        
        // get output path, if not provide, set output to current exe path
        if (arg.hasOutput() && GlobTools::is_directory(arg.getOutput()))
            output = arg.getOutput()+FWSlash;
        else
#ifdef WIN32
            output = GlobTools::getCurrExePathW();
#else
            output = GlobTools::getCurrExePathA();
#endif
        
        // write splitted files
        while (curr_len < total_len) {
            // open file
            file_in.open(arg.getInput(), std::ios::binary);
            file_in.seekg(curr_len);
            // handle exception
            if (file_in.fail()) {
#ifdef WIN32
                std::wcout << L"Cannot Open File: " << arg.getInput() << L"\nProgram Terminate.\n";
#else
                std::cout << "Cannot Open File: " << arg.getInput() << "\nProgram Terminate.\n";
#endif
                return -1;
            } // split file
            else {
                int loc_len = arg.getSplitSize();
                if (curr_len+arg.getSplitSize() > total_len)
                    loc_len = total_len - curr_len;
                char *buff = new char[loc_len];
                file_in.read(buff, loc_len);
                file_in.close();
                // write to new file
#ifdef WIN32
                file_out.open(output + L"file_" + std::to_wstring(counter), std::ios::binary);
#else
                file_out.open(output + "file_" + std::to_string(counter), std::ios::binary);
#endif
                file_out.write(buff, loc_len);
                file_out.close();
                counter++;
                curr_len += loc_len;
                delete[] buff;
            }
        }
    }
    // concat mode
    else if (arg.isConcatMode()) { 
#ifdef WIN32
        std::wcout << L"Concatenate Files:\n";
#else
        std::cout << "Concatenate Files:\n";
#endif
        // setup fstream
        GlobTools::utf8_ifstream file_in;
        file_in.imbue(std::locale());
        GlobTools::utf8_ofstream file_out;
        file_out.imbue(std::locale());
        STRING output;
        std::vector<STRING> all_files;
        
        // make sure input is directory
        if (arg.hasInput() && GlobTools::is_directory(arg.getInput())) {
#ifdef WIN32
            GlobTools::getFilesUnderDirW(arg.getInput(), all_files);
            for (auto it : all_files) {
                std::wcout << it << std::endl;
            }
        }
        else
            std::wcout << L"Please do not input a single file for concat.\n";
#else
            GlobTools::getFilesUnderDirA(arg.getInput(), all_files);
            for (auto it : all_files) {
                std::cout << it << std::endl;
            }
        }
        else
            std::cout << "Please do not input a single file for concat.\n";
#endif
        
        // get output file path before open
        // if not provide, set output to current exe path
#ifdef WIN32
        if (arg.hasOutput() && (GlobTools::like_file(arg.getOutput()))) {
            output = arg.getOutput();
        }
#else
        if (arg.hasOutput() && (GlobTools::like_file(arg.getOutput()))) {
            output = arg.getOutput();
            // drop '.' for linux output file without an extension
            if (like_file_without_extension(arg.getOutput()))
                output.assign(output.begin(), output.end()-1);
        }
#endif
        else
#ifdef WIN32
            output = GlobTools::getCurrExePathW() + L"output";
#else
            output = GlobTools::getCurrExePathA() + "output";
#endif
        
        // read all files & concat them
        for (auto it : all_files) {
            STRING file_name = arg.getInput() + FWSlash + it;
            // open input file
            file_in.open(file_name, std::ios::binary);
            // write to output file
            file_out.open(output, std::ios::app | std::ios::binary);
            file_out << file_in.rdbuf();
            // close two files
            file_out.close();
            file_out.clear();
            file_in.close();
            file_in.clear();
        }
    }
    
    return 0;
}
