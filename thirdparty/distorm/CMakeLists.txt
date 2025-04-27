CPMAddPackage(
  NAME distorm
  GITHUB_REPOSITORY gdabah/distorm
  GIT_TAG 39de02a118f95e254550a944843ee69f721c79d9 # v3.4.1
  PATCH_COMMAND git checkout -q .
  COMMAND git apply --ignore-whitespace --whitespace=nowarn ${CMAKE_CURRENT_LIST_DIR}/patch/fix-asmtk.patch
  GIT_SHALLOW YES
  DOWNLOAD_ONLY YES
)

add_library(distorm STATIC)

target_gothic_lib_options(distorm)

target_compile_definitions(distorm PRIVATE DISTORM_STATIC SUPPORT_64BIT_OFFSET)

target_include_directories(distorm INTERFACE ${distorm_SOURCE_DIR}/include)

# libprotobuf-lite
target_tree_sources(distorm
    ROOT ${distorm_SOURCE_DIR}
    BASE ${distorm_SOURCE_DIR}/include
    PRIVATE
      distorm.h
      mnemonics.h

    BASE ${distorm_SOURCE_DIR}/src
    PRIVATE
      config.h
      decoder.c
      decoder.h
      distorm.c
      instructions.c
      instructions.h
      insts.c
      insts.h
      mnemonics.c
      operands.c
      operands.h
      prefix.c
      prefix.h
      textdefs.c
      textdefs.h
      wstring.c
      wstring.h
      x86defs.h
)
