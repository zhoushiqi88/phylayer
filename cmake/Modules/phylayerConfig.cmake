INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_PHYLAYER phylayer)

FIND_PATH(
    PHYLAYER_INCLUDE_DIRS
    NAMES phylayer/api.h
    HINTS $ENV{PHYLAYER_DIR}/include
        ${PC_PHYLAYER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PHYLAYER_LIBRARIES
    NAMES gnuradio-phylayer
    HINTS $ENV{PHYLAYER_DIR}/lib
        ${PC_PHYLAYER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PHYLAYER DEFAULT_MSG PHYLAYER_LIBRARIES PHYLAYER_INCLUDE_DIRS)
MARK_AS_ADVANCED(PHYLAYER_LIBRARIES PHYLAYER_INCLUDE_DIRS)

