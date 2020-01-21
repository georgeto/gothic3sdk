# Create CollisionMesh
-cmin=&lt;Mesh name> [-cmout=&lt;CollisionMesh save path> -convex=true -scale=&lt;Uniform scaling> -scalex=&lt;Scale in X> -scaley=&lt;Scale in Y> -scalez=&lt;Scale in Z]
: Creates a TriMesh-CollisionMesh or ConvexHull-CollisionMesh from a specified mesh.
  Optionally, a file path can be specified where the CollisionMesh should be saved.
  Additionally, either a uniform scale or a scale for each coordinate direction can be specified.

!!! note "Example 1"
	`Gothic3.exe -cmin=G3_Weapon_Axe_BarbarianAxe_01.xcmsh`

	Create a TriMesh-CollisionMesh for the mesh `G3_Weapon_Axe_BarbarianAxe_01.xcmsh` and save it as `Data/_compiledPhysic/G3_Weapon_Axe_BarbarianAxe_01.xnvmsh`.

!!! note "Example 2"
	`Gothic3.exe -cmin=G3_Weapon_Axe_BarbarianAxe_01.xcmsh -cmout=Data/_compiledPhysic/MyColMesh.xnvmsh`

	Creates a TriMesh-CollisionMesh for the mesh `G3_Weapon_Axe_BarbarianAxe_01.xcmsh` and save it as `Data/_compiledPhysic/MyColMesh.xnvmsh`.
	The storage path must be a valid path in the virtual filesystem of Gothic 3.

!!! note "Example 3"
	`Gothic3.exe -cmin=G3_Weapon_Axe_BarbarianAxe_01.xcmsh -convex=true -scale=1.5`

	Create a ConvexHull CollisionMesh for the mesh `G3_Weapon_Axe_BarbarianAxe_01.xcmsh` and save it as `Data/_compiledPhysic/G3_Weapon_Axe_BarbarianAxe_01_CV_SC_1_5000.xnvmsh`.

!!! hint "Hint"
	In contrast to the [equivalent console command](console.md#file) you save the loading time for starting a new game, because the CollisionMesh is already created when reaching the main menu.

# Automatic start
-autostart=&lt;true/false>
: Controls the [automatic start](other.md#automatic-start) of a new game.