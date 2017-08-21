#!/usr/bin/python

import os

try:
    from setuptools import setup, Extension
except ImportError:
    print "WARNING: SetupTools Error, Falling back to DistUtils"
    from distutils.core import setup, Extension

from PyMulator import __version__

arm_thumb_dir =  '../simulator/core/isa/arm-thumb/' 
arm_thumb_files = map(lambda y: arm_thumb_dir+y, filter(lambda x: '.c' in x, os.listdir(arm_thumb_dir)))
operations_dir = '../simulator/core/operations/'
operations_files = map(lambda y: operations_dir+y, 
                    filter(lambda x: '.c' in x, os.listdir(operations_dir)))

# the c++ extension module
extension_mod = Extension(
    name = "PyMulatorC", 
    define_macros = [ ('M_PROFILE', None) ],
    include_dirs = ['../simulator/', './PyMulator'],
    sources = [   
        "PyMulator/PyMulatorModuleC.c",

        "PyMulator/csrc/core.c",
        "PyMulator/csrc/extra.c",
        "PyMulator/csrc/exception.c",
        "PyMulator/csrc/helpers.c",
        "PyMulator/csrc/interface.c",
        "PyMulator/csrc/interrupts.c",
        "PyMulator/csrc/memory.c",
        "PyMulator/csrc/registers.c",
        "PyMulator/csrc/terminate.c",
        "PyMulator/csrc/error.c",

		"../simulator/cpu/misc.c",
		"../simulator/core/opcodes.c",
		"../simulator/core/isa/decode_helpers.c",
		"../simulator/core/isa/decompile.c",

        ] + arm_thumb_files + operations_files,
        #debug only?
        extra_compile_args = ["-UNDEBUG", "-g", "-O0"]
)


setup(
    name = "PyMulator", 
    version = __version__,
    description = 'GDB-like interface for Mulator',
    ext_modules=[extension_mod],
    )

