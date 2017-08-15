import os
#import os.path
#my_path = os.path.dirname(os.path.realpath(__file__))
#par_path = os.path.realpath( os.path.join( my_path, os.pardir))
#os.chdir( par_path)

from distutils.core import setup, Extension

#abspath = os.path.dirname(os.path.realpath(__file__)) + '/'

arm_thumb_dir =  'simulator/core/isa/arm-thumb/' 
arm_thumb_files = map(lambda y: arm_thumb_dir+y, filter(lambda x: '.c' in x, os.listdir(arm_thumb_dir)))
operations_dir = 'simulator/core/operations/'
operations_files = map(lambda y: operations_dir+y, 
                    filter(lambda x: '.c' in x, os.listdir(operations_dir)))

# the c++ extension module
extension_mod = Extension(
    name = "step", 
    define_macros = [ ('M_PROFILE', None) ],
    include_dirs = ['./simulator/'],
    sources = [   
        "lib_python/stepmodule.cc",
        "lib_python/core.c",
        "lib_python/exception.c",
        "lib_python/interrupts.c",
        "lib_python/memory.c",
        "lib_python/registers.c",
        "lib_python/step.c",
        "lib_python/terminate.c",
		"simulator/cpu/misc.c",
		"simulator/core/opcodes.c",
		"simulator/core/isa/decode_helpers.c",
		"simulator/core/isa/decompile.c",
        ] + arm_thumb_files + operations_files,
)


setup(
    name = "step", 
    version = '0.1',
    description = 'Soft-Step a single instruction using M-ulator',
    ext_modules=[extension_mod],
    package_dir = { '' : 'lib_python' },
    #script_name='./lib_python/setup.py',
    #data_files=['./lib_python/setup.py'],
    )

