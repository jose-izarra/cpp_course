# -- Project information -----------------------------------------------------
import os
#This will print an error if the path is wrong, helping you diagnose the issue further.
if not os.path.exists("../../build/docs/doxygen/xml"):
    print("Error: Cannot find Doxygen XML output at ../../build/docs/doxygen/xml")


project = os.getenv("PROJECT_NAME", "OOP III Homework")
author = os.getenv("AUTHOR_NAME", "Jose Izarra")
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
