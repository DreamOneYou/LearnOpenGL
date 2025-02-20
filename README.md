# learnopengl.com code repository
Contains code samples for all chapters of Learn OpenGL and [https://learnopengl.com](https://learnopengl.com). 

## 如何在window编译成visual studio可执行文件
    1、首先克隆代码到本地
    2、在下载的文件里创建一个/build文件夹
    3、使用cmake进行编译。需要设置一个选项在编译的时候：CMAKE_CONFIGURATION_TYPES:Debug;Release
    4、之后可以Configure，我选择的是vs2017，x64。之后在Generate，之后可以Open Project。
    5、之后你可以选择指定的项目设置为启动项，然后右击生成，之后就可以点击本地windows调试器了。
    
建议使用cmake，从源代码构建库。
## [学习笔记](https://github.com/DreamOneYou/LearnOpenGL/blob/master/learnNoteBook.md)
## Linux building
First make sure you have CMake, Git, and GCC by typing as root (sudo) `apt-get install g++ cmake git` and then get the required packages:
Using root (sudo) and type `apt-get install libsoil-dev libglm-dev libassimp-dev libglew-dev libglfw3-dev libxinerama-dev libxcursor-dev  libxi-dev libfreetype-dev libgl1-mesa-dev xorg-dev` .
Next, run CMake (preferably CMake-gui). The source directory is LearnOpenGL and specify the build directory as LearnOpenGL/build. Creating the build directory within LearnOpenGL is important for linking to the resource files (it also will be ignored by Git). Hit configure and specify your compiler files (Unix Makefiles are recommended), resolve any missing directories or libraries, and then hit generate. Navigate to the build directory (`cd LearnOpenGL/build`) and type `make` in the terminal. This should generate the executables in the respective chapter folders.

Note that CodeBlocks or other IDEs may have issues running the programs due to problems finding the shader and resource files, however it should still be able to generate the executables. To work around this problem it is possible to set an environment variable to tell the tutorials where the resource files can be found. The environment variable is named LOGL_ROOT_PATH and may be set to the path to the root of the LearnOpenGL directory tree. For example:

    `export LOGL_ROOT_PATH=/home/user/tutorials/LearnOpenGL`

Running `ls $LOGL_ROOT_PATH` should list, among other things, this README file and the resources directory.

## Mac OS X building
Building on Mac OS X is fairly simple:
```
brew install cmake assimp glm glfw freetype
cmake -S . -B build
cmake --build build -j$(sysctl -n hw.logicalcpu)
```
## Create Xcode project on Mac platform
Thanks [@caochao](https://github.com/caochao):
After cloning the repo, go to the root path of the repo, and run the command below:
```
mkdir xcode
cd xcode
cmake -G Xcode ..
```

## Glitter
Polytonic created a project called [Glitter](https://github.com/Polytonic/Glitter) that is a dead-simple boilerplate for OpenGL. 
Everything you need to run a single LearnOpenGL Project (including all libraries) and just that; nothing more. 
Perfect if you want to follow along with the chapters, without the hassle of having to manually compile and link all third party libraries!


