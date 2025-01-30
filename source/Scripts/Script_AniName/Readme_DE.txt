--- Script_AniName ---

0. Description
Um die Animationen (.xmot) für ein animiertes Mesh (.xact) zu bestimmen, nimmt
Gothic 3 normalerweise das zweite Wort im Mesh-Dateinamen als Animationspräfix.
Dieses Skript überschreibt dieses Zuordnungsmuster für bestimmte Spezies:
  - gESpecies_Skeleton: Skelett_....xmot
  - gESpecies_Zombie: Zombie_....xmot

Das gleiche Zuordnungsmuster wird auf die Effekte `eff_creature_<actor name>_stumble_01` und
`eff_creature_<actor name>_die_01` angewendet:
  - gESpecies_Skeleton: eff_creature_skeleton_stumble_01, eff_creature_skeleton_die_01
  - gESpecies_Zombie: eff_creature_zombie_stumble_01, eff_creature_zombie_die_01

1. Installation
Der Ordner 'scripts' muss ins Gothic 3 Installationverzeichnis kopiert werden.
Es ist nicht notwendig ein neues Spiel zu beginnen.
