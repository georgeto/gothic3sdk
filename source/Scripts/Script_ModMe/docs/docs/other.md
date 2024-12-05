# Automatic start
When starting Gothic 3, makes sure to skip the main menu and start a new game immediately.
This function can be controlled via the `scriptmodme.ini` (Game.AutoStart) or the [command line parameter autostart](commandline.md#automatic-start). The command line parameter has the higher priority.

# Repair static meshes
Static meshes contain two properties that are not calculated by the existing tools (e.g. [G3MC](https://forum.worldofplayers.de/forum/threads/1459848-Release-G3MC-Gothic3-Mesh-Converter) or [Rimy3D](https://www.baltr.de/rimy3d/help/en/)). These are the 'spatial hierarchy' and the 'lightmap UV groups'.

Fortunately Gothic 3 contains code to recalculate these properties, which can be used as follows:

First you have to create the directory `_compiledMesh` in the Gothic 3 data directory, and within `_compiledMesh` another directory named `FixMe`.
Now Gothic 3 recalculates the above mentioned properties for all `.xcmsh`s in the `FixMe` directory on startup, when reaching the main menu. For each of the meshes, a version repaired in this way is stored in the 'FixMe' directory.

!!! caution "Attention"
	To write the fixed `.xcmhsh`s, Gothic 3 needs write access to its installation directory.
	Therefore, move Gothic 3 to a folder without write restrictions, i.e. outside of `Program Files`, or run the game as administrator.

# Repair animated meshes
Animated meshes (.xact), called eCResourceAnimationActor_PS within the engine, are structured as follows:
```cpp
struct eSLookAtConstraintData
{
    bCString m_strName;
    GEFloat  m_fInterpolationSpeed;
    bCVector m_MinConstraints;
    bCVector m_MaxConstraints;
};

struct eSMaterialReference
{
	GEInt    Index;
	bCString Name;
};

struct eSRgbaColor
{
	GEU8 Red;
	GEU8 Green;
	GEU8 Blue;
	GEU8 Alpha;
};

class eCWrapper_emfx2Actor
{
	EMotionFX::Actor          Actor; // Actor in a proprietary format
	List<eSMaterialReference> Materials;
	List<List<eSRgbaColor>>   AmbientOcclusion; // Per vertex color attribute
	List<bCVector>            Tangents; // Per vertex tangent attribute
};

class eCResourceAnimationActor_PS
{
	GEU32      ResourceSize;
	GEFloat    ResourcePriority;
	bCDateTime RativeFileTime;
	GEU32      NativeFileSize;
	bCBox      Boundary;

	List<eSLookAtConstraintData> LookAtConstraints;
	List<eCWrapper_emfx2Actor>   LoDs;
	eCWrapper_emfx2Actor         Actor;
};
```

The `AmbientOcclusion` property in `eCWrapper_emfx2Actor` is problematic, as it is not calculated by the existing tools (e.g. [Rimy3D](https://www.baltr.de/rimy3d/help/en/)), but is only filled with a constant value. As a result, modified animated meshes will be appear brighter than their unmodified original version.

Fortunately, Gothic 3 contains code to recalculate the AmbientOcclusion of an actor, which can now be used as follows:

First you have to create the directory `_compiledAnimation` in the Gothic 3 data directory, and within `_compiledAnimation` another directory named `FixMe`.
Now Gothic 3 recalculates the AmbientOcclusion for all `.xact`s in the `FixMe` directory on startup, more precisely when reaching the main menu. For each of the meshes, a version repaired in this way is stored in the `FixMe` directory.

!!! caution "Attention"
	To write the fixed `.xact`s, Gothic 3 needs write access to its installation directory.
	Therefore, move Gothic 3 to a folder without write restrictions, i.e. outside of `Program Files`, or run the game as administrator.

# Automatic scaling of Convex-CollisionMeshes
When converting a CollisionShape to the physics engine PhsyX used by Gothic 3, it is scaled with the scaling factors of its entity.
Strangely though, the code responsible for this is duplicated. Even worse, the two versions subtly differ from each other - details will follow.
For Triangle-/Convex-CollisionShapes, if required, i.e. if no correspondingly scaled version exists yet, one will be created and stored in `_compiledPhysic`. So much for the theory, but if you look closely you can see that in one of the two versions there is no automatic scaling for Convex-CollisionShapes. Even the log messages are the same. But instead of checking if an unscaled CollisionShape exists in the absence of a scaled version, it simply directly assumes that it does not and issues an error message.
This inconsistency has been removed; now scaled versions are created for Convex-CollisionShape if required.

!!! caution "Attention"
	To write the scaled collision mmeshes, Gothic 3 needs write access to its installation directory.
	Therefore, move Gothic 3 to a folder without write restrictions, i.e. outside of `Program Files`, or run the game as administrator.

# Box-CollisionShapes and unevenly scaled entities
The PhsyX conversion function was not able to convert Box-CollisionShapes correctly if the corresponding entity was not scaled uniformly, i.e. had different scales on X-axis, Y-axis and Z-axis. This limitation has been fixed.