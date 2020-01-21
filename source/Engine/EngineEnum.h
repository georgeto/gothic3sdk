#ifndef ENGINEENUM_H_INCLUDED
#define ENGINEENUM_H_INCLUDED

// gCAmbientSequencer.Climate
// gCAmbientSound.Climate

enum eEAmbientClimate {
    eEAmbientClimate_Mediterranean = 0,
    eEAmbientClimate_Arctic        = 1,
    eEAmbientClimate_Desert        = 2,
    eEAmbientClimate_Cave          = 3
};

// gCAmbientSequencer.DayTime
// gCAmbientSound.DayTime

enum eEAmbientDayTime {
    eEAmbientDayTime_Morning = 0,
    eEAmbientDayTime_Day     = 1,
    eEAmbientDayTime_Evening = 2,
    eEAmbientDayTime_Night   = 3
};

// eCSpeedTree_PS.AmbientEnvironment
// gCAmbientSequencer.Environment
// gCAmbientSound.Environment

enum eEAmbientEnvironment {
    eEAmbientEnvironment_Forest   = 0,
    eEAmbientEnvironment_Meadow   = 1,
    eEAmbientEnvironment_Plain    = 2,
    eEAmbientEnvironment_Mountain = 3,
    eEAmbientEnvironment_Coast    = 4,
    eEAmbientEnvironment_Town     = 5
};

// eCAudioEmitter_PS.SpawningMode

enum eEAudioEmitterMode {
    eEAudioEmitterMode_Once   = 0,
    eEAudioEmitterMode_Loop   = 1,
    eEAudioEmitterMode_Repeat = 2
};

// eCCollisionShape_PS.Group
// eCVisualAnimation_PS.SkeletonShapeGroup

enum eECollisionGroup {
    eECollisionGroup_Undefined     = 0,
    eECollisionGroup_Static        = 1,
    eECollisionGroup_Dynamic       = 2,
    eECollisionGroup_Player        = 3,
    eECollisionGroup_NPC           = 4,
    eECollisionGroup_Item_Equipped = 5,
    eECollisionGroup_Item_World    = 6,
    eECollisionGroup_Item_Attack   = 7,
    eECollisionGroup_Interactable  = 8,
    eECollisionGroup_Trigger       = 9,
    eECollisionGroup_Zone          = 10,
    eECollisionGroup_Camera        = 11,
    eECollisionGroup_Tree          = 12,
    eECollisionGroup_DownCharacter = 13,
    eECollisionGroup_PlayerTrigger = 14,
    eECollisionGroup_ObjectTrigger = 15,
    eECollisionGroup_Ghost         = 16,
    eECollisionGroup_Mover         = 17,
    eECollisionGroup_RagDoll       = 18
};

// eCCollisionShape.Type

enum eECollisionShapeType {
    eECollisionShapeType_None       = 0,
    eECollisionShapeType_TriMesh    = 1,
    eECollisionShapeType_Plane      = 2,
    eECollisionShapeType_Box        = 3,
    eECollisionShapeType_Capsule    = 4,
    eECollisionShapeType_Sphere     = 5,
    eECollisionShapeType_ConvexHull = 6,
    eECollisionShapeType_Point      = 7
};

// eCParticle_PS.CollisionSound

enum eECollisionSound {
    eECollisionSound_Disabled     = 0,
    eECollisionSound_LinearLocal  = 1,
    eECollisionSound_LinearGlobal = 2,
    eECollisionSound_Random       = 3
};

// eCColorSrcCombiner.CombinerType

enum eEColorSrcCombinerType {
    eEColorSrcCombinerType_Add      = 0,
    eEColorSrcCombinerType_Subtract = 1,
    eEColorSrcCombinerType_Multiply = 2,
    eEColorSrcCombinerType_Max      = 3,
    eEColorSrcCombinerType_Min      = 4
};

// eCColorSrcSampler.TexRepeatU
// eCColorSrcSampler.TexRepeatV

enum eEColorSrcSampleTexRepeat {
    eEColorSrcSampleTexRepeat_Wrap   = 0,
    eEColorSrcSampleTexRepeat_Clamp  = 1,
    eEColorSrcSampleTexRepeat_Mirror = 2
};

