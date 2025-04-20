CPMAddPackage(
  NAME dl_asmjit
  GITHUB_REPOSITORY asmjit/asmjit
  GIT_TAG 45b01147814594cca69d6cb9d93ed9eb049243cf
  DOWNLOAD_ONLY YES
)

CPMAddPackage(
  NAME asmtk
  OPTIONS
    # Asmjit
    "ASMJIT_STATIC YES"
    "ASMJIT_NO_AARCH32 YES"
    "ASMJIT_NO_AARCH64 YES"
    "ASMJIT_NO_BUILDER YES"
    "ASMJIT_NO_COMPILER YES"
    "ASMJIT_NO_INTROSPECTION YES"

    # Asmtk
    "ASMJIT_DIR ${dl_asmjit_SOURCE_DIR}"
    "ASMTK_STATIC YES"
    # Make CPM FindXYZ.cmake available to dependencies.
    "CMAKE_INCLUDE_PATH ${asmjit_SOURCE_DIR}/src"
  GITHUB_REPOSITORY asmjit/asmtk
  GIT_TAG 425b108d3afe510f8b94ca5523cd31ae29381422
)

target_gothic_lib_options(asmjit)
target_gothic_lib_options(asmtk)
