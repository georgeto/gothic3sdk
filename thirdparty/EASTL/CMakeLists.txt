CPMAddPackage(
  NAME EASTL
  GITHUB_REPOSITORY electronicarts/EASTL
  GIT_TAG e757b44f712902a78fe22886842eaba25e0a7797 # 3.21.12
  PATCH_COMMAND git checkout -q .
  COMMAND git apply --ignore-whitespace --whitespace=nowarn ${CMAKE_CURRENT_LIST_DIR}/patch/intrinsic-cdecl.patch
  COMMAND git apply --ignore-whitespace --whitespace=nowarn ${CMAKE_CURRENT_LIST_DIR}/patch/target-use-keyword.patch
  # Submdoules are only used for tests, we do not care for them.
  GIT_SUBMODULES ".gitignore" # Workaround for deficiency in CPM, should be ""
  GIT_SHALLOW YES
)

# We define a custom allocator, which uses Gothic 3's memory allocator.
target_compile_definitions(EASTL PUBLIC EASTL_USER_DEFINED_ALLOCATOR)
target_sources(EASTL PRIVATE src/allocator.cpp)

# When compiling for MSVC, EASTL sets /permissive-, but some parts of
# SharedBase.h are not compatible with it (yet), so force /permissive.
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set_source_files_properties(src/allocator.cpp
    TARGET_DIRECTORY EASTL
    PROPERTIES COMPILE_FLAGS /permissive
  )
endif()

target_gothic_lib_options(EASTL)

target_link_libraries(EASTL PRIVATE SharedBase)