// eCColorSrcSampler.SwitchRepeat

enum eEColorSrcSwitchRepeat {
    eEColorSrcSwitchRepeat_Repeat   = 0,
    eEColorSrcSwitchRepeat_Clamp    = 1,
    eEColorSrcSwitchRepeat_PingPong = 2
};

// eCParticle_PS.CoordinateSystem

enum eECoordinateSystem {
    eECoordinateSystem_Independent = 0,
    eECoordinateSystem_Relative    = 1
};

// eCIlluminated_PS.DirectionalShadowType

enum eEDirectionalShadowType {
    eEDirectionalShadowType_Terrain  = 0,
    eEDirectionalShadowType_Building = 1,
    eEDirectionalShadowType_Object   = 2
};

// eCPointLight_PS.Effect

enum eEDynamicLightEffect {
    eEDynamicLightEffect_Steady  = 0,
    eEDynamicLightEffect_Pulse   = 1,
    eEDynamicLightEffect_Blink   = 2,
    eEDynamicLightEffect_Flicker = 3,
    eEDynamicLightEffect_Strobe  = 4
};

// eCEventFilter_PS.FireEventWhenDamaged
// eCEventFilter_PS.FireEventWhenIntersects
// eCEventFilter_PS.FireEventWhenTouched
// eCEventFilter_PS.FireEventWhenTriggered
// eCEventFilter_PS.FireEventWhenUntouched
// eCEventFilter_PS.FireEventWhenUntriggered
// eCTrigger_PS.LastEvent
// eCTrigger_PS.RunningEventType

enum eEEventType {
    eEEventType_None      = 0,
    eEEventType_Trigger   = 1,
    eEEventType_Untrigger = 2,
    eEEventType_Touch     = 3,
    eEEventType_Untouch   = 4,
    eEEventType_Intersect = 5,
    eEEventType_Damage    = 6
};

// eCParticle_PS.FacingDirection

enum eEFacingDirection {
    eEFacingDirection_FacingCamera              = 0,
    eEFacingDirection_AlongMovementFacingCamera = 1,
    eEFacingDirection_SpecifiedNormal           = 2,
    eEFacingDirection_AlongMovementFacingNormal = 3,
    eEFacingDirection_PerpendicularToMovement   = 4
};

// eCStrip_PS.FinalBlend

enum eEFinalBlend {
    eEFinalBlend_Overwrite     = 0,
    eEFinalBlend_AlphaBlend    = 1,
    eEFinalBlend_AlphaModulate = 2,
    eEFinalBlend_Modulate      = 3,
    eEFinalBlend_Translucent   = 4,
    eEFinalBlend_Darken        = 5,
    eEFinalBlend_Brighten      = 6,
    eEFinalBlend_Invisible     = 7
};

// eCForceField_PS.DirMode

enum eEForceFieldDirMode {
    eEForceFieldDirMode_Entity_AtVec        = 0,
    eEForceFieldDirMode_ShapeCenterOutside  = 1,
    eEForceFieldDirMode_ShapeCenterInside   = 2,
    eEForceFieldDirMode_EntityCenterOutside = 3,
    eEForceFieldDirMode_EntityCenterInside  = 4
};

// eCForceField_PS.DistanceScale

enum eEForceFieldDistanceScale {
    eEForceFieldDistanceScale_One    = 0,
    eEForceFieldDistanceScale_Linear = 1,
    eEForceFieldDistanceScale_Ease   = 2,
    eEForceFieldDistanceScale_Exp    = 3
};

// eCForceField_PS.Type

enum eEForceFieldType {
    eEForceFieldType_AddForce       = 0,
    eEForceFieldType_ChangeVelocity = 1
};

// eCJointDesc.Flag

enum eEJointFlag {
    eEJointFlag_None             = 0,
    eEJointFlag_CollisionEnabled = 1,
    eEJointFlag_Visualization    = 2
};

// eCSphericalJointDesc.JointProjectionMode

enum eEJointProjectionMode {
    eEJointProjectionMode_NONE          = 0,
    eEJointProjectionMode_POINT_MINDIST = 1
};

// eCParticle_PS.LightingStyle

