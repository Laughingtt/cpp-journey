import os
import sys
import subprocess
import versioneer

from setuptools import setup, find_packages, Extension
from setuptools.command.build_ext import build_ext


class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=""):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    def run(self):
        try:
            out = subprocess.check_output(["cmake", "--version"])
        except OSError:
            raise RuntimeError(
                "CMake must be installed to build the following extentions: "
                + ", ".join(e.name for e in self.extensions))
        for ext in self.extensions:
            self.build_extension(ext)

    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        cmake_args = [
            "-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=" + extdir,
            "-DPYTHON_EXECUTABLE=" + sys.executable
            ]
        platform_ = sys.platform
        if platform_ == "darwin":
            cmake_args.extend([
            "-DOPENSSL_ROOT_DIR=/usr/local/opt/openssl/",
            "-DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib/"])
        elif platform_ == "linux":
            cmake_args.extend([
            "-DOPENSSL_ROOT_DIR=/usr/local/openssl/",
            "-DOPENSSL_LIBRARIES=/usr/local/openssl/lib/"])
        else:
            raise KeyError("other platform not support")


        cfg = "Debug" if self.debug else "Release"
        build_args = ["--config", cfg]
        cmake_args += ["-DCMAKE_BUILD_TYPE=" + cfg]
        build_args += ["--", "-j6"]

        env = os.environ.copy()
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
        print("ext.sourcedir ",ext.sourcedir)
        subprocess.check_call(["cmake", ext.sourcedir] + cmake_args, cwd=self.build_temp, env=env)
        subprocess.check_call(["cmake", "--build", ".", "--target",
                               "_ecdh_lib"] + build_args, cwd=self.build_temp, env=env)


setup(
    name="ecdh_lib",
    version=versioneer.get_version(),
    author="Jian tian",
    author_email="jian.tian@rongshu.link",
    description="Encapsulation of prematching about bloom filter",
    packages=find_packages(where="python", include=["ecdh_lib", "ecdh_lib.*"]),
    package_dir={"": "python"},
    classifiers=[
        "Programming Language :: C++",
        "Programming Language :: Python :: 3",
        "Operating System :: OS Independent",
        "Topic :: Security :: Cryptography",
    ],
    ext_modules=[CMakeExtension("ecdh_lib")],
    cmdclass=dict(build_ext=CMakeBuild),
    zip_safe=False
)
