# Windows
# commands
# pip install click py2exe PyYAML
# python setup.py install
# python setup.py py2exe

from distutils.core import setup
import py2exe

setup(
    console=['moon.py'],
    zipfile = None
)