enum eELightingStyle {
    eELightingStyle_Disabled = 0,
    eELightingStyle_Flat     = 1,
    eELightingStyle_Particle = 2,
    eELightingStyle_System   = 3
};

// eCVisualMeshBase_PS.LightmapAmbientOcclusion

enum eELightmapAmbientOcclusion {
    eELightmapAmbientOcclusion_None        = 0,
    eELightmapAmbientOcclusion_PerTriangle = 1,
    eELightmapAmbientOcclusion_PerVertex   = 2
};

// eCVisualMeshBase_PS.LightmapType

enum eELightmapType {
    eELightmapType_PerVertex = 0,
    eELightmapType_Mixed     = 1
};

// eCParticle_PS.StartLocation

enum eELocationShape {
    eELocationShape_Box    = 0,
    eELocationShape_Sphere = 1
};

// eCCollisionShape_PS.Range

enum eEPhysicRangeType {
    eEPhysicRangeType_World           = 0,
    eEPhysicRangeType_ProcessingRange = 1,
    eEPhysicRangeType_VisibilityRange = 2
};

// eCTrigger_PS.RecognizesPSType
// gCEffectCommandModifyEntity.PropertySet

enum eEPropertySetType {
    eEPropertySetType_Unknown                = 0,
    eEPropertySetType_Base                   = 1,
    eEPropertySetType_MeshVisual             = 2,
    eEPropertySetType_DummyVisual            = 3,
    eEPropertySetType_Advanced               = 4,
    eEPropertySetType_Navigation             = 5,
    eEPropertySetType_DynamicCollisionCircle = 6,
    eEPropertySetType_CollisionCircle        = 7,
    eEPropertySetType_NavZone                = 8,
    eEPropertySetType_NegZone                = 9,
    eEPropertySetType_NavPath                = 10,
    eEPropertySetType_PrefPath               = 11,
    eEPropertySetType_NavHelper              = 12,
    eEPropertySetType_RigidBody              = 13,
    eEPropertySetType_CollisionShape         = 14,
    eEPropertySetType_DynamicLight           = 15,
    eEPropertySetType_DirectionalLight       = 16,
    eEPropertySetType_PointLight             = 17,
    eEPropertySetType_SpotLight              = 18,
    eEPropertySetType_Hemisphere             = 19,
    eEPropertySetType_MovementBase           = 20,
    eEPropertySetType_CharacterMovement      = 21,
    eEPropertySetType_CharacterControl       = 22,
    eEPropertySetType_CharacterSensor        = 23,
    eEPropertySetType_CameraAI               = 24,
    eEPropertySetType_Editor                 = 25,
    eEPropertySetType_AIHelper               = 26,
    eEPropertySetType_AIHelperFreePoint      = 27,
    eEPropertySetType_AIHelperSpawnPoint     = 28,
    eEPropertySetType_AIHelperPlayerStart    = 29,
    eEPropertySetType_NPC                    = 30,
    eEPropertySetType_Inventory              = 31,
    eEPropertySetType_Clock                  = 32,
    eEPropertySetType_Effect                 = 33,
    eEPropertySetType_ParticleEffect         = 34,
    eEPropertySetType_EventFilter            = 35,
    eEPropertySetType_EventDebugger          = 36,
    eEPropertySetType_EventLogic             = 37,
    eEPropertySetType_EventScript            = 38,
    eEPropertySetType_Trigger                = 39,
    eEPropertySetType_TriggerList            = 40,
    eEPropertySetType_TriggerCombiner        = 41,
    eEPropertySetType_Skydome                = 42,
    eEPropertySetType_EditorVisual           = 43,
    eEPropertySetType_EngineCaps             = 44,
    eEPropertySetType_ScriptRoutine          = 45,
    eEPropertySetType_SpeedTree              = 46,
    eEPropertySetType_SpeedTreeWind          = 47,
    eEPropertySetType_Item                   = 48,
    eEPropertySetType_Interaction            = 49,
    eEPropertySetType_TouchDamage            = 50,
    eEPropertySetType_Damage                 = 51,
    eEPropertySetType_DamageReceiver         = 52,
    eEPropertySetType_QuestManager           = 53,
    eEPropertySetType_Quest                  = 54,
    eEPropertySetType_InfoManager            = 55,
    eEPropertySetType_Info                   = 56,
    eEPropertySetType_InfoScript             = 57,
    eEPropertySetType_InfoScriptLine         = 58,
    eEPropertySetType_Focus                  = 59,
    eEPropertySetType_PlayerMemory           = 60,
    eEPropertySetType_NavOffset              = 61,
    eEPropertySetType_Enclave                = 62,
    eEPropertySetType_Arena                  = 63,
    eEPropertySetType_Area                   = 64,
    eEPropertySetType_Vegetation             = 65,
    eEPropertySetType_VegetationBrush        = 66,
    eEPropertySetType_VegetationRubber       = 67,
    eEPropertySetType_Dialog                 = 68,
    eEPropertySetType_Lock                   = 69,
    eEPropertySetType_Door                   = 70,
    eEPropertySetType_StaticLight            = 71,
    eEPropertySetType_StaticPointLight       = 72,
    eEPropertySetType_StaticSpotLight        = 73,
    eEPropertySetType_Illuminated            = 74,
    eEPropertySetType_Statistics             = 75,
    eEPropertySetType_PhysicScene            = 76,
    eEPropertySetType_Party                  = 77,
    eEPropertySetType_Anchor                 = 78,
    eEPropertySetType_Letter                 = 79,
    eEPropertySetType_Book                   = 80,
    eEPropertySetType_Map                    = 81,
    eEPropertySetType_LinkContainer          = 82,
    eEPropertySetType_Projectile             = 83,
    eEPropertySetType_Sound                  = 84,
    eEPropertySetType_Strip                  = 85,
    eEPropertySetType_ForceField             = 86,
    eEPropertySetType_Particle               = 87,
    eEPropertySetType_ParticleSystem         = 88,
    eEPropertySetType_ParticleEmitter        = 89,
    eEPropertySetType_SpriteEmitter          = 90,
    eEPropertySetType_BeamEmitter            = 91,
    eEPropertySetType_SparkEmitter           = 92,
    eEPropertySetType_MeshEmitter            = 93,
    eEPropertySetType_AIZone                 = 94,
    eEPropertySetType_AudioEmitter           = 95,
    eEPropertySetType_Effect2                = 96,
    eEPropertySetType_LightStreaks           = 97,
    eEPropertySetType_WeatherZone            = 98,
    eEPropertySetType_Precipitation          = 99,
    eEPropertySetType_Animation              = 100,
    eEPropertySetType_Magic                  = 101,
    eEPropertySetType_Skill                  = 102,
    eEPropertySetType_Mover                  = 103,
    eEPropertySetType_Teleporter             = 104,
    eEPropertySetType_ArmorSet               = 105,
    // eEPropertySetType_??? = 106,
    eEPropertySetType_Flock           = 107,
    eEPropertySetType_TreasureSet     = 108,
    eEPropertySetType_Recipe          = 109,
    eEPropertySetType_WaterZone       = 110,
    eEPropertySetType_DistanceTrigger = 111,
    eEPropertySetType_TimeZone        = 112
};

