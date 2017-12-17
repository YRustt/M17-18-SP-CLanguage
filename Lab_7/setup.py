from distutils.core import setup, Extension

setup(
    name='sum2',
    version='0.0.1',
    ext_modules=[Extension('sum2', ['sum2module.c'])]
)
