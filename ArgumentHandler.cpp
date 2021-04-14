#include "ArgumentHandler.h"

// ====================== ArgumentHandlerA ======================

// constructor
ArgumentHandlerA::ArgumentHandlerA(int argc, char** argv)
    : m_InputFileDir(""), m_OutputFileDir(""), m_SplitSize(0),
    m_HasSplitSize(false), m_HasInput(false),
    m_HasOutput(false), m_IsConcatMode(false),
    m_HasHelp(false)
{
    try {
        std::string buff;
        for (int i = 1; i < argc; ++i) {
            buff.assign(argv[i]);
            if (buff == "-s") { // set split size
                m_SplitSize = std::stoi(argv[i + 1]);
                m_HasSplitSize = true;
            }
            else if (buff == "-f") { // set input file/dir
                m_InputFileDir = argv[i + 1];
                m_HasInput = true;
            }
            else if (buff == "-c") { // set concat mode
                m_IsConcatMode = true;
            }
            else if (buff == "-o") { // set output file/dir
                m_OutputFileDir = argv[i + 1];
                m_HasOutput = true;
            }
            else if (buff == "-h" || buff == "--help")
                m_HasHelp = true;
        }
    } catch (...) {
        throw std::invalid_argument("Argument Invalid or Incomplete");
    }
}


// getters
int ArgumentHandlerA::getSplitSize()
{
    return m_SplitSize;
}
std::string ArgumentHandlerA::getInput()
{
    return m_InputFileDir;
}
std::string ArgumentHandlerA::getOutput()
{
    return m_OutputFileDir;
}


// argument flags
bool ArgumentHandlerA::hasSplitSize()
{
    return m_HasSplitSize;
}
const bool ArgumentHandlerA::hasSplitSize() const
{
    return m_HasSplitSize;
}
bool ArgumentHandlerA::hasInput()
{
    return m_HasInput;
}
const bool ArgumentHandlerA::hasInput() const
{
    return m_HasInput;
}
bool ArgumentHandlerA::hasOutput()
{
    return m_HasOutput;
}
const bool ArgumentHandlerA::hasOutput() const
{
    return m_HasOutput;
}
bool ArgumentHandlerA::isConcatMode()
{
    return (m_IsConcatMode && hasInput() && !hasSplitSize());
}
const bool ArgumentHandlerA::isConcatMode() const
{
    return (m_IsConcatMode && hasInput() && !hasSplitSize());
}
bool ArgumentHandlerA::isSplitMode()
{
    return (hasSplitSize() && hasInput() && !m_IsConcatMode);
}
const bool ArgumentHandlerA::isSplitMode() const
{
    return (hasSplitSize() && hasInput() && !m_IsConcatMode);
}


bool ArgumentHandlerA::hasHelp()
{
    return m_HasHelp;
}
const bool ArgumentHandlerA::hasHelp() const
{
    return m_HasHelp;
}
void ArgumentHandlerA::printHelp()
{
    std::cout << "\nFileSC - File Splitting and Concatenating\n"
        << "Usage: FileSC [options] [arguments] ...\n\n"
        << "Options:\n"
        << "\t-h, --help\t\t\tDisplay help message.\n"
        << "\n"
        << "\t-s [arguments]\t\tSplit Mode, [arguments] should be number of bytes in each file slices.\n"
        << "\n"
        << "\t-f [arguments]\t\tFile input, [arguments] should be a complete file/directory.\n"
        << "\t\t\t\tIf in Split mode, [arguments] should be a file path.\n"
        << "\t\t\t\tIf in Concat mode, [arguments] should be a directory without \'/\' or \'\\\' at the end.\n"
        << "\n"
        << "\t-c\t\t\tConcat Mode.\n"
        << "\n"
        << "\t-o [arguments]\t\tOutput, [arguments] should be a complete file/directory.\n"
        << "\t\t\t\tIf in Split mode, [arguments] should be a directory without \'/\' or \'\\\' at the end.\n"
        << "\t\t\t\tIf in Concat mode, [arguments] should be a file path.\n"
        << "\n"
        << "Examples:\n"
        << "\tSplit A File: FileSC -s 1024 -f \"path\\to\\file.extension\" -o \"path\\to\\outputdir\"\n\n"
        << "\tConcat Files: FileSC -c -f \"path\\to\\filesdir\" -o \"path\\to\\output\\file.extension\"\n\n"
        << "\tHint: You can remove file extension and left a single \".\" at the end of\n"
        << "\t      output file to generate a file without extension.\n";
    ;
}