// eCRigidBody_PS.BodyFlag

enum eERigidbody_Flag {
    // ???
};

// eCParticle_PS.RotationFrom

enum eERotationFrom {
    eERotationFrom_None   = 0,
    eERotationFrom_Entity = 1,
    eERotationFrom_Offset = 2,
    eERotationFrom_Normal = 3
};

// eCShaderBase.BlendMode

enum eEShaderMaterialBlendMode {
    eEShaderMaterialBlendMode_Normal        = 0,
    eEShaderMaterialBlendMode_Masked        = 1,
    eEShaderMaterialBlendMode_AlphaBlend    = 2,
    eEShaderMaterialBlendMode_Modulate      = 3,
    eEShaderMaterialBlendMode_AlphaModulate = 4,
    eEShaderMaterialBlendMode_Translucent   = 5,
    eEShaderMaterialBlendMode_Darken        = 6,
    eEShaderMaterialBlendMode_Brighten      = 7,
    eEShaderMaterialBlendMode_Invisible     = 8
};

// eCShaderDefault.TransformationType

enum eEShaderMaterialTransformation {
    eEShaderMaterialTransformation_Default       = 0,
    eEShaderMaterialTransformation_Instanced     = 1,
    eEShaderMaterialTransformation_Skinned       = 2,
    eEShaderMaterialTransformation_Tree_Branches = 3,
    eEShaderMaterialTransformation_Tree_Fronds   = 4,
    eEShaderMaterialTransformation_Tree_Leafs    = 5,
    eEShaderMaterialTransformation_Billboard     = 6
};

