# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

# import subprocess, os

# def configureDoxyfile(input_dir, output_dir):

# 	with open('Doxyfile.in', 'r') as file :
# 		filedata = file.read()

# 	filedata = filedata.replace('@DOXYGEN_INPUT_DIR@', input_dir)
# 	filedata = filedata.replace('@DOXYGEN_OUTPUT_DIR@', output_dir)

# 	with open('Doxyfile', 'w') as file:
# 		file.write(filedata)

# # Check if we're running on Read the Docs' servers
# read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

# breathe_projects = {}
# if read_the_docs_build:
# 	input_dir = '../src'
# 	output_dir = '../../build'
# 	configureDoxyfile(input_dir, output_dir)
# 	subprocess.call('doxygen', shell=True)
# 	breathe_projects['Homework'] = output_dir + '/xml'


# -- Project information -----------------------------------------------------
import os
#This will print an error if the path is wrong, helping you diagnose the issue further.
if not os.path.exists("../../build/docs/doxygen/xml"):
    print("Error: Cannot find Doxygen XML output at ../../build/docs/doxygen/xml")


project = os.getenv("PROJECT_NAME", "default name")
author = os.getenv("AUTHOR_NAME", "unknown")
copyright = os.getenv("COPYRIGHT", "2024, Jose")

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["breathe"]

# Breathe Configuration
breathe_default_project = project
breathe_default_members = ( "members", "undoc-members" )  # Document class members by default


templates_path = ["_templates"]
exclude_patterns = []


html_theme = "sphinx_rtd_theme"
# html_static_path = ["_static"]

breathe_projects = {
    "Homework": "../../build/docs/doxygen/xml"
}

# Adding to this variable allows to pass variables to the ReST files.
rst_epilog = """
.. |project| replace:: {}
""".format(
    project
)
