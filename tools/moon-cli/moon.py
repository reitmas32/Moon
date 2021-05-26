import os
import glob
import subprocess
import time
import shutil

import click
import yaml


moon_studio_dir = ""

moon_info = """
Manage your Moon-Proyect development.

Common commands:

  moon create <output directory>
    Create a new Moon project in the specified directory.

  moon run [options]
    Run your Moon-Proyect application.

Usage: moon <command> [arguments]

Global options:
--help                  Print this usage information.
info                    Print Info verbose of Moon

Available commands:
  create                   Create a new Moon project.
  build                    Build this project
  run                      Run your app
  clean                    Remove the binaries
  doctor                   Show information about the installed tooling.
  version                  List Moon and plugins version.
  install                  Install a Plugin
  upgrade                  Upgrade a Plugin or Moon

"""

# def :
try:
    moon_studio_dir = os.environ['MOON_STUDIO_DIR']
except:
    print("It was not found ENV MOON_STUDIO_DIR")
    print("Create MOON_STUDIO_DIR")
    exit()

official_plugins = ["Moon", "Moon_Terminal"]

official_plugins_repo = {"Moon": "https://github.com/reitmas32/Moon.git",
                         "Moon_Terminal": "https://github.com/reitmas32/Moon_Terminal.git"}

glob_name_project = "jj"
glob_description = ""
glob_build_dir = ""
glob_name_build = ""
glob_build_system_exe = ""
glob_c_compiler = ""
glob_cxx_compiler = ""
glob_build_system = ""
glob_cmake_flags = []
glob_build_system_flags = []

config_data_yaml = {}

def read_config():
    global config_data_yaml
    try:
        this_dir = os.getcwd()
        config_file_location = this_dir + "/config.yaml"
        config_data = open(config_file_location)
        config_data_yaml = yaml.load(config_data, Loader=yaml.FullLoader)

        try:
            glob_name_project = config_data_yaml["name_project"]
        except:
            print(" ERROR Not find value name_project in " + config_file_location)

        try:
            glob_description = config_data_yaml["description"]
        except:
            print(" WARNING Not find value description in " + config_file_location)

        try:
            glob_build_dir = config_data_yaml["build_dir"]
        except:
            print(" ERROR Not find value build_dir in " + config_file_location)

        try:
            glob_name_build = config_data_yaml["name_build"]
        except:
            print(" ERROR Not find value name_build in " + config_file_location)

        try:
            glob_build_system_exe = config_data_yaml["build_system_exe"]
        except:
            print(" ERROR Not find value build_system_exe in " + config_file_location)

        try:
            glob_c_compiler = config_data_yaml["c_compiler"]
        except:
            print(" ERROR Not find value c_compiler in " + config_file_location)

        try:
            glob_cxx_compiler = config_data_yaml["cxx_compiler"]
        except:
            print(" ERROR Not find value cxx_compiler in " + config_file_location)

        try:
            glob_build_system = config_data_yaml["build_system"]
        except:
            print(" ERROR Not find value build_system in " + config_file_location)

        try:
            glob_cmake_flags = config_data_yaml["cmake_flags"]
        except:
            print(" WARNING Not find value cmake_flags in " + config_file_location)

        try:
            glob_build_system_flags = config_data_yaml["build_system_flags"]
        except:
            print(" WARNING Not find value build_system_flags in " + config_file_location)

    except:
        print("ERROR This not is a Moon Project")


@click.group()
def main():
    pass


@main.command()
def info():
    print(moon_info)


@main.command()
@click.argument('plugins', nargs=-1)
def install(plugins):

    os.chdir(moon_studio_dir)

    installed_plugins = os.listdir(moon_studio_dir)

    for plugin in plugins:
        if plugin in official_plugins:
            try:
                if not plugin in installed_plugins:
                    subprocess.run(
                        ["git", "clone", "--recursive", official_plugins_repo[plugin]])
                else:
                    print(
                        plugin + " is already installed to update use -> moon update " + plugin)
            except:
                print("ERROR when installing " + plugin)
        else:
            print(plugin + " Not is a official plugin")


@main.command()
@click.argument('plugins', nargs=-1)
def upgrade(plugins):

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
                    print(
                        plugin + " not installed to install use -> moon install " + plugin)
            except:
                print("ERROR when update " + plugin)
        else:
            print(plugin + " Not is a official plugin")


@main.command()
def version():

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

    dependencies = compilers + build_systems + cmakes

    print("Check Requirements")
    time.sleep(0.5)
    with click.progressbar(dependencies,) as bar:
        time.sleep(0.5)
        for compiler in bar:
            print(" -" + compiler)
            time.sleep(0.5)

    print("\n")

    plugins = os.listdir(moon_studio_dir)

    print("Check Plugins")
    time.sleep(0.5)
    with click.progressbar(plugins) as bar:
        time.sleep(0.5)
        for plugin in bar:
            time.sleep(0.5)
            if plugin in official_plugins:
                file = open(moon_studio_dir + "/" + plugin + "/" + "version", "r")
                print(" -" + plugin + " " + file.read())
            else:
                print(" -" + plugin + " Not is a official plugin")

    print("\n")
    print("Moon Studio Dir: " + moon_studio_dir)