// eCShaderBase.MaxShaderVersion

enum eEShaderMaterialVersion {
    eEShaderMaterialVersion_1_1 = 0,
    eEShaderMaterialVersion_1_4 = 1,
    eEShaderMaterialVersion_2_0 = 2,
    eEShaderMaterialVersion_3_0 = 3
};

// eCCollisionShape.ShapeAABBAdapt

enum eEShapeAABBAdapt {
    eEShapeAABBAdapt_None      = 0,
    eEShapeAABBAdapt_LocalNode = 1,
    eEShapeAABBAdapt_LocalTree = 2
};

// eCCollisionShape.Group
// eCVisualAnimation_PS.BoneShapeGroup

enum eEShapeGroup {
    eEShapeGroup_Undefined         = 0,
    eEShapeGroup_Static            = 1,
    eEShapeGroup_Dynamic           = 2,
    eEShapeGroup_Shield            = 3,
    eEShapeGroup_MeleeWeapon       = 4,
    eEShapeGroup_Projectile        = 5,
    eEShapeGroup_Movement          = 6,
    eEShapeGroup_WeaponTrigger     = 7,
    eEShapeGroup_ParadeSphere      = 8,
    eEShapeGroup_Tree_Trunk        = 9,
    eEShapeGroup_Tree_Branches     = 10,
    eEShapeGroup_Camera            = 11,
    eEShapeGroup_Movement_ZoneNPC  = 12,
    eEShapeGroup_HeightRepulsor    = 13,
    eEShapeGroup_Cloth             = 14,
    eEShapeGroup_PhysicalBodyPart  = 15,
    eEShapeGroup_KeyframedBodyPart = 16,
    eEShapeGroup_Camera_Obstacle   = 17,
    eEShapeGroup_Projectile_Level  = 18,
    eEShapeGroup_Trigger           = 19,
    eEShapeGroup_Door              = 20
};

// eCCollisionShape.Material
// eCResourceShaderMaterial_PS.PhysicMaterial
// eCVisualAnimation_PS.BoneShapeMaterial

enum eEShapeMaterial {
    eEShapeMaterial_None             = 0,
    eEShapeMaterial_Wood             = 1,
    eEShapeMaterial_Metal            = 2,
    eEShapeMaterial_Water            = 3,
    eEShapeMaterial_Stone            = 4,
    eEShapeMaterial_Earth            = 5,
    eEShapeMaterial_Ice              = 6,
    eEShapeMaterial_Leather          = 7,
    eEShapeMaterial_Clay             = 8,
    eEShapeMaterial_Glass            = 9,
    eEShapeMaterial_Flesh            = 10,
    eEShapeMaterial_Snow             = 11,
    eEShapeMaterial_Debris           = 12,
    eEShapeMaterial_Foliage          = 13,
    eEShapeMaterial_Magic            = 14,
    eEShapeMaterial_Grass            = 15,
    eEShapeMaterial_SpringAndDamper1 = 16,
    eEShapeMaterial_SpringAndDamper2 = 17,
    eEShapeMaterial_SpringAndDamper3 = 18,
    eEShapeMaterial_Damage           = 19,
    eEShapeMaterial_Sand             = 20,
    eEShapeMaterial_Movement         = 21
};

// eCResourceSound_PS.LoopMode

enum eESoundLoopMode {
    eESoundLoopMode_Off      = 0,
    eESoundLoopMode_Normal   = 1,
    eESoundLoopMode_PingPong = 2
};

// eCParticle_PS.SpawningSound

enum eESpawningSound {
    eESpawningSound_Disabled     = 0,
    eESpawningSound_LinearLocal  = 1,
    eESpawningSound_LinearGlobal = 2,
    eESpawningSound_Random       = 3
};

