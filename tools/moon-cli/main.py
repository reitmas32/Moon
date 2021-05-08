import click
import os
import shutil
import glob
import subprocess
import time

official_plugins = ["Moon", "Moon_Terminal"]

official_plugins_repo = {"Moon": "git@github.com:reitmas32/Moon.git",
                         "Moon_Terminal": "git@github.com:reitmas32/Moon_Terminal.git"}


@click.group()
def main():
    pass


@main.command()
@click.argument('plugins', nargs=-1)
def install(plugins):
    # Get MoonStudioDir
    moon_studio_dir = os.environ['MOON_STUDIO_DIR']

    os.chdir(moon_studio_dir)

    installed_plugins = os.listdir(moon_studio_dir)

    for plugin in plugins:
        if plugin in official_plugins:
            try:
                if not plugin in installed_plugins:
                    subprocess.run(["git", "clone", "--recursive", official_plugins_repo[plugin]])
                else:
                    print(plugin + " is already installed to update use -> moon update " + plugin)
            except:
                print("ERROR when installing " + plugin)
        else:
            print(plugin + " Not is a official plugin")

@main.command()
@click.argument('plugins', nargs=-1)
def update(plugins):
    # Get MoonStudioDir
    moon_studio_dir = os.environ['MOON_STUDIO_DIR']

    os.chdir(moon_studio_dir)

    installed_plugins = os.listdir(moon_studio_dir)

    for plugin in plugins:
        if plugin in official_plugins:
            try:
                if plugin in installed_plugins:
                    os.chdir(plugin)
                    subprocess.run(["git", "pull", "origin", "master"])
                    os.chdir("..")
                else:
                    print(plugin + " not installed to install use -> moon install " + plugin)
            except:
                print("ERROR when update " + plugin)
        else:
            print(plugin + " Not is a official plugin")

@main.command()
def version():
    # Get MoonStudioDir
    moon_studio_dir = os.environ['MOON_STUDIO_DIR']

    time.sleep(1.0)

    plugins = os.listdir(moon_studio_dir)

    for plugin in plugins:
        if plugin in official_plugins:
            file = open(moon_studio_dir + "/" + plugin + "/" + "version", "r")
            print("-" + plugin + " " + file.read())
        else:
            print("-" + plugin + " Not is a official plugin")

@main.command()
def doctor():
    compilers = []
    cmakes = []
    build_systems = []
    gits = []

    print("Moon Doctor check dependencies")
    time.sleep(1.0)
    try:
        # Check CMake Install
        subprocess.run(["cmake", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        cmakes.append("[✓] cmake")
    except:
        cmakes.append("[✗] cmake")

    try:
        # Check CMake Install
        subprocess.run(["git", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        gits.append("[✓] git")
    except:
        gits.append("[✗] git")

    try:
        # Check Make Install
        subprocess.run(["make", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        build_systems.append("[✓] make")
    except:
        build_systems.append("[✗] make")

    try:
        # Check Ninja Install
        subprocess.run(["ninja", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        build_systems.append("[✓] ninja")
    except:
        build_systems.append("[✗] ninja")

    try:
        # Check GCC Compiler version
        subprocess.run(["gcc", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] gcc")
    except:
        compilers.append("[✗] gcc")

    try:
        # Check GCC 10 Compiler version
        subprocess.run(["gcc-10", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] gcc-10")
    except:
        compilers.append("[✗] gcc-10")
    try:
        # Check Clang 10 Compiler version
        subprocess.run(["clang", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] clang")
    except:
        compilers.append("[✗] clang")

    try:
        # Check Clang 10 Compiler version
        subprocess.run(["clang-10", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] clang-10")
    except:
        compilers.append("[✗] clang-10")

    try:
        # Check Clang 11 Compiler version
        subprocess.run(["clang-11", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] clang-11")
    except:
        compilers.append("[✗] clang-11")

    try:
        # Check Clang 12 Compiler version
        subprocess.run(["clang-12", "--version"], stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL)
        compilers.append("[✓] clang-12")
    except:
        compilers.append("[✗] clang-12")

    # print("Compilers")
    for compiler in compilers:
        print("-" + compiler)

    #print("Build Systems")
    for build_system in build_systems:
        print("-" + build_system)

    # print("CMake")
    for cmake in cmakes:
        print("-" + cmake)

    # print("Git")
    for git in gits:
        print("-" + git)

    print("\n")

    print("Moon plugins")

    # Get MoonStudioDir
    moon_studio_dir = os.environ['MOON_STUDIO_DIR']

    time.sleep(1.0)

    plugins = os.listdir(moon_studio_dir)

    for plugin in plugins:
        if plugin in official_plugins:
            file = open(moon_studio_dir + "/" + plugin + "/" + "version", "r")
            print("-" + plugin + " " + file.read())
        else:
            print("-" + plugin + " Not is a official plugin")


@main.command()
@click.argument('name', required=True, type=str)
def create(name):
    print("Create a proyect of moon in")
    try:
        # Create the dir
        os.mkdir(name)

        # Get MoonStudioDir
        moon_studio_dir = os.environ['MOON_STUDIO_DIR']

        # Get MoonEmptyProjectDir
        moon_empty_project_dir = moon_studio_dir + \
            "/Moon/tools/moon-cli/assets/empty-project/"

        # Copy the MoonEmptyProjectDir in new project {name}
        shutil.copytree(moon_empty_project_dir, name, dirs_exist_ok=True)

        # View the dir of new project {name}
        print(os.getcwd() + "/" + name)

    except OSError as exc:
        print(exc)


if __name__ == "__main__":
    main()
