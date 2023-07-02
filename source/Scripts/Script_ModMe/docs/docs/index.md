# Introduction
Script_ModMe is a collection of modifications to Gothic 3's engine intended for modders.

# Installation
Copy the `Ini` and `scripts` folders into the root directory of your Gothic 3 installation.

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