// eCIlluminated_PS.StaticIlluminated

enum eEStaticIlluminated {
    eEStaticIlluminated_Static  = 0,
    eEStaticIlluminated_Dynamic = 1
};

// eCVisualMeshBase_PS.StaticLightingType

enum eEStaticLighingType {
    eEStaticLighingType_Lightmap = 0,
    eEStaticLighingType_Instance = 1
};

// eCStrip_PS.Spawning

enum eEStripSpawning {
    eEStripSpawning_Continuous = 0,
    eEStripSpawning_Movement   = 1,
    eEStripSpawning_Timed      = 2
};

// eCTexCoordSrcOscillator.OscillatorTypeU
// eCTexCoordSrcOscillator.OscillatorTypeV

enum eETexCoordSrcOscillatorType {
    eETexCoordSrcOscillatorType_Pan           = 0,
    eETexCoordSrcOscillatorType_Stretch       = 1,
    eETexCoordSrcOscillatorType_StretchRepeat = 2,
    eETexCoordSrcOscillatorType_Jitter        = 3
};

// eCTexCoordSrcRotator.RotationType

enum eETexCoordSrcRotatorType {
    eETexCoordSrcRotatorType_Once      = 0,
    eETexCoordSrcRotatorType_Constant  = 1,
    eETexCoordSrcRotatorType_Oscillate = 2
};

// eCParticle_PS.DrawStyle

enum eETextureDrawStyle {
    eETextureDrawStyle_Regular       = 0,
    eETextureDrawStyle_AlphaBlend    = 1,
    eETextureDrawStyle_Modulated     = 2,
    eETextureDrawStyle_Translucent   = 3,
    eETextureDrawStyle_AlphaModulate = 4,
    eETextureDrawStyle_Darken        = 5,
    eETextureDrawStyle_Brighten      = 6,
    eETextureDrawStyle_Invisible     = 7
};

// eCTriggerList_PS.ProcessType

enum eETriggerListProcessType {
    eETriggerListProcessType_All      = 0,
    eETriggerListProcessType_NextOne  = 1,
    eETriggerListProcessType_Rand_One = 2
};

// eCVegetationBrush_PS.ColorFunction

enum eEVegetationBrushColorFunction {
    // eEVegetationBrushColorFunction_??? = 0,
    eEVegetationBrushColorFunction_Random                         = 1,
    eEVegetationBrushColorFunction_PerlinNoise                    = 2,
    eEVegetationBrushColorFunction_PerlinNoise_Improved           = 3,
    eEVegetationBrushColorFunction_EbertNoise                     = 4,
    eEVegetationBrushColorFunction_PeacheyNoise                   = 5,
    eEVegetationBrushColorFunction_PeacheyNoise_Gradient          = 6,
    eEVegetationBrushColorFunction_PeacheyNoise_GradientValue     = 7,
    eEVegetationBrushColorFunction_PeacheyNoise_SparseConvolusion = 8,
    eEVegetationBrushColorFunction_PeacheyNoise_ValueConvolusion  = 9
};

// eCVegetationBrush_PS.BrushMode

enum eEVegetationBrushMode {
    eEVegetationBrushMode_Place  = 0,
    eEVegetationBrushMode_Remove = 1
};

// eCVegetationBrush_PS.BrushPlacement

enum eEVegetationBrushPlace {
    eEVegetationBrushPlace_DistanceSelf  = 0,
    eEVegetationBrushPlace_DistanceOther = 1,
    eEVegetationBrushPlace_RemoveOther   = 2
};

// eCVegetationBrush_PS.ProbabilityFunction

enum eEVegetationBrushProbabilityFunction {
    eEVegetationBrushProbabilityFunction_None                           = 0,
    eEVegetationBrushProbabilityFunction_Shape                          = 1,
    eEVegetationBrushProbabilityFunction_PerlinNoise                    = 2,
    eEVegetationBrushProbabilityFunction_PerlinNoise_Improved           = 3,
    eEVegetationBrushProbabilityFunction_EbertNoise                     = 4,
    eEVegetationBrushProbabilityFunction_PeacheyNoise                   = 5,
    eEVegetationBrushProbabilityFunction_PeacheyNoise_Gradient          = 6,
    eEVegetationBrushProbabilityFunction_PeacheyNoise_GradientValue     = 7,
    eEVegetationBrushProbabilityFunction_PeacheyNoise_SparseConvolusion = 8,
    eEVegetationBrushProbabilityFunction_PeacheyNoise_ValueConvolusion  = 9
};

