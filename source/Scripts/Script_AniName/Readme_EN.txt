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
