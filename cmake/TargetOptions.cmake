include(CheckCXXCompilerFlag)
include(CheckLinkerFlag)

# Not supported by clang.
check_cxx_compiler_flag("/d1trimfile:${PROJECT_SOURCE_DIR}/" CXX_HAS_D1TRIMFILE)

# Not supported by old clang-lld
check_linker_flag(CXX "LINKER:/RELEASE" LINKER_HAS_RELEASE)
# Not supported by old clang-lld
check_linker_flag(CXX "LINKER:/LTCG" LINKER_HAS_LTCG)

# Common options for both libs and scripts
function(target_gothic_common_options TARGET)
  # Compile options
  set(COMMON_COMPILE_OPTIONS_DEBUG
    # BasicRuntimeChecks = EnableFastChecks
    "/RTC1"
    # Optimization = Disabled
    "/Od"
    # RuntimeLibrary = MultiThreadedDebug (set via CMAKE_MSVC_RUNTIME_LIBRARY)
    "/MTd"
  )

  set(COMMON_COMPILE_OPTIONS_RELEASE
    # BufferSecurityCheck = false
    "/GS-"
    # ExceptionHandling = No (C++ exception not enabled, only SEH)
    # /EH not set -> Default exception handling behavior (see https://learn.microsoft.com/en-us/cpp/build/reference/eh-exception-handling-model?view=msvc-170#default-exception-handling-behavior)
    # Optimization = MaxSpeed
    "/O2"
    # PreprocessorDefinitions = NDEBUG;%(PreprocessorDefinitions)
    "/D NDEBUG"
    # RuntimeLibrary = MultiThreaded (set via CMAKE_MSVC_RUNTIME_LIBRARY)
    "/MT"
    # StringPooling = true
    "/GF"
    # WholeProgramOptimization = true
    "/GL"
  )

  set(COMMON_COMPILE_OPTIONS_CLANG_CL
    # NOTE: Need to enable AVX2 and LZCNT so that clang accepts _m256i
    #       intrinsics, but that also implicates that the compiler itself may
    #       use these instructions, making the generated code incompatible with
    #       old CPUs.
    "-mavx2"
    "-mlzcnt"

    # Clangd needs -m32 in the clang-cl command line!
    "-m32"

    # Disable noisy warnings.
    "-Wno-microsoft-enum-forward-reference"
    "-Wno-invalid-offsetof"

    # Required for offsetof to work with clang-cl (see https://github.com/llvm/llvm-project/issues/59689).
    "/D _CRT_USE_BUILTIN_OFFSETOF"
  )

  set(COMMON_COMPILE_OPTIONS
    # CallingConvention = StdCall
    "$<IF:$<BOOL:${G3SDK_USE_STDCALL}>,/Gz,/Gd>"
    # DebugInformationFormat = ProgramDatabase
    "/Zi"
    # EnableEnhancedInstructionSet = StreamingSIMDExtensions2
    "/arch:SSE2"
    # FunctionLevelLinking = true
    "/Gy"
    # MinimalRebuild = false
    "/Gm-"
    # WarningLevel = Level4
    "/W4"
    # MultiProcessorCompilation = true
    "/MP"
    # LanguageStandard = stdcpp17
    #"/std:c++17"
    # Set via target_compile_features() below.

    # Enable preprocessor conformance mode
    "/Zc:preprocessor"
    # UseFullPaths = false
    "$<$<BOOL:${CXX_HAS_D1TRIMFILE}>:/d1trimfile:${CMAKE_BINARY_DIR}/>"
    "$<$<BOOL:${CXX_HAS_D1TRIMFILE}>:/d1trimfile:${PROJECT_SOURCE_DIR}/>"
    "$<$<BOOL:${CXX_HAS_D1TRIMFILE}>:/d1trimfile:${G3SDK_SOURCE_DIR}/>"

    # DisableSpecificWarnings
    "/wd4251" # class 'TEMPLATE' needs to have dll-interface to be used by clients of class '...'
    "/wd4275" # non dll-interface class '...' used as base for dll-interface class '...'

    "/D _CRT_SECURE_NO_WARNINGS"

    "$<$<BOOL:${G3SDK_TARGET_COMPILER_CLANG_CL}>:${COMMON_COMPILE_OPTIONS_CLANG_CL}>"

    # Include config specific options
    $<IF:$<CONFIG:Debug>,${COMMON_COMPILE_OPTIONS_DEBUG},${COMMON_COMPILE_OPTIONS_RELEASE}>
  )

  target_compile_options("${TARGET}" PRIVATE "${COMMON_COMPILE_OPTIONS}")

  target_compile_features("${TARGET}" PRIVATE cxx_std_17)

  # Link options
  set(COMMON_LINK_OPTIONS_RELEASE
    # EnableCOMDATFolding = true
    "/OPT:ICF"
    # OptimizeReferences = true
    "/OPT:REF"
    # SetChecksum = true
    "$<$<BOOL:${LINKER_HAS_RELEASE}>:/RELEASE>"
    # LinkTimeCodeGeneration = UseLinkTimeCodeGeneration
    "$<$<BOOL:${LINKER_HAS_LTCG}>:/LTCG>"
  )

  set(COMMON_LINK_OPTIONS
    # GenerateDebugInformation = true
    "/DEBUG:FULL"
    # TargetMachine = MachineX86
    "/MACHINE:X86"
    # AdditionalOptions = /pdbaltpath:%_PDB%
    # NOTE: Cannot specify % here, gets escaped to %%, so instead use TARGET_PDB_FILE_NAME.
    "/pdbaltpath:$<TARGET_PDB_FILE_NAME:${TARGET}>"

    # Include config specific options
    $<IF:$<CONFIG:Debug>,${COMMON_LINK_OPTIONS_DEBUG},${COMMON_LINK_OPTIONS_RELEASE}>
  )

  target_link_options("${TARGET}" PRIVATE "${COMMON_LINK_OPTIONS}")
endfunction()

# Libs
function(target_gothic_lib_options TARGET)
  target_gothic_common_options("${TARGET}")

  set(LIB_COMPILE_OPTIONS_DEBUG
    # PreprocessorDefinitions = GE_DEBUG;%(PreprocessorDefinitions)
    "/D GE_DEBUG"
  )

  # GothicLib.props
  set(LIB_COMPILE_OPTIONS

    # Include config specific options
    $<IF:$<CONFIG:Debug>,${LIB_COMPILE_OPTIONS_DEBUG},${LIB_COMPILE_OPTIONS_RELEASE}>
  )

  target_compile_options("${TARGET}" PRIVATE "${LIB_COMPILE_OPTIONS}")

  # Link options
  set(LIB_LINK_OPTIONS)

  target_link_options("${TARGET}" PRIVATE "${LIB_LINK_OPTIONS}")
endfunction()

# Scripts
function(target_gothic_script_options TARGET)
  target_gothic_lib_options("${TARGET}")

  set(SCRIPT_COMPILE_OPTIONS
    "/D TARGET_FILE_NAME=$<TARGET_FILE_NAME:${TARGET}>"

    # Include config specific options
    $<IF:$<CONFIG:Debug>,${SCRIPT_COMPILE_OPTIONS_DEBUG},${SCRIPT_COMPILE_OPTIONS_RELEASE}>
  )

  target_compile_options("${TARGET}" PRIVATE "${SCRIPT_COMPILE_OPTIONS}")

  # Link options
  set(SCRIPT_LINK_OPTIONS)

  target_link_options("${TARGET}" PRIVATE "${SCRIPT_LINK_OPTIONS}")
endfunction()
