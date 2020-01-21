# Using the Console
The console can be opened with the `^` key when the cheat mode is activated. You can complete commands and parameters automatically via `Tab`. The command `help` lists all available commands and their descriptions.
With `Tab` or `Shift`+`Tab` you can scroll through all available commands.
With `Ctrl` + `Tab` you can display the help for a command.


# New commands
Script_ModMe introduces new console commands, each of which has several subcommands available. The help and auto complete functionality described in the previous section also works at the subcommand level.

## File
ColMeshConvexHull &lt;Meshname> [&lt;scale> oder &lt;scalex> &lt;scaley> &lt;scalez>]
: Creates a ConvexHull-CollisionMesh (CVCS) from a specified mesh. Optionally, you can specify a uniform scale or a separate scale for each coordinate direction.

!!! caution "Attention"
	Gothic 3 cannot load non-uniformly scaled ConvexHull collision meshes. This limitation has no deeper technical background, but was probably never needed and therefore not implemented in the loading routine. If such ConvexHull-CollisionMeshes are needed, they could be added without any problems.

!!! caution "Attention"
	CVCS always have only one SubMesh (at least in the original data). Apart from whether CVCS with multiple submeshes would work correctly at all, there is an error in the calculation function which causes the creation of such CVCS to produce an incorrect result. If the function is called for a mesh (.xcmsh) with `n` SubMeshes and a scaling factor `s`, the BoundingBoxes (and also other parts?) of the CVCS are scaled incorrectly with a factor of `s^n`, because the calculation is executed once in each loop pass (per submesh).

ColMeshTriMesh &lt;Meshname> [&lt;scale> oder &lt;scalex> &lt;scaley> &lt;scalez>]
: Creates a TriMesh-CollisionMesh from a specified mesh. Optionally, a uniform scale or a separate scale for each coordinate direction can be specified.

Reload &lt;Ressource>
: Reloads the specified resource.
A texture located in `Data/_compiledImage` (or in a subdirectory) can be used as resource.

## Tools
SetGameEvent &lt;GameEvent>
: Sets a GameEvent. Specifying multiple semicolon-separated GameEvents (like in CondPlayerKnows) is supported.

ClearGameEvent &lt;GameEvent>
: Clears a GameEvent. Specification of multiple semicolon-separated GameEvents (like in CondPlayerKnows) is supported.

IsSetGameEvent &lt;GameEvent>
: Checks if a GameEvent is set. Specification of multiple semicolon separated GameEvents (like in CondPlayerKnows) is supported.

SetStringtable &lt;Key> &lt;Value>
: Sets the string table entry to the specified value.

SetQuestStatus &lt;Quest> &lt;Status>
: Sets the status of a quest.

DumpGameState
: Saves the current game status, such as set GameEvents, in a text file. Can be helpful for the editor of a bug report, if the tester adds such a dump to it.

## Vars
DebugRoutines &lt;true/false>
: The individual tasks of a NPC routine task take much less time than usual.

## World
CompileLightmaps
: Calculates the illumination for the whole world. In order to save the resulting lightmaps, the (empty) directory `Lightmaps` in the Gothic 3 Data folder must be created. The `Lightmaps.pak` does not need to be renamed or moved.
	<br>In addition, the command creates a directory named `StaticLightdata` in which `sldat` files are created during the light calculation. To understand their purpose, you need to know how static lighting, i.e. lighting from light sources that don't move or otherwise change, works in Gothic 3.
	For static lighting Gothic 3 has two methods. An entity can either be illuminated with a lightmap (xlmp file in the Lightmaps folder) or with so-called instance lighting, i.e. the four light sources you can enter at the end of the `eCIlluminated` class.
	When you use the CompileLightmaps command to calculate the lighting, Gothic 3 calculates either lightmaps or instance lighting for each entity, depending on the lighting type set for the entity. The calculated lightmaps are stored in the `Lightmaps` folder.
	The instance lighting, however, is modified in the eCIlluminated class of the entity and then the modified entity, or the file containing the entity, is stored in the Projects_compiled folder. However, the `.lrentdat`/`.node` files that Gothic 3 creates in this way are partly 'faulty' and therefore useless for us.
	Therefore the instance lighting is additionally saved into the StaticLightdata folder. Each `.sldat` contains the instance lighting of one entity. With [g3dit](https://forum.worldofplayers.de/forum/threads/1330059-Tool-g3dit-Weltdaten-Editor), you can import the .sldat files, and thus assign the recalculated instance lighting to entities.

!!! caution "Attention"
	The configuration parameter 'Render.PrefetchGridCellSize' should be set to its default value of 10000, otherwise problems with the lighting calculation may occur.

CompileLightmaps &lt;minX> &lt;maxX> &lt;minZ> &lt;maxZ>
: Calculates the illumination for the specified area. The coordinates must be divisible by 10000.

CompileLightmaps &lt;Entity> &lt;Square-edge-length> [&lt;Y-Offset>]
: Calculates the illumination for the area covered by the square, using the entity as the center (shifted by Y offset) of the square.

## DummyCollector
The DummyCollector takes care of supplying the gCDummyCollectorAdmin with entities. For example, it is responsible for the display of navigation objects (Ctrl+N).
If the DummyCollector decides that an entity (e.g. a NavZone) is in the player's field of view, it instructs the DummyCollectorAdmin to take care of its display.
The representation of invisible entities is realized with dummy entities, hence the name gCDummyCollectorAdmin.
Unfortunately, the dummy collector is not 100% reliable, so that some entities are not displayed although they should be visible. An example are extremely large NavZones like the zone `360403A8490B14468FBD24CCCBBD381F00000000`.

Log
: Enables logging for the next execution of the DummyCollector.

Pin &lt;Guid>
:	Forces the display of an entity, even if the DummyCollector does not classify it as visible.
	The format of the Guid must be `{777777-7777-7777-7777-7777-7777}` (called *Gothic 3 Text* in the g3dit Guid Formats dialog).

Unpin &lt;Guid>
: Disables the forced display of an entity again.
	For the guid the same format specifications apply as within the `Pin` command.

Pin Navigation
: Forces the display of all navigation entities (NavZone, NavPath, NegZone, PrefPath), even if the DummyCollector does not classify them as visible.

Unpin Navigation
: Disables the forced display of all navigation entities again.