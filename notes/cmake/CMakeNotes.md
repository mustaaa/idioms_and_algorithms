# cmake notes

## Wonderful explanation of the key variables and source, binary, list trees

article is here <https://cgold.readthedocs.io/en/latest/tutorials/cmake-sources/common.html>

```CMAKE_SOURCE_DIR``` = root of the source tree (top level cmakelists.txt file)

```CMAKE_BINARY_DIR``` = root of the build tree (corresponding top level cmakelists.txt file)

```PROJECT_SOURCE_DIR``` = path of the first ```project()``` call

```PROJECT_BINARY_DIR``` = corresponding binary dir for the first ```project()``` call  

```CMAKE_CURRENT_SOURCE_DIR``` = in the source tree first ```CMakeLists.txt``` file?  

```CMAKE_CURRENT_BINARY_DIR``` = corresponding binary dir for the first ```CMakeLists.txt``` file  

if you have a .cmake file which defines functions you want to use the following
variables these are the relative to the list file

    CMAKE_CURRENT_LIST_FILE
    CMAKE_CURRENT_LIST_LINE
    CMAKE_CURRENT_LIST_DIR
    CMAKE_PARENT_LIST_FILE
