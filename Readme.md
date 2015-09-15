#QT-Examples

This repository was created during a Mobile-Linux-Programming coures at the [Jamk.fi](http://Jamk.fi/) 

I used cmake instead of qmake because cmake is more popular in big open-source projects, for example [Webkit](https://github.com/WebKit/webkit) or [OpenWebRTC](https://github.com/EricssonResearch/openwebrtc)
The second reason is for embedding third party libraries and provide a cross operating system development environment is in my opinion cmake more common and provide a more efficient way for configuration different targets and libraries. 


##Getting started 

Requirements
* cmake 2.8.+
* qt 5.+

### OSX-Setup 

1. Install required software via brew 

    ```
        brew install cmake
        brew install qt5
    
    ```

2. Set up your **CMAKE_PREFIX_PATH** to your local folder 

    The default folder is */usr/local/opt/qt5/*
    
    
###Windows-Setup

**Not tested jet! **

1. install required software 
    Follow the instructions: 
        * http://www.cmake.org/install/
        * http://doc.qt.io/qt-5/gettingstarted.html
    

###Linux-Setup
**Not tested jet! **

1. Install required software
    ```
        sudo apt-get install cmake
        sudo apt-get install qt5-default qttools5-dev-tools
    
    ```
    
###Mobile-Setup 

Not tested jet! 
