CPMAddPackage(
  NAME EABase
  GITHUB_REPOSITORY electronicarts/EABase
  GIT_TAG 521cb053d9320636f53226ffc616216cf532f0ef
  # Submdoules are only used for tests, we do not care for them.
  GIT_SUBMODULES ".gitignore" # Workaround for deficiency in CPM, should be ""
)
