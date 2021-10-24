# import os
# import platform
# import subprocess
# import sys
#
# from setuptools import setup, Extension
# from setuptools.command.build_ext import build_ext
#
#
# # https://martinopilia.com/posts/2018/09/15/building-python-extension.html
# class CMakeExtension(Extension):
#     def __init__(self, name, cmake_lists_dir='.', **kwa):
#         Extension.__init__(self, name, sources=[], **kwa)
#         self.cmake_lists_dir = os.path.abspath(cmake_lists_dir)
#
#
# cmake = "/Users/tomaszslazak/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.4746.93/CLion.app/Contents/bin/cmake/mac/bin/cmake"
# cfg = "Release"
#
#
# class cmake_build_ext(build_ext):
#     def build_extensions(self):
#         # Ensure that CMake is present and working
#         try:
#             out = subprocess.check_output([cmake, '--version'])
#         except OSError:
#             raise RuntimeError('Cannot find CMake executable')
#
#         for ext in self.extensions:
#
#             extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
#
#             cmake_args = [
#                 '-DCMAKE_BUILD_TYPE=%s' % cfg,
#                 # Ask CMake to place the resulting library in the directory
#                 # containing the extension
#                 '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir),
#                 # Other intermediate static libraries are placed in a
#                 # temporary build directory instead
#                 '-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), self.build_temp),
#                 # Hint CMake to use the same Python executable that
#                 # is launching the build, prevents possible mismatching if
#                 # multiple versions of Python are installed
#                 '-DPYTHON_EXECUTABLE={}'.format(sys.executable),
#                 # Add other project-specific CMake arguments if needed
#                 # ...
#             ]
#
#             # We can handle some platform-specific settings at our discretion
#             if platform.system() == 'Windows':
#                 plat = ('x64' if platform.architecture()[0] == '64bit' else 'Win32')
#                 cmake_args += [
#                     # These options are likely to be needed under Windows
#                     '-DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE',
#                     '-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir),
#                 ]
#                 # Assuming that Visual Studio and MinGW are supported compilers
#                 if self.compiler.compiler_type == 'msvc':
#                     cmake_args += [
#                         '-DCMAKE_GENERATOR_PLATFORM=%s' % plat,
#                     ]
#                 else:
#                     cmake_args += [
#                         '-G', 'MinGW Makefiles',
#                     ]
#
#             # cmake_args += cmake_cmd_args
#
#             if not os.path.exists(self.build_temp):
#                 os.makedirs(self.build_temp)
#
#             # Config
#             subprocess.check_call([cmake, ext.cmake_lists_dir] + cmake_args,
#                                   cwd=self.build_temp)
#
#             # Build
#             subprocess.check_call([cmake, '--build', '.', '--config', cfg],
#                                   cwd=self.build_temp)
#
#
# setup(name="enginet",
#       version="0.1",
#       ext_modules=[CMakeExtension("enginet")],
#       cmdclass={'build_ext': cmake_build_ext},
#       )

from skbuild import setup

setup(
    name="python-enginet",
    version="0.1.2",
    author="Tomasz Ślązak",
    license="MIT",
    packages=['pyenginet']
)
