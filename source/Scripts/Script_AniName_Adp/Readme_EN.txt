--- Script_AniName ---

0. Description
Usually to determine the animations (.xmot) to use for an animated mesh (.xact),
Gothic 3 takes the second word in the mesh file name as the animation prefix.
This Script overrides that mapping for certain species:
  - gESpecies_Skeleton: Skeleton_....xmot
  - gESpecies_Zombie: Zombie_....xmot

The same mapping override is applied to the `eff_creature_<actor name>_stumble_01` and
`eff_creature_<actor name>_die_01` effects.
  - gESpecies_Skeleton: eff_creature_skeleton_stumble_01, eff_creature_skeleton_die_01
  - gESpecies_Zombie: eff_creature_zombie_stumble_01, eff_creature_zombie_die_01

1. Installation
The 'scripts' folder has to be copied into the Gothic 3 install folder.
There is no need to start a new game.


2. Useful Power-Shells Tools for the Creation of the Needed Renamed Duplicates
*Bevor you use the command lines in PS, you would need to extract all the compiledAnimation-files in a SEPERATE folder
That is important if you dont want to loose your current animation data!*

cd "<Path of the directory of the extracted animation files>"
------------------------------------------------------------------------------------------
Remove-Item -Path "*" -Exclude Hero_*
New-Item -Path ".\Skeleton" -ItemType "directory"
New-Item -Path ".\Zombie" -ItemType "directory"
Copy-Item ".\Hero_*" -Destination ".\Skeleton\"
Copy-Item ".\Hero_*" -Destination ".\Zombie\"
Get-Item ".\Skeleton\Hero_*" | Rename-Item -NewName {$_.name -replace "Hero","Skeleton"}
Get-Item ".\Zombie\Hero_*" | Rename-Item -NewName {$_.name -replace "Hero","Zombie"}
------------------------------------------------------------------------------------------

With these lines you will create 2 directories with adjusted names for the Hero_* animation file duplicates