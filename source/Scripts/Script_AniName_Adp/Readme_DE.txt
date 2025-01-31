--- Script_AniName_Adp ---

0. Description
Um die Animationen (.xmot) für ein animiertes Mesh (.xact) zu bestimmen, nimmt
Gothic 3 normalerweise das zweite Wort im Mesh-Dateinamen als Animationspräfix.
Dieses Skript überschreibt dieses Zuordnungsmuster für bestimmte Spezies:
  - gESpecies_Skeleton: Skeleton_....xmot
  - gESpecies_Zombie: Zombie_....xmot

Das gleiche Zuordnungsmuster wird auf die Effekte `eff_creature_<actor name>_stumble_01` und
`eff_creature_<actor name>_die_01` angewendet:
  - gESpecies_Skeleton: eff_creature_skeleton_stumble_01, eff_creature_skeleton_die_01
  - gESpecies_Zombie: eff_creature_zombie_stumble_01, eff_creature_zombie_die_01

1. Installation
Der Ordner 'scripts' muss ins Gothic 3 Installationverzeichnis kopiert werden.
Es ist nicht notwendig ein neues Spiel zu beginnen.

2. Nützliche Power-Shell Tools für die Erstellung der Duplicate und der Namens Anpassung
*Davor sollten alle Animationsdateien in einem SEPERATEM Ordner extrahiert werden, da nicht gewollte Daten gelöscht werden!*

cd "<Pfad von dem Ordner mit den Extrahierten Animationen>"
------------------------------------------------------------------------------------------
Remove-Item -Path "*" -Exclude Hero_*
New-Item -Path ".\Skeleton" -ItemType "directory"
New-Item -Path ".\Zombie" -ItemType "directory"
Copy-Item ".\Hero_*" -Destination ".\Skeleton\"
Copy-Item ".\Hero_*" -Destination ".\Zombie\"
Get-Item ".\Skeleton\Hero_*" | Rename-Item -NewName {$_.name -replace "Hero","Skeleton"}
Get-Item ".\Zombie\Hero_*" | Rename-Item -NewName {$_.name -replace "Hero","Zombie"}
------------------------------------------------------------------------------------------

Dadurch entstehen 2 Ordner (Skeleton,Zombie) mit angepassten Duplikat-Animationsdateien.


