# Introduction
Script_ModMe is a collection of modifications to Gothic 3's engine intended for modders.

# Installation
Copy the `Ini` and `scripts` folders into the root directory of your Gothic 3 installation.

If you don't want to overwrite the original Gothic3.exe, you can put the new one under a different name (e.g. Gothic3Launcher.exe) in the root directory instead. Then you have to make sure that you start the game with this new exe, when you want to make use of Script_ModMe.

!!! caution "Attention"
	The Community Patch v1.75.14 is required!

# Configuration
It is possible to enable/disable certain functionalities via the file `Gothic3\ini\scriptmodme.ini`. The configuration file is divided into several sections.

## Game
AutoStart
: Skips the main menu and immediately starts a new game.

HideTips
: Activates the option "Don't show tips anymore" and thus ensures that no tutorial is shown.

## Logging
ModMe
: Debug logging for Script_ModMe into the file `logs\Script_ModMe.log`.

Gothic
: Taps the internal engine logging and writes it to the file `logs\g3debug.log`.
Additionally `Debug.Filter=normal` must be set in the `ge3.ini`.