@main.command()
@click.argument('name', required=True, type=str)
@click.option('--build_dir', required=False, type=str)
@click.option('--name_build', required=False, type=str)
@click.option('--build_system_exe', required=False, type=str)
@click.option('--c_compiler', required=False, type=str)
@click.option('--cxx_compiler', required=False, type=str)
@click.option('--build_system', required=False, type=str)
def create(name, build_dir, name_build, build_system_exe, c_compiler, cxx_compiler, build_system):

    print("Create a proyect of moon in")
    try:
        # Create the dir
        os.mkdir(name)

        # Get MoonEmptyProjectDir
        moon_empty_project_dir = moon_studio_dir + \
            "/Moon/tools/moon-cli/assets/empty-project/"

        # Copy the MoonEmptyProjectDir in new project {name}
        shutil.copytree(moon_empty_project_dir, name, dirs_exist_ok=True)

        # View the dir of new project {name}
        dir_new_project = os.getcwd() + "/" + name

        print(os.getcwd() + "/" + name)

        remplace_in_file(dir_new_project + "/config.yaml", "__name_project__", name)
        remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_project__", name)

        if build_dir:
            remplace_in_file(dir_new_project + "/config.yaml", "__build_dir__", build_dir)
        else:
            remplace_in_file(dir_new_project + "/config.yaml", "__build_dir__", "build")

        if name_build:
            remplace_in_file(dir_new_project + "/config.yaml", "__name_build__", name_build)
            remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_build__", name_build)
        else:
            remplace_in_file(dir_new_project + "/config.yaml", "__name_build__", "app")
            remplace_in_file(dir_new_project + "/CMakeLists.txt", "__name_build__", "app")

        if build_system_exe and build_system:
            remplace_in_file(dir_new_project + "/config.yaml", "__build_system_exe__", build_system_exe)
            remplace_in_file(dir_new_project + "/config.yaml", "__build_system__", build_system)
        else:
            remplace_in_file(dir_new_project + "/config.yaml", "__build_system_exe__", "ninja")
            remplace_in_file(dir_new_project + "/config.yaml", "__build_system__", "Ninja")

        if c_compiler:
            remplace_in_file(dir_new_project + "/config.yaml", "__c_compiler__", c_compiler)
        else:
            remplace_in_file(dir_new_project + "/config.yaml", "__c_compiler__", "gcc")

        if cxx_compiler:
            remplace_in_file(dir_new_project + "/config.yaml", "__cxx_compiler__", cxx_compiler)
        else:
            remplace_in_file(dir_new_project + "/config.yaml", "__cxx_compiler__", "g++")

    except OSError as exc:
        print(exc)

@main.command()
def build():

    read_config()
    try:
        this_dir = os.getcwd()
        try:
            list_dir = os.listdir()
            if not config_data_yaml["build_dir"] in list_dir:
                os.mkdir(config_data_yaml["build_dir"])

            os.chdir(config_data_yaml["build_dir"])

            subprocess.run([
                "cmake", this_dir + "/.", 
                "-G" + config_data_yaml["build_system"], 
                "-DCMAKE_CXX_COMPILER=" +  config_data_yaml["cxx_compiler"], 
                "-DCMAKE_C_COMPILER=" +  config_data_yaml["c_compiler"]] + config_data_yaml["cmake_flags"])

            subprocess.run([config_data_yaml["build_system_exe"]] + config_data_yaml["build_system_flags"])

        except OSError as exc:
            print(exc)
    except OSError as exc:
        print(exc)
        exit()

@main.command()
def clean():
    read_config()
    try:
        shutil.rmtree(config_data_yaml["build_dir"])
    except OSError as exc:
        print(exc)
        exit()

@main.command()
def run():
    read_config()
    try:
        os.chdir(config_data_yaml["build_dir"])
        subprocess.run(["./" + config_data_yaml["name_build"]])
    except OSError as exc:
        print(exc)
        exit()

def remplace_in_file(file_location, old_text, new_text):
    try:
        #input file
        fin = open(file_location, "rt")

        old_data = fin.readlines()

        new_data = ""

        #for each line in the input file
        for line in old_data:
            #read replace the string and write to output file
            new_data += line.replace(old_text, new_text)
        #close input and output files
        fin.close()

        #output file to write the result to
        fout = open(file_location, "wt")

        #Write new data
        fout.write(new_data)

        #Close output file
        fout.close()
    except:
        print("Not remplace " + old_text + " in " + file_location)


if __name__ == "__main__":
    main()
