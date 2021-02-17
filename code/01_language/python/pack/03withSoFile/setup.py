from setuptools import setup

setup(name='mymathlib',
      version='0.1',
      description='this is a math packages',
      author='wsl',
      author_email='hbag666@163.com',
      packages=['mymathlib'],
      data_files=[('/mymathlib/clib',
                   ['mymathlib/clib/libtarget.so'])]
      )