// eCVegetationBrush_PS.BrushShape

enum eEVegetationBrushShape {
    eEVegetationBrushShape_Circle = 0,
    eEVegetationBrushShape_Rect   = 1,
    eEVegetationBrushShape_Single = 2
};

// eCVegetation_Mesh.MeshShading

enum eEVegetationMeshShading {
    eEVegetationMeshShading_MeshNormal       = 0,
    eEVegetationMeshShading_EntryOrientation = 1
};

// eCParticle_PS.VelocityDirectionFrom

enum eEVelocityDirectionFrom {
    eEVelocityDirectionFrom_None                  = 0,
    eEVelocityDirectionFrom_StartPositionAndOwner = 1,
    eEVelocityDirectionFrom_OwnerAndStartPosition = 2
};

// eCWeatherZone_PS.AmbientBackLightOverwrite
// eCWeatherZone_PS.AmbientGeneralOverwrite
// eCWeatherZone_PS.AmbientIntensityOverwrite
// eCWeatherZone_PS.CloudColorOverwrite
// eCWeatherZone_PS.CloudThicknessOverwrite
// eCWeatherZone_PS.FogColorOverwrite
// eCWeatherZone_PS.FogEndOverwrite
// eCWeatherZone_PS.FogStartOverwrite
// eCWeatherZone_PS.HazeColorOverwrite
// eCWeatherZone_PS.LightDiffuseOverwrite
// eCWeatherZone_PS.LightIntensityOverwrite
// eCWeatherZone_PS.LightSpecularOverwrite
// eCWeatherZone_PS.SkyColorOverwrite

enum eEWeatherZoneOverwrite {
    eEWeatherZoneOverwrite_None      = 0,
    eEWeatherZoneOverwrite_Overwrite = 1,
    eEWeatherZoneOverwrite_Modulate  = 2,
    eEWeatherZoneOverwrite_Add       = 3
};

// eCWeatherZone_PS.Shape

enum eEWeatherZoneShape
{
    eEWeatherZoneShape_2D_Circle = 0,
    eEWeatherZoneShape_2D_Rect   = 1,
    eEWeatherZoneShape_3D_Sphere = 2,
    eEWeatherZoneShape_3D_Box    = 3
};

