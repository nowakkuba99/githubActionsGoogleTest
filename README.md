![githubActionsGoogleTest-blank](https://github.com/nowakkuba99/githubActionsGoogleTest/actions/workflows/googleTestCpp.yml/badge.svg)
<img align="right" src="https://visitor-badge.laobi.icu/badge?page_id=nowakkuba99/githubActionsGoogleTest">


# GitHub actions configuration for GoogleTest framework

Template repository that allows for use of [GoogleTest](https://github.com/google/googletest) framework within [GitHub actions](https://github.com/features/actions).
It consists of simple C++ project with one tests file that can be easily adjusted after using this template.
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

The install of of GoogleTest framework is done through `CMakeLists.txt` inside tests folder:
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
## Results
Sample results from run within VSCode:
<h1 align="center">
<img width="1375" alt="gTestTemplate" src="https://user-images.githubusercontent.com/81216407/227485802-49538fa6-e23f-4d38-bca7-ac2ae426c1be.png">
</h1>

Result from GitHub actions:
<h1 align="center">
<img width="1627" alt="gTestTemplateActions" src="https://user-images.githubusercontent.com/81216407/227487018-7c7b1d74-4323-431c-a294-427590234ebe.png">
</h1>
