![githubActionsGoogleTest-blank](https://github.com/nowakkuba99/githubActionsGoogleTest/actions/workflows/googleTestCpp.yml/badge.svg)
<img align="right" src="https://visitor-badge.laobi.icu/badge?page_id=nowakkuba99/githubActionsGoogleTest">


# GitHub actions configuration for GoogleTest framework

Template repository that allows for use of [GoogleTest](https://github.com/google/googletest) framework within [GitHub actions](https://github.com/features/actions).
It consists of simple C++ project with one test file that can be easily adjusted after using this template.
Necessary actions to use are listed below.

## Setup
Use green button on the top of the page: `Use this template` or create workflow file directory: `.github/workflows/yourName.yml` with insides presented below:
```yaml
name: GoogleTests_template

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v1
    - name: Create build folder inside tests folder
      run: cd /home/runner/work/githubActionsGoogleTest/githubActionsGoogleTest/tests
      && mkdir build
      && cd build
      && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-Werror" ..
    - name: Make tests with CMakeLists
      run: cd /home/runner/work/githubActionsGoogleTest/githubActionsGoogleTest/tests
      && cd build
      && make
    - name: Run Tests
      run: /home/runner/work/githubActionsGoogleTest/githubActionsGoogleTest/tests/build/test_module
```

Make sure to replace the project name within paths: `githubActionsGoogleTest`.   
So the `cd` command for creating build foler should look like this: `cd /home/runner/work/YOUR_PROJECT_NAME/YOUR_PROJECT_NAME/tests`

The install of of GoogleTest framework is done through CMake inside tests folder `tests/CMakeLists.txt` :
```cmake
# Include googleTests from github
include(FetchContent)
set (CMAKE_CXX_STANDARD 17)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Create executable
add_executable(test_module tests.cc)

# Link googleTest library
target_link_libraries(test_module
 PRIVATE
  GTest::GTest
  )
```
The whole file is avaiable in `tests/CMakeLists.txt`. When it is being build in job Make tests, the GoogleTest framework is being downloaded form github and installed.
## Customization
### Add code
While adjusting this template to your needs make sure to add the necessary directories to `tests/CMakeLists.txt`:
```cmake
# Include directrories with code to test
include_directories(
    ${CMAKE_SOURCE_DIR}/../inc)
link_directories(
    ${CMAKE_SOURCE_DIR}/../inc)
```
After this you can include your files within tests files:
```c++
/* --- Includes --- */
#include <gtest/gtest.h>
#include <iostream>
/* --- User includes --- */
#include "../inc/yourFile.hpp"
```
### Add dependencies
If you have some dependencies they need to be added to `tests/CMakeLists.txt`. One way is to include them like GoogleTest framework through FetchContent or if you have `CMakeLists.txt` for dependencies you can add it as library to `tests/CMakeLists.txt` and add following line to .yml file adjusting `dependencyPath`.
```yml
- name: Create build folder for dependency
      run: cd /home/runner/work/githubActionsGoogleTest/githubActionsGoogleTest/dependencyPath
      && mkdir build && cd build
      && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-Werror" ..
    - name: Make dependency with CMakeLists
      run: cd /home/runner/work/githubActionsGoogleTest/githubActionsGoogleTest/dependencyPath
      && cd build
      && make
```
You need to build all dependencies before you build tests, so that they will be find by CMake.
## Results
Below there is a result from GitHub actions where the workflow file is run after the push/pull request on main branch. The different steps of the build can be viewed and here the test run is expanded:
<h1 align="center">
<img width="1627" alt="gTestTemplateActions" src="https://github.com/nowakkuba99/githubActionsGoogleTest/blob/main/resources/gTestTemplateActions.png">
</h1>

In comparation to GoogleTest run locally within the VSCode the only difference is the lack of colors:
<h1 align="center">
<img width="1375" alt="gTestTemplate" src="https://github.com/nowakkuba99/githubActionsGoogleTest/blob/main/resources/gTestTemplate.png">
</h1>


