check_install_cmake()
{
    CMAKE_VERSION="cmake --version"
    RETVAL=0
    if eval $CMAKE_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install CMake"
    fi
    return $RETVAL
}

check_install_git()
{
    GIT_VERSION="git --version"
    RETVAL=0
    if eval $GIT_VERSION 
    then
        RETVAL=1
        printf "n"
    else
        echo "Not install git"
    fi
    return $RETVAL
}

check_install_make()
{
    MAKE_VERSION="make --version"
    RETVAL=0
    if eval $MAKE_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install make"
    fi
    return $RETVAL
}

check_install_gcc()
{
    gcc_VERSION="gcc --version"
    RETVAL=0
    if eval $gcc_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install gcc"
    fi
    return $RETVAL
}

clone_moon_rep(){
    mkdir -p $HOME/MoonStudio
    cd $HOME/MoonStudio
    sudo rm -r Moon
    git clone git@github.com:reitmas32/Moon.git
}

build_moon(){
    cd $HOME/MoonStudio/Moon
    mkdir -p $HOME/MoonStudio/Moon/build
    cd $HOME/MoonStudio/Moon/build
    cmake .. -DCMAKE_CXX_FLAGS="-stdlib=libc++"
}

main(){
    check_install_git
    check_install_gcc
    check_install_make
    check_install_cmake
    clone_moon_rep
    build_moon
}

main