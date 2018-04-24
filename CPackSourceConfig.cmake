# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_ALL_INSTALL_TYPES "Minimal;Full")
SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "OFF")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_FREEBSD "OFF")
SET(CPACK_BINARY_IFW "OFF")
SET(CPACK_BINARY_NSIS "OFF")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_PRODUCTBUILD "")
SET(CPACK_BINARY_RPM "OFF")
SET(CPACK_BINARY_STGZ "ON")
SET(CPACK_BINARY_TBZ2 "OFF")
SET(CPACK_BINARY_TGZ "ON")
SET(CPACK_BINARY_TXZ "OFF")
SET(CPACK_BINARY_TZ "ON")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_BUILD_SOURCE_DIRS "/home/eduard/programming/PeakFinder;/home/eduard/programming/PeakFinder")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENTS_ALL "libraries;test;examples")
SET(CPACK_COMPONENTS_ALL_SET_BY_USER "TRUE")
SET(CPACK_COMPONENT_EXAMPLES_DESCRIPTION "Evolving Objects examples")
SET(CPACK_COMPONENT_EXAMPLES_DISPLAY_NAME "Evolving Objects")
SET(CPACK_COMPONENT_EXAMPLES_GROUP "Devel")
SET(CPACK_COMPONENT_EXAMPLES_INSTALL_TYPES "Full")
SET(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Evolving Objects library")
SET(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Evolving Objects")
SET(CPACK_COMPONENT_LIBRARIES_GROUP "Devel")
SET(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES "Minimal;Full")
SET(CPACK_COMPONENT_TEST_DESCRIPTION "Evolving Objects test")
SET(CPACK_COMPONENT_TEST_DISPLAY_NAME "Evolving Objects")
SET(CPACK_COMPONENT_TEST_GROUP "Devel")
SET(CPACK_COMPONENT_TEST_INSTALL_TYPES "Full")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6, libgcc1, libc6, g++")
SET(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
SET(CPACK_DEBIAN_PACKAGE_SECTION "devel")
SET(CPACK_GENERATOR "TBZ2;TGZ;TXZ;TZ")
SET(CPACK_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_INSTALLED_DIRECTORIES "/home/eduard/programming/PeakFinder;/")
SET(CPACK_INSTALL_CMAKE_PROJECTS "")
SET(CPACK_INSTALL_PREFIX "/usr/local")
SET(CPACK_MODULE_PATH "")
SET(CPACK_NSIS_DISPLAY_NAME "EO 1.3")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_PACKAGE_NAME "EO 1.3")
SET(CPACK_OUTPUT_CONFIG_FILE "/home/eduard/programming/PeakFinder/CPackConfig.cmake")
SET(CPACK_PACKAGE_CONTACT "eodev-help@sourceforge.net")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION "Evolving Objects")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/home/eduard/programming/PeakFinder/dep/eo/README")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Evolving Objects")
SET(CPACK_PACKAGE_EXECUTABLES "EO;EO")
SET(CPACK_PACKAGE_FILE_NAME "Project-1.3.0-Source")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "EO 1.3")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "EO 1.3")
SET(CPACK_PACKAGE_NAME "Project")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "Evolving Objects")
SET(CPACK_PACKAGE_VERSION "1.3.0")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "3")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_RESOURCE_FILE_LICENSE "/home/eduard/programming/PeakFinder/dep/eo/LICENSE")
SET(CPACK_RESOURCE_FILE_README "/usr/share/cmake-3.10/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.10/Templates/CPack.GenericWelcome.txt")
SET(CPACK_RPM_PACKAGE_SOURCES "ON")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
SET(CPACK_SOURCE_IGNORE_FILES "/CVS/;/\\.svn/;/\\.bzr/;/\\.hg/;/\\.git/;\\.swp\$;\\.#;/#")
SET(CPACK_SOURCE_INSTALLED_DIRECTORIES "/home/eduard/programming/PeakFinder;/")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/eduard/programming/PeakFinder/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "Project-1.3.0-Source")
SET(CPACK_SOURCE_RPM "OFF")
SET(CPACK_SOURCE_STRIP_FILES "bin/EO")
SET(CPACK_SOURCE_TBZ2 "ON")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_SOURCE_TXZ "ON")
SET(CPACK_SOURCE_TZ "ON")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_STRIP_FILES "bin/EO")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux-Source")
SET(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/eduard/programming/PeakFinder/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
