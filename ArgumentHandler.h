#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#ifdef WIN32
#define ArgumentHandler ArgumentHandlerW
#else
#define ArgumentHandler ArgumentHandlerA
#endif


// handling arguments in wWinMain() function
// produce commands with input arguments
class ArgumentHandlerA
{
public:
    // constructor
    ArgumentHandlerA(int argc, char** argv);
    
    // getters
    int getSplitSize();
    std::string getInput();
    std::string getOutput();
    
    // argument flags
    bool hasSplitSize();
    const bool hasSplitSize() const;
    bool hasInput();
    const bool hasInput() const;
    bool hasOutput();
    const bool hasOutput() const;
    bool isConcatMode();
    const bool isConcatMode() const;
    bool isSplitMode();
    const bool isSplitMode() const;
    
    bool hasHelp();
    const bool hasHelp() const;
    void printHelp();
    
private:
    // argument buffer
    std::string m_InputFileDir;
    std::string m_OutputFileDir;
    int m_SplitSize;
    // flags
    bool m_HasSplitSize;
    bool m_HasInput;
    bool m_HasOutput;
    bool m_IsConcatMode;
    bool m_HasHelp;
};


// handling arguments in wWinMain() function
// produce commands with input arguments
class ArgumentHandlerW
{
public:
    // constructor
    ArgumentHandlerW(int argc, wchar_t** argv);
    
    // getters
    int getSplitSize();
    std::wstring getInput();
    std::wstring getOutput();
    
    // argument flags
    bool hasSplitSize();
    const bool hasSplitSize() const;
    bool hasInput();
    const bool hasInput() const;
    bool hasOutput();
    const bool hasOutput() const;
    bool isConcatMode();
    const bool isConcatMode() const;
    bool isSplitMode();
    const bool isSplitMode() const;
    
    bool hasHelp();
    const bool hasHelp() const;
    void printHelp();
    
private:
    // argument buffer
    std::wstring m_InputFileDir;
    std::wstring m_OutputFileDir;
    int m_SplitSize;
    // flags
    bool m_HasSplitSize;
    bool m_HasInput;
    bool m_HasOutput;
    bool m_IsConcatMode;
    bool m_HasHelp;
};
