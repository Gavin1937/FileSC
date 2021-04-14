## FileSC - File Splitting and Concatenating

* This program will do simple file splitting and concatenating.
* All files will be treated as raw bytes

## Building

* build with cmake
```sh
mkdir build
cd build
cmake ..
```
* build without cmake
```sh
g++ -c ./*.cpp
g++ ./*.o -o output
```

## Documentation
```

FileSC - File Splitting and Concatenating\

Usage: FileSC [options] [arguments] ...

Options:
    -h, --help          Display help message.
    
    -s [arguments]      Split Mode, [arguments] should be number of bytes in each file slices.
    
    -f [arguments]      File input, [arguments] should be a complete file/directory.
                        If in Split mode, [arguments] should be a file path.
                        If in Concat mode, [arguments] should be a directory without '/' or '\' at the end.
    
    -c                  Concat Mode.
    
    -o [arguments]      Output, [arguments] should be a complete file/directory.
                        If in Split mode, [arguments] should be a directory without '/' or '\' at the end.
                        If in Concat mode, [arguments] should be a file path.
    
Examples:
        Split A File: FileSC -s 1024 -f "path/to/file.extension" -o "path/to/outputdir"
        
        Concat Files: FileSC -c -f "path/to/filesdir" -o "path/to/output/file.extension"
        
        Hint: You can remove file extension and left a single '.' at the end of
              output file to generate a file without extension.
```