// ====================== ArgumentHandlerA End ======================





// ====================== ArgumentHandlerW ======================

// constructor
ArgumentHandlerW::ArgumentHandlerW(int argc, wchar_t** argv)
    : m_InputFileDir(L""), m_OutputFileDir(L""), m_SplitSize(0),
    m_HasSplitSize(false), m_HasInput(false),
    m_HasOutput(false), m_IsConcatMode(false),
    m_HasHelp(false)
{
    try {
        std::wstring buff;
        for (int i = 1; i < argc; ++i) {
            buff.assign(argv[i]);
            if (buff == L"-s") { // set split size
                m_SplitSize = std::stoi(argv[i + 1]);
                m_HasSplitSize = true;
            }
            else if (buff == L"-f") { // set input file/dir
                m_InputFileDir = argv[i + 1];
                m_HasInput = true;
            }
            else if (buff == L"-c") { // set concat mode
                m_IsConcatMode = true;
            }
            else if (buff == L"-o") { // set output file/dir
                m_OutputFileDir = argv[i + 1];
                m_HasOutput = true;
            }
            else if (buff == L"-h" || buff == L"--help")
                m_HasHelp = true;
        }
    } catch (...) {
        throw std::invalid_argument("Argument Invalid or Incomplete");
    }
}


// getters
int ArgumentHandlerW::getSplitSize()
{
    return m_SplitSize;
}
std::wstring ArgumentHandlerW::getInput()
{
    return m_InputFileDir;
}
std::wstring ArgumentHandlerW::getOutput()
{
    return m_OutputFileDir;
}


// argument flags
bool ArgumentHandlerW::hasSplitSize()
{
    return m_HasSplitSize;
}
const bool ArgumentHandlerW::hasSplitSize() const
{
    return m_HasSplitSize;
}
bool ArgumentHandlerW::hasInput()
{
    return m_HasInput;
}
const bool ArgumentHandlerW::hasInput() const
{
    return m_HasInput;
}
bool ArgumentHandlerW::hasOutput()
{
    return m_HasOutput;
}
const bool ArgumentHandlerW::hasOutput() const
{
    return m_HasOutput;
}
bool ArgumentHandlerW::isConcatMode()
{
    return (m_IsConcatMode && hasInput() && !hasSplitSize());
}
const bool ArgumentHandlerW::isConcatMode() const
{
    return (m_IsConcatMode && hasInput() && !hasSplitSize());
}
bool ArgumentHandlerW::isSplitMode()
{
    return (hasSplitSize() && hasInput() && !m_IsConcatMode);
}
const bool ArgumentHandlerW::isSplitMode() const
{
    return (hasSplitSize() && hasInput() && !m_IsConcatMode);
}


bool ArgumentHandlerW::hasHelp()
{
    return m_HasHelp;
}
const bool ArgumentHandlerW::hasHelp() const
{
    return m_HasHelp;
}
void ArgumentHandlerW::printHelp()
{
    std::cout << "\nFileSC - File Splitting and Concatenating\n"
        << "Usage: FileSC [options] [arguments] ...\n\n"
        << "Options:\n"
        << "\t-h, --help\t\t\tDisplay help message.\n"
        << "\n"
        << "\t-s [arguments]\t\tSplit Mode, [arguments] should be number of bytes in each file slices.\n"
        << "\n"
        << "\t-f [arguments]\t\tFile input, [arguments] should be a complete file/directory.\n"
        << "\t\t\t\tIf in Split mode, [arguments] should be a file path.\n"
        << "\t\t\t\tIf in Concat mode, [arguments] should be a directory.\n"
        << "\n"
        << "\t-c\t\t\tConcat Mode.\n"
        << "\n"
        << "\t-o [arguments]\t\tOutput, [arguments] should be a complete file/directory.\n"
        << "\t\t\t\tIf in Split mode, [arguments] should be a directory.\n"
        << "\t\t\t\tIf in Concat mode, [arguments] should be a file path.\n"
        << "\n"
        << "Examples:\n"
        << "\tSplit A File: FileSC -s 1024 -f \"path\\to\\file.extension\" -o \"path\\to\\outputdir\"\n\n"
        << "\tConcat Files: FileSC -c -f \"path\\to\\filesdir\" -o \"path\\to\\output\\file.extension\"\n\n"
        << "\tHint: You can remove file extension and left a single \'.\' at the end of\n"
        << "\t      output file to generate a file without extension.\n";
    ;
}


// ====================== ArgumentHandlerW End ======================