enum eEVertexStreamArrayType
{
    /*
     * Faces / Triangles
     */
    eEVertexStreamArrayType_Face = 0,
    /*
     * Vertex format includes the position of an untransformed vertex. (D3DFVF_XYZ) (bCVector3)
     */
    eEVertexStreamArrayType_VertexPosition = 1,
    /*
     * Vertex format includes the position of a transformed vertex. (D3DFVF_XYZRHW) (bCVector4)
     */
    eEVertexStreamArrayType_VertexPositionTransformed = 2,
    /*
     * Vertex format includes a vertex normal vector. (D3DFVF_NORMAL) (bCVector3)
     */
    eEVertexStreamArrayType_Normal = 3,
    /*
     * Vertex format includes a diffuse color component. (D3DFVF_DIFFUSE) (DWORD in ARGB order)
     * <p>
     * Bi-Tangent Heading (G3MC Manual) - 00FF0000
     * <p>
     * Texture Fading (G3MC)
     */
    eEVertexStreamArrayType_Diffuse = 4,
    /*
     * Vertex format includes a specular color component. (D3DFVF_SPECULAR) (DWORD in ARGB
     * order)
     * <p>
     * ? (G3MC Manual) - FF000000
     * <p>
     * "eCTexCoordSrcBumpOffset::GetImplementation - No color source for height set!"
     * <p>
     * "eCTexCoordSrcBumpOffset::GetImplementation - Invalid color source component. Color
     * component forced to alpha!"
     */
    eEVertexStreamArrayType_Specular = 5,
    /*
     * Vertex format specified in point size. This size is expressed in camera space units for
     * vertices that are not transformed and lit, and in device-space units for transformed and
     * lit vertices. (D3DFVF_PSIZE) (GEFloat)
     */
    eEVertexStreamArrayType_PointSize = 6,
    /*
     * Vertex format contains position data, and a corresponding number of weighting (beta)
     * values to use for multimatrix vertex blending operations. (D3DFVF_XYZB1 through
     * D3DFVF_XYZB5) (GEFloat)
     */
    eEVertexStreamArrayType_XYZB1             = 7,
    eEVertexStreamArrayType_XYZB2             = 8,
    eEVertexStreamArrayType_XYZB3             = 9,
    eEVertexStreamArrayType_XYZB4             = 10,
    eEVertexStreamArrayType_XYZB5             = 11,
    eEVertexStreamArrayType_TextureCoordinate = 12,
    eEVertexStreamArrayType_13                = 13,
    eEVertexStreamArrayType_14                = 14,
    /*
     * Water Reflections (G3MC)
     */
    eEVertexStreamArrayType_15 = 15,
    eEVertexStreamArrayType_16 = 16,
    eEVertexStreamArrayType_17 = 17,
    eEVertexStreamArrayType_18 = 18,
    eEVertexStreamArrayType_19 = 19,
    eEVertexStreamArrayType_20 = 20,
    eEVertexStreamArrayType_21 = 21,
    eEVertexStreamArrayType_22 = 22,
    eEVertexStreamArrayType_23 = 23,
    eEVertexStreamArrayType_24 = 24,
    eEVertexStreamArrayType_25 = 25,
    eEVertexStreamArrayType_26 = 26,
    eEVertexStreamArrayType_27 = 27,
    eEVertexStreamArrayType_28 = 28,
    eEVertexStreamArrayType_29 = 29,
    eEVertexStreamArrayType_30 = 30,
    eEVertexStreamArrayType_31 = 31,
    eEVertexStreamArrayType_32 = 32,
    eEVertexStreamArrayType_33 = 33,
    eEVertexStreamArrayType_34 = 34,
    eEVertexStreamArrayType_35 = 35,
    eEVertexStreamArrayType_36 = 36,
    eEVertexStreamArrayType_37 = 37,
    eEVertexStreamArrayType_38 = 38,
    eEVertexStreamArrayType_39 = 39,
    eEVertexStreamArrayType_40 = 40,
    eEVertexStreamArrayType_41 = 41,
    eEVertexStreamArrayType_42 = 42,
    eEVertexStreamArrayType_43 = 43,
    eEVertexStreamArrayType_44 = 44,
    eEVertexStreamArrayType_45 = 45,
    eEVertexStreamArrayType_46 = 46,
    eEVertexStreamArrayType_47 = 47,
    eEVertexStreamArrayType_48 = 48,
    eEVertexStreamArrayType_49 = 49,
    eEVertexStreamArrayType_50 = 50,
    eEVertexStreamArrayType_51 = 51,
    eEVertexStreamArrayType_52 = 52,
    eEVertexStreamArrayType_53 = 53,
    eEVertexStreamArrayType_54 = 54,
    eEVertexStreamArrayType_55 = 55,
    eEVertexStreamArrayType_56 = 56,
    eEVertexStreamArrayType_57 = 57,
    eEVertexStreamArrayType_58 = 58,
    eEVertexStreamArrayType_59 = 59,
    eEVertexStreamArrayType_60 = 60,
    eEVertexStreamArrayType_61 = 61,
    eEVertexStreamArrayType_62 = 62,
    eEVertexStreamArrayType_63 = 63,
    /**
     * Tangent Vector (G3MC Manual)
     */
    eEVertexStreamArrayType_64               = 64,
    eEVertexStreamArrayType_65               = 65,
    eEVertexStreamArrayType_66               = 66,
    eEVertexStreamArrayType_67               = 67,
    eEVertexStreamArrayType_68               = 68,
    eEVertexStreamArrayType_69               = 69,
    eEVertexStreamArrayType_70               = 70,
    eEVertexStreamArrayType_71               = 71,
    eEVertexStreamArrayType_72               = 72,
    eEVertexStreamArrayType_UVLightmapGroups = 73,
};

#